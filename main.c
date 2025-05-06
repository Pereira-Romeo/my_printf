/*
** EPITECH PROJECT, 2024
** main
** File description:
** testing the library
*/

#include "my.h"
#include <stdio.h>

static
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

static
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

static
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

static
void test_mod_big_s(void)
{
    char *strs[] = {"hello", "world", "here is", "a", "list of string!", NULL};

    my_printf("strs: %10S\n", strs);
    my_printf("strs: % S\n", strs);
}

void test_mod_b(void)
{
    my_printf("1:%8.4b\n", 1);
    my_printf("69:% .8b\n", 69);
    my_printf("16:%#.8b\n", 16);
    my_printf("16:%# .8b\n", 16);
    my_printf("16:%# .8b\n", 16);
    my_printf("16:%# .12b\n", 16);
    my_printf("16:%# .14b\n", 16);
    my_printf("16:%# .16b\n", 16);
    my_printf("69420:%# .20b\n", 69420);
}

void test_mod_f(void)
{
    my_printf("69.69: %10f\n", 69.69);
    printf("69.69: %10f\n", 69.69);
    my_printf("49.3: %.2f\n", 49.3);
    printf("49.3: %.2f\n", 49.3);
    my_printf("10: %f\n", 10.0);
    printf("10: %f\n", 10.0);
    my_printf("10: %4.0f\n", 10.0);
    printf("10: %4.0f\n", 10.0);
    my_printf("10: %#4.0f\n", 10.0);
    printf("10: %#4.0f\n", 10.0);
    my_printf("10: %#-4.0f\n", 10.0);
    printf("10: %#-4.0f\n", 10.0);
}

void test_mod_p(void)
{
    char bruh[] = "hello there!";
    char *bruh2 = bruh + 2;

    my_printf("bruh is: '%s' at %p\n", bruh, bruh);
    printf("bruh is: '%s' at %p\n", bruh, bruh);
    my_printf("bruh2 is: '%*s' at %.20p\n", my_strlen(bruh) - 1, bruh2, bruh2);
    printf("bruh2 is: '%*s' at %.20p\n", my_strlen(bruh) - 1, bruh2, bruh2);
}

void test_mod_c(void)
{
    my_printf("%cell%-2ci'm testing modulo%2c\n", 'H', 'o', 'c');
}

int main(void)
{
    test_mod_s();
    test_mod_x();
    test_mod_d();
    test_mod_big_s();
    test_mod_b();
    test_mod_f();
    test_mod_p();
    test_mod_c();
    my_printf("Done testing\n");
    return 0;
}
