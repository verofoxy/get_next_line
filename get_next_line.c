/*
** EPITECH PROJECT, 2019
** fghjk
** File description:
** fghj
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

void put_back_slash_zero(char *buffer, int slash_n)
{
    int count = 0;

    while (count < slash_n) {
        buffer[count] = '\0';
        count++;
    }
}

char *my_strcatt(char *src, char const *dest)
{
    int j = 0, length_src, length_dest;
    char *str = NULL;

    for (length_src = 0; src && src[length_src] != '\0'; length_src++);
    for (length_dest = 0; dest && dest[length_dest] != '\0'; length_dest++);
    str = malloc(sizeof(char) * (length_dest + length_src + 1));
    if (str == NULL)
        return NULL;
    while (j < length_src) {
        str[j] = src[j];
        j++;
    }
    j = 0;
    while (j < length_dest) {
        str[j + length_src] = dest[j];
        j++;
    }
    str[length_dest + length_src] = '\0';
    return (str);
}

char *stock_read_file(int fd)
{
    char *result = NULL;
    int bytes;
    char *buffer;

    if (fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    if (buffer == NULL)
        return NULL;
    put_back_slash_zero(buffer, READ_SIZE + 1);
    while ((bytes = read(fd, buffer, READ_SIZE)) > 0) {
        result = my_strcatt(result, buffer);
        put_back_slash_zero(buffer, READ_SIZE + 1);
    }
    return (result);
}

int if_back_slash_n_th(char* str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (str[count] == '\n')
            return count;
        count++;
    }
    if (count > 0 && str[count] == '\0')
        return count;
    return -1;
}

char *my_strvcpy(char *all_sent)
{
    static int offset = 0;
    int slash_n;
    char *ready = NULL;
    int i = 0;

    slash_n = if_back_slash_n_th(all_sent + offset);
    if (slash_n >= 0) {
        ready = malloc(sizeof(char) * (slash_n + 1));
        if (ready == NULL)
            return NULL;
        put_back_slash_zero(ready, slash_n + 1);
        while (i < slash_n && all_sent[offset + i] != '\n') {
            ready[i] = all_sent[i + offset];
            i++;
        }
    } else
        return NULL;
    offset = offset + slash_n + 1;
    return ready;
}

char *get_next_line(int fd)
{
    static char *all_sent = NULL;
    static int first_time = 0;
    char *ready;
    if (first_time == 0) {
        all_sent = stock_read_file(fd);
        if (all_sent == NULL)
            return NULL;
        first_time = 1;
    }
    ready = my_strvcpy(all_sent);
    return ready;
}

