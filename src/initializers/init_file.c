/*
** EPITECH PROJECT, 2021
** init file
** File description:
** file with every initialization function
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

int bg_init(background_t *bckg, const char *const *filepaths)
{
    bckg->data->type = 0;
    bckg->bg = create_object(FILEPATHS[BCKG], bckg->data);
    bckg->stars = create_object(FILEPATHS[STARS], bckg->data);
    bckg->cl_L = create_object(FILEPATHS[CLOUDS_L], bckg->data);
    bckg->cloud = create_object(FILEPATHS[CLOUD], bckg->data);
    bckg->mtn = create_object(FILEPATHS[MOUNTAINS], bckg->data);
    bckg->cl_s = create_object(FILEPATHS[CLOUDS_S], bckg->data);
    bckg->ground = create_object(FILEPATHS[GROUND], bckg->data);
    bckg->menu = create_object(FILEPATHS[MENU], bckg->data);
    bckg->dth = create_object(FILEPATHS[DEATH], bckg->data);
    bckg->yes = create_object(FILEPATHS[WIN], bckg->data);
    bckg->controls = create_object(FILEPATHS[CONTROLS], bckg->data);
    if (bckg == NULL) {
        my_putsterr("Error initializing background");
        return 84;
    }
    return 0;
}

int win_init(sfVideoMode mode, background_t *bck)
{
    bck->win = sfRenderWindow_create(mode, "runner", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(bck->win, 10000);
    if (!bck->win)
        return 84;
    return 0;
}

gameobject_t *main_char_init(utils_t *uts)
{
    char *path = "img/main_sprite/samurai_spritesheet.png";

    uts->pause = false;
    uts->sp_dat->type = 1;
    uts->sp_dat->rect.left = 30;
    uts->sp_dat->rect.width = 62;
    uts->sp_dat->rect.height = 113;
    uts->sp_dat->pos.y = 700;
    uts->sp_dat->pos.x = -120;
    uts->sp_dat->scale.x = 2;
    uts->sp_dat->scale.y = 2;
    uts->sam = create_object(path, uts->sp_dat);
    sfSprite_setScale(uts->sam->sprite, uts->sp_dat->scale);
    return uts->sam;
}

void speed_init(background_t *bckg)
{
    bckg->stars->speed = 1;
    bckg->stars->clock_refresh = 100;
    bckg->cl_L->speed = 2;
    bckg->cl_L->clock_refresh = 25;
    bckg->cloud->speed = 2;
    bckg->cloud->clock_refresh = 17;
    bckg->mtn->speed = 1;
    bckg->mtn->clock_refresh = 19;
    bckg->cl_s->speed = 2;
    bckg->cl_s->clock_refresh = 13;
    bckg->ground->speed = 5;
    bckg->ground->clock_refresh = 15;
}

void data_init(obj_data_t *data)
{
    data->pos.x = 0;
    data->pos.y = 0;
    data->rect.left = 0;
    data->rect.width = 1920;
    data->rect.height = 1080;
}
