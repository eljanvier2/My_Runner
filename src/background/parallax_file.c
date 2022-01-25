/*
** EPITECH PROJECT, 2022
** parallax file
** File description:
** parallax handling functions
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

void parallax_pars(background_t *bckg)
{
    bck_clock_handle(bckg->stars, 0);
    bck_clock_handle(bckg->cl_L, 1);
    bck_clock_handle(bckg->cloud, 1);
    bck_clock_handle(bckg->mtn, 0);
    bck_clock_handle(bckg->cl_s, 1);
    bck_clock_handle(bckg->ground, 0);
}

void parallax_handle(gameobject_t *obj)
{
    if (obj->rect.left + obj->speed < 1920)
        obj->rect.left += obj->speed;
    else
        obj->rect.left = 0;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void parallax_handle2(gameobject_t *obj)
{
    if (obj->rect.left + obj->speed < 1920 * 2)
        obj->rect.left += obj->speed;
    else
        obj->rect.left = 0;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}
