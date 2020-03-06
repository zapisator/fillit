/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_of_the_result.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:36:51 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/20 22:04:39 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Output of the result.
*/

/*
**	The function adds line breaks at the end of each expected line.
*/

static void		put_down_line_feed(char result[], t_input *tm)
{
	int			correction;
	int			i;

	correction = tm->field_len;
	i = correction + 1;
	while (i--)
	{
		*(result + correction) = '\n';
		correction += tm->field_len + 1;
	}
	return ;
}

/*
**	Here an array will be created in succession, used to display the result on
** the screen. It is filled with blank field characters, line breaks, field end
** (corresponding to zero byte). Then, a cycle on all nodes of the linked list
** of tetramino on the field in the appropriate previously found position will
** be put down the symbols corresponding to the tetramino in the order in which
** they are fed to the input (from A to Z).
*/

void			print_result(t_list *head)
{
	char		result[4096];
	t_list		*node;
	t_input		*tm;
	int			i;
	int			correction;

	node = head;
	tm = (t_input *)(node->content);
	i = (tm->field_len + 1) * (tm->field_len + 1 - 1);
	ft_bzero(result, 4096);
	ft_memset(result, '.', i);
	while (node)
	{
		tm = (t_input *)(node->content);
		i = 4;
		while (i--)
		{
			correction = tm->ofset + *(tm->block_by_len + i);
			*(result + correction + correction / tm->field_len) = tm->id;
		}
		node = node->next;
	}
	put_down_line_feed(result, tm);
	ft_putstr(result);
	return ;
}
