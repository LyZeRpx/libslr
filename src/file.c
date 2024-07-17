/*
** EPITECH PROJECT, 2024
** libslr [WSL: Ubuntu]
** File description:
** file.c
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct stat get_file_stats(const char *filename)
{
    struct stat statbuff;

    if (stat(filename, &statbuff) == -1) {
        perror("stat");
        exit(84);
    }
    return statbuff;
}