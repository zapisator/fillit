/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_placing_and_limiting.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:10:27 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/20 21:29:28 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	MAIN PART.
*/

/*
**	The function removes tetramino elements from the field. The number of placed
** elements is given by the third argument. In the general case, the actions of
** removing elements of tetramino take place in the reverse order with respect
** to the order of their placement on the field.
*/

int				place_out(char solution[], t_input *tm, int i)
{
	int			ofset;

	ofset = tm->ofset;
	while (i < 4)
		--*(solution + ofset + *(tm->block_by_len + i++));
	return (FAILURE);
}

/*
**	The function places on the field of zeros (there is not a single element of
** the other tetramino) and units (in this area there is an element of the other
** tetramino) each element of this tetramino, corresponding to one. If the new
** value of the field element after the installation of the tetramino element in
** it is equal to 1, then everything is fine. Otherwise, you need to roll back
** the arrangement of the tetramino elements.
*/

int				place(char solution[], t_input *tm)
{
	int			i;
	int			ofset;

	i = 4;
	ofset = tm->ofset;
	while (i--)
		if ((*(solution + ofset + *(tm->block_by_len + i)) += '\1') > 1)
			return (place_out(solution, tm, i));
	return (SUCCESS);
}

/*
**	The calculation of the lowest position of the first tetramino element on a
** two-dimensional field which in fact represents only a mapping of a two-
** dimensional field into a one-dimensional array. The starting point is
** related to the side of the square. Next you need to find a position so that
** other elements do not go beyond the bottom. What is the same as the minimum
** value of the set of rounded results dividing the initial position of each
** element of a given tetramine by 4.
**	Perhaps it is by simplifying the calculations here that you can
** significantly increase the performance of the program algorithm.
*/

static void		calculate_row_max(t_input *tm)
{
	int			tmp;
	int			i;

	i = 4;
	tm->row_max = tm->field_len - 1;
	while (i--)
	{
		tmp = tm->field_len - *(tm->block_id + i) / 4 - 1;
		if (tmp < tm->row_max)
			tm->row_max = tmp;
	}
	return ;
}

/*
**	The calculation of the rightmost position of the first tetramino element on
** a two-dimensional field which in fact represents only a mapping of a two-
** dimensional field into a one-dimensional array. The starting point is related
** to the side of the square. Next you need to find a position so that other
** elements do not go beyond the bottom. What is the same as the minimum value
** of the set of results of residues from dividing the initial position of each
** element of a given tetramino by 4.
**	Perhaps it is by simplifying the calculations here that you can
** significantly increase the performance of the program algorithm.
*/

static void		calculate_col_max(t_input *tm)
{
	int			tmp;
	int			i;

	i = 4;
	tm->col_max = tm->field_len - 1;
	while (i--)
	{
		tmp = tm->field_len - *(tm->block_id + i) % 4 - 1;
		if (tmp < tm->col_max)
			tm->col_max = tmp;
	}
	return ;
}

/*
**	Here calculate the extreme right and lowest position of the first element of
** each tetramine for a given field size, as well as the new ratio of the
** positions of the other elements.
*/

void			set_boundaries(t_list *head, t_list *node)
{
	t_input		*tm;
	int			i;

	tm = (t_input *)(node->content);
	tm->field_len = ((t_input *)(head->content))->field_len;
	i = 4;
	while (i--)
		*(tm->block_by_len + i) = *(tm->block_id + i) + (*(tm->block_id + i)
				/ 4) * (tm->field_len - 4);
	calculate_row_max(tm);
	calculate_col_max(tm);
	return ;
}
