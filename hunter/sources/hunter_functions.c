/*
** EPITECH PROJECT, 2020
** set_and_draw.c
** File description:
** set and draw function for my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundStatus.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../includes/my_hunter.h"

sfSprite *create_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

void draw_elements(sprite_t *sprite)
{
    sfRenderWindow_drawSprite(sprite->window, sprite->bg, NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->bird, NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->mouse, NULL);
    sfRenderWindow_drawSprite(sprite->window, sprite->bullet, NULL);
}

void move_rect(sprite_t *sprite)
{
    if (sprite->rect.left < 330) {
        set_position_bird(sprite);
        draw_elements(sprite);
        sprite->time = sfClock_getElapsedTime(sprite->clock_move);
        sprite->seconds = sprite->time.microseconds / 1000000.0;
        if (sprite->seconds > 0.15) {
            sfSprite_setTextureRect(sprite->bird, sprite->rect);
            sprite->rect.left += 110;
            sfClock_restart(sprite->clock_move);
        }
        if (sprite->rect.left == 330)
            sprite->rect.left = 0;
    }
}

void destroy_elements(sprite_t *sprite)
{
    sfRenderWindow_destroy(sprite->window);
    sfSprite_destroy(sprite->bg);
    sfSprite_destroy(sprite->bird);
    sfSprite_destroy(sprite->mouse);
    sfSprite_destroy(sprite->bullet);
}