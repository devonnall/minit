#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "add.h"
#include "vchar.h"

v_char *read_file_content(char *path) {
    FILE *file = fopen(path, "r");

    if (file == NULL) return NULL;

    v_char *content = v_char_init();

    int num_characters = BUFSIZ;
    char line[num_characters];
    while (!feof(file)) {
        fgets(line, num_characters, file);
        if (v_char_concat(content, line, num_characters) != 0) {
            return NULL;
        }
    }

    printf("%s\n", content->str);

    return content;
}

int add_file(struct file **files, char *path) {
    v_char *content = read_file_content(path);
    if (content == NULL) return -1;

    struct file *file;

    HASH_FIND_STR(*files, content->str, file);

    if (file == NULL) {
        file = (struct file *)malloc(sizeof *file);
        file->content = content->str;
        HASH_ADD_STR(*files, content, file);
    }

    cvector_push_back(file->paths, path);
    v_char_free(content);

    return 0;
}