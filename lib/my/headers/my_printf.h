/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** my_printf
** excluding my_printf and my_dprintf, any functions in this header file
** should remain unused as they are subject to change and only intended
** to be used by my_printf and my_dprintf
*/

#ifndef MA_PRINTF_H
    #define MA_PRINTF_H
    #include <stddef.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include "my_errno.h"
    #include "my_bool.h"
    #define NB_SPE 20 //number of specifiers

int my_printf(char *format, ...);

int my_dprintf(int fd, char *format, ...);

//fspe_t struct for my_printf
//@param fd the output
//@param current_len current number of characters written
//@param width min width
//@param precision max len of str or numbers after the dot
//@param flags string with all flags
//@param len_mod type length modifier
typedef struct fspe_s {
    int fd;
    int current_len;
    int width;
    int precision;
    char flags;
    char len_mod;
}fspe_t;

//reset all values of an fspe struct but fd and current_len
//@param pf fspee_t struct
void reset_pf(fspe_t *pf);
//Read the format of the transformation
//@param pf fspe_t struct
//@param ptr adresse of the current string
//@param list va_list
//@note ptr will be moved and once this function stop, it should be on top
//of the specifier, if there is nothing then the specifier is missing
void make_fspe_mod(fspe_t *pf, char **ptr, va_list list);
//print everything inside an fspe_t struct, uses printf
//@param pf fspe_t struct to print
void fspe_mod_debug(fspe_t *pf);

//spe_t struct for my_printf
//@param letter the specifier
//@param func the function assigned to specifier
//@note func have to return an int representing the number of characters
//they wrote and take as parameter:
//va_list list, fspe_t *pf
typedef struct spe_s {
    char letter;
    int (*func)(va_list list, fspe_t *pf);
}spe_t;


//transformations:

//handle a string transformation
//@param list va_list
//@param pf fspe_t struct
//@returns number of written characters
//OR -1 on error
int mod_s(va_list list, fspe_t *pf);

//utils:

//Get length of an str
//@param str string to get length of
//@returns length of str
int pf_strlen(char *str);

//Get smallest value
//@param v1 first number to compare
//@param v2 second number to compare
//@returns smallest value
int pf_min(int v1, int v2);

//Add enough padding to reach minimum field width if padding is neeeded
//@param length current field width
//@param pf fspe_t struct
//@returns number of characters written
int pf_width_handler(int length, fspe_t *pf);

//get a number from a string
//@param str string to get number from
//@returns the number in str
int pf_getint(char *str);

#endif /* MA_PRINTF_H */
