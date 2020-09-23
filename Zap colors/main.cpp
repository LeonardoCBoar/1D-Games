#include <SFML\Graphics.hpp>
#include "AssetManager.h"
#include "GameFuncs.h"
#include<SFML\Window.hpp>






enum Round{
    STARTING = 0,
    STARTED = 1,
    ENDING = 2,
    ENDED = 3
};


int main(){

    
    //#########################################Graphical Variables#################################################
    float scr_factor = sf::VideoMode::getDesktopMode().width/1920.0;
    
    sf::RenderWindow window(sf::VideoMode(1920*scr_factor,320*scr_factor),"Zap Color",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);


    sf::RectangleShape Render_list[6];
    initialize_sprites(Render_list,scr_factor);


    //#########################################Game Variables########################################################

    update_seed();
    




    sf::Clock timer;
    sf::Time delta_time;


    int game_state = STARTING;

    int selected_square = 6;



    while(window.isOpen()){
        
        delta_time = timer.restart();


        //Input handling
        sf::Event input;
        while(window.pollEvent(input)){
            
            //Close Window/Esc 
            if((input.type == sf::Event::EventType::Closed)||(input.type==sf::Event::EventType::KeyPressed && input.key.code==sf::Keyboard::Escape)){
                window.close();
                continue;
            }

            //Resize Window

            //Mouse clicks
            
            if(input.type==sf::Event::MouseButtonPressed ){
                selected_square = (sf::Mouse::getPosition(window).x)/(320*scr_factor);
                printf("Clicked at %i\n",selected_square);
            }
            




        }

        //Game Logic
        float d_time = delta_time.asSeconds();

        switch (game_state)
        {
        case STARTING:
            //printf("Starting\n");
            start_round(Render_list);
            selected_square = 6;
            game_state = STARTED;
            break;
        
        case STARTED:
            if(update_timer(Render_list,d_time)){
                end_round(Render_list,false);
                game_state = ENDED;

            };

            //If the player clicked on a game square, the rounds will end
            //printf("%i\n",selected_square);
            if(selected_square>0 && selected_square<4){
                game_state = ENDING;
                
            }
            break;

    
        
        case ENDING:
            end_round(Render_list,check_victory(selected_square));
            selected_square = 6;
            game_state = ENDED;
            break;

        case ENDED:
            if(update_timer(Render_list,d_time)||selected_square!=6){
                game_state =STARTING;
            }

            break;
        
        default:
            break;
        }

        

        //Render
        window.clear(sf::Color::White);

        for(auto shape:Render_list){
            window.draw(shape);
        }

        window.display();


    }




};