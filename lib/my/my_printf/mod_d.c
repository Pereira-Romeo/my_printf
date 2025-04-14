/*
** EPITECH PROJECT, 2025
** my_lib_new_printf
** File description:
** mod_d
*/

#include "../headers/my_printf.h"

int pf_putlli(long long int nb)
{

}

static
int handle_precision(int length, fspe_t *pf)
{

}

static
int base_mod_d(va_list list, fspe_t *pf)
{
    int nb = va_arg(list, int);
    int nb_len = pf_intlen(nb) + (pf->flags & 16 && nb > -1) ? 1 : 0;
    int len = 0;

    if (!(pf->flags & 4))
        len += pf_width_handler(nb_len, pf);
    if (pf->flags & 16 && nb > -1)
        len += write(pf->fd, "+", 1);
    if (nb < 0) {
        len += write(pf->fd, "-", 1);
        nb *= -1;
    }
    len = handle_precision(pf_intlen(nb), pf);
    len += my_putlli(nb);
    if (pf->flags & 4)
        len += pf_width_handler(len, pf);
    return len;
}

static
int long_mod_d(va_list list, fspe_t *pf)
{
    long int nb = va_arg(list, long int);
}

static
int lglg_mod_d(va_list list, fspe_t *pf)
{
    long long int nb = va_arg(list, long long int);
}

int mod_d(va_list list, fspe_t *pf)
{
    if (pf->len_mod & 2)
        return lglg_mod_d(list, pf);
    if (pf->len_mod & 1)
        return long_mod_d(list, pf);
    return basic_mod_d(list, pf);
}
