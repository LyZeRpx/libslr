/*
** EPITECH PROJECT, 2024
** libslr [WSL: Ubuntu]
** File description:
** dir.c
*/

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include "libslr.h"

size_t dir_size(const char *dirpath)
{
    DIR *folder = opendir(dirpath);
    size_t i = 1;

    for (size_t count = 0; readdir(folder) != NULL; count++) {
        if (count > 2)
            i++;
    }
    return i;
}

const char **dir_list_files(const char *dirpath)
{
    DIR *folder = opendir(dirpath);
    struct dirent *next = readdir(folder);
    size_t size = dir_size(dirpath);
    size_t **slr_results = malloc(sizeof(size_t *) * size + 1);
    const char **file_list = malloc(sizeof(char *) * size + 1);
    char **keywords = load_keywords();

    for (signed int i = -2; next != NULL; i++) {
        if (i >= 0) {
            file_list[i] = strdup(next->d_name);
           // printf("[%d] %s\n", i, next->d_name); debug print
            slr_results[i] = review_file(next->d_name, keywords);
            dump_results()
        }
        next = readdir(folder);
    }
    closedir(folder);
    return file_list;
}
