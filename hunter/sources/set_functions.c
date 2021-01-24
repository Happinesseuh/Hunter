/*
** EPITECH PROJECT, 2020
** set_position.c
** File description:
** function set
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../includes/my_hunter.h"

void set_elements(sprite_t *sprite)
{
    sprite->clock_move = sfClock_create();
    sprite->rect.top = 0;
    sprite->rect.left = 0;
    sprite->rect.width = 110;
    sprite->rect.height = 110;
    sprite->pos.x = -10;
    sprite->pos.y = 400;
    sprite->rect_bullet.top = 0;
    sprite->rect_bullet.left = 0;
    sprite->rect_bullet.width = 70;
    sprite->rect_bullet.height = 110;
}

void set_postion_mouse(sprite_t *sprite)
{
    if (sprite->event.type == sfEvtMouseMoved) {
        sprite->pos_mouse.x = sprite->event.mouseMove.x - 25;
        sprite->pos_mouse.y = sprite->event.mouseMove.y - 25;
        sfSprite_setPosition(sprite->mouse, sprite->pos_mouse);
    }
}

void set_position_bird(sprite_t *sprite)
{
    srand(time(NULL));
    if (sprite->pos.x > 1610) {
        sprite->pos.y = (150 + rand() / (RAND_MAX / (750 - 150 + 1) + 1));
        sprite->pos.x = -110;
    } else
        sprite->pos.x += 10 * sprite->velocity;
    sfSprite_setPosition(sprite->bird, sprite->pos);
}

void set_pistol_sound(sprite_t *sprite)
{
    sprite->soundbuffer = sfSoundBuffer_createFromFile("asset/tir.wav");
    sprite->sound = sfSound_create();
    sfSound_setBuffer(sprite->sound, sprite->soundbuffer);
}

void set_sprite(sprite_t *sprite)
{
    sfVideoMode mode = {1600, 900, 60};

    sprite->window = sfRenderWindow_create(mode, "My_hunter",
        sfTitlebar | sfClose, NULL);
    sprite->bg = create_sprite(sfTexture_createFromFile("asset/bg.png", NULL));
    sprite->bird = create_sprite(sfTexture_createFromFile("asset/bird.png",
    NULL));
    sprite->mouse = create_sprite(sfTexture_createFromFile("asset/mouse2.png",
    NULL));
    sprite->bullet = create_sprite(sfTexture_createFromFile("asset/bullet2.png",
    NULL));
}