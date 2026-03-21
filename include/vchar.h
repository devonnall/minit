#ifndef VCHAR_H
#define VCHAR_H

typedef struct {
    char *str;
    int size;
    int capacity;
} v_char;

int v_char_concat(v_char *dst, const char *src, int size);
v_char *v_char_init();
void v_char_free(v_char *arr);

#endif