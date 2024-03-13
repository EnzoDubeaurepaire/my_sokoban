/*
** EPITECH PROJECT, 2023
** B_PSU_100_LIL_1_1_sokoban_enzo_dubeaurepaire
** File description:
** event.c
*/

#include "../include/my.h"

void move_left(tab_t *tab, cursor_t *cursor)
{
    if (cursor->x - TAB_XO == 0)
        return;
    if (tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO - 1] == 'X') {
        if (cursor->x - TAB_XO - 1 == 0 ||
            tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO - 2] == '#' ||
            tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO - 2] == 'X')
            return;
        tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO - 2] = 'X';
    }
    if (tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO - 1] != '#') {
        tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO - 1] = 'P';
        tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO] = ' ';
        cursor->x -= 1;
    }
}

void move_right(tab_t *tab, cursor_t *cursor)
{
    if (tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO + 1] == '\0')
        return;
    if (tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO + 1] == 'X') {
        if (tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO + 2] == '\0' ||
            tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO + 2] == '#' ||
            tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO + 2] == 'X')
            return;
        tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO + 2] = 'X';
    }
    if (tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO + 1] != '#') {
        tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO + 1] = 'P';
        tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO] = ' ';
        cursor->x += 1;
    }
}

void move_up(tab_t *tab, cursor_t *cursor)
{
    if (cursor->y - TAB_YO == 0 ||
        cursor->x - TAB_XO >= my_strlen(tab->map[cursor->y - TAB_YO - 1]))
        return;
    if (tab->map[cursor->y - TAB_YO - 1][cursor->x - TAB_XO] == 'X') {
        if (cursor->y - 1 - TAB_YO == 0 || cursor->x - TAB_XO >=
            my_strlen(tab->map[cursor->y - TAB_YO - 2]) ||
            tab->map[cursor->y - TAB_YO - 2][cursor->x - TAB_XO] == '#' ||
            tab->map[cursor->y - TAB_YO - 2][cursor->x - TAB_XO] == 'X')
            return;
        tab->map[cursor->y - TAB_YO - 2][cursor->x - TAB_XO] = 'X';
    }
    if (tab->map[cursor->y - TAB_YO - 1][cursor->x - TAB_XO] != '#') {
        tab->map[cursor->y - TAB_YO - 1][cursor->x - TAB_XO] = 'P';
        tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO] = ' ';
        cursor->y -= 1;
    }
}

void move_down(tab_t *tab, cursor_t *cursor)
{
    if (!tab->map[cursor->y - TAB_YO + 1] ||
        cursor->x - TAB_XO >= my_strlen(tab->map[cursor->y - TAB_YO + 1]))
        return;
    if (tab->map[cursor->y - TAB_YO + 1][cursor->x - TAB_XO] == 'X') {
        if (!tab->map[cursor->y - TAB_YO + 2] || cursor->x - TAB_XO >=
            my_strlen(tab->map[cursor->y - TAB_YO + 2]) ||
            tab->map[cursor->y - TAB_YO + 2][cursor->x - TAB_XO] == '#' ||
            tab->map[cursor->y - TAB_YO + 2][cursor->x - TAB_XO] == 'X')
            return;
        tab->map[cursor->y - TAB_YO + 2][cursor->x - TAB_XO] = 'X';
    }
    if (tab->map[cursor->y - TAB_YO + 1][cursor->x - TAB_XO] != '#') {
        tab->map[cursor->y - TAB_YO + 1][cursor->x - TAB_XO] = 'P';
        tab->map[cursor->y - TAB_YO][cursor->x - TAB_XO] = ' ';
        cursor->y += 1;
    }
}

void manage_events(tab_t *tab, tab_t *tab_cpy, cursor_t *cursor)
{
    int key = getch();

    if (key == ' ')
        game(tab_cpy);
    if (key == 'e') {
        endwin();
        exit(0);
    }
    if (key == KEY_LEFT)
        move_left(tab, cursor);
    if (key == KEY_RIGHT)
        move_right(tab, cursor);
    if (key == KEY_UP)
        move_up(tab, cursor);
    if (key == KEY_DOWN)
        move_down(tab, cursor);
}
