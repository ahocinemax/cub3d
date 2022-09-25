/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:27:28 by ahocine           #+#    #+#             */
/*   Updated: 2021/05/30 21:27:55 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!dest && !src && len)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, len);
	else
		while (len--)
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
	return (dest);
}
