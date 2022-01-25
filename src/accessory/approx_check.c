/*
** EPITECH PROJECT, 2022
** approx check
** File description:
** functions used to check if objects are approximatively at the same spot
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

int valabs(int nb)
{
    if (nb < 0)
        nb *= -1;
    return nb;
}

int check_equal(utils_t *uts, int epsi)
{
    if (valabs(uts->fl1_dat->pos.x - uts->sp_dat->pos.x) < epsi) {
        if (valabs(uts->fl1_dat->pos.y - uts->sp_dat->pos.y) < epsi)
            return 1;
        return 0;
    }
    return 0;
}
