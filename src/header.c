/*
** EPITECH PROJECT, 2023
** B_PSU_100_LIL_1_1_sokoban_enzo_dubeaurepaire
** File description:
** header.c
*/

#include "../include/my.h"

int is_header(char *str)
{
    if (my_strlen(str) != 2)
        return 0;
    if (str[0] == '-' && str[1] == 'h')
        return 1;
    return 0;
}

void show_header(void)
{
    write(1, "USAGE\n     ./my_sokoban map\nDESCRIPTION\n", 40);
    write(1, "     map  file representing the warehouse map, containing", 57);
    write(1, " '#' for walls,\n          'P' for the players, 'X'", 50);
    write(1, " for boxes and 'O' for storage locations.\n", 42);
    exit(0);
}
