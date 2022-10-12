/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:36:09 by ahocine           #+#    #+#             */
/*   Updated: 2021/05/31 16:36:11 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	size_s;
	size_t	tmp;

	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	if (start + len > size_s)
		tmp = size_s;
	else
		tmp = len;
	res = malloc(sizeof(char) * (tmp + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i + start] && i + start < size_s && i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}
