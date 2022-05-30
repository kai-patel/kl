#include <stdlib.h>

#include "kl_vector.h"

bool kl_vector_resize(struct kl_vector* vec, uint32_t capacity) {
    void** items = realloc(vec->items, sizeof(void*) * capacity);
    if (items != NULL) {
        vec->items = items;
        vec->capacity = capacity;
        return false;
    }
    return true;
}

bool kl_vector_add(struct kl_vector* vec, void* i) {
    if (vec->length == vec->capacity) {
        if(kl_vector_resize(vec, vec->capacity * 2)) return true;
    }
    vec->items[vec->length++] = i;
    return false;
}

void kl_vector_free(struct kl_vector* vec) {
    free(vec->items);
    free(vec);
}

static bool kl_vector_init(kl_vector* vec) {
    vec->capacity = KL_INTERNAL_VECTOR_INITIAL_CAPACITY;
    vec->length = 0;
    vec->items = malloc(sizeof(void*) * vec->capacity);
    vec->add = &kl_vector_add;
    vec->free = &kl_vector_free;
    vec->resize = &kl_vector_resize;
    if (vec->items != NULL) {
        return false;
    }
    return true;
}

kl_vector* kl_vector_new(void) {
    kl_vector* vec = (kl_vector*) malloc(sizeof(kl_vector));
    bool res = kl_vector_init(vec);
    if (res) return NULL;
    return vec;
}
