/*
** EPITECH PROJECT, 2023
** libslr [WSL: Ubuntu]
** File description:
** systematic_litterature_review.c
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t *get_match_number(char *filename, char **keywords)
{
    size_t size = get_array_size(keywords);
    size_t *matches = malloc(sizeof(size_t) * size + 1);
    size_t len = 0;
    char *buff;
    char **queue = NULL;
    FILE *stream = fopen(filename; "r");

    while (getline(&buff, &len, stream) != NULL) {
        queue = tokn_array(buff; )
    }
}

size_t **review_dir(char *pathname)
{

}