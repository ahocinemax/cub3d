/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:36:27 by ahocine           #+#    #+#             */
/*   Updated: 2021/05/31 16:36:29 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, const char *sep)
{
	size_t	j;

	j = -1;
	while (sep[++j])
		if (c == sep[j])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *sep)
{
	size_t	start;
	size_t	len;
	char	*str;

	if (!s1 || !sep)
		return (NULL);
	str = (char *)s1;
	start = 0;
	while (str[start] && ft_is_charset(str[start], sep))
		start++;
	len = ft_strlen(str);
	while (start < len && str[len - 1] && ft_is_charset(str[len - 1], sep))
		len--;
	return (ft_substr(s1, start, len - start));
}
