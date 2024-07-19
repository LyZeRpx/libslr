/*
** EPITECH PROJECT, 2024
** libslr [WSL: Ubuntu]
** File description:
** libslr.h
*/

#ifndef LIBSLH_H
    #define LIBSLH_H
    #include <sys/stat.h>
    #include <stddef.h>
char **load_keywords(void);
size_t *review_file(const char *filename, char **keywords);
char **str_tolist(char *str);
struct stat get_file_stats(const char *filename);
const char **dir_list_files(const char *dirpath);
size_t dir_size(const char *dirpath);
#endif