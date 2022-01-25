/*
** EPITECH PROJECT, 2022
** flea ressources
** File description:
** everey function allowing ennemy fleas to operate
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

void flea_move_rect(obj_data_t *fl_dat, int offset, int max)
{
    static int cont = 0;

    if ((fl_dat->rect.left + offset) < max && cont == 0) {
        fl_dat->rect.top -= 0;
        fl_dat->rect.left += offset;
        cont = 1;
    } else if ((fl_dat->rect.left + offset) < max && cont == 1) {
        fl_dat->rect.top += 0;
        fl_dat->rect.left += offset;
        cont = 0;
    } else {
        fl_dat->rect.left = 0;
    }
}

void flea_clock_handle(gameobject_t *flea, obj_data_t *fl_dat)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(flea->clock);
    seconds = time.microseconds / 100000.0;
    if (seconds > 1.0) {
        flea_move_rect(fl_dat, 101, 1910);
        sfSprite_setTextureRect(flea->sprite, fl_dat->rect);
        sfClock_restart(flea->clock);
    }
}

int flea_run(utils_t *uts)
{
    sfSprite_setPosition(uts->flea1->sprite, uts->fl1_dat->pos);
    sfSprite_setPosition(uts->flea2->sprite, uts->fl2_dat->pos);
    if (check_equal(uts, 90))
        return 1;
    flea_clock_handle(uts->flea1, uts->fl1_dat);
    flea_clock_handle(uts->flea2, uts->fl2_dat);
    sfRenderWindow_drawSprite(uts->bckg->win, uts->flea1->sprite, 0);
    sfRenderWindow_drawSprite(uts->bckg->win, uts->flea2->sprite, 0);
    return 0;
}

void entity_handler(sfSprite *sprite, obj_data_t *fl_dat, map_t *map)
{
    static int count = 0;

    if (fl_dat->pos.x >= -500 && count == 0) {
        fl_dat->pos.x -= 5;
        if (fl_dat->pos.x <= -200) {
            fl_dat->pos.x = 1930;
            map->active1 = false;
            map->map_index++;
        }
    }
    sfSprite_setPosition(sprite, fl_dat->pos);
}
