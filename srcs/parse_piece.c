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

static void	add_point(t_struct **filler, int x, int y, int pt_nb)
{
	t_point *point;
		// ft_printf_fd(2, "\n add point x:%d y:%d pt_nb:%d\n", x, y, pt_nb);
	if (!(point = (t_point*)ft_memalloc(sizeof(t_point))))
		error_handling("MALLOC");
	point->x = x;
	point->y = y;
	// ft_printf_fd(2, "\n add point pt_coord: x:%d y:%d \n", point->x, point->y);
	(*filler)->piece->points[pt_nb] = *point;
	(*filler)->piece->pt_nb++;
	// ft_printf_fd(2, "\n add point pt_nb: %d \n", (*filler)->piece->pt_nb);
	// ft_printf_fd(2, "\n add point verif: x:%d y:%d \n", (*filler)->piece->points[pt_nb].x, (*filler)->piece->points[pt_nb].y);
}

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
	// ft_printf_fd(2, "\n PARSE_PIECE_STATE: y:%d target=:%d \n", y, (*filler)->piece->size[1]);
	while (line[++x]) {
		if (line[x] == '*')
			add_point(filler, x, y, (*filler)->piece->pt_nb);
	}
	(*filler)->piece_line++;
	if ((*filler)->piece_line == (*filler)->piece->size[1])	{
		shoot(filler);
		return;
	}
}
