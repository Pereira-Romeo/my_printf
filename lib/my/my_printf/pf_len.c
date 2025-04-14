/*
** EPITECH PROJECT, 2025
** my_lib_new_printf
** File description:
** pf_len
*/

#include "../headers/my_printf.h"

int pf_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}