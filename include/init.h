#ifndef INIT_H
#define INIT_H

int create_dir(char *dir);
int create_dirs(char *root, char **dirs, int num_dirs);
int create_file(char *root, char *file);
int init(char *root_path);

#endif