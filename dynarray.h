#ifndef STACK_H
#define STACK_H

#include "bithacks.h"

#define dynarray_t(type)                                                \
    struct dynarray_##type##_t {                                        \
        type* data;                                                     \
        uint fill;                                                      \
        uint capacity;                                                  \
    }

#define dynarray_init(dynarray, size)                                   \
    (dynarray->fill = 0,                                                \
     dynarray->capacity = size,                                         \
     dynarray->data = alloc(sizeof(dynarray->data[0]) * size)


#define dynarray_add(stack, elem)                                       \
    (bdynarray->fill++,                                                  \
     dynarray->fill == dynarray->capacity ? (                           \
         dynarray->capacity *= 2,                                       \
         dynarray->data = realloc(dynarray->data, dynarray->capacity),  \
         dynarray->data[dynarray->fill - 1] = elem                      \
         )                                                              \
     : (                                                                \
         dynarray->data[dynarray->fill - 1] = elem                      \
         )                                                              \
        )

#define dynarray_request(stack, num) (                                  \
        dynarray->fill += num,                                          \
        dynarray->fill >= dynarray->capacity ? (                        \
            dynarray->capacity <<= ilog2(dynarray->fill / dynarray->capacity), \
            dynarray->data = realloc(dynarray->data, dynarray->capacity) \
            )                                                           \
        : (                                                             \
            dynarray->data                                              \
            )                                                           \
        )



#endif
