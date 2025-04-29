/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** fspe_maker
*/

#include "my_printf.h"
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
    switch (flag) {
    case '#':
        mod->flags |= 1;
        return TRUE;
    case '0':
        mod->flags |= 2;
        return TRUE;
    case '-':
        mod->flags |= 4;
        return TRUE;
    case ' ':
        mod->flags |= 8;
        return TRUE;
    case '+':
        mod->flags |= 16;
        return TRUE;
    default:
        return FALSE;
    }
}

static
void add_width(fspe_t *pf, char **ptr, va_list list)
{
    (*ptr)++;
    if (**ptr == '*') {
        pf->precision = va_arg(list, int);
        (*ptr)++;
    } else {
        pf->precision = my_getnbr(*ptr);
        while (my_c_isnum(**ptr))
            (*ptr)++;
    }
}

static
void add_wp(fspe_t *pf, char **ptr, va_list list)
{
    if (**ptr == '*') {
        pf->width = va_arg(list, int);
        (*ptr)++;
    } else {
        pf->width = my_getnbr(*ptr);
        while (my_c_isnum(**ptr))
            (*ptr)++;
    }
    if (**ptr == '.') {
        add_width(pf, ptr, list);
    }
}

void make_fspe_mod(fspe_t *pf, char **ptr, va_list list)
{
    for (; **ptr; *ptr += 1) {
        if (add_flags(**ptr, pf))
            continue;
        break;
    }
    add_wp(pf, ptr, list);
    for (; **ptr; *ptr += 1) {
        if (add_len_mod(**ptr, pf))
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
