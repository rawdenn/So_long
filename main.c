/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:41:12 by rdennaou          #+#    #+#             */
/*   Updated: 2024/08/16 17:34:17 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(t_img *img, char *mlx_ptr)
{
	if (img)
	{
		if (img->player)
			mlx_destroy_image(mlx_ptr, img->player);
		if (img->wall)
			mlx_destroy_image(mlx_ptr, img->wall);
		if (img->bg)
			mlx_destroy_image(mlx_ptr, img->bg);
		if (img->exit)
			mlx_destroy_image(mlx_ptr, img->exit);
		if (img->collectible)
			mlx_destroy_image(mlx_ptr, img->collectible);
	}
	free(img);
}

int	on_destroy(t_game *game)
{
	free_image(game->img, game->mlx_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_str(game->map);
	free(game->mlx_ptr);
	free(game);
	exit(0);
	return (0);
}

void	check_argv(int argc, char *argv)
{
	int	len;

	if (argc > 2)
		error("Too Many Arguments\n");
	else if (argc < 2)
		error("Not Enough Arguments\n");
	len = ft_strlen(argv);
	if (argv[len - 1] != 'r' && argv[len - 2] != 'e'
		&& argv[len - 3] != 'b' && argv[len - 4] != '.')
		error("File should end in .ber\n");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	check_argv(argc, argv[1]);
	check_path(argv[1]);
	game = create_window(argv[1]);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &on_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, game);
	mlx_loop(game->mlx_ptr);
	on_destroy(game);
}
