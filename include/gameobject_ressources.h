/*
** EPITECH PROJECT, 2021
** game object ressources
** File description:
** enum and struct
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef GAMEOBJECT_H_
    #define GAMEOBJECT_H_

enum type {
    BACKGROUND,
    SPRITE,
    PLATFORM,
    ENNEMY,
    SPIKES,
    VICTORY
};

enum PATHS {
    BCKG,
    STARS,
    CLOUDS_L,
    CLOUD,
    MOUNTAINS,
    CLOUDS_S,
    GROUND,
    MENU,
    DEATH,
    WIN,
    CONTROLS
};

static const char *const FILEPATHS[] = {
    [BCKG] = "./img/good_background/background.png",
    [STARS] = "./img/good_background/stars.png",
    [CLOUDS_L] = "./img/good_background/clouds_L.png",
    [CLOUD] = "./img/good_background/cloud.png",
    [MOUNTAINS] = "./img/good_background/mountains.png",
    [CLOUDS_S] = "./img/good_background/clouds_s.png",
    [GROUND] = "./img/good_background/ground.png",
    [MENU] = "./img/good_background/menu_new.png",
    [DEATH] = "./img/good_background/end_screen.png",
    [WIN] = "./img/good_background/victory_screen.png",
    [CONTROLS] = "./img/good_background/controls.png"
};

typedef struct gameobject
{
    enum type type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    int speed;
    sfClock *clock;
    float clock_refresh;
    bool jump;
} gameobject_t;

typedef struct object_data
{
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    enum type type;
} obj_data_t;

typedef struct backgrounds
{
    gameobject_t *bg;
    gameobject_t *stars;
    gameobject_t *cl_L;
    gameobject_t *cloud;
    gameobject_t *mtn;
    gameobject_t *cl_s;
    gameobject_t *ground;
    gameobject_t *menu;
    gameobject_t *dth;
    gameobject_t *yes;
    gameobject_t *controls;
    sfRenderWindow *win;
    obj_data_t *data;
} background_t;

typedef struct map
{
    bool map_switch;
    char *map_buf;
    bool active1;
    bool active2;
    int map_index;
    sfClock *clock;
} map_t;

typedef struct score
{
    sfText *sc_disp;
    sfText *points;
    sfFont *font;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f scale;
    sfClock *clock;
    int number;
    char *num_char;
    int tmp_val;
    int fin_nbr;
} score_t;

typedef struct utils
{
    background_t *bckg;
    gameobject_t *sam;
    score_t *score;
    obj_data_t *sp_dat;
    obj_data_t *fl1_dat;
    obj_data_t *fl2_dat;
    gameobject_t *flea1;
    gameobject_t *flea2;
    bool pause;
} utils_t;

#endif
