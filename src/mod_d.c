/*
** EPITECH PROJECT, 2025
** my_lib_new_printf
** File description:
** mod_d
*/

#include "my_printf.h"

int mod_d(va_list list, fspe_t *pf)
{
    if (pf->len_mod & 2)
        return lli_mod_d(list, pf);
    if (pf->len_mod & 1)
        return long_mod_d(list, pf);
    return int_mod_d(list, pf);
}
