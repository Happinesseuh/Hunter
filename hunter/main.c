/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c for project my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System/InputStream.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "./includes/my_hunter.h"

void cond_function(sprite_t *sprite)
{
    sfFloatRect clic_bird;

    clic_bird = sfSprite_getGlobalBounds(sprite->bird);
    if (sfFloatRect_contains(&clic_bird, sprite->event.mouseButton.x,
        sprite->event.mouseButton.y) &&
        sprite->event.type == sfEvtMouseButtonPressed) {
            set_pistol_sound(sprite);
            sfSound_play (sprite->sound);
            srand(time(NULL));
            sprite->pos.x = 0;
            sprite->pos.y = (150 + rand() / (RAND_MAX / (750 - 150 + 1) + 1));
            sprite->velocity += 0.10;
            sprite->score += 1;
        } else if (sprite->event.type == sfEvtMouseButtonPressed &&
        !sfFloatRect_contains(&clic_bird, sprite->event.mouseButton.x,
        sprite->event.mouseButton.y)) {
            sfSprite_setTextureRect(sprite->bullet, sprite->rect_bullet);
            sprite->rect_bullet.width -= 35;
        }
}

void window_open(sprite_t *sprite)
{
    display_menu(sprite);
    while (sfRenderWindow_isOpen(sprite->window)) {
        sfRenderWindow_clear(sprite->window, sfBlack);
        move_rect(sprite);
        sfRenderWindow_display(sprite->window);
        while (sfRenderWindow_pollEvent(sprite->window, &sprite->event)) {
            sfRenderWindow_setMouseCursorVisible(sprite->window, sfFalse);
            set_postion_mouse(sprite);
            cond_function(sprite);
            if (sprite->rect_bullet.width < 0)
                sfRenderWindow_close(sprite->window);
            if (sprite->event.type == sfEvtClosed)
                sfRenderWindow_close(sprite->window);
        }
    }
    my_printf("score : %d\n", sprite->score);
}

int my_hunter(void)
{
    sprite_t sprite;

    sprite.velocity = 0.30;
    sprite.score = 0;
    set_sprite(&sprite);
    if (!sprite.bg)
        return (84);
    sfRenderWindow_setFramerateLimit(sprite.window, 60);
    set_elements(&sprite);
    window_open(&sprite);
    destroy_elements(&sprite);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_printf("--USAGE--\n");
        my_printf("./my_hunter for play\n");
        my_printf("./my_hunter -h for help\n");
        my_printf("The object of the game is to hit as many times as possible "
        "the bird to get the highest score possible !\n"
        "The game starts once the play button is pressed.\n"
        "Then to kill the birds scrolling on the screen, you just need to "
        "click on it with the left click of the mouse.\n"
        "The score will increase by one each time a bird is hit.\n"
        "But be careful if you don't touch the bird enough times. "
        "the game stops (you can see how many lives are left. "
        "thanks to the number of balls in the top right"
        " corner of the screen).");
    }
    else
        my_hunter();
    return 0;
}