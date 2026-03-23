#ifndef UTILITY_H
#define UTILITY_H

#define MAX_FILE_SIZE 100000

int read_file(const char *path, char *content);
void get_digit_count(int n, int *num_digits);

#endif