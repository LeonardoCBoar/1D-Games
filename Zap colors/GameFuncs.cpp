#include "GameFuncs.h"
#include <time.h>
#include <stdlib.h>
#include <map>


//############################################Graphical##########################

void initialize_sprites(sf::RectangleShape *shapes,float factor){
    int sqr_s = 320*factor;
    for (int i = 0; i < 6; i++)
    {
        shapes[i] = sf::RectangleShape(sf::Vector2f(sqr_s,sqr_s));
        shapes[i].setPosition(sf::Vector2f(i*sqr_s,0));
        shapes[i].setFillColor(sf::Color::White);
        shapes[i].setOutlineColor(sf::Color::Black);
        shapes[i].setOutlineThickness(1);
    }
    
}



void change_all_square_colors(sf::RectangleShape *shapes, sf::Color col){
    for (size_t i = 0; i < 4; i++)
    {
        shapes[i].setFillColor(col);
    }
    

};








//############################################Time##########################
enum times{
    ROUND = 5,
    END = 2
};

float time_left;
int selected_timer;
void start_time(int time){
    selected_timer = time;
    time_left = time;
};

bool update_timer(sf::RectangleShape *shapes, float time){
    time_left-=time;
    if(time_left<0){
        time_left=0;
        return true;
    }

    sf::Uint8 bright = (255.0/(float)selected_timer)*time_left;

    sf::Color timer_color{0,0,0,bright};
    //printf("%i\n",bright);

    shapes[4].setFillColor(timer_color);

    return false;



};



//############################################Dependences##########################

void update_seed(){
    srand(time(NULL));
}

sf::Color col_list[3]{sf::Color::Blue,sf::Color::Magenta,sf::Color::Yellow};

sf::Color*  get_colors(){
    return col_list;
}

sf::Color last_colors[3]{};

bool is_sequence(sf::Color new_col){
    

    for (auto col : last_colors)
    {
        if(new_col!=col) {
            
            last_colors[3] = last_colors[2];
            last_colors[2] = last_colors[1];
            last_colors[0] = new_col;
            return false;
        }
    }
    


    return true;
};

void shuffle_color_list(){
    //Shuffles the color list
    int ran = rand()%3;
    sf::Color temp = col_list[ran];

    if(ran%2==0) {
        col_list[ran] = col_list[(ran+1)%3];
        col_list[(ran+1)%3] = col_list[(ran+2)%3];
        col_list[(ran+2)%3] = temp;
    }
    else{
        col_list[ran] = col_list[(ran+2)%3];
        col_list[(ran+2)%3] = col_list[(ran+1)%3];
        col_list[(ran+1)%3] = temp;
    }


    if(is_sequence(temp)) shuffle_color_list();

    

};




int target_square{};
bool check_victory(int sel_square){

    if(sel_square == target_square+1) return true;
    else return false;
}

int lvl = 0;
void update_points(sf::RectangleShape *shapes){
    sf::Color col = sf::Color(255,180,0,lvl*8);
    shapes[5].setFillColor(col);
}

//############################################Rounds##########################

sf::Clock round_timer;
void start_round(sf::RectangleShape *shapes){
    

    round_timer.restart();

    start_time(ROUND-(lvl*0.15));

    shuffle_color_list();
    target_square = rand()%3;
    shapes[0].setFillColor(col_list[target_square]);

    for (int i = 1; i < 4; i++)
    {
        shapes[i].setFillColor(col_list[i-1]);
    }

    printf("Starting round %i\n",lvl);
}

void end_round(sf::RectangleShape *shapes,bool victory){

    start_time(END);

    float time = round_timer.restart().asSeconds();

    if(victory){
        if(lvl<30) lvl++;
        printf("Player won this round in %f seconds\n",time);
        change_all_square_colors(shapes,sf::Color::Green);
        update_points(shapes);
    } 
    else {
        lvl = 0;
        update_points(shapes);
        printf("Player lost this round in %f seconds\n",time);
        change_all_square_colors(shapes,sf::Color::Red );
    }


};