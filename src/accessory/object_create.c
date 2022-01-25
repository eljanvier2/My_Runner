/*
** EPITECH PROJECT, 2021
** create object
** File description:
** global function for object initialization
*/
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stddef.h>
#include "gameobject_ressources.h"

int error_check(gameobject_t *obj_struct)
{
    if (!obj_struct->texture)
        return 84;
    if (!obj_struct->sprite)
        return 84;
}

gameobject_t *create_object(const char *path, obj_data_t *data)
{
    gameobject_t *obj = malloc(sizeof(gameobject_t));
    obj->position = data->pos;
    obj->type = data->type;
    obj->rect = data->rect;
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(path, NULL);
    obj->clock = sfClock_create();

    if (error_check(obj) == 84)
        return NULL;
    sfSprite_setTexture(obj->sprite, obj->texture, 0);
    sfSprite_setPosition(obj->sprite, obj->position);
    return (obj);
}
