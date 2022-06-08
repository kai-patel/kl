#include <stdlib.h>
#include <assert.h>
#include "kl_llist.h"

static kl_llist_node* kl_llist_node_new(void* i) {
    kl_llist_node* node = malloc(sizeof(*node));
    if (node == NULL) {
        perror("llist_node_new");
        return NULL;
    }
    node->value = i;
    node->next = NULL;
    return node;
}
static kl_llist_node* kl_llist_find(struct kl_llist* llist, void* i, int (*compare) (const void*, const void*)) {
    kl_llist_node* curr = llist->head;

    while (curr) {
        if (compare(i, curr->value) == 0) {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

static void kl_llist_reverse(struct kl_llist* llist) {
    kl_llist_node* prev = NULL;
    kl_llist_node* curr = llist->head;
    kl_llist_node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    llist->head = prev;
}

static void kl_llist_delete_p(struct kl_llist* llist, void* i) {
    kl_llist_node* curr = llist->head;
    kl_llist_node* prev = NULL;

    while (curr != NULL) {
        if (curr->value == i) {
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                llist->head = NULL;
            }
            return;
        }
            
        prev = curr;
        curr = curr->next;
    }
}

static void kl_llist_delete_v(struct kl_llist* llist, void* i, int (*compare) (const void* a, const void* b)) {
    kl_llist_node* curr = llist->head;
    kl_llist_node* prev = NULL;

    while (curr != NULL) {
        if (compare(i, curr->value) == 0) {
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                llist->head = NULL;
            }
            return;
        }
            
        prev = curr;
        curr = curr->next;
    }
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
    kl_llist_node* tmp;
    kl_llist_node* head = llist->head;

    while (llist->head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    free(llist);
}

void kl_llist_init(kl_llist* llist) {
    llist->head = NULL;
    llist->find = &kl_llist_find;
    llist->reverse = &kl_llist_reverse;
    llist->add = &kl_llist_add;
    llist->free = &kl_llist_free;
    llist->delete_p = &kl_llist_delete_p;
    llist->delete_v = &kl_llist_delete_v;
}

kl_llist* kl_llist_new(void) {
    kl_llist* llist = malloc(sizeof(*llist));
    if (llist == NULL) perror("llist_new");
    kl_llist_init(llist);
    return llist;
}
