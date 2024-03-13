/*
** EPITECH PROJECT, 2023
** B_PSU_100_LIL_1_1_sokoban_enzo_dubeaurepaire
** File description:
** game.c
*/

#include "../include/my.h"

static int is_not_movable(tab_t *tab, int i, int j)
{
    int not_movable = 0;

    if (j == 0 || tab->map[i][j - 1] == '#' || tab->map[i][j - 1] == 'X' ||
        tab->map[i][j + 1] == '\0' || tab->map[i][j + 1] == '#' ||
        tab->map[i][j + 1] == 'X')
        not_movable += ((i == 0 || tab->map[i - 1][j] == '#' ||
                tab->map[i - 1][j] == 'X' || tab->map[i + 1] == 0 ||
                tab->map[i + 1][j] == '#' ||
                tab->map[i + 1][j] == 'X')) ? 1 : 0;
    return not_movable;
}

static int get_box_number(tab_t *tab)
{
    int count = 0;

    for (int i = 0; tab->map[i]; i++)
        for (int j = 0; tab->map[i][j] != '\0'; j++)
            count += (tab->map[i][j] == 'X') ? 1 : 0;
    return count;
}

static void is_lose(tab_t *tab, tab_t *tab_cpy)
{
    int lose = 0;

    for (int i = 0; i < tab->lines; i++)
        for (int j = 0; j < tab->columns; j++)
            lose += (tab->map[i][j] == 'X' &&
                    is_not_movable(tab, i, j)) ? 1 : 0;
    if (lose == get_box_number(tab)) {
        endwin();
        exit(1);
    }
}

static void is_win(tab_t *tab, tab_t *tab_cpy)
{
    int win = 1;

    for (int i = 0; i < tab->lines; i++)
        for (int j = 0; j < tab->columns; j++)
            win = (tab_cpy->map[i][j] == 'O' && tab->map[i][j] != 'X')
                    ? 0 : win;
    if (win == 1) {
        endwin();
        exit(0);
    }
}

static void add_missing_storage(tab_t *tab, tab_t *tab_cpy)
{
    for (int i = 0; i < tab->lines; i++) {
        for (int j = 0; j < tab->columns; j++) {
            tab->map[i][j] = (tab_cpy->map[i][j] == 'O' &&
                    tab->map[i][j] == ' ') ? tab_cpy->map[i][j] :
                    tab->map[i][j];
        }
    }
}

tab_t copy_tab(tab_t *tab)
{
    char **map = malloc(sizeof(char *) * (tab->lines + 1));
    int j;

    for (int i = 0; i < tab->lines; i++) {
        map[i] = malloc(my_strlen(tab->map[i]) + 1);
        j = 0;
        for (; tab->map[i][j] != '\0'; j++) {
            map[i][j] = tab->map[i][j];
        }
        map[i][j] = '\0';
    }
    map[tab->lines] = 0;
    return (tab_t){map, tab->lines, tab->columns};
}

void show_tab(tab_t *tab, cursor_t *cursor)
{
    clear();
    if (tab->lines > LINES || tab->columns > COLS) {
        move(LINES / 2, COLS / 2 - 8);
        printw("Enlarge Terminal");
    }
    for (int i = 0; tab->map[i] && !(tab->lines > LINES ||
        tab->columns > COLS); i++) {
        move(LINES / 2 + i - tab->lines / 2, COLS / 2 - tab->columns / 2);
        printw(tab->map[i]);
    }
}

cursor_t init_cursor(tab_t *tab)
{
    cursor_t cursor;

    cursor.x = 0;
    cursor.y = 0;
    for (int i = 0; tab->map[i]; i++)
        for (int j = 0; tab->map[i][j] != '\0'; j++) {
            cursor.x = (tab->map[i][j] == 'P') ? TAB_XO + j : cursor.x;
            cursor.y = (tab->map[i][j] == 'P') ? TAB_YO + i : cursor.y;
        }
    return cursor;
}

void game(tab_t *tab)
{
    tab_t tab_cpy = copy_tab(tab);
    cursor_t cursor;

    initscr();
    curs_set(0);
    cursor = init_cursor(tab);
    keypad(stdscr, TRUE);
    while (1) {
        show_tab(tab, &cursor);
        refresh();
        is_win(tab, &tab_cpy);
        is_lose(tab, &tab_cpy);
        move(cursor.y, cursor.x);
        manage_events(tab, &tab_cpy, &cursor);
        add_missing_storage(tab, &tab_cpy);
    }
}
