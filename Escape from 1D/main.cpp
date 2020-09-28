#include <cstdio>
#include <SFML\Graphics.hpp>

#include "AssetManager.h"
#include "Map.h"
#include "Visual.h"






int main(){

    Map map;

    
    int square_size = sf::VideoMode::getDesktopMode().width/7;
    sf::RenderWindow win(sf::VideoMode(square_size*7,square_size),"Escape from 1D");
    
    graphic_setup(&win,square_size,&map);

    
    while (win.isOpen())
    {
        int movement{0};
        sf::Event input;

        while(win.pollEvent(input)){
            if((input.type == sf::Event::EventType::Closed)||(input.type==sf::Event::EventType::KeyPressed && input.key.code==sf::Keyboard::Escape)){
                win.close();
            }

            if(input.type==sf::Event::EventType::KeyPressed){
                switch (input.key.code)
                {
                case sf::Keyboard::A:
                    movement = -1;
                    break;
                case sf::Keyboard::D:
                    movement = 1;
                    break;
                
                default:
                    movement = 0;
                    break;
                }
            }
        }
        

        map.move_ahead();
        map.move_player(movement);
        //map.print_map();
        update_squares();
        




    }
    



}