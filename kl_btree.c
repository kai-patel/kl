#include "kl_btree.h"

#include <stdlib.h>

bool kl_btree_add(struct kl_btree* tree, void* i, bool (*compare)(const void* a, const void* b)) {
    if (tree == NULL || i == NULL || compare == NULL) return true;
    return false;
}

static kl_btree* kl_btree_init(kl_btree* tree) {
    tree->value = NULL;
    tree->left = NULL;
    tree->right = NULL;
    tree->add = &kl_btree_add;
    return tree;
}

kl_btree* kl_btree_new(void) {
    kl_btree* tree = (kl_btree*) malloc(sizeof(kl_btree));
    if (tree == NULL) return NULL;
    return kl_btree_init(tree);
}
