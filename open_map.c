/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:43:27 by rdennaou          #+#    #+#             */
/*   Updated: 2024/08/16 12:45:16 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_extra_lines(char *line, char *temp, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(temp);
	close(fd);
	error("Extra lines found\n");
}

char	*ft_error(int fd, char *line)
{
	char	*temp;

	if (fd < 0)
		error("Invalid File\n");
	if (!line)
		error("Map Empty\n");
	temp = ft_strdup("");
	return (temp);
}

char	*join_array(char *temp, char *line)
{
	char	*array;

	array = ft_strjoin(temp, line);
	free(line);
	free(temp);
	return (array);
}

char	*read_map(char *argv)
{
	char	*line;
	char	*array;
	char	*temp;
	int		fd;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	temp = ft_error(fd, line);
	while (line)
	{
		if (ft_strncmp(line, "\n", ft_strlen(line)) != 0)
		{
			array = join_array(temp, line);
			temp = ft_strdup(array);
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			free(array);
		}
		else
			check_for_extra_lines(line, temp, fd);
	}
	free(temp);
	close(fd);
	return (array);
}

char	**open_map(char *argv)
{
	char	*array;
	char	**splittedarray;

	array = read_map(argv);
	splittedarray = ft_split(array, '\n');
	free(array);
	return (splittedarray);
}
