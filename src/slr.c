/*
** EPITECH PROJECT, 2024
** libslr [WSL: Ubuntu]
** File description:
** slr.c
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libslr.h"

static size_t count_delims(const char *str, const char delim)
{
    size_t count = 0;

    for (size_t i = 0; str[i]; i++) {
        str[i] == delim ? count++ : 0;
    }
    return count + 1;
}

char **str_tolist(char *str)
{
    const char delim = ' ';
    size_t size = count_delims(str, delim);
    char **list = malloc(sizeof(char *) * size + 1);
    size_t i = 0;

    list[0] = strtok(str, &delim);
    for(; i != size; i++) {
        list[i] = strdup(strtok(NULL, &delim));
    }
    list[i + 1] = NULL;
    return list;
}

char **load_keywords(void)
{
    const char *config_filepath = "config/keywords.conf";
    struct stat statbuff = get_file_stats(config_filepath);
    int fd = open(config_filepath, S_IRUSR);
    char *line = NULL;
    char **keywords = NULL;

    read(fd, line, statbuff.st_size);
    keywords = str_tolist(line);
    return keywords;
}

void dump_results(char *filename, size_t *match_counter, char **keywords)
{
    printf("%s:\n", filename):
    for(size_t i = 0; keywords[i]; i++) {
        printf("Found %ld matches with keyword [%s]\n", match_counter[i], keywords[i]);
    }
}

size_t *review_file(const char *filename, char **keywords)
{
    char *line = NULL;
    size_t n = 0;
    size_t *match_counter = NULL;
    FILE *fileptr = fopen(strcat("files/", filename), "r");
    char **list_buff = NULL;

    while(getline(&line, &n, fileptr) != -1) {
        list_buff = str_tolist(line);
        for(size_t i = 0; list_buff[i]; i++) {
            for(size_t j = 0; keywords[j]; j++) {
                if (strcmp(list_buff[i], keywords[j]) == 0) {
                    match_counter[j] += 1;
                }
            }
        }
    }
    return match_counter;
}