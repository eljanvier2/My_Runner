/*
** EPITECH PROJECT, 2022
** map loader
** File description:
** every map loading function
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

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd < 0) {
        my_putsterr("FAILURE\n");
        return 84;
    }
    return fd;
}

void fs_understand_return_of_read(int fd , char *buffer , int size)
{
    int lenght = read(fd, buffer, size);

    buffer[lenght] = '\0';
}

int fs_cat_line(char const *filepath, int size, map_t *map)
{
    char *buffer = malloc(sizeof(char) * (size + 1));
    int fd = fs_open_file(filepath);
    if (fd == 84)
        return 84;
    fs_understand_return_of_read(fd, buffer, (size));
    map->map_buf = buffer;
    close(fd);
    return 0;
}

int map_loader(char *filepath, map_t *map)
{
    struct stat my_stat;
    stat(filepath, &my_stat);
    if ((fs_cat_line(filepath, (my_stat.st_mode), map)) == 84)
        return 84;
    return 0;
}

void map_reader(utils_t *uts, map_t *map)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(map->clock);
    seconds = time.microseconds / 130000;
    if (seconds > 1.0){
        if (map->map_buf[map->map_index] == '3' && map->active1 == false)
            map->active1 = true;
        sfClock_restart(map->clock);
        if (map->map_buf[map->map_index] != '3' && map->active1 == false)
            map->map_index++;
        if (map->map_buf[map->map_index] == '5')
            good_end(uts, map);
    }
}
