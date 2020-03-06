/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_recognition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:22:01 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 15:21:19 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Validation of input..
*/

/*
**	Trim means here that row of 5 elemnts with '\n' at the end is cut by last
** fifth element to make field of 4 elements.
*/

static void	trim(int *block_id)
{
	int i;

	i = 4;
	while (i--)
		*(block_id + i) -= *(block_id + i) / 5;
	return ;
}

/*
**	Get the coordinates of the tetramino elements after setting the shape to the
** left upper position.
*/

static int	unify(int *block_id)
{
	int		ofset;
	int		i;
	int		min;
	int		copy[4];

	ofset = 0;
	ofset += (*block_id / 5) * 5;
	i = 4;
	while (i--)
		*(copy + i) = *(block_id + i) % 5;
	i = 2;
	min = ft_imin(*(copy + i + 1), *(copy + i));
	while (i--)
		min = ft_imin(min, *(copy + i));
	ofset += min;
	i = 4;
	while (i--)
		*(block_id + i) -= ofset;
	trim(block_id);
	return (SUCCESS);
}

/*
**	The function translates the values of the indices of the four elements of
** the intended tetramino into the code. The code is an integer where each index
** is matched by a power of two by the formula 2 ^ 16 - * block_id.
*/

static int	encipher(t_input *tm)
{
	int		i;

	i = 4;
	tm->hash = 0;
	while (i--)
		tm->hash |= 1 << (15 - *(tm->block_id + i));
	return (tm->hash > 0 ? 0 : -1);
}

/*
**	Let's make the cipher for this TM in order to compare it with the ciphers of
** each type of TM. It is easy to make a cipher: calculate the sums of each
** index of each TM element multiplied by 1 by 1, second by 2, third by 4 and
** fourth by 8.
*/

int			recognize(t_input *tm)
{
	unify(tm->block_id);
	if (encipher(tm) == ERROR || match(tm) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
