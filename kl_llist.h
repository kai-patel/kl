#ifndef KL_LLIST_H
#define KL_LLIST_H

typedef struct kl_llist_node {
    void* value;
    struct kl_llist_node* next;
} kl_llist_node;

typedef struct kl_llist {
    kl_llist_node* head;
    kl_llist_node* (*find)(struct kl_llist*, void*, int (*) (const void*, const void*));
    void (*reverse)(struct kl_llist*);
    void (*add)(struct kl_llist*, void*);
    void (*free)(struct kl_llist*);
    void (*delete_p)(struct kl_llist*, void*); // Delete-by-pointer
    void (*delete_v)(struct kl_llist*, void*, int (*) (const void*, const void*)); // Delete-by-value
} kl_llist;

kl_llist* kl_llist_new(void);

#endif
