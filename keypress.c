/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 09:41:46 by rdennaou          #+#    #+#             */
/*   Updated: 2024/08/16 14:15:56 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x, int y)
{
	char	next_tile;

	next_tile = game->map[y][x];
	if ((game->player.x <= 0 || next_tile == '1')
		|| (next_tile == 'E' && (game->tocollect != game->countc)))
		return ;
	if (next_tile == 'C')
		game->countc++;
	else if (next_tile == 'E')
	{
		if (game->tocollect == game->countc)
		{
			write(1, "Victory!\n", 9);
			on_destroy(game);
		}
	}
	game->map[game->player.y][game->player.x] = '0';
	game->map[y][x] = 'P';
	game->player.x = x;
	game->player.y = y;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	display_image(game->map, game);
	game->moves++;
	ft_printf("You moved %d times!\n", game->moves);
}

void	display_count(t_game *game)
{
	char	*moves_str;
	char	*text;

	moves_str = ft_itoa(game->moves);
	text = ft_strjoin("Moves ", moves_str);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		game->player.x * SIZE, game->player.y * SIZE, 0x000000, text);
	free(moves_str);
	free(text);
}

int	on_keypress(int keysym, t_game *game)
{
	int	i;
	int	j;

	if (keysym == ESC)
		on_destroy(game);
	if (keysym == UP || keysym == KEY_W)
		move_player(game, game->player.x, game->player.y - 1);
	if (keysym == DOWN || keysym == KEY_S)
		move_player(game, game->player.x, game->player.y + 1);
	if (keysym == RIGHT || keysym == KEY_D)
	{
		mlx_destroy_image(game->mlx_ptr, game->img->player);
		game->img->player = mlx_xpm_file_to_image(game->mlx_ptr,
				"images/cat.xpm", &i, &j);
		move_player(game, game->player.x + 1, game->player.y);
	}
	if (keysym == LEFT || keysym == KEY_A)
	{
		mlx_destroy_image(game->mlx_ptr, game->img->player);
		game->img->player = mlx_xpm_file_to_image(game->mlx_ptr,
				"images/cat2.xpm", &i, &j);
		move_player(game, game->player.x - 1, game->player.y);
	}
	display_count(game);
	return (0);
}
