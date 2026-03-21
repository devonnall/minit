#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

int init(char *root_path) {
    strcat(root_path, "/");

    char minit_directory[] = ".minit/";
    char *minit_relative_path = malloc(256 * sizeof(char));
    int minit_result = create_directory(root_path, minit_directory, &minit_relative_path);
    if (minit_result == -1) {
        printf("Minit repository already initialized.\n\nAborting...\n");
        return -1;
    } else if (minit_result == -2) {
        fprintf(stderr, "A problem occurred initializing minit repository.\n\nAborting...\n");
        return -1;
    }

    char *directories[] = {
        "refs/",
        "objects/"
    };

    int num_directories = 2;

    if (create_directories(minit_relative_path, directories, num_directories) != 0) {
        return -1;
    }

    char filename[] = "HEAD";
    strcat(minit_relative_path, filename);

    FILE *head = fopen(minit_relative_path, "w");
    if (head == NULL) {
        printf("Failed creating file.");
        return -1;
    }

    fprintf(head, "ref: refs/heads/main");
    fclose(head);

    printf("Minit repository successfully initialized\n");

    return 0;
}