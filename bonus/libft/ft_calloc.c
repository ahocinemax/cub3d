/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:35:50 by ahocine           #+#    #+#             */
/*   Updated: 2021/05/31 16:35:52 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t len)
{
	void	*res;

	res = malloc(number * len);
	if (!(res))
		return (NULL);
	res = ft_memset(res, 0, number * len);
	return (res);
}
