/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:46:24 by ahocine           #+#    #+#             */
/*   Updated: 2021/05/31 15:24:44 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	if (len < 1)
		return (0);
	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	if (len == 1)
		return (b1[0] - b2[0]);
	i = 0;
	while (b1[i] == b2[i] && i < len - 1)
		i++;
	return (b1[i] - b2[i]);
}
