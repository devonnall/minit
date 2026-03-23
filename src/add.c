#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "add.h"
#include "object.h"
#include "path.h"


// int add_file(string_t *file) {
//     struct blob_object blob;
//     if (get_blob_object(file, &blob) != 0) return -1;

//     printf("SHA1 hash: %s\n", blob.hash_hex);

//     return 0;
// }


// int add_file(struct file **files, char *path) {
//     v_char *content = read_file_content(path);
//     if (content == NULL) return -1;

//     struct file *file;

//     HASH_FIND_STR(*files, content->str, file);

//     if (file == NULL) {
//         file = (struct file *)malloc(sizeof *file);
//         file->content = content->str;
//         HASH_ADD_STR(*files, content, file);
//     }

//     cvector_push_back(file->paths, path);
//     v_char_free(content);

//     return 0;
// }