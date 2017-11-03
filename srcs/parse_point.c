/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

int 	who_is_it(char grid_pt, int player)
{
	char *me;
	if (player == 1)
		me = "Oo";
	else
		me = "Xx";
	if (grid_pt == '.')
		return 0;
	if (grid_pt == me[0] || grid_pt == me[1])
		return 1;
	return 2;
}

t_point		*make_point(int x, int y)
{
	t_point *point;

	if (!(point = (t_point*)ft_memalloc(sizeof(t_point))))
		error_handling("MALLOC");
	point->x = x;
	point->y = y;
	return point;
}

t_point		**make_point_list(int nb)
{
	t_point **point_list;

	ft_printf_fd(2, "make_point_list nb: %d\n", nb);
	if (!(point_list = (t_point**)ft_memalloc(sizeof(t_point*) * (nb + 1))))
		error_handling("MALLOC");
	ft_printf_fd(2, "make_point_list end\n");
	return point_list;
}

int			count_me_on_map(t_struct **filler)
{
	int x;
	int y;
	int	my_pt;

	my_pt = 0;
	y = -1;
	while (++y < (*filler)->size[1]){
		x = -1;
		while (++x < (*filler)->size[0]) {
			if (who_is_it((*filler)->grid[y][x], (*filler)->player_num) == 1)
				my_pt++;
		}
	}
	return my_pt;
}
