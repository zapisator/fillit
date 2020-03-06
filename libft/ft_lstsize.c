/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:42:00 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:42:03 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *head)
{
	size_t	size;

	size = 0;
	while (head && (head = head->next) && size != SIZE_MAX)
		size++;
	return (size);
}
