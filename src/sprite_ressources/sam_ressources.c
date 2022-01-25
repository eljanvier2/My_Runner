/*
** EPITECH PROJECT, 2022
** sam ressources
** File description:
** part 1 of main sprite functions
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

void move_rect(utils_t *uts, int offset, int max)
{
    static int cont = 0;

    if ((uts->sp_dat->rect.left + offset) < max && cont == 0) {
        uts->sp_dat->rect.top -= 0;
        uts->sp_dat->rect.left += offset;
        cont = 1;
    } else if ((uts->sp_dat->rect.left + offset) < max && cont == 1) {
        uts->sp_dat->rect.top += 0;
        uts->sp_dat->rect.left += offset;
        cont = 0;
    } else {
        uts->sp_dat->rect.left = 30;
    }
}

void sprite_clock_handle(utils_t *uts)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(uts->sam->clock);
    seconds = time.microseconds / 80000.0;
    if (seconds > 1.0) {
        move_rect(uts, 163, 1231);
        sfSprite_setTextureRect(uts->sam->sprite, uts->sp_dat->rect);
        sfClock_restart(uts->sam->clock);
    }
}

void sam_arrival(utils_t *uts, sfEvent event)
{
    while (uts->sp_dat->pos.x < 400) {
        background_run(uts->bckg, event, uts);
        sprite_clock_handle(uts);
        uts->sp_dat->pos.x += 1;
        sfSprite_setPosition(uts->sam->sprite, uts->sp_dat->pos);
        sfRenderWindow_drawSprite(uts->bckg->win, uts->sam->sprite, 0);
        sfRenderWindow_display(uts->bckg->win);
    }
}

void sprite_run(utils_t *uts)
{
    if (uts->sam->jump == true)
        jump_clock_handle(uts);
    else
        sprite_clock_handle(uts);
    sfRenderWindow_drawSprite(uts->bckg->win, uts->sam->sprite, 0);
}
