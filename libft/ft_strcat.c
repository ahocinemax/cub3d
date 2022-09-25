/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:27:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/09/25 02:27:35 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (src[j] && dest[i + j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
}
