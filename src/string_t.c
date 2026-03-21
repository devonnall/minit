#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_t.h"

int string_t_concat(string_t *dst, const char *src, int size) {
    if (dst->capacity <= dst->size) {
        dst->capacity = dst->capacity * 2;
        char *new_str = realloc(dst->str, dst->capacity);
        if (new_str == NULL) {
            return -1;
        }
        dst->str = new_str;
    }
    strncat(dst->str, src, size);
    dst->size = strlen(dst->str);
    return 0;
}

string_t *string_t_init() {
    string_t *arr = (string_t*)malloc(sizeof *arr);
    arr->str = malloc(BUFSIZ * sizeof(char));
    arr->size = 0;
    arr->capacity = BUFSIZ;
    return arr;
}

void string_t_free(string_t *arr) {
    free(arr->str);
    free(arr);
}