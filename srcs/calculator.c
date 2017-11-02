/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

int			check_pos(t_struct **filler, t_point *target)
{
	int i;
	int x;
	int y;
	int k;

	i = -1;
	k = 0;
	ft_printf_fd(2, "check_pos\n");
	while (++i < (*filler)->piece->pt_nb) {
		x = target->x + (*filler)->piece->points[i].x;
		y = target->y + (*filler)->piece->points[i].y;
		ft_printf_fd(2, "check_pos iter k: %d x: %*d y: %*d\n", k, 2, x, 2, y);
		if (who_is_it((*filler)->grid[y][x], (*filler)->player_num) == 1)
			k++;
	}
	ft_printf_fd(2, "check_pos k: %d\n", k);
	return k == 1 ? 1 : 0;
}

int			is_in(t_struct **filler, int xt, int yt)
{
	int i;
	int x;
	int y;
	int *size;

	i = -1;
	size = (*filler)->size;
	while (++i < (*filler)->piece->pt_nb) {
		x = xt + (*filler)->piece->points[i].x;
		y = yt + (*filler)->piece->points[i].y;
		if (x < 0 || y < 0 || x >= size[0] || y >= size[1])
			return 0;
	}
	return 1;
}

t_point		**get_possible_coord(t_struct **filler, t_point *target)
{
	t_point	**possibilities;
	int i;
	int x;
	int y;

	possibilities = make_point_list((*filler)->piece->pt_nb);
	i = -1;
	while (++i < (*filler)->piece->pt_nb) {
		x = target->x - (*filler)->piece->points[i].x;
		y = target->y - (*filler)->piece->points[i].y;
		if (is_in(filler, x, y))
			possibilities[i] = make_point(x, y);

	}
	return possibilities;
}

t_point		*can_position_accept_piece(t_struct **filler, t_point *target)
{
	int i;
	t_point **pos_target;

	i = -1;
	pos_target = get_possible_coord(filler, target);
	ft_printf_fd(2, "can_position_accept_piece\n");
	// ft_printf_fd(2, "is point possible: x:%*d, y:%*d\n", 2, x, 2, y);
	while (pos_target[++i]) {
		ft_printf_fd(2, "can_position_accept_piece possible: i: %d, x: %d, y: %d\n", i, pos_target[i]->x, pos_target[i]->y);
		if (check_pos(filler, pos_target[i]) == 1)
			return pos_target[i];
	}
	return NULL;
}

void	shoot(t_struct **filler)
{
	int i;
	t_point *shoot;

	i = -1;
	print_grid(filler);
	print_points(filler);
	// print_my_positions(filler);
	ft_printf_fd(2, "Shoot size[0]:%d, size[1]:%d\n", (*filler)->size[0], (*filler)->size[1]);
	while ((*filler)->my_points[++i]) {
		shoot = can_position_accept_piece(filler, (*filler)->my_points[i]);
		if (shoot) {
			ft_printf_fd(2, "About to shoot x:%d, y:%d\n", shoot->x, shoot->y);
			ft_printf("%d %d\n", shoot->x, shoot->y);
			(*filler)->grid_init = RESET_GRID;
			(*filler)->next_action = PARSE_PIECE_SIZE;
			ft_printf_fd(2, "About to shoot x:%d, y:%d\n", shoot->x, shoot->y);
			return;
		}
	}
}