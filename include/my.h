/*
** EPITECH PROJECT, 2023
** B_PSU_100_LIL_1_1_sokoban_enzo_dubeaurepaire
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/ioctl.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #define TAB_XO (COLS / 2 - tab->columns / 2)
    #define TAB_YO (LINES / 2 - tab->lines / 2)
typedef struct {
    char **map;
    int lines;
    int columns;
} tab_t;
typedef struct {
    int x;
    int y;
} cursor_t;
void game(tab_t *tab);
int is_header(char *str);
void show_header(void);
int my_strlen(char const *str);
void do_sokoban(int fd);
char *my_strcat(char *dest, char const *src);
void manage_events(tab_t *tab, tab_t *tab_cpy, cursor_t *cursor);
#endif
