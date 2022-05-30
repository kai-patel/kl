#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "kl_vector.h"

int main(void) {
    kl_vector* vec = kl_vector_new();
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
    return 0;
}
