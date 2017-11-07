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
	int p;

	i = -1;
	k = 0;
	// ft_printf_fd(2, "check_pos\n");
	while (++i < (*filler)->piece->pt_nb) {
		x = target->x + (*filler)->piece->points[i]->x;
		y = target->y + (*filler)->piece->points[i]->y;
		// ft_printf_fd(2, "check_pos iter k: %d x: %*d y: %*d\n", k, 2, x, 2, y);
		p = who_is_it((*filler)->grid[y][x], (*filler)->player_num);
		if (p == 1)
			k++;
		else if (p == 2) {
			k = 0;
			break;
		}
	}
	// ft_printf_fd(2, "check_pos k: %d\n", k);
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
		x = xt + (*filler)->piece->points[i]->x;
		y = yt + (*filler)->piece->points[i]->y;
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
	int id;

	// ft_printf_fd(2, "start get_possible_coord \n");
	possibilities = make_point_list((*filler)->piece->pt_nb);
	id = 0;
	i = -1;
	while (++i < (*filler)->piece->pt_nb) {
		x = target->x - (*filler)->piece->points[i]->x;
		y = target->y - (*filler)->piece->points[i]->y;
		if (is_in(filler, x, y))
			possibilities[i] = make_point(x, y, id++);

	}
	// ft_printf_fd(2, "end get_possible_coord \n");
	return possibilities;
}

t_point		*can_position_accept_piece(t_struct **filler, t_point *target)
{
	int i;
	t_point **pos_target;
	t_point **sorted_target;
	t_point *result;

	i = -1;
	result = NULL;
	// print_point_list((*filler)->my_points, "in can_position_accept_piece, my points sorted");
	pos_target = get_possible_coord(filler, target);
	if (!pos_target[0])
		return NULL;
	// print_point_list(pos_target, "possible shoots");
	// ft_printf_fd(2, "sort point for calcul\n");
	sorted_target = sort_points(filler, pos_target, p_len(pos_target));
	// print_point_list(sorted_target, "possibles shoots sorted");
	// ft_printf_fd(2, "can_position_accept_piece\n");
	// ft_printf_fd(2, "is point possible: x:%*d, y:%*d\n", 2, x, 2, y);
	while (sorted_target[++i]) {
		// ft_printf_fd(2, "can_position_accept_piece possible: i: %d, x: %d, y: %d\n", i, sorted_target[i]->x, sorted_target[i]->y);
		if (check_pos(filler, sorted_target[i]) == 1) {
			// ft_printf_fd(2, "can_position_accept_piece RETURN: i: %d, x: %d, y: %d\n", i, sorted_target[i]->x, sorted_target[i]->y);
			result = make_point(sorted_target[i]->x, sorted_target[i]->y, 0);
			break;
		}
	}
	free_point_list(sorted_target, "after can_position_accept_piece");
	return result;
}

void	shoot(t_struct **filler)
{
	int i;
	t_point *shoot;

	i = -1;
	// print_grid(filler);
	// print_piece((*filler)->piece, "before calcul");
	// print_my_positions(filler);
	// ft_printf_fd(2, "Shoot size[0]:%d, size[1]:%d\n", (*filler)->size[0], (*filler)->size[1]);
	while ((*filler)->my_points[++i]) {
		shoot = can_position_accept_piece(filler, (*filler)->my_points[i]);
		if (shoot) {
			ft_printf_fd(2, "About to shoot x:%d, y:%d\n", shoot->x, shoot->y);
			ft_printf_fd(2, "About to shoot strat: %d %d\n", (*filler)->strat_x, (*filler)->strat_y);
			ft_printf_fd(2, "About to shoot turn: %d\n", (*filler)->turn);
			print_piece((*filler)->piece, "on Shoot");
			ft_printf("%d %d\n", shoot->y, shoot->x);
			if ((*filler)->mid_reached)
				(*filler)->strat_x *= -1;
			// if ((*filler)->strat == GO_LD)
			// 	(*filler)->strat = GO_RU;
			// else if ((*filler)->strat == GO_RU)
			// 	(*filler)->strat = GO_LD;
			(*filler)->grid_init = RESET_GRID;
			(*filler)->next_action = REINIT;
			(*filler)->turn++;
			return;
		}
	}
	ft_printf("%d %d\n", 0, 0);
}
