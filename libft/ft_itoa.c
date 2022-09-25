/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:36:41 by ahocine           #+#    #+#             */
/*   Updated: 2021/06/02 14:03:45 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n < -9 || n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	index;
	long	nbr;

	index = ft_counter(n);
	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	res = malloc(sizeof(char) * (index + 1));
	if (!res)
		return (NULL);
	res[index--] = 0;
	while (index > 0)
	{
		res[index--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	else
		res[0] = nbr + '0';
	return (res);
}
