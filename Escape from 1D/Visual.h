#ifndef VISUAL
#define VISUAL

#include "Map.h"
#include <SFML/Graphics.hpp>



void graphic_setup(sf::RenderWindow* win,int square_size,Map *world);

void update_squares();


#endif