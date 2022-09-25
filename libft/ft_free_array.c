/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 03:04:22 by ahocine           #+#    #+#             */
/*   Updated: 2022/09/25 03:04:35 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void **array, t_funcptr f)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		f(array[i++]);
	f(array);
	array = NULL;
}
