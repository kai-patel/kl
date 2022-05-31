#ifndef KL_BSTREE_H
#define KL_BSTREE_H

#include <stdbool.h>

typedef struct kl_bstree {
    void* value;
    struct kl_bstree* left;
    struct kl_bstree* right;
    struct kl_bstree* (*add)(struct kl_bstree*, void*, int (*)(const void*, const void*));
    struct kl_bstree* (*find)(struct kl_bstree* const, const void*, int (*)(const void*, const void*));
    void (*free)(struct kl_bstree*);
} kl_bstree;

kl_bstree* kl_bstree_new(void*);

#endif
