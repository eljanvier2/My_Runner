/*
** EPITECH PROJECT, 2022
** starters
** File description:
** start and restart game functions
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

int restart_game(utils_t *uts, map_t *map)
{
    uts->sp_dat->pos.x = -120;
    sfSprite_setPosition(uts->sam->sprite, uts->sp_dat->pos);
    uts->fl1_dat->pos.x = 1930;
    sfSprite_setPosition(uts->sam->sprite, uts->fl1_dat->pos);
    uts->score->tmp_val = 0;
    uts->score->scale.x = 1;
    uts->score->scale.y = 1;
    uts->score->pos2.x = 210;
    uts->score->pos2.y = 980;
    sfText_setScale(uts->score->points, uts->score->scale);
    sfText_setPosition(uts->score->points, uts->score->pos2);
    map->map_index = 0;
    run(uts, map);
}

int start(map_t *map)
{
    utils_t *uts = mallocker();
    sfVideoMode mode = {1920, 1080, 600};
    sfMusic *music = sfMusic_createFromFile("audio/background_music.wav");

    if (uts == NULL)
        return 84;
    sfMusic_setLoop(music, true);
    sfMusic_play(music);
    if (initializer(uts, map, mode) == 84)
        return 84;
    run(uts, map);
    freeer(uts);
    sfMusic_destroy(music);
    return 0;
}
