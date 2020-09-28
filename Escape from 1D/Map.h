#ifndef MAP
#define MAP



struct Map{


    int* queue[20]{};
    Map();
    void print_map();

    void gen_line(int* line);
    void move_ahead();

    int  distances[3];
    int* update_distances();

    int  player_pos{1};
    int  move_player(int dir);



};

#endif