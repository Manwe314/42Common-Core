/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:31:45 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/30 18:54:55 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "locations.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Input.h"
# include "MLX42/MLX42_Int.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game_info
{
	int	moves;
	int	collectable_amount;
	int	collected_amount;
	int	*collectable_x;
	int	*collecatble_y;
	int	*spawn;
	int	*exit;
}	t_game_info;

typedef struct s_map_validity
{
	int	is_walled;
	int	is_rectangle;
	int	has_dupliactes;
	int	has_exit;
	int	has_spawn;
	int	has_collect;
	int	has_solution;
	int	invalid_characters;

}	t_map_validity;

typedef struct s_game_manager
{
	mlx_t					*mlx;
	char					**map;
	struct s_game_info		*game;
	struct s_map_validity	*map_validity;
	mlx_image_t				*player;
	mlx_image_t				*collectable;
	mlx_image_t				*exit;
	mlx_image_t				***images;
	xpm_t					*xpmc;
	xpm_t					*xpmp;
	xpm_t					*xpme;
}	t_game_manager;

void			character_check(char *map, t_map_validity *map_validity);
t_map_validity	*initialise_map_validity(t_game_manager *game_manager);
void			free_split(char **split);
void			is_map_walled(char **map, int lines, \
t_map_validity *map_validity, int i);
void			is_rectangle(char **map, t_map_validity *map_validity);
int				error_handler(char *msg, t_map_validity *map_valid);
void			find_solution(char **map, t_map_validity *map_validity, \
int number_of_lines);
void			check_solution(char **map, t_map_validity *map_validity);
void			recursive_find(char **map, int row, \
int col, int number_of_lines);
void			has_duplicates(char *map, t_map_validity *map_validity);
void			validate_map_validity(char **map, \
t_map_validity *map_validity, char *enitre_map);
char			**map_validificator(int fd, t_game_manager *game_manager);
int				final_check(t_map_validity *map_valididty);
int				get_width(char **map);
int				get_height(char **map);
void			top_perimeter_fill(mlx_image_t ***images, \
mlx_t *mlx, int width, int j);
void			bot_perimeter_fill(mlx_image_t ***images, \
mlx_t *mlx, int width, int j);
void			floor_fill(mlx_image_t ***images, mlx_t *mlx, int i, int j);
void			wall_fill(mlx_image_t ***images, mlx_t *mlx, int i, int j);
void			mid_perimeter_fill(mlx_image_t ***images, \
mlx_t *mlx, int i, int j);
void			images_fill(mlx_image_t ***images, \
mlx_t *mlx, char **map, int i);
void			images_to_window(mlx_t *mlx, mlx_image_t ***images);
mlx_image_t		***paint_map(char **map, mlx_t *mlx, int width, int height);
mlx_t			*draw_map(char **map, t_game_manager *game);
t_game_info		*game_info_setup(char **map);
int				*collect_y(int size, char **map);
int				*collect_x(int size, char **map);
int				count_collectables(char **map);
int				*point_finder(char *to_find, char **map);
int				find_e(char **map, char index);
int				find_p(char **map, char index);
void			try_to_move_right(t_game_manager *game);
void			try_to_move_down(t_game_manager *game);
void			try_to_move_left(t_game_manager *game);
void			try_to_move_up(t_game_manager *game);
mlx_image_t		*get_image(mlx_t *mlx, char *name, t_game_manager *game);
void			overlay_display(mlx_t *mlx, t_game_info *game, \
t_game_manager *game_manager);
int				get_instance(t_game_manager *game_manager);
void			start_game(mlx_t *mlx, char **map, \
t_game_manager *game_manager);
void			game_key_manage(mlx_key_data_t keydata, void *param);
void			handle_collectable(t_game_info *game, \
t_game_manager *game_manager);
void			check_game_end(t_game_manager *game);
void			close_function(void *param);
void			display(t_game_manager *game);
void			f_norm(char *entire_map, char **map, \
t_map_validity *map_validity);
char			**f_norm_two(char *f_norm);
void			free_images(t_game_manager	*game);
void			free_xpm(t_game_manager *game);
#endif