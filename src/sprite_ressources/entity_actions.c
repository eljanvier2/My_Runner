/*
** EPITECH PROJECT, 2022
** jump
** File description:
** jumping functions
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

void jump(utils_t *uts)
{
    static int count = 0;

    if (uts->sp_dat->pos.y <= 400)
        count = 1;
    if (uts->sp_dat->pos.y > 400 && count == 0)
        uts->sp_dat->pos.y -= 20;
    else if (uts->sp_dat->pos.y < 700)
        uts->sp_dat->pos.y += 20;
    if (uts->sp_dat->pos.y == 700) {
        count = 0;
        uts->sam->jump = false;
    }
    sfSprite_setPosition(uts->sam->sprite, uts->sp_dat->pos);
    return;
}

void jump_clock_handle(utils_t *uts)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(uts->sam->clock);
    seconds = time.microseconds / 25000.0;
    if (seconds > 1.0) {
        jump(uts);
        sfClock_restart(uts->sam->clock);
    }
}
