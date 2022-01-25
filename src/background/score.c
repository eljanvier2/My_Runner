/*
** EPITECH PROJECT, 2022
** score
** File description:
** score operating functions
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

void score_init(utils_t *uts)
{
    uts->score->clock = sfClock_create();
    uts->score->pos1.x = 50;
    uts->score->pos1.y = 980;
    uts->score->pos2.x = 210;
    uts->score->pos2.y = 980;
    uts->score->sc_disp = sfText_create();
    uts->score->points = sfText_create();
    uts->score->font = sfFont_createFromFile("img/fonts/good_times.otf");
    uts->score->num_char[0] = '0';
    uts->score->num_char[1] = '\0';
    sfText_setFont(uts->score->sc_disp, uts->score->font);
    sfText_setFont(uts->score->points, uts->score->font);
    sfText_setString(uts->score->sc_disp, "Score : ");
    sfText_setString(uts->score->points, uts->score->num_char);
    sfText_setPosition(uts->score->sc_disp, uts->score->pos1);
    sfText_setPosition(uts->score->points, uts->score->pos2);
}

char *count_score(utils_t *uts)
{
    int i = 0;
    int ret = (uts->score->number) % 10;

    if (uts->score->number == 0) {
        uts->score->num_char[i] = '0';
        uts->score->num_char[i + 1] = '\0';
        return "0";
    }
    while (uts->score->number != 0) {
        ret = uts->score->number % 10;
        uts->score->num_char[i] = (ret > 9)? (ret-10) + 'a': ret + '0';
        uts->score->number /= 10;
        i++;
    }
    uts->score->num_char[i] = '\0';
    my_revstr(uts->score->num_char);
    return uts->score->num_char;
}

void score_update(utils_t *uts)
{
    sfTime time = sfClock_getElapsedTime(uts->score->clock);
    float seconds = time.microseconds / 250000.0;
    static int tmp = 0;

    if (uts->score->tmp_val == 0)
        tmp = uts->score->tmp_val;
    count_score(uts);
    if (seconds > 1.0) {
        uts->score->number = tmp;
        uts->score->number += 1;
        tmp = uts->score->number;
        sfText_setString(uts->score->points, count_score(uts));
        sfClock_restart(uts->score->clock);
    }
    sfRenderWindow_drawText(uts->bckg->win, uts->score->sc_disp, NULL);
    sfRenderWindow_drawText(uts->bckg->win, uts->score->points, NULL);
    uts->score->fin_nbr = tmp;
}
