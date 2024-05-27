#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// #include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1 
# endif

// x = xpm   i = img
typedef struct s_img
{
    // character paths
    char        *x_p_c;
    char        *x_p_c_rr;
    char        *x_p_c_u;
    char        *x_p_c_uu;
    char        *x_p_c_l;
    char        *x_p_c_ll;
    char        *x_p_c_d;
    char        *x_p_c_dd;
    // objects paths
    char        *xpw;
    char        *xpg;
    char        *xpcoll;
    char        *xpd;
    //character images
    void        *x_i_c;
	void        *x_i_c_rr;
	void        *x_i_c_u;
	void        *x_i_c_uu;
	void        *x_i_c_l;
	void        *x_i_c_ll;
	void        *x_i_c_d;
	void        *x_i_c_dd;
    //objects images
    void        *xiwal;
    void        *xigro;
    void        *xicol;
    void        *xidoo;
}               t_img;

typedef struct s_gamefile 
{
    char        *map_file;
}           t_gamefile;

// x_h == xpm_height
typedef struct s_game
{
    char        **map;
    int         map_height;
    int         map_width;
    int         player_pos_x;
    int         player_pos_y;
    int         player_sprite;
    int         steps;
    void        *mlx;
    void        *win;
    int         x_h;
    int         x_w;
    int         nb_collectibles;
    int         got_collectibles;
    int         game_complete;
    int         win_w;
    int         win_h;
    t_img       img; 
}               t_game;


// # include "../minilibx/mlx.h"
// # include "../minilibx/mlx_int.h"

#include "../my_printf/ft_printf.c"
#include "./gnl_utils.c"
#include "./gnl.c"
#include "./init.c"
#include "./init_window.c"

#include "./checkmap.c"
#include "./checkmap2.c"
#include "./checkmap3.c"

#include "./floodfill.c"

#include "./map.c"
#include "./free.c"

#include "./controls.c"
#include "./controls2.c"


// LIBFT UTILS
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int i);
char	*ft_strjoin(char const *s1, char const *s2);
static char *make_line(int fd, char *buffer, char *storage);

// GNL
// static char	*extract(char *line);
static char	*my_extract(char *line);
char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t length);
int     calculate_len(t_game *game, char *treated_line);
static char *manage_storage(char *storage, char *buffer);
void 	free_storage(char *storage);
//int     calculate_len(char *treated_line);
//void    display_image_before(t_game *game, char *path);


// CHECK THE MAP
int	    check_extension_file_name(char *name);
int     check_rectangle(t_game *game);
int     check_walls_horizontal(t_game *game);
int     check_walls_vertical(t_game *game);
int     check_if_rectangle(t_game *game);
//int     check_walls(t_game *game);
int	    check_walls_and_collectibles(t_game *game);
int     check_map(t_game *game); 


// CREATE MAP (FOR CHECK) (FOR ACTUAL GAME)
static int	save_line_in_map(t_game *game, char *line);
// static int manage_temp(t_game *game, char *line);
static char  **manage_temp(t_game *game, char *line);
static int if_temp_null(t_game *game, char **temp);
int     check_allowed_caracters(t_game *game);
void	malloc_game(t_game *game);
// int     create_map(t_game *game);
int 	create_map(t_game *game, t_gamefile *gamefile);
void    drawGrid(t_game *game);
int     count_collectibles(t_game *game);
int     count_exit_and_caracter(t_game *game);
void    window_init(t_game *game);
int 	create_map_for_game(t_game *game, t_gamefile *gamefile);


// FLOODFILL
void 	display_map(t_game *game);
int     map_len(t_game *game);
void	flood_map(t_game *game, int x, int y);
int     check_flood_fill(t_game *game);
int     map_free_after_flood_fill(t_game *game);
int     check_flood_fill_map(t_game *game, t_gamefile *gamefile);

// INIT IMAGES/WINDOW
void 	init_images_character(t_game *game);
void    init_images_obj(t_game *game);
void 	initialize_window(t_game *game);


// void drawGrid(void *mlx, void *mlx_win, int xpm_width, int xpm_height, t_game *game);
int     display_player_pos(t_game *game);
// moves
int     close_window(t_game *game);
int	    controls_working(int command, t_game *game);
int     move_right(t_game *game);
int     move_left(t_game *game);
int     move_up(t_game *game);
int     move_down(t_game *game);
void    move_forward(t_game *game, int y, int x);
void    portal(t_game *game);
void    animation_caracter(t_game *game, int x, int y);
void    walking(t_game *game);

// RUN GAME
void 	run_game(t_game *game);

// FREE GAME
void     free_mlx(t_game *game);
int     free_game(t_game *game);
void 	free_images(t_game *game);



#endif