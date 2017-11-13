/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

void	free_point_list(t_point **points)
{
	int i;

	i = -1;
	while (points[++i])
		free(points[i]);
	free(points);
}

void	reinit_piece(t_piece *piece)
{
	piece->size[0] = 0;
	piece->size[1] = 0;
	piece->pt_nb = 0;
	free_point_list(piece->points);
}

void	reinit_filler(t_struct **filler)
{
	t_point **points;
	t_point **my_points;

	(*filler)->piece_line = 0;
	(*filler)->next_action = PARSE_GRID_SIZE;
	free_point_list((*filler)->my_points);
	(*filler)->my_points = NULL;
	(*filler)->my_pt_nb = 0;
	reinit_piece((*filler)->piece);
	if (!(points = (t_point**)ft_memalloc(sizeof(t_point*) * 100)))
		error_handling("MALLOC");
	(*filler)->piece->points = points;
	(*filler)->piece->pt_nb = 0;
}

void	free_all(t_struct *filler)
{
	free_point_list(filler->my_points);
	ft_strdel_tab(filler->grid);
	free_point_list(filler->piece->points);
	free(filler->piece);
}
