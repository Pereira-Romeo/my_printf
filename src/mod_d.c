/*
** EPITECH PROJECT, 2025
** my_lib_new_printf
** File description:
** mod_d
*/

#include "my_printf.h"

static
int handle_precision(int length, fspe_t *pf)
{
    int len = 0;

    while (len < pf->width - length)
        len += write(pf->fd, "0", 1);
    return len;
}

static
int basic_mod_d(va_list list, fspe_t *pf)
{
    int nb = va_arg(list, int);
    int len = my_intlen(nb) + (pf->flags & 16 && nb > -1) ? 1 : 0;
    int real_len = 0;

    if (!(pf->flags & 4))
        real_len += pf_width_handler(len, pf);
    if (pf->flags & 16 && nb > -1)
        real_len += write(pf->fd, "+", 1);
    if (nb < 0) {
        real_len += write(pf->fd, "-", 1);
        nb *= -1;
    }
    real_len = handle_precision(my_intlen(nb), pf);
    real_len += my_putlli(nb);
    if (pf->flags & 4)
        real_len += pf_width_handler(real_len, pf);
    return real_len;
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

/*
if (pf->len_mod & 2)
    return lglg_mod_d(list, pf);
if (pf->len_mod & 1)
    return long_mod_d(list, pf);
*/
int mod_d(va_list list, fspe_t *pf)
{    
    return basic_mod_d(list, pf);
}
