/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** fspe_maker
*/

#include "../headers/my_printf.h"
#include <stdio.h>

static
int my_c_isnum(char const c)
{
    if (c < 48 || c > 57)
        return FALSE;
    return TRUE;
}

void reset_pf(fspe_t *pf)
{
    pf->flags = 0;
    pf->len_mod = 0;
    pf->precision = 0;
    pf->width = 0;
}

static
int add_len_mod(char flag, fspe_t *mod)
{
    if (flag == 'l') {
        mod->len_mod |= (mod->len_mod & 1) ? 2 : 1;
        return TRUE;
    }
    if (flag == 'h') {
        mod->len_mod |= (mod->len_mod & 4) ? 8 : 4;
        return TRUE;
    }
    return FALSE;
}

static
int add_flags(char flag, fspe_t *mod)
{
    if (flag == '#') {
        mod->flags |= 1;
        return TRUE;
    }
    if (flag == '0') {
        mod->flags |= 2;
        return TRUE;
    }
    if (flag == '-') {
        mod->flags |= 4;
        return TRUE;
    }
    if (flag == ' ') {
        mod->flags |= 8;
        return TRUE;
    }
    if (flag == '+') {
        mod->flags |= 16;
        return TRUE;
    }
    return FALSE;
}

static
void add_wp(fspe_t *mod, char **ptr, va_list list)
{
    if (**ptr == '*') {
        mod->width = va_arg(list, int);
        *ptr += 1;
    } else {
        mod->width = pf_getint(*ptr);
        for (; my_c_isnum(**ptr); *ptr += 1) {}
    }
    if (**ptr == '.') {
        *ptr += 1;
        if (**ptr == '*') {
            mod->precision = va_arg(list, int);
            *ptr += 1;
        } else {
            mod->precision = pf_getint(*ptr);
            for (; my_c_isnum(**ptr); *ptr += 1) {}
        }
    }
}

void make_fspe_mod(fspe_t *mod, char **ptr, va_list list)
{
    for (; **ptr; *ptr += 1) {
        if (add_flags(**ptr, mod))
            continue;
        break;
    }
    add_wp(mod, ptr, list);
    for (; **ptr; *ptr += 1) {
        if (add_len_mod(**ptr, mod))
            continue;
        break;
    }
}

void fspe_mod_debug(fspe_t *mod)
{
    printf("\n");
    printf("\e[1;34mflags:\e[0m\n'#':%d\n'0':%d\n'-':%d\n' ':%d\n'+':%d\n"
    "overall: %d\n",
    mod->flags & 1, mod->flags & 2, mod->flags & 4, mod->flags & 8,
    mod->flags & 16, mod->flags);
    printf("\e[1;34mwidth:\e[0m %d\n\e[1;34mprecision:\e[0m %d\n",
    mod->width, mod->precision);
    printf("\e[1;34mlength modifiers:\e[0m\nl :%d\nll:%d\nh :%d\nhh:%d\n"
    "overall: %d\n",
    mod->len_mod & 1, mod->len_mod & 2, mod->len_mod & 4, mod->len_mod & 8,
    mod->len_mod);
    printf("\e[1;34mcurrent length:\e[0m %d\n", mod->current_len);
    printf("\n");
}
