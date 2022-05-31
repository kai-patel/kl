#ifndef KL_BTREE_H
#define KL_BTREE_H

#include <stdbool.h>

typedef struct kl_btree {
    void* value;
    struct kl_btree* left;
    struct kl_btree* right;
    struct kl_btree* (*add)(struct kl_btree*, void*, bool (*)(const void*, const void*));
    void (*free)(struct kl_btree*);

} kl_btree;

kl_btree* kl_btree_new(void*);

#endif
