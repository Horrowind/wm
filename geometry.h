#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "datasizes.h"

typedef struct {
    union {
        struct {
            f32 x;
            f32 y;
        };
        f32 coords[2];
    };
} fvec2_t;

inline
fvec2_t fvec2(float x, float y) {
    fvec2_t fvec2 = {x, y};
    return fvec2;
}

typedef struct {
    union {
        struct {
            f32 xmin;
            f32 ymin;
        };
        fvec2_t min_vec;
    };
    union {
        struct {
            f32 xmax;
            f32 ymax;
        };
        fvec2_t max_vec;
    };
} rect_t;

rect_t rect_create(f32 xmin, f32 xmax, f32 ymin, f32 ymax) {
    rect_t rect = {xmin, ymin, xmax, ymax};
    return rect;
}


b32 rect_contains(rect_t rect, fvec2_t vec) {
    return rect.xmin <= vec.x && vec.x < rect.xmax && rect.ymin <= vec.y && vec.y < rect.ymax;
};

#endif
