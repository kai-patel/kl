#include "kl_bstree.h"

#include <stdlib.h>
#include <errno.h>

static void kl_bstree_free(struct kl_bstree* tree) {
    if (tree == NULL) return;

    kl_bstree_free(tree->left);
    kl_bstree_free(tree->right);

    if (tree->value != NULL)
        free(tree->value);
    free(tree);
}

static struct kl_bstree* kl_bstree_add(struct kl_bstree* tree, void* i, bool (*compare)(const void* a, const void* b)) {
    if (tree == NULL) return kl_bstree_new(i);
    if (compare(i, tree->value) == false) {
        tree->left = kl_bstree_add(tree->left, i, compare);
    } else {
        tree->right = kl_bstree_add(tree->right, i, compare);
    }

    return tree;
}

static kl_bstree* kl_bstree_init(kl_bstree* tree, void* val) {
    tree->value = val;
    tree->left = NULL;
    tree->right = NULL;
    tree->add = &kl_bstree_add;
    tree->free = &kl_bstree_free;
    return tree;
}

kl_bstree* kl_bstree_new(void* val) {
    kl_bstree* tree = (kl_bstree*) malloc(sizeof(kl_bstree));
    if (tree == NULL) perror("new");
    return kl_bstree_init(tree, val);
}

