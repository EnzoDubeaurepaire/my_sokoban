/*
** EPITECH PROJECT, 2023
** B_PSU_100_LIL_1_1_sokoban_enzo_dubeaurepaire
** File description:
** sokoban.c
*/

#include "../include/my.h"

static int is_valid_char(char c)
{
    return (c == 'X' || c == ' ' ||
        c == 'O' || c == 'P' || c == '#' || c == '\n');
}

char **fill_tab(char *map, int lines, int max_columns)
{
    char **tab = malloc(sizeof(char *) * (lines + 1));
    int k = 0;
    int line_passed;

    for (int i = 0; i < lines; i++) {
        tab[i] = malloc(max_columns + 1);
        line_passed = 0;
        for (int j = 0; j < max_columns; j++) {
            line_passed = (map[k] == '\n') ? 1 : line_passed;
            tab[i][j] = (!line_passed) ? map[k] : '\0';
            k = (!line_passed) ? k + 1 : k;
        }
        k++;
        tab[i][max_columns] = '\0';
    }
    tab[lines] = NULL;
    return tab;
}

tab_t get_tab(char *map)
{
    int lines = 0;
    int max_columns = 0;
    int tmp = 0;
    char **tab;

    for (int i = 0; map[i] != '\0'; i++) {
        if (!is_valid_char(map[i]))
            exit(84);
        max_columns = (tmp > max_columns) ? tmp : max_columns;
        tmp = (tmp > max_columns) ? 0 : tmp + 1;
        tmp = (map[i] == '\n') ? 0 : tmp;
        lines += (map[i] == '\n') ? 1 : 0;
    }
    tab = fill_tab(map, lines, max_columns);
    return (tab_t){tab, lines, max_columns};
}

void do_sokoban(int fd)
{
    char buffer[30001];
    long int size = read(fd, &buffer, 30000);
    char *map = malloc(sizeof(char) * (size + 1));
    tab_t tab;

    map[0] = '\0';
    buffer[size] = '\0';
    my_strcat(map, buffer);
    tab = get_tab(map);
    game(&tab);
}
