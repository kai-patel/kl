#include <stdlib.h>
#include <assert.h>
#include "kl_llist.h"

static kl_llist_node* kl_llist_find(struct kl_llist* llist) {
    assert(0 && "Not implemented");
    return NULL;
}
static void kl_llist_reverse(struct kl_llist* llist) {
    assert(0 && "Not implemented");
}
static void kl_llist_add(struct kl_llist* llist, void* i) {
    assert(0 && "Not implemented");
}
static void kl_llist_free(struct kl_llist* llist) {
    assert(0 && "Not implemented");
}

void kl_llist_init(kl_llist* llist, void* i) {
    llist->head = (kl_llist_node*) malloc(sizeof(kl_llist_node));
    if (llist->head == NULL) {
        perror("llist_init");
        return;
    }
    llist->head->value = i;
    llist->head->next = NULL;
    llist->find = &kl_llist_find;
    llist->reverse = &kl_llist_reverse;
    llist->add = &kl_llist_add;
    llist->free = &kl_llist_free;
}

kl_llist* kl_llist_new(void* i) {
    kl_llist* llist = (kl_llist*) malloc(sizeof(kl_llist));
    if (llist == NULL) perror("llist_new");
    kl_llist_init(llist, i);
    return llist;
}
