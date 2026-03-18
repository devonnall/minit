#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vchar.h"

int v_char_concat(v_char *dst, const char *src, int size) {
    if (dst->capacity <= dst->size) {
        dst->capacity = dst->capacity * 2;
        char *new_str = realloc(dst->str, dst->capacity);
        if (new_str == NULL) {
            return -1;
        }
        dst->str = new_str;
    }
    strncat(dst->str, src, size);
    dst->size += size;
    return 0;
}

v_char *v_char_init() {
    v_char *arr = (v_char*)malloc(sizeof *arr);
    arr->str = malloc(BUFSIZ * sizeof(char));
    arr->size = 0;
    arr->capacity = BUFSIZ;
    return arr;
}

void v_char_free(v_char *arr) {
    free(arr->str);
    free(arr);
}