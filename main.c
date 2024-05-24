#include "./minilibx/mlx.h"
#include <stdio.h>
#include "./logic/get_next_line.h"
#include <stdlib.h>


int main() {

    t_game  game;
    
    // - FLOOD FILL CHECK - //
    if (!check_flood_fill_map(&game))
        return (0);
    // - CREATE THE MAP -// 
    if (!create_map_for_game(&game))
        return (0);
    // - INIT WINDOW AND IMAGES - // 
    initialize_window(&game);
    // - DRAWING GRID AND LOOPING TILL END - // 
    run_game(&game);
    
    return 0;
}



