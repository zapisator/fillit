/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_matching.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:26:58 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 15:25:49 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Validation of input..
*/

/*
**	The function fills a two-dimensional array of names and type codes of
** tetramino with the values of codes.
*/

static void		fill_hash(int hash_names[][19])
{
	hash_names[0][0] = 34952;
	hash_names[0][1] = 61440;
	hash_names[0][2] = 17600;
	hash_names[0][3] = 36352;
	hash_names[0][4] = 51328;
	hash_names[0][5] = 57856;
	hash_names[0][6] = 35008;
	hash_names[0][7] = 59392;
	hash_names[0][8] = 50240;
	hash_names[0][9] = 11776;
	hash_names[0][10] = 52224;
	hash_names[0][11] = 19968;
	hash_names[0][12] = 35968;
	hash_names[0][13] = 58368;
	hash_names[0][14] = 19520;
	hash_names[0][15] = 50688;
	hash_names[0][16] = 19584;
	hash_names[0][17] = 27648;
	hash_names[0][18] = 35904;
	return ;
}

/*
**	The function fills a two-dimensional array of names and type codes of
** tetramino with the values of names.
*/

static void		fill_name(int hash_names[][19])
{
	hash_names[1][0] |= (int)'I' | (int)'0' << 8;
	hash_names[1][1] |= (int)'I' | (int)'1' << 8;
	hash_names[1][2] |= (int)'J' | (int)'0' << 8;
	hash_names[1][3] |= (int)'J' | (int)'1' << 8;
	hash_names[1][4] |= (int)'J' | (int)'2' << 8;
	hash_names[1][5] |= (int)'J' | (int)'3' << 8;
	hash_names[1][6] |= (int)'L' | (int)'0' << 8;
	hash_names[1][7] |= (int)'L' | (int)'1' << 8;
	hash_names[1][8] |= (int)'L' | (int)'2' << 8;
	hash_names[1][9] |= (int)'L' | (int)'3' << 8;
	hash_names[1][10] |= (int)'O' | (int)'0' << 8;
	hash_names[1][11] |= (int)'T' | (int)'0' << 8;
	hash_names[1][12] |= (int)'T' | (int)'1' << 8;
	hash_names[1][13] |= (int)'T' | (int)'2' << 8;
	hash_names[1][14] |= (int)'T' | (int)'3' << 8;
	hash_names[1][15] |= (int)'Z' | (int)'0' << 8;
	hash_names[1][16] |= (int)'Z' | (int)'1' << 8;
	hash_names[1][17] |= (int)'Z' | (int)'2' << 8;
	hash_names[1][18] |= (int)'Z' | (int)'3' << 8;
	return ;
}

/*
**	The function matches the current code of the incoming buffer with the
** tetramino types. If a match is found, the corresponding buffer field is
** populated with the name tetramino. Returns 0 if lucky, -1 otherwise.
*/

int				match(t_input *tm)
{
	static int	hash_names[2][19];
	static int	isset;
	int			i;
	int			ismatch;

	ismatch = FAILURE;
	if (!isset)
	{
		fill_hash(hash_names);
		fill_name(hash_names);
		isset = 1;
	}
	i = 19;
	while (i--)
		if (tm->hash == *(*(hash_names + 0) + i))
		{
			ismatch = SUCCESS;
			ft_memcpy(tm->type, *(hash_names + 1) + i, 3);
			break ;
		}
	return (ismatch);
}
