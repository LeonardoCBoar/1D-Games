#include "Map.h"
#include <cstdio>
#include <stdlib.h>





Map::Map(){
    for (int i = 0; i < 20; i++)
    {   
        queue[i] = new int[3]{0,0,0};
        gen_line(queue[i]);
        //printf("Gen %i|%i|%i\n",line[0],line[1],line[2]);
    }


}

void Map::print_map(){

    for (size_t y = 0; y < 20; y++)
    {
        for (size_t x = 0; x < 3; x++)
        {
            printf("|%i|",queue[y][x]);
        }
        printf("\n");
        
        
    }
    

}

void Map::gen_line(int* line){

    
    int obs_pos = rand()%4;
    if(obs_pos<3){
        line[obs_pos] = 1;
    }
    //printf("Gen %i|%i|%i\n",line[0],line[1],line[2]);


}

void Map::move_ahead(){

    for (size_t i = 0; i < 19; i++)
    {
        queue[i] = queue[i+1];
    }

    queue[19] = new int[3]{0,0,0};
    gen_line(queue[19]);
    
}

int* Map::update_distances(){

    
    for (size_t x = 0; x < 3; x++)
    {
        for (size_t i = 0; i <20; i++)
        {
            if(queue[i][x]==1){
                distances[x] = i;
                break;
            }
        }
        
    }

    printf("Distances:%i|%i|%i\n",distances[0],distances[1],distances[2]);
    return distances;
    
}

int Map::move_player(int dir){
    player_pos+=dir;
    if(player_pos<0) player_pos=0;
    if(player_pos>2) player_pos=2;

    if(queue[0][player_pos]==1){
        printf("Collision\n");
        return 1;
    }
    return 0;
    
}

