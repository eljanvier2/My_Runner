/*
** EPITECH PROJECT, 2022
** menu accessories
** File description:
** functions to help run menus
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

void controls(background_t *bckg, utils_t *uts)
{
    sfEvent event;

    event.type = 0;
    event.key.code = 0;
    while (sfRenderWindow_isOpen(bckg->win)) {
        sfRenderWindow_clear(bckg->win, sfBlack);
        sfRenderWindow_pollEvent(bckg->win, &event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return;
        background_run2(bckg, event, uts);
        sfRenderWindow_drawSprite(bckg->win, bckg->controls->sprite, NULL);
        sfRenderWindow_display(bckg->win);
    }
    return;
}

void good_end_utils(utils_t *us, map_t *map)
{
    sfRenderWindow_drawSprite(us->bckg->win, us->bckg->yes->sprite, NULL);
    us->score->pos2.x = 950;
    us->score->pos2.y = 570;
    us->score->scale.x = 2;
    us->score->scale.y = 2;
    sfText_setScale(us->score->points, us->score->scale);
    sfText_setPosition(us->score->points, us->score->pos2);
    sfRenderWindow_drawText(us->bckg->win, us->score->points, NULL);
    sfRenderWindow_display(us->bckg->win);
}
