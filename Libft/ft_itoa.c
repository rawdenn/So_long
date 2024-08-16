/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdennaou <rdennaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:44:51 by rdennaou          #+#    #+#             */
/*   Updated: 2024/06/13 13:39:21 by rdennaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	check_negative(int n)
{
	if (n < 0)
		return ((unsigned int)(-n));
	else
		return ((unsigned int)n);
}

int	count_digits(int n)
{
	unsigned int	count;
	unsigned int	num;

	count = 0;
	if (n < 0)
		count++;
	num = check_negative(n);
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	unsigned int	len;
	char			*str;

	len = count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	num = check_negative(n);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	else
	{
		while (num > 0)
		{
			str[--len] = (num % 10) + '0';
			num /= 10;
		}
	}
	return (str);
}
