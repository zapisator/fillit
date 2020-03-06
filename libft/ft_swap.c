/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:56:58 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:57:00 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_swap(void *x, void *y, size_t size)
{
	unsigned char	t;
	unsigned char	*xptr;
	unsigned char	*yptr;

	xptr = (unsigned char *)x;
	yptr = (unsigned char *)y;
	while (size--)
	{
		t = *xptr;
		*xptr++ = *yptr;
		*yptr++ = t;
	}
	return ;
}
