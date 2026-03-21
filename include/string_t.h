#ifndef VCHAR_H
#define VCHAR_H

typedef struct {
    char *str;
    int size;
    int capacity;
} string_t;

int string_t_concat(string_t *dst, const char *src, int size);
string_t *string_t_init();
void string_t_free(string_t *arr);

#endif