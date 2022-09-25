/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:33:06 by ahocine           #+#    #+#             */
/*   Updated: 2021/06/02 11:45:56 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)b;
	while (i < len)
	{
		if (res[i] == (unsigned char)c)
			return ((void *)(res + i));
		i++;
	}
	return (NULL);
}
