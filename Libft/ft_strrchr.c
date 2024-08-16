/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:17:01 by rdennaou          #+#    #+#             */
/*   Updated: 2024/06/12 10:34:22 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	size_t			i;

	uc = (unsigned char) c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == uc)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == uc)
	{
		return ((char *)s);
	}
	return (NULL);
}
