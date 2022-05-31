#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "kl_vector.h"
#include "kl_btree.h"

bool compare(const void* a, const void* b) {
    return *((int*) a) < *((int*) b) ? false : true;
}

void print_tree(kl_btree* tree, uint8_t indent) {
    if (tree == NULL) return;
    for (uint8_t i = 0; i < indent; i++)
        printf(" ");
    printf("%d\n", *(int*) tree->value);
    print_tree(tree->left, indent+1);
    print_tree(tree->right, indent+1);
}

int main(void) {

    // Vector Testing
    kl_vector* vec = kl_vector_new();
    if (vec == NULL) fprintf(stderr, "Error creating vector!\n");
    for (int i = 0; i < 1024; i++) {
        int* item = (int*) malloc(sizeof(int));
        if (item != NULL) *item = i+1;
        vec->add(vec, (void*) item);
    }

    for (size_t i = 0; i < vec->length; i++) {
        printf("%d\n", *(int*)(vec->items[i]));
    }
    printf("Length: %" PRIu32 "\n", vec->length);
    vec->free(vec);

    // Binary Tree Testing
    int* root_val = (int*) malloc(sizeof(int));
    *root_val = 4;

    kl_btree* tree = kl_btree_new((void*) root_val);
    printf("Initial Root: %d\n", *(int*) tree->value);

    for (int i = 0; i < 8; i++) {
        int* new_val = (int*) malloc(sizeof(int));
        *new_val = i+1;
        if (i != 3)
            tree->add(tree, new_val, compare);
    }

    print_tree(tree, (uint8_t) 0);

    printf("Final Root: %d\n", *(int*) tree->value);
    printf(
           "Root: %p, Left: %p, Right: %p\n",
           tree->value,
           (void*) tree->left,
           (void*) tree->right
           );
    tree->free(tree);
    return 0;
}
