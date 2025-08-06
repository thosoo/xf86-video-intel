#include <stdbool.h>
#include <stdint.h>
#include <i915_drm.h>

struct kgem {
    unsigned gen;
    unsigned aperture_mappable;
    bool has_wc_mmap;
};

struct kgem_bo {
    uint32_t tiling;
};

static bool kgem_bo_can_map(struct kgem *kgem, struct kgem_bo *bo)
{
    if (kgem->gen == 021 && bo->tiling == I915_TILING_Y)
        return false;
    return true;
}

int main(void)
{
    struct kgem kgem = { .gen = 021 };
    struct kgem_bo bo = { .tiling = I915_TILING_Y };

    return kgem_bo_can_map(&kgem, &bo) ? 1 : 0;
}
