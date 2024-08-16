/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:06:34 by rdennaou          #+#    #+#             */
/*   Updated: 2024/06/27 16:52:23 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
    read the line until BUFFER_SIZE
*/
char	*read_line(int fd, char *saved)
{
	char	*buffer;
	char	*temp;
	int		bytes;

	bytes = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((!saved || !ft_strchr(saved, '\n')) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), NULL);
		buffer[bytes] = '\0';
		if (saved)
		{
			temp = ft_strjoin(saved, buffer);
			free(saved);
		}
		else
			temp = ft_strjoin("", buffer);
		saved = temp;
	}
	return (free(buffer), saved);
}
/*
    returns the string until \n with \n included
*/

char	*check_new_line(char *saved)
{
	int		i;
	char	*str;

	i = 0;
	if (!saved)
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		str[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}
/*
    saves everything after the \n 
*/

char	*get_new_str(char *saved)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(saved) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (saved[i])
		str[j++] = saved[i++];
	str[j] = '\0';
	free(saved);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_line(fd, saved);
	if (!saved)
		return (NULL);
	buffer = check_new_line(saved);
	saved = get_new_str(saved);
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}
