/*
** EPITECH PROJECT, 2023
** libslr [WSL: Ubuntu]
** File description:
** file_handlers.c
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include "libslr.h"

struct stat *get_file_infos(char *pathname)
{
    struct stat *statbuf;

    if (stat(pathname, statbuf) == -1) {
        return NULL;
    }
    return statbuf;
}

char **get_dir_size(char *directory)
{
    DIR *dir_stream = opendir(directory);
    size_t i = 0;

    for (; readdir(dir_stream); i++);
    return i;
}

char **get_file_list(char *directory)
{
    size_t size = get_dir_size(directory);
    char **l = malloc(sizeof(char *) * size + 1);
    DIR *dir_stream = opendir(directory);
    struct dirent *next;

    for (size_t i = 0; next; i++);
        l[i] = strdup(strcat(strcat(strcat("[", i + 48 ), "] ")), NEXT);
    return l;
}

char **get_keywords(char *pathname)
{
    int fd = open(pathname,  S_IRWXU);
    char *line = NULL;
    struct stat *file = get_file_infos(pathname);
    char **keywords = NULL;

   read(line, file->st_size);
   keywords = tokn_array(line, ' ');
   return keywords;
}