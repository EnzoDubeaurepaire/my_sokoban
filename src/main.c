/*
** EPITECH PROJECT, 2023
** B_PSU_100_LIL_1_1_sokoban_enzo_dubeaurepaire
** File description:
** main.c
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    int fd;

    if (ac != 2)
        return 84;
    if (is_header(av[1]))
        show_header();
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return 84;
    do_sokoban(fd);
}
