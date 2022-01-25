/*
** EPITECH PROJECT, 2022
** run
** File description:
** main running loop and utils
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "gameobject_ressources.h"
#include "my.h"

int checks(utils_t * uts, map_t * map, sfEvent event)
{
    if (map->map_switch == true)
        map_reader(uts, map);
    if (flea_run(uts) == 1) {
        end_menu(uts, map);
        return 1;
    }
    if (map->active1 == true)
        entity_handler(uts->flea1->sprite, uts->fl1_dat, map);
    if (map->active2 == true)
        entity_handler(uts->flea2->sprite, uts->fl2_dat, map);
}

int checks2(utils_t *uts, map_t *map, sfEvent event)
{
    sfClock *waitabit = sfClock_create();

    if (flea_run(uts) == 1) {
        end_menu(uts, map);
        return 1;
    }

    if (random_gen() == 1)
        entity_handler(uts->flea1->sprite, uts->fl1_dat, map);
    return 0;
}

void run(utils_t *uts, map_t *map)
{
    sfEvent event;

    uts->sam->jump = false;
    speed_init(uts->bckg);
    if (start_menu(uts->bckg, uts) == 2)
        return;
    sam_arrival(uts, event);
    while (sfRenderWindow_isOpen(uts->bckg->win)) {
        analyse_events(uts->bckg->win, event, uts);
        if (uts->pause == true)
            my_pause(uts, map, event);
        background_run(uts->bckg, event, uts);
        sprite_run(uts);
        if (map->map_switch == false && checks2(uts, map, event) == 1)
            return;
        else if (checks(uts, map, event) == 1)
            return;
        score_update(uts);
        sfRenderWindow_display(uts->bckg->win);
        uts->score->tmp_val = 1;
    }
}
