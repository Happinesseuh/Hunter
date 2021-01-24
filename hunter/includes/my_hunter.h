/*
** EPITECH PROJECT, 2020
** my_hunter.h
** File description:
** struct and protoypes functions for my_hunter
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

typedef struct sprite_s {

    sfRenderWindow *window;
    sfSprite* bg;
    sfSprite* bird;
    sfSprite* mouse;
    sfSprite* play;
    sfVector2f pos;
    sfVector2f pos_play;
    sfEvent event;
    sfIntRect rect;
    sfClock *clock_move;
    sfVector2f pos_mouse;
    sfTime time;
    sfSoundBuffer *soundbuffer;
    sfSound *sound;
    sfSprite *bullet;
    sfVector2f pos_bullet;
    sfIntRect rect_bullet;
    int score;
    int disp_menu;
    float velocity;
    float seconds;
    sfFloatRect b_play;

}sprite_t;

/* SET FUNCTIONS */
void set_sprite(sprite_t *sprite);
void set_elements(sprite_t *sprite);
void set_pistol_sound(sprite_t *sprite);
/* SET POSITION */
void set_position_play(sprite_t *sprite);
void set_postion_mouse(sprite_t *sprite);
void set_pos_bullet(sprite_t *sprite);
void set_position_bird(sprite_t *sprite);
/* OTHER */
void draw_elements(sprite_t *sprite);
void destroy_elements(sprite_t *sprite);
void move_rect(sprite_t *sprite);
sfSprite *create_sprite(sfTexture *texture);
int my_printf(char *format, ...);
void display_menu(sprite_t *sprite);
void display_menu2(sprite_t *sprite);

#endif /* !FRAMEBUFFER_H_ */
