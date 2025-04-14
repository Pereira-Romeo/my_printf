/*
** EPITECH PROJECT, 2024
** main
** File description:
** testing the library
*/

#include "my.h"

int main(void)
{
    my_printf("Hello %s!\n", "World");
    my_printf("test '#+- 012.5s' %#+- 012.5s!\n", "World");
    my_printf("test '12.3s' %+ 12.3s!\n", "World");
    my_printf("test 2 mods back to back %s%c\n", "World", 'c');
    my_printf("empty mod at end of string %");
    my_printf("\n");
    my_printf("empty mod at end of string but with formatting %#0 12ll");
    my_printf("\n");
    my_dprintf(STDOUT_FILENO, "This is my_dprintf in %s\n", "STDOUT_FILENO");
    my_dprintf(STDERR_FILENO, "This one is in the STDERR_FILENO\n");
    return 0;
}
