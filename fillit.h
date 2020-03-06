/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:02:52 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/20 15:32:48 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>

/*
**	The main structure used in the project.
**	id				: Tetrimino name from A to Z.
**	mark			: Pointer to the place of input data of this tetrimino.
**	block_id		: Local indices of each element in tetrimino field 4x4.
**	block_by_len	: Local indices in a field of a certain size.
**	hash			: The unique code of one of the 19 types of tetrimino.
**	type			: Tetrimino type.
**	filed_len		: Field length. Field - the place of Tetrimino installation.
**	row_max			: Limit lower position on the field.
**	col_max			: The extreme right position on the field.
**	ofset			: The indent from which to start installing this tetrimino.
*/

typedef struct		s_input
{
	char			id;
	char			*mark;
	int				block_id[4];
	int				block_by_len[4];
	int				hash;
	char			type[3];
	int				field_len;
	int				row_max;
	int				col_max;
	int				ofset;
}					t_input;

/*
**	A list of global functions defined by the project files.
*/

int					validate(int argc, char **argv, t_list **head, int *fd);
int					recognize(t_input *tm);
int					match(t_input *tm);
void				solve(t_list *head, int elem_nb);
int					place_out(char solution[], t_input *tm, int i);
int					place(char solution[], t_input *tm);
void				set_boundaries(t_list *head, t_list *node);
void				print_result(t_list *head);

#endif
