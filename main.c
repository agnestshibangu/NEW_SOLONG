#include "./minilibx/mlx.h"
#include <stdio.h>
#include "./logic/get_next_line.h"
#include <stdlib.h>


int main() {

    t_game  game;
    
    // - FLOOD FILL CHECK - //
    check_flood_fill_map(&game);

    // - CREATE THE MAP -// 
    create_map(&game);
    map_len(&game);
    check_map(&game);
    count_collectibles(&game);

    // - INIT WINDOW AND IMAGES - // 
    window_init(&game);
    init_images_character(&game);
    init_images_obj(&game);
    display_player_pos(&game);
   
    // char *path = "./images_op_end/first_image.xpm";
    //display_image_before(&game, path);

    // - DRAWING GRID AND LOOPING TILL END - // 
    drawGrid(&game);    
    mlx_key_hook(game.win, controls_working, &game);    
    mlx_loop(game.mlx);
    
    return 0;
}



