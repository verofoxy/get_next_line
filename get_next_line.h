/*
** EPITECH PROJECT, 2019
** bootstrap
** File description:
** ihddfghjklfkjgrhjij
*/


#ifndef READ_SIZE
#define READ_SIZE (4096)
#endif

#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H

void put_back_slash_zero(char *buffer, int slash_n);
char *stock_read_file(int fd);
char *my_strcatt(char *src, char const *dest);
char *my_strvcpy(char *all_sent);
int if_black_slash_n_th(char *str);
char *get_next_line(int fd);

#endif
