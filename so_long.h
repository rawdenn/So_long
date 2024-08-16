/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:26:27 by rdennaou          #+#    #+#             */
/*   Updated: 2024/08/16 13:51:01 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../Libft/libft.h"
# include "../mlx/mlx.h"

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# define SIZE 40
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_count
{
	int	counte;
	int	countc;
	int	countp;
}	t_count;

typedef struct s_img
{
	void	*player;
	void	*wall;
	void	*bg;
	void	*exit;
	void	*collectible;
}	t_img;

typedef struct s_game
{
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player;
	int			size_x;
	int			size_y;
	t_img		*img;
	int			countc;
	int			tocollect;
	int			moves;
}	t_game;

void		error(char *msg);
char		**open_map(char *argv);
int			count_lines(char *argv);
int			line_size(char *argv);
void		check_map(char **map, char *argv);
void		free_str(char **tab);
int			count_collectibles(char **map);
int			count_characters(char **map);
void		check_path(char *argv);
t_player	player_pos(char **map);
void		flood_fill(char **tab, t_player size, t_player begin, t_count *p);
int			destroy_window(t_game *game);
t_game		*display_image(char **map, t_game *game);
void		save_images(t_game *game);
t_game		*create_window(char *argv);
void		free_image(t_img *img, char *mlx_ptr);
int			on_destroy(t_game *game);
int			on_keypress(int keysym, t_game *game);
int			ft_printf(const char *format, ...);

#endif