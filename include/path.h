#ifndef PATH_H
#define PATH_H

int exists(const char *path);
int get_absolute_root(char *current_dir, char *marker_path);
int get_file_path(const char *filename, char **path);

#endif