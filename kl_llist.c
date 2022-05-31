#include <stdlib.h>
#include <assert.h>
#include "kl_llist.h"

static kl_llist_node* kl_llist_node_new(void* i) {
    kl_llist_node* node = (kl_llist_node*) malloc(sizeof(kl_llist_node));
    if (node == NULL) {
        perror("llist_node_new");
        return NULL;
    }
    node->value = i;
    node->next = NULL;
    return node;
}
static kl_llist_node* kl_llist_find(struct kl_llist* llist) {
    assert(0 && "Not implemented");
    return NULL;
}
static void kl_llist_reverse(struct kl_llist* llist) {
    assert(0 && "Not implemented");
}
static void kl_llist_add(struct kl_llist* llist, void* i) {
    if (llist->head == NULL) {
        llist->head = kl_llist_node_new(i);
        return;
    }

    kl_llist_node* curr = llist->head;
    while (curr != NULL && curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = kl_llist_node_new(i);
}
static void kl_llist_free(struct kl_llist* llist) {
    assert(0 && "Not implemented");
}

void kl_llist_init(kl_llist* llist) {
    llist->head = NULL;
    llist->find = &kl_llist_find;
    llist->reverse = &kl_llist_reverse;
    llist->add = &kl_llist_add;
    llist->free = &kl_llist_free;
}

kl_llist* kl_llist_new(void) {
    kl_llist* llist = (kl_llist*) malloc(sizeof(kl_llist));
    if (llist == NULL) perror("llist_new");
    kl_llist_init(llist);
    return llist;
}
