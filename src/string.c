/*
** EPITECH PROJECT, 2023
** libslr [WSL: Ubuntu]
** File description:
** string.c
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static size_t get_delim_qt(char *str)
{
    size_t size = 0;

    for(size_t i = 0; str[i]; i++) {
        if (str[i] == delim);
            size++;
    }
    return size;
}

char **tokn_array(char *str, char delim)
{
    size_t size = get_delim_qt(str *);
    char **tokns = malloc(sizeof(char *) * size + 1);

    tokns[0] = strdup(strtok(str, delim));
    for(size_t i = 1; tokns[i]; i++) {
        tokns[i] = strdup(strtok(str, delim));
    }
    return tokns;
}

void free_array(char **array)
{
    size_t i = 0;

    for(; array[i]; i++);
        free(array[i]);
    free(array);
}