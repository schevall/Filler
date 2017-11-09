/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

void	parse_piece_size(char *line, t_struct **filler)
{
	char **tab;

	tab = ft_strsplit_whitespace(line);
	(*filler)->piece->size[0] = ft_atoi(tab[2]);
	(*filler)->piece->size[1] = ft_atoi(tab[1]);
	(*filler)->next_action = PARSE_PIECE_STATE;
}

void	parse_piece_state(char *line, t_struct **filler)
{
	int x;
	int y;

	x = -1;
	y = (*filler)->piece_line;
	while (line[++x])
	{
		if (line[x] == '*')
		{
			(*filler)->piece->points[(*filler)->piece->pt_nb] =
			make_point(x, y, (*filler)->piece->pt_nb);
			(*filler)->piece->pt_nb++;
		}
	}
	(*filler)->piece_line++;
	if ((*filler)->piece_line == (*filler)->piece->size[1])
	{
		(*filler)->next_action = SHOOT;
		return ;
	}
}
