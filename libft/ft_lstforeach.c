/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:38:09 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:38:11 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstforeach(t_list *node, void (*fptr)(void *))
{
	t_list	*curr;

	curr = node;
	if (fptr)
		while (curr)
		{
			(*fptr)(curr->content);
			curr = curr->next;
		}
	return ;
}
