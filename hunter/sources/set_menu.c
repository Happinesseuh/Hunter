/*
** EPITECH PROJECT, 2020
** set_functions2.c
** File description:
** set elements
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

void set_play(sprite_t *sprite)
{
    sprite->disp_menu = 1;
    sprite->play = create_sprite(sfTexture_createFromFile("asset/play.png",
    NULL));
    sprite->pos_play.x = 600;
    sprite->pos_play.y = 350;
    sfSprite_setPosition(sprite->play, sprite->pos_play);
}

void display_menu(sprite_t *sprite)
{
    set_play(sprite);
    while (sfRenderWindow_isOpen(sprite->window) && sprite->disp_menu) {
        sfRenderWindow_clear(sprite->window, sfBlack);
        sfRenderWindow_drawSprite(sprite->window, sprite->bg, NULL);
        sfRenderWindow_drawSprite(sprite->window, sprite->play, NULL);
        while (sfRenderWindow_pollEvent(sprite->window, &sprite->event)){
            if (sprite->event.type == sfEvtClosed) {
                sfRenderWindow_close(sprite->window);
            }
            sprite->b_play = sfSprite_getGlobalBounds(sprite->play);
            if (sprite->event.type == sfEvtMouseButtonPressed &&
            sfFloatRect_contains(&sprite->b_play, sprite->event.mouseButton.x,
            sprite->event.mouseButton.y)) {
                sprite->disp_menu = 0;
            }
        }
        sfRenderWindow_display(sprite->window);
    }
}