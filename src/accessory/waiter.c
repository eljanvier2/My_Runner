/*
** EPITECH PROJECT, 2022
** waiter
** File description:
** function used to wait
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameobject_ressources.h"
#include "my.h"

void waiter(utils_t *uts, sfClock *clock, sfEvent event)
{
    sfTime time;
    float seconds;

    while (sfRenderWindow_isOpen(uts->bckg->win)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 100000;
        if (seconds > 1.0) {
            sfClock_restart(clock);
            return;
        }
    }
}

int random_gen(void)
{
    int rdm = 0;

    srand(time(NULL));
    rand();
    rdm = rand() % 2 + 1;
    return rdm;
}
