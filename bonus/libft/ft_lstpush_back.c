/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:51:46 by ahocine           #+#    #+#             */
/*   Updated: 2022/09/03 01:51:49 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **start, t_list *this)
{
	t_list	*prev_this;

	if (!start || !this || !this->next)
		return ;
	prev_this = NULL;
	if (*start != this)
	{
		prev_this = *start;
		while (prev_this && prev_this->next && prev_this->next != this)
			prev_this = prev_this->next;
	}
	if (prev_this)
		prev_this->next = this->next;
	else
		*start = this->next;
	ft_lstadd_back(start, this);
}
