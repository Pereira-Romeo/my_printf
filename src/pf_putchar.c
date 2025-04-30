/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** pf_putchar
*/

#include "my_printf.h"

int pf_putchar(char c, fspe_t *pf)
{
    return write(pf->fd, &c, 1);
}
