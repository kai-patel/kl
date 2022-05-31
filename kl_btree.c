#include "kl_btree.h"

#include <stdlib.h>
#include <errno.h>

static void kl_btree_free(struct kl_btree* tree) {
    if (tree == NULL) return;

    kl_btree_free(tree->left);
    kl_btree_free(tree->right);

    if (tree->value != NULL)
        free(tree->value);
    free(tree);
}

static struct kl_btree* kl_btree_add(struct kl_btree* tree, void* i, bool (*compare)(const void* a, const void* b)) {
    if (tree == NULL) return kl_btree_new(i);
    if (compare(i, tree->value) == false) {
        tree->left = kl_btree_add(tree->left, i, compare);
    } else {
        tree->right = kl_btree_add(tree->right, i, compare);
    }

    return tree;
}

static kl_btree* kl_btree_init(kl_btree* tree, void* val) {
    tree->value = val;
    tree->left = NULL;
    tree->right = NULL;
    tree->add = &kl_btree_add;
    tree->free = &kl_btree_free;
    return tree;
}

kl_btree* kl_btree_new(void* val) {
    kl_btree* tree = (kl_btree*) malloc(sizeof(kl_btree));
    if (tree == NULL) perror("new");
    return kl_btree_init(tree, val);
}

