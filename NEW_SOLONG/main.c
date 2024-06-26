#include "./logic/get_next_line.h"

int main(int ac, char **av) {

    t_game  game;
    t_gamefile gamefile;

    if (ac != 2)
    {
        ft_printf("Error: argument file missing\n");
        return (0);
    }
    if (!check_extension_file_name(av[1]))
    {
        ft_printf("Error: invalid file extension\n");
        return (0);
    }

    gamefile.map_file = av[1];
    
    if (!does_file_exist(gamefile.map_file))
        return (0);

    // - FLOOD FILL CHECK - //
    if (!check_flood_fill_map(&game, &gamefile))
        return (0);
    // - CREATE THE MAP -// 
    if (!create_map_for_game(&game, &gamefile))
        return (0);
    // - INIT WINDOW AND IMAGES - // 
    initialize_window(&game);
    // - DRAWING GRID AND LOOPING TILL END - // 
    run_game(&game);
    
    return (0);
}



