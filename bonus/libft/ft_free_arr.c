/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:52:54 by ahocine           #+#    #+#             */
/*   Updated: 2022/08/26 00:52:59 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arr(void **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}