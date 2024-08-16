/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:26:12 by rdennaou          #+#    #+#             */
/*   Updated: 2024/08/16 12:05:56 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all_lines(char **map, char *argv)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			count++;
			j++;
		}
		if (count != line_size(argv))
			return (0);
		count = 0;
		i++;
	}
	return (1);
}

int	check_borders(char **map, char *argv)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = line_size(argv) - 1;
	j = count_lines(argv) - 1;
	while (x <= i)
	{
		if (map[0][x] != '1' || map[j][x] != '1')
			return (0);
		x++;
	}
	while (y <= j)
	{
		if (map[y][0] != '1' || map [y][i] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_characters(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map [i][j] != 'E'
				&& map[i][j] != '1' && map [i][j] != '0'
					&& map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(char **map, char *argv)
{
	if (!check_characters(map))
	{
		free_str(map);
		error("Invalid Character\n");
	}
	if (!check_all_lines(map, argv))
	{
		free_str(map);
		error("Size Error\n");
	}
	if (!check_borders(map, argv))
	{
		free_str(map);
		error("The Borders Are Not Closed\n");
	}
	if (!count_characters(map))
	{
		free_str(map);
		error("Too Many or No Player/Exit\n");
	}
	if (!count_collectibles(map))
	{
		free_str(map);
		error("Not Enough Collectibles\n");
	}
}

void	check_path(char *argv)
{
	t_player	start;
	t_count		c;
	char		**map;
	int			count;

	map = open_map(argv);
	check_map(map, argv);
	count = count_collectibles(map);
	c.countc = 0;
	c.counte = 0;
	c.countp = 0;
	start = player_pos(map);
	flood_fill(map, (t_player){line_size(argv), count_lines(argv)}, start, &c);
	if (c.countc != count || c.counte != 1 || c.countp != 1)
	{
		free_str(map);
		error("Invalid Path\n");
	}
	free_str(map);
}
