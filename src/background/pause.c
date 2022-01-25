/*
** EPITECH PROJECT, 2022
** pause
** File description:
** pause
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

int analyse_pause(sfRenderWindow *window, sfEvent event, utils_t *uts)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
            uts->pause = false;
}

void my_pause(utils_t *uts, map_t *map, sfEvent event)
{
    while (uts->pause == true) {
        analyse_events(uts->bckg->win, event, uts);
        analyse_pause(uts->bckg->win, event, uts);
    }
}
