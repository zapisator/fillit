/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:59:54 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/25 17:28:23 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Validation of input.
*/

/*
**	The function checks '\n' at the ends of lines of TM, and between TM`s,
** only 4 '#' and the rest is only '.'. It writes indices from the beggining if
** TM of its elements to tm->block_id
*/

static int		check_symbol(t_input *tm, int isfinal)
{
	int			column;
	int			row;
	int			i;
	int			id;

	i = 0;
	column = 4;
	id = 0;
	while (column--)
	{
		row = 4;
		while (row--)
		{
			if (*(tm->mark + i) == '#' && id < 4)
				*(tm->block_id + id++) = i;
			else if (*(tm->mark + i) != '.')
				return (ERROR);
			++i;
		}
		if (*(tm->mark + i++) != '\n')
			return (ERROR);
	}
	if (!isfinal && *(tm->mark + i) != '\n')
		return (ERROR);
	return (SUCCESS);
}

/*
**	The function sets sructures of tetriminoes whith initial values. id is the
** capital letter, that identifize TM by input order. mark is for ofset of TM in
** input data. block_id is an array of indices of TM elemets. Type is a type of
** TM.
**	Further, the data is transmitted to assess whether the correct number of
** characters of the expected types is submitted. Then there is a check whether
** these data correspond to at least one of 19 tetramino types. If the results
** of all checks are positive, then 0 is returned, otherwise -1.
*/

static int		initialize(t_list *node, char *file, int tm_nbr, int tm_count)
{
	t_input		*tm;

	tm = (t_input *)node->content;
	tm->id = 'A' + tm_count;
	tm->mark = file + (tm_count * 21);
	if (check_symbol(tm, !tm_nbr) == ERROR || recognize(tm) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

/*
**	The function binds together all the data format conditions.
**	It makes a linked list which content fieled is a structure relevant to
** tetraminoes (see fillit.h). Cap variable is just to make apropriate new list
** with variable allocated for data pointed by the content field.
*/

static int		tie(t_list **head, int tm_count, char *file)
{
	t_list		*node;
	char		cap[sizeof(t_input)];
	int			tm_nbr;

	node = NULL;
	tm_nbr = 0;
	ft_bzero(cap, sizeof(t_input));
	while (tm_count--)
	{
		if (!(node = ft_lstnew(cap, sizeof(t_input))) ||
				initialize(node, file, tm_nbr++, tm_count) == EOF)
		{
			ft_lstdel(head, ft_lstcontentdel);
			return (ERROR);
		}
		ft_lstadd(head, node);
	}
	return (SUCCESS);
}

/*
**	The task of this function is to open the file and check the number of input
** arguments, then copy the file to a heap and send it for further processing.
** The checks include counting the number of bytes read. Obviously, the number
** of bytes should be a positive integer. The smallest value corresponds to one
** tetramino, it takes 20 bytes, and the largest corresponds to 26 tetramino,
** this is 545 bytes. The read data is sent for further processing (see the
** description of the program in the first file).
**	The function returns the total number of elements of all submitted
** tetramino, or -1 in case of an error.
*/

int				validate(int argc, char **argv, t_list **head, int *fd)
{
	char		*file;
	ssize_t		size;
	ssize_t		i;

	if ((argc != 2) || ((*fd = open(*(argv + 1), O_RDONLY)) == EOF))
	{
		argc != 2 ? ft_putendl("usage: fillit file") : ft_putendl("error");
		return (ERROR);
	}
	file = NULL;
	*head = NULL;
	size = ft_read_file(*fd, &file, 1024);
	i = size / 21;
	if (size == EOF || (size < 20 || size > 545 ||
			(i + 1) != (size - i) / 20 || (size - i) % 20) ||
			(tie(head, (size + 1) / 21, file) == EOF))
	{
		ft_putendl("error");
		return (ERROR);
	}
	return ((size + 1) / 21 * 4);
}
