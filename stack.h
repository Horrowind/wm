#ifndef STACK_H
#define STACK_H

#include "pool.h"

#define stack_t(type_t)                         \
    struct stack_##type##_t {                   \
        pool_t pool;                            \
        type_t data_type[0];                    \
    }

#define stack_init(stack)                       \
    pool_init(&(stack)->pool)

#define stack_push(stack, elem)                 \
    *pool_alloc(                                \
        &(stack)->pool,                         \
        sizeof((stack)->data_type[0])) = elem
    

#define stack_pop(stack)                        \
    ((stack)->pool.fill -=                      \
     sizeof((stack)->data_type[0]),             \
     *(typeof(&(stack)->data_type[0]))          \
     (&(stack)->pool.data[(stack)->pool.fill]))




#endif
