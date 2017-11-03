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

void	free_point_list(t_point **points, char *str)
{
	int i;

	i = -1;
	ft_printf_fd(2, "start free_point_list on %s\n", str);
	while (points[++i])
		free(points[i]);
	free(points);
	ft_printf_fd(2, "end free_point_list on %s\n", str);
}

void	reinit_piece(t_piece *piece)
{
	piece->size[0] = 0;
	piece->size[1] = 0;
	piece->pt_nb = 0;
	free_point_list(piece->points, "reinit_piece");
}

void	reinit_filler(t_struct **filler)
{
	t_point **points;
	t_point **my_points;

	ft_printf_fd(2, "\nStart Reinit\n");
	(*filler)->piece_line = 0;
	(*filler)->next_action = PARSE_GRID_SIZE;

	free_point_list((*filler)->my_points, "my pt");
	(*filler)->my_points = NULL;
	(*filler)->my_pt_nb = 0;

	print_piece((*filler)->piece, "before reinit_piece");
	reinit_piece((*filler)->piece);
	print_piece((*filler)->piece, "after free_point_list");
	if(!(points = (t_point**)ft_memalloc(sizeof(t_point*) * 100)))
		error_handling("MALLOC");
	(*filler)->piece->points = points;
	(*filler)->piece->pt_nb = 0;
	ft_printf_fd(2, "End Reinit\n");
}
