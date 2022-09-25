/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 01:49:51 by ahocine           #+#    #+#             */
/*   Updated: 2021/07/01 01:49:53 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	if (!src || !dest)
		return ;
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
}

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		((unsigned char *)dest)[i] = (unsigned char)c;
	return (dest);
}

void	*ft_calloc(size_t number, size_t len)
{
	void	*res;

	res = malloc(number * len);
	if (!(res))
		return (NULL);
	res = ft_memset(res, 0, number * len);
	return (res);
}

int	ft_search_end(char *str)
{
	ssize_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
