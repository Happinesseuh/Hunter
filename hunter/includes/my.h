/*
** EPITECH PROJECT, 2020
** my_printf.h
** File description:
** prototypes function for my_printf.c
*/

#ifndef MY_PRINTF_H
#define MY_PRINT_H

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
char *my_revstr(char *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
int my_str_isprintable(char const *str);
int my_getnbr(char const *str);
int my_printf(char *format, ...);

#endif
