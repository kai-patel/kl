#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "kl_vector.h"
#include "kl_bstree.h"
#include "kl_llist.h"

int compare(const void* a, const void* b) {
    return *((int*) a) - *((int*) b);
}

void print_tree(kl_bstree* tree, uint8_t indent) {
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
        int* item = malloc(sizeof(int));
        if (item != NULL) *item = i+1;
        vec->add(vec, (void*) item);
    }

    for (size_t i = 0; i < vec->length; i++) {
        printf("%d\n", *(int*)(vec->items[i]));
    }
    printf("Length: %" PRIu32 "\n", vec->length);
    vec->free(vec);

    // Binary Search Tree Testing
    int* root_val = malloc(sizeof(int));
    *root_val = 4;

    kl_bstree* tree = kl_bstree_new((void*) root_val);
    printf("Initial Root: %d\n", *(int*) tree->value);

    for (int i = 0; i < 8; i++) {
        int* new_val = malloc(sizeof(int));
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

    int* val_to_find = malloc(sizeof(int));
    *val_to_find = 5;
    kl_bstree* found = tree->find(tree, (void*) val_to_find, compare);
    printf("Found: %d @ %p\n", *(int*) found->value, (void*) found);
    printf("Expected: 5 @ %p\n", (void*) tree->right);
    tree->free(tree);

    // Singly Linked List Testing
    kl_llist* llist = kl_llist_new();

    for (int i = 0; i < 16; i++) {
        int* new_val = malloc(sizeof(int));
        *new_val = i+1;
        llist->add(llist, (void*) new_val);
    }

    kl_llist_node* curr = llist->head;
    while (curr != NULL) {
        printf("%d\n", *(int*) curr->value);
        curr = curr->next;
    }

    *val_to_find = 2;

    kl_llist_node* found_node = llist->find(llist, (void*) val_to_find, compare);
    printf("Found: %d @ %p\n", *(int*) found_node->value, (void*) found_node);
    printf("Expected: 2 @ %p\n", (void*) llist->head->next);

    llist->reverse(llist);
    llist->delete_v(llist, (void*) val_to_find, compare);

    curr = llist->head;
    while (curr != NULL) {
        printf("%d\n", *(int*) curr->value);
        curr = curr->next;
    }
    
    llist->free(llist);
    return 0;
}
