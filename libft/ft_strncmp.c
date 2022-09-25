/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 06:18:04 by ahocine           #+#    #+#             */
/*   Updated: 2021/06/24 19:01:51 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	if (n < 1)
		return (0);
	if (!s1 || !s2)
		return (1);
	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	if (!b1[0] || !b2[0])
		return (b1[0] - b2[0]);
	i = 0;
	while (i < n && b1[i] && b2[i])
	{
		if (s1[i] != s2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	if ((!b1[i] || !b2[i]) && i != n)
		return ((b1[i] - b2[i]));
	return (0);
}
