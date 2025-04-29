/*
** EPITECH PROJECT, 2025
** my_lib_new_printf
** File description:
** mod_d
*/

#include "my_printf.h"

static
int int_mod_d(va_list list, fspe_t *pf)
{
    int nb = va_arg(list, int);
    char buffer[12] = "00000000000";
    char *ptr = buffer;
    int Tlen = my_max(my_intlen(nb), pf->precision);
    int len = 0;

    if (!(pf->flags & 4))
        len += pf_width_handler(Tlen, pf);
    if (nb < 0) {
        len += write(pf->fd, "-", 1);
        nb *= -1;
    }
    len += zero_padding(my_intlen(nb), pf);
    len += my_putint(nb);
    if (pf->flags & 4)
        len += pf_width_handler(Tlen, pf);
    return len;
}

static
int long_mod_d(va_list list, fspe_t *pf)
{
    long int nb = va_arg(list, long int);
    char buffer[22] = "000000000000000000000";
    char *ptr = buffer;
    int Tlen = my_max(my_lgilen(nb), pf->precision);
    int len = 0;

    if (!(pf->flags & 4))
        len += pf_width_handler(Tlen, pf);
    if (nb < 0) {
        len += write(pf->fd, "-", 1);
        nb *= -1;
    }
    len += zero_padding(my_lgilen(nb), pf);
    len += my_putlgi(nb);
    if (pf->flags & 4)
        len += pf_width_handler(Tlen, pf);
    return len;
}

static
int lli_mod_d(va_list list, fspe_t *pf)
{
    long long int nb = va_arg(list, long long int);
    char buffer[22] = "000000000000000000000";
    char *ptr = buffer;
    int Tlen = my_max(my_llilen(nb), pf->precision);
    int len = 0;

    if (!(pf->flags & 4))
        len += pf_width_handler(Tlen, pf);
    if (nb < 0) {
        len += write(pf->fd, "-", 1);
        nb *= -1;
    }
    len += zero_padding(my_llilen(nb), pf);
    len += my_putlli(nb);
    if (pf->flags & 4)
        len += pf_width_handler(Tlen, pf);
    return len;
}

int mod_d(va_list list, fspe_t *pf)
{
    if (pf->len_mod & 2)
        return lli_mod_d(list, pf);
    if (pf->len_mod & 1)
        return long_mod_d(list, pf);
    return int_mod_d(list, pf);
}
