/*
** EPITECH PROJECT, 2022
** free
** File description:
** freeing functions
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

void destroy_object(gameobject_t *obj)
{
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
    sfClock_destroy(obj->clock);
    free(obj);
}

void freeer(utils_t *uts)
{
    destroy_object(uts->bckg->bg);
    destroy_object(uts->bckg->stars);
    destroy_object(uts->bckg->cl_L);
    destroy_object(uts->bckg->cloud);
    destroy_object(uts->bckg->mtn);
    destroy_object(uts->bckg->cl_s);
    destroy_object(uts->bckg->ground);
    destroy_object(uts->bckg->menu);
    destroy_object(uts->bckg->dth);
    destroy_object(uts->bckg->yes);
    destroy_object(uts->bckg->controls);
    destroy_object(uts->sam);
}
