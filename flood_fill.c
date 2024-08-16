/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:08:31 by rdennaou          #+#    #+#             */
/*   Updated: 2024/08/16 12:37:37 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	to_fill(char **map, int i, int j)
{
	if (map[j][i] == 'P' || map[j][i] == '0'
		|| map[j][i] == 'C' || map[j][i] == 'E')
		return (1);
	return (0);
}

void	fill(char **tab, t_player size, t_player cur, t_count *p)
{
	if (!to_fill(tab, cur.x, cur.y))
		return ;
	if (tab[cur.y][cur.x] == 'C')
		p->countc++;
	else if (tab[cur.y][cur.x] == 'E')
		p->counte++;
	else if (tab[cur.y][cur.x] == 'P')
		p->countp++;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_player){cur.x - 1, cur.y}, p);
	fill(tab, size, (t_player){cur.x + 1, cur.y}, p);
	fill(tab, size, (t_player){cur.x, cur.y - 1}, p);
	fill(tab, size, (t_player){cur.x, cur.y + 1}, p);
}

void	flood_fill(char **tab, t_player size, t_player begin, t_count *p)
{
	fill(tab, size, begin, p);
}

t_player	player_pos(char **map)
{
	int			i;
	int			j;
	t_player	player;

	i = 0;
	player = (t_player){-1, -1};
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player.x = j;
				player.y = i;
			}
			j++;
		}
		i++;
	}
	return (player);
}
