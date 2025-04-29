/*
** EPITECH PROJECT, 2025
** my_lib_new_printf
** File description:
** mod_s
*/

#include "my_printf.h"

int mod_s(va_list list, fspe_t *pf)
{
    char *str = va_arg(list, char *);
    int str_len = 0;
    int real_len = 0;

    if (!str)
        str = "(nil)";
    if (pf->precision > 0)
        str_len = my_min(my_strlen(str), pf->precision);
    else
        str_len = my_strlen(str);
    if (!(pf->flags & 4))
        real_len += pf_width_handler(str_len, pf);
    real_len += write(pf->fd, str, str_len);
    if (pf->flags & 4)
        real_len += pf_width_handler(str_len, pf);
    return real_len;
}
