/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:05:41 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/20 22:14:01 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The program is designed for all incoming Tetraminos with a number from 1 to
** 26 selects such a minimum square in which all tetramino can be placed.
**
**	An additional rule is that the coverage of a square in the presence of
** several options is correct only that which places the tetramino in the
** maximum upper left position that which is found in the order in the file
** before.
**
**	The arguments for calling the program are 1 single file filled in according
** to the format. Properly formatted are those input parameters in which each
** tetrimino is given in four lines, each completed with a line break. The
** string is represented only by the characters of the empty field element '.'
** and symbols of the field element filled with the tetramino element. Between
** the two tetramino should be put an additional line break. No other
** characters.
**
**	A positive result of the program is a field that holds all the tratraminos,
** in which each line ends with a line break, and all elements of the tetramino
** are represented on the field by Latin characters in ascending order, counting
** from the first input figure. In the case of an incorrect number of data, the
** program suggests the program call format. In other cases, the output is an
** "error".
*/

int				main(int argc, char **argv)
{
	int			fd;
	t_list		*head;
	int			elem_nb;

	if ((elem_nb = validate(argc, argv, &head, &fd)) == ERROR)
		return (ERROR);
	solve(head, elem_nb);
	print_result(head);
	ft_memdel((void **)(&((t_input *)(head->content))->mark));
	ft_lstdel(&head, ft_lstcontentdel);
	if (close(fd) == ERROR)
	{
		ft_putendl("error");
		return (ERROR);
	}
	return (SUCCESS);
}
