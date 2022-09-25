/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 05:50:26 by ahocine           #+#    #+#             */
/*   Updated: 2021/04/11 05:59:27 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nb)
{
	long	i;
	long	res;
	long	neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == ' ')
		i++;
	if (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(nb[i]))
	{
		res = res * 10 + nb[i] - '0';
		i++;
	}
	return ((int)res * (int)neg);
}
