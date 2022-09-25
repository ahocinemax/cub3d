/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:13:01 by ahocine           #+#    #+#             */
/*   Updated: 2021/06/28 22:13:02 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*element;

	if (alst)
	{
		if (*alst)
		{
			element = ft_lstlast(*alst);
			element->next = new;
		}
		else
			*alst = new;
		new->next = NULL;
	}
}
