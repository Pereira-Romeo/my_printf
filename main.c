/*
** EPITECH PROJECT, 2024
** main
** File description:
** testing the library
*/

#include "my.h"
#include <stdio.h>

void test_mod_s(void)
{
    my_printf("Hello %s!\n", "World");
    printf("Hello %s!\n", "World");
    my_printf("test '-012.5s' %-12.5s!\n", "World");
    printf("test '-012.5s' %-12.5s!\n", "World");
    my_printf("test '12.3s' %12.3s!\n", "World");
    printf("test '12.3s' %12.3s!\n", "World");
    my_printf("test 2 mods back to back %s%x\n", "World", 10);
    printf("test 2 mods back to back %s%x\n", "World", 10);
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

void test_mod_d(void)
{
    my_printf("15 in hexa is: %+8.8d\n", 15);
    printf("15 in hexa is: %+8.8d\n", 15);
    my_printf("16 in hexa is: %8d\n", -16);
    printf("16 in hexa is: %8d\n", -16);
    my_printf("69 in hexa is: %d\n", 69);
    printf("69 in hexa is: %d\n", 69);
    my_printf("long int: %.8ld\n", 1191981951651689151);
    printf("long int: %.8ld\n", 1191981951651689151);
    my_printf("long int: %+8.10ld\n", 1015160854169810681);
    printf("long int: %+8.10ld\n", 1015160854169810681);
    my_printf("15 in hexa is: %- 8.8d\n", -15);
    printf("15 in hexa is: %- 8.8d\n", -15);
}

void test_mod_big_s(void)
{
    char *strs[] = {"hello", "world", "here is", "a", "list of string!", NULL};

    my_printf("strs: %10S\n", strs);
    my_printf("strs: % S\n", strs);
}

int main(void)
{
    //test_mod_s();
    //test_mod_x();
    //test_mod_d();
    test_mod_big_s();
    my_printf("Done testing\n");
    return 0;
}
