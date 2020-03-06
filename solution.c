/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:00:38 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/20 21:38:38 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The MAIN PART.
*/

/*
**	The function calculates initial length of TM field.
**	To accommodate 1 tetramino type O you need a square with side 2, for 1 or 2
** tetramino among which there is at least 1 tetramino type I the minimum field
** size is 4x4. In other cases, when we have only two tetramino, the initial
** size of the field is 3x3. In other cases, the square of the minimum area is
** calculated in order to contain the total number of all elements of all
** tetramino.
*/

static int		calculate(int elem_nb, t_list *head)
{
	int			len;
	t_input		*tm_curr;
	t_input		*tm_next;
	static int	hash[3] = {52224, 34952, 61440};

	tm_curr = (t_input *)(head->content);
	tm_next = !head->next ? NULL : (t_input *)(head->next->content);
	if (elem_nb <= 8 && ((tm_next && (tm_next->hash == *(hash + 1) ||
		tm_next->hash == *(hash + 2))) || tm_curr->hash == *(hash + 1) ||
		tm_curr->hash == *(hash + 2)))
		len = 4;
	else if (elem_nb == 4 && tm_curr->hash == *hash)
		len = 2;
	else
		len = 3;
	while (len * len < elem_nb)
		++len;
	return (len);
}

/*
**	The tasks of this function include the calculation of the new allowed
** position of the first tetramino symbol. The remaining characters are
** naturally tied to the position of the first character.
*/

static int		set_new_position(t_input *tm)
{
	int			row;
	int			col;

	row = tm->ofset / tm->field_len;
	col = tm->ofset % tm->field_len;
	if (row <= tm->row_max && col < tm->col_max)
	{
		++(tm->ofset);
		return (SUCCESS);
	}
	else if (row < tm->row_max)
	{
		tm->ofset = (tm->ofset / tm->field_len + 1) * tm->field_len;
		return (SUCCESS);
	}
	tm->ofset = 0;
	return (FAILURE);
}

/*
**	Having received at the beginning of the linked list of all tetramino and the
** currently considered tetramino, this function searches for a new position
** among the possible ones, gradually shifting within the line, then moving to a
** new line. If such a position is found, it is entered into the appropriate
** fields of the structure associated with the tetramine, and the current node
** will be returned. Otherwise, an attempt is made to find a tetramino higher in
** the list. If this succeeds, then its current location on the field is
** deleted, and the search cycle of the new position is already done with the
** new tetramino. We perform such rollback until a suitable position is found.
** Otherwise all tetramino will be removed from the field and the return value
** is 0.
*/

static t_list	*displace_or_backtrack(t_list *head, t_list *node,
		t_input *tm, char solution[])
{
	while (set_new_position(tm) == FAILURE)
	{
		if (!(node = ft_lstfind_prev(head, node)))
			break ;
		tm = (t_input *)(node->content);
		(void)place_out(solution, tm, 0);
	}
	return (node);
}

/*
**	This function probably expresses the very essence of the process of finding
** a solution. Here, in several cycles with returns, it goes through the
** enumeration of all possible arrangements of each tetrama, until the first
** suitable one is found.
*/

static void		dispose(t_list *head, char solution[], int isresult)
{
	t_list		*node;
	t_input		*tm;

	while (TRUE)
	{
		node = head;
		while (node)
		{
			tm = (t_input *)(node->content);
			set_boundaries(head, node);
			if (place(solution, tm) == FAILURE)
			{
				if (!(node = displace_or_backtrack(head, node, tm, solution)))
					break ;
				continue ;
			}
			if (!(node = node->next))
				isresult = TRUE;
		}
		if (isresult)
			break ;
		++(((t_input *)(head->content))->field_len);
	}
	return ;
}

/*
**	The basic function of the decision finding process. The field for placement
** is stored here, hence the calculation functions of the beginning of the
** calculation and decision making.
*/

void			solve(t_list *head, int elem_nb)
{
	char		solution[4096];
	t_input		*tm;
	int			isresult;

	ft_bzero(solution, 4096);
	tm = (t_input *)(head->content);
	tm->field_len = calculate(elem_nb, head);
	isresult = 0;
	dispose(head, solution, isresult);
	return ;
}
