#ifndef GAMEFUNCS
#define GAMEFUNCS


#include <SFML/Graphics.hpp>


void initialize_sprites(sf::RectangleShape *shapes,float factor);



bool update_timer(sf::RectangleShape *shapes, float time);

void update_seed();


bool check_victory(int sel_square);

void start_round(sf::RectangleShape *shapes);

void end_round(sf::RectangleShape *shapes,bool victory);




#endif