/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:47:29 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:47:31 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function changes the sequence of bytes of a certain section of this
** buffer (buffer) to the opposite. The function requires the parameters of the
** index of the first byte of the buffer section and the index of the last
** section.
*/

char	*ft_reverse(char *buffer, int i, int j)
{
	size_t	size;

	size = sizeof(char);
	while (i < j)
		ft_swap(buffer + i++, buffer + j--, size);
	return (buffer);
}
