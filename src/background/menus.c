/*
** EPITECH PROJECT, 2022
** menus
** File description:
** file regrouping different menues
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

int start_menu(background_t *bckg, utils_t *uts)
{
    int click_ind = 0;
    sfEvent event;

    while (sfRenderWindow_isOpen(bckg->win)) {
        if ((click_ind = menu_click(bckg->win, event)) == 1 || click_ind == 2)
            return (click_ind);
        else if (click_ind == 3)
            controls(bckg, uts);
        sfRenderWindow_clear(bckg->win, sfBlack);
        background_run2(bckg, event, uts);
        sfRenderWindow_drawSprite(bckg->win, bckg->menu->sprite, NULL);
        sfRenderWindow_display(bckg->win);
    }
    return 0;
}

void end_menu(utils_t * us, map_t *map)
{
    sfClock *waitabit = sfClock_create();
    int click_ind = 0;
    sfEvent event;

    my_put_nbr(us->score->fin_nbr);
    my_putchar('\n');
    waiter(us, waitabit, event);
    while (sfRenderWindow_isOpen(us->bckg->win)) {
        ender(us->bckg->win, us, event, map);
        sfRenderWindow_clear(us->bckg->win, sfBlack);
        background_run2(us->bckg, event, us);
        sfRenderWindow_drawSprite(us->bckg->win, us->bckg->dth->sprite, NULL);
        sfRenderWindow_display(us->bckg->win);
    }
    return;
}

void good_end(utils_t *us, map_t *map)
{
    sfClock *waitabit = sfClock_create();
    sfEvent event;

    my_put_nbr(us->score->fin_nbr);
    my_putchar('\n');
    waiter(us, waitabit, event);
    while (sfRenderWindow_isOpen(us->bckg->win)) {
        ender(us->bckg->win, us, event, map);
        sfRenderWindow_clear(us->bckg->win, sfBlack);
        background_run2(us->bckg, event, us);
        good_end_utils(us, map);
    }
    return;
}
