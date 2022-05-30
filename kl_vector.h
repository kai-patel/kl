#ifndef KL_VECTOR_H
#define KL_VECTOR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define KL_INTERNAL_VECTOR_INITIAL_CAPACITY 32

typedef struct kl_vector {
    void** items;
    uint32_t capacity;
    uint32_t length;
    bool (*add)(struct kl_vector*, void*);
    void (*free)(struct kl_vector*);
    bool (*resize)(struct kl_vector*, uint32_t);
} kl_vector;

kl_vector* kl_vector_new(void);

#endif
