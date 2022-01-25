/*
** EPITECH PROJECT, 2022
** init file 2
** File description:
** second init file
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

gameobject_t *flea_init(obj_data_t *fl_dat, gameobject_t *flea)
{
    char *path = "img/flea/flea_spritesheet2.png";

    fl_dat->type = 3;
    fl_dat->rect.left = 0;
    fl_dat->rect.width = 100;
    fl_dat->rect.height = 130;
    fl_dat->pos.y = 710;
    fl_dat->pos.x = 1930;
    fl_dat->scale.x = 1.5;
    fl_dat->scale.y = 1.5;
    flea = create_object(path, fl_dat);
    sfSprite_setScale(flea->sprite, fl_dat->scale);
    sfSprite_setTextureRect(flea->sprite, fl_dat->rect);
    return flea;
}

utils_t *mallocker2(utils_t *uts)
{
    uts->fl2_dat = malloc(sizeof(obj_data_t));
    if (uts->fl2_dat == NULL)
        return NULL;
    uts->score = malloc(sizeof(score_t));
    if (uts->score == NULL)
        return NULL;
    uts->score->num_char = malloc(sizeof(char) * 5);
    if (uts->score->num_char == NULL)
        return NULL;
    return uts;
}

utils_t *mallocker(void)
{
    utils_t *uts = malloc(sizeof(utils_t));

    if (uts == NULL)
        return NULL;
    uts->sp_dat = malloc(sizeof(obj_data_t));
    if (uts->sp_dat == NULL)
        return NULL;
    uts->fl1_dat = malloc(sizeof(obj_data_t));
    if (uts->fl1_dat == NULL)
        return NULL;
    uts->bckg = malloc(sizeof(background_t));
    if (uts->bckg == NULL)
        return NULL;
    uts->bckg->data = malloc(sizeof(obj_data_t));
    if (uts->bckg->data == NULL)
        return NULL;
    uts = mallocker2(uts);
    return uts;
}

int initializer(utils_t *uts, map_t *map, sfVideoMode mode)
{
    data_init(uts->bckg->data);
    score_init(uts);
    map->map_index = 0;
    uts->score->number = 0;
    uts->score->fin_nbr = 0;
    uts->score->tmp_val = 0;
    uts->sam = main_char_init(uts);
    uts->flea1 = flea_init(uts->fl1_dat, uts->flea1);
    uts->flea2 = flea_init(uts->fl2_dat, uts->flea2);
    if (bg_init(uts->bckg, FILEPATHS) == 84 ||
    win_init(mode, uts->bckg) == 84) {
        my_putsterr("Error initializing background");
        return 84;
    }
}
