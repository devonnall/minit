#ifndef UTILITY_H
#define UTILITY_H

#include "string_t.h"

int read_file(char *path, string_t *content, int *n_digits);
int prepend(char *first, char *second, char **dst);
int create_directory(char *root, char *name, char **path);
int create_directories(char *root, char **names, int n);

#endif