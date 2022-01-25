/*
** EPITECH PROJECT, 2021
** background functions
** File description:
** every background/parallax related function
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

void backg_draw(background_t *back)
{
    sfRenderWindow_drawSprite(back->win, back->stars->sprite, NULL);
    sfRenderWindow_drawSprite(back->win, back->cl_L->sprite, NULL);
    sfRenderWindow_drawSprite(back->win, back->cloud->sprite, NULL);
    sfRenderWindow_drawSprite(back->win, back->mtn->sprite, NULL);
    sfRenderWindow_drawSprite(back->win, back->cl_s->sprite, NULL);
    sfRenderWindow_drawSprite(back->win, back->ground->sprite, NULL);
}

void background_run(background_t *bckg, sfEvent event, utils_t *uts)
{
    sfRenderWindow_clear(bckg->win, sfBlack);
    analyse_events(bckg->win, event, uts);
    sfRenderWindow_drawSprite(bckg->win, bckg->bg->sprite, NULL);
    parallax_pars(bckg);
    backg_draw(bckg);
}

void background_run2(background_t *bckg, sfEvent event, utils_t *uts)
{
    analyse_events2(bckg->win, event, uts);
    sfRenderWindow_drawSprite(bckg->win, bckg->bg->sprite, NULL);
    parallax_pars(bckg);
    backg_draw(bckg);
}

void bck_clock_handle(gameobject_t *obj, int type)
{
    sfTime time;
    float milliseconds = 0;

    time = sfClock_getElapsedTime(obj->clock);
    milliseconds = time.microseconds / 1000;
    if (milliseconds > obj->clock_refresh && type == 0) {
        parallax_handle(obj);
        sfClock_restart(obj->clock);
    } else if (milliseconds > obj->clock_refresh && type == 1) {
        parallax_handle2(obj);
        sfClock_restart(obj->clock);
    }
}
