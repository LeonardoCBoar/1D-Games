#include <SFML\Graphics.hpp>
#include "Visual.h"
#include "Map.h"



sf::RectangleShape render_list[7];
sf::RenderWindow* window;

int sqr_s;

Map *board;

void graphic_setup(sf::RenderWindow* win,int square_size,Map *world){

    sqr_s = square_size;
    window = win;
    board = world;

    window->setFramerateLimit(3);


    for (size_t i = 0; i < 7; i++)
    {
        render_list[i] = sf::RectangleShape(sf::Vector2f(sqr_s,sqr_s));
        render_list[i].setPosition(sf::Vector2f(sqr_s*i,0));
        render_list[i].setFillColor(sf::Color::Black);
        render_list[i].setOutlineThickness(1);
    }
    
}

float dist_factor = 200/20;
void apply_distance(sf::RectangleShape *obs,int dist){
    sf::Color col = obs->getFillColor();
    col.a = 50+(int)(dist_factor*dist);
    obs->setFillColor(col);


};

void update_squares(){


    render_list[0].setFillColor(sf::Color(0,60,0));
    render_list[6].setFillColor(sf::Color(0,60,0));

    render_list[1].setFillColor(sf::Color(0,100,0));
    render_list[5].setFillColor(sf::Color(0,100,0));

    
    //board->print_map();
    auto distances = board->update_distances();
    for (size_t i = 0; i < 3; i++)
    {   
        //printf("\nDistance%i at %i\n",distances[i],i);
        if(i==board->player_pos) (&render_list[i+2])->setFillColor(sf::Color(255,0,0));
        else                     (&render_list[i+2])->setFillColor(sf::Color::White);
        apply_distance(&render_list[i+2],distances[i]);
    }
    
    


    window->clear(sf::Color::Black);
    for (size_t i = 0; i < 7; i++)
    {
        window->draw(render_list[i]);
    }
    window->display();
    
}




