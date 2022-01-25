/*
** EPITECH PROJECT, 2021
** headers
** File description:
** headers
*/

#include "gameobject_ressources.h"

#ifndef MY_H_
    #define MY_H_

gameobject_t *create_object(const char *path, obj_data_t *data);
gameobject_t *main_char_init(utils_t *utils);
gameobject_t *flea_init(obj_data_t *fl_dat, gameobject_t *flea);
utils_t *mallocker(void);
void my_putchar(char const c);
void bck_clock_handle(gameobject_t *obj, int type);
void destroy_object(gameobject_t *obj);
void my_putr(char c);
void manage_mouse_click(sfMouseButtonEvent event);
void backg_draw(background_t *back);
void parallax_handle(gameobject_t *obj);
void parallax_handle2(gameobject_t *obj);
void speed_init(background_t *bckg);
void background_run(background_t *bckg, sfEvent event, utils_t *utils);
void background_run2(background_t *bckg, sfEvent event, utils_t *utils);
void parallax_pars(background_t *bckg);
void move_rect(utils_t *utils, int offset, int max_value);
void sprite_clock_handle(utils_t *utils);
void sprite_run(utils_t *utils);
void data_init(obj_data_t *data);
void arrival_clock(utils_t *utils);
void sam_arrival(utils_t *utils, sfEvent event);
void map_reader(utils_t *utils, map_t *map);
void entity_handler(sfSprite *sprite, obj_data_t *fl_dat, map_t *map);
void score_init(utils_t *utils);
void score_update(utils_t *utils);
void jump_clock_handle(utils_t *utils);
void run(utils_t *utils, map_t *map);
void end_menu(utils_t * utils, map_t *map);
void descript(void);
void waiter(utils_t *utils, sfClock *clock, sfEvent event);
void good_end(utils_t *utils, map_t *map);
void waiter(utils_t *uts, sfClock *clock, sfEvent event);
void controls(background_t *bckg, utils_t *uts);
void good_end_utils(utils_t *us, map_t *map);
void freeer(utils_t *uts);
void my_pause(utils_t *uts, map_t *map, sfEvent event);
char **backg_img(void);
char *my_revstr(char *str);
char *count_score(utils_t *utils);
char *my_put_nbr(int nb);
int error_check(gameobject_t *obj_struct);
int my_putsterr(char const *str);
int analyse_events(sfRenderWindow *window, sfEvent event, utils_t *utils);
int bg_init(background_t *bck, const char *const *filepaths);
int win_init(sfVideoMode mode, background_t *bck);
int manage_menu_click(sfMouseButtonEvent event);
int menu_click(sfRenderWindow *window, sfEvent event);
int my_putstr(char const *str);
int start_menu(background_t *bckg, utils_t *utils);
int map_loader(char *filepath, map_t *map);
int flea_run(utils_t *utils);
int valabs(int nb);
int check_equal(utils_t *utils, int epsi);
int start(map_t *map);
int restart_game(utils_t *utils, map_t *map);
int initializer(utils_t *utils, map_t *map, sfVideoMode mode);
int my_strcmp(char const *s1, char const *s2);
int input_check(int argc, char **argv, map_t *map);
int ender(sfRenderWindow *win, utils_t *utils, sfEvent event, map_t *map);
int start(map_t *map);
int restart_game(utils_t *utils, map_t *map);
int analyse_events2(sfRenderWindow *window, sfEvent event, utils_t *uts);
int random_gen(void);

#endif
