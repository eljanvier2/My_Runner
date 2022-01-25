/*
** EPITECH PROJECT, 2021
** window create
** File description:
** functions used to create a window
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

int main(char argc, char *argv[])
{
    map_t *map = malloc(sizeof(map_t));
    map->clock = sfClock_create();

    if (argc < 2) {
        my_putstr("No map given, infinite mode chosen.\n");
        map->map_switch = false;
    }
    else
        if (input_check(argc, argv, map) == 84)
            return 84;
    map->active1 = false;
    map->active2 = false;
    start(map);
    return 0;
}
