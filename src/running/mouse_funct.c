/*
** EPITECH PROJECT, 2021
** mouse funct
** File description:
** mouse related functions
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameobject_ressources.h"
#include "my.h"

int analyse_events(sfRenderWindow *window, sfEvent event, utils_t *uts)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
            uts->sam->jump = true;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
            uts->pause = true;
    }
    return 0;
}

int analyse_events2(sfRenderWindow *window, sfEvent event, utils_t *uts)
{
    event.type = 0;
    event.key.code = 0;
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return 1;
    return 0;
}

int menu_click(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonReleased)
            return (manage_menu_click(event.mouseButton));
    }
    return 0;
}

int manage_menu_click(sfMouseButtonEvent event)
{
    if (event.x >= 702 && event.x <= 1212) {
        if (event.y >= 401 && event.y <= 495)
            return 1;
        if (event.y >= 721 && event.y <= 840)
            return 2;
        if (event.y >= 466 && event.y <= 656)
            return 3;
    }
    return 0;
}

int ender(sfRenderWindow *win, utils_t *uts, sfEvent event, map_t *map)
{
    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR)
            restart_game(uts, map);
    }
    return 0;
}
