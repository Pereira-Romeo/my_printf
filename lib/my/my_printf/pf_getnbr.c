/*
** EPITECH PROJECT, 2025
** my_lib_new_printf
** File description:
** pf_getnbr
*/

#include "../headers/my_printf.h"

int pf_getint(char *str)
{
    int nb = 0;
    int nbr_of_minus = 0;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            nbr_of_minus++;
        i += 1;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        i += 1;
    }
    if (nbr_of_minus % 2 == 1)
        return nb * -1;
    return nb;
}
