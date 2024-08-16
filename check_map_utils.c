/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:12:06 by rdennaou          #+#    #+#             */
/*   Updated: 2024/08/16 14:13:45 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *argv)
{
	int	fd;
	int	count;
	int	bytes;

	count = 0;
	bytes = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &bytes, 1) > 0)
	{
		if (bytes == '\n')
			count++;
	}
	close(fd);
	return (count);
}

int	line_size(char *argv)
{
	int	fd;
	int	count;
	int	bytes;

	count = 0;
	bytes = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &bytes, 1) > 0)
	{
		if (bytes == '\n')
			break ;
		count++;
	}
	close(fd);
	return (count);
}

int	count_characters(char **map)
{
	int	i;
	int	j;
	int	countp;
	int	counte;

	i = 0;
	countp = 0;
	counte = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (counte > 1 || countp > 1)
				return (0);
			if (map[i][j] == 'P')
				countp++;
			else if (map[i][j] == 'E')
				counte++;
			j++;
		}
		i++;
	}
	return (countp >= 1 && counte >= 1);
}

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	countc;

	i = 0;
	countc = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				countc++;
			j++;
		}
		i++;
	}
	return (countc);
}
