/*
** EPITECH PROJECT, 2022
** h writer
** File description:
** -h writing
*/

#include "my.h"

int input_check(int argc, char **argv, map_t *map)
{
    if (my_strcmp(argv[1], "-h") == 0 && argc == 2) {
        descript();
        my_putstr("No map given, infinite mode chosen\n");
    } else if (map_loader(argv[1], map)  == 84) {
        my_putsterr("Error loading map\n");
        return 84;
    }
    else
        map->map_switch = true;
    if (argc == 3 && map->map_switch == true)
        descript();
    return 0;
}

void descript(void)
{
    my_putstr("Welcome to My_Runner 2022 !\n");
    my_putstr("The point of the game is to go as far as you can ");
    my_putstr("without getting ate by the terrible sand fleas\n");
    my_putstr("You can avoid that by jumping over them with your super high ");
    my_putstr("Ninja jumps\n");
    my_putstr("Good luck !\n(you'll need some)\n");
}
