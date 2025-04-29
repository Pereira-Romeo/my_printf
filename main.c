/*
** EPITECH PROJECT, 2024
** main
** File description:
** testing the library
*/

#include "my.h"

void test_mod_s(void)
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
}

void test_mod_x(void)
{
    my_printf("15 in hexa is: %.8x\n", 15);
    printf("15 in hexa is: %.8x\n", 15);
    my_printf("16 in hexa is: %8x\n", 16);
    printf("16 in hexa is: %8x\n", 16);
    my_printf("69 in hexa is: %#x\n", 69);
    printf("69 in hexa is: %#x\n", 69);
    my_printf("5543646 in hexa is: %#.8X\n", 5543646);
    printf("5543646 in hexa is: %#.8X\n", 5543646);
    my_printf("10 in hexa is: %#8x\n", 10);
    printf("10 in hexa is: %#8x\n", 10);
}

int main(void)
{
    test_mod_s();
    test_mod_x();
    my_printf("Done testing\n");
    return 0;
}
