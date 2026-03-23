#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include "utility.h"

int read_file(const char *path, char *content) {
    FILE *file = fopen(path, "r");
    if (file == NULL) return -1;

    char line[BUFSIZ];
    while (fgets(line, BUFSIZ, file) != NULL) {
        strncat(content, line, MAX_FILE_SIZE - strlen(content) - 1);
    }

    return 0;
}

void get_digit_count(int n, int *num_digits) {
    *num_digits = (n == 0) ? 1 : (int)log10(abs(n)) + 1;
}

