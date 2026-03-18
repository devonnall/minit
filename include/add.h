#ifndef ADD_H
#define ADD_H

#include "uthash.h"
#include "vchar.h"
#include "cvector.h"

struct file {
    char *content;
    cvector(char*) paths;
    UT_hash_handle hh;
};

v_char *read_file_content(char*);

int add_file(struct file **files, char*);

#endif