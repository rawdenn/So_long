/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:46:10 by rdennaou          #+#    #+#             */
/*   Updated: 2024/08/29 12:47:11 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_game *game)
{
	if (game->mlx_ptr)
	{
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
}

void	save_images(t_game *game)
{
	int	i;
	int	j;

	game->img->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/cat.xpm", &i, &j);
	game->img->collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/cookie.xpm", &i, &j);
	game->img->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/exit.xpm", &i, &j);
	game->img->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/wall.xpm", &i, &j);
	game->img->bg = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/grass.xpm", &i, &j);
}

void	display_image1(t_game *game, char **map, int i, int j)
{
	if (map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img->exit, j * SIZE, i * SIZE);
	else if (map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img->player, j * SIZE, i * SIZE);
}

t_game	*display_image(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img->bg, j * SIZE, i * SIZE);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img->collectible, j * SIZE, i * SIZE);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img->wall, j * SIZE, i * SIZE);
			else
				display_image1(game, map, i, j);
			j++;
		}
		i++;
	}
	return (game);
}

t_game	*create_window(char *argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map = open_map(argv);
	game->size_x = line_size(argv) * SIZE;
	game->size_y = count_lines(argv) * SIZE;
	game->player = player_pos(game->map);
	game->countc = 0;
	game->moves = 0;
	game->tocollect = count_collectibles(game->map);
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->size_x,
			game->size_y, "so_long");
	game->img = (t_img *)malloc(sizeof(t_img));
	save_images(game);
	display_image(game->map, game);
	return (game);
}
