#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void list_untracked_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) return;

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".git") == 0)
            continue;

        printf("U %s/%s\n", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            char next_path[1024];
            snprintf(next_path, sizeof(next_path), "%s/%s", path, entry->d_name);
            
            list_untracked_files(next_path);
        }
    }
    closedir(dp);
}