/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:35:34 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:35:35 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddtip(t_list **head, t_list *new)
{
	t_list *last;

	last = NULL;
	if (head && *head && new)
	{
		last = ft_lstlast(*head);
		last->next = new;
		new->next = NULL;
	}
	return ;
}
