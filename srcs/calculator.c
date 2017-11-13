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
	while (++i < (*filler)->piece->pt_nb)
	{
		x = target->x + (*filler)->piece->points[i]->x;
		y = target->y + (*filler)->piece->points[i]->y;
		p = who_is_it((*filler)->grid[y][x], (*filler)->player_num);
		if (p == 1)
			k++;
		else if (p == 2)
		{
			k = 0;
			break ;
		}
	}
	return (k == 1 ? 1 : 0);
}

int			is_in(t_struct **filler, int xt, int yt)
{
	int i;
	int x;
	int y;
	int *size;

	i = -1;
	size = (*filler)->size;
	while (++i < (*filler)->piece->pt_nb)
	{
		x = xt + (*filler)->piece->points[i]->x;
		y = yt + (*filler)->piece->points[i]->y;
		if (x < 0 || y < 0 || x >= size[0] || y >= size[1])
			return (0);
	}
	return (1);
}

t_point		**get_possible_coord(t_struct **filler, t_point *target)
{
	t_point	**possibilities;
	int		i;
	int		x;
	int		y;
	int		id;

	possibilities = make_point_list((*filler)->piece->pt_nb);
	id = 0;
	i = -1;
	while (++i < (*filler)->piece->pt_nb)
	{
		x = target->x - (*filler)->piece->points[i]->x;
		y = target->y - (*filler)->piece->points[i]->y;
		if (is_in(filler, x, y))
		{
			possibilities[id] = make_point(x, y, id);
			id++;
		}
	}
	return (possibilities);
}

t_point		*can_position_accept_piece(t_struct **filler, t_point *target)
{
	int		i;
	t_point **pos_target;
	t_point **sorted_target;
	t_point *result;

	i = -1;
	result = NULL;
	pos_target = get_possible_coord(filler, target);
	if (!pos_target[0])
		return (NULL);
	sorted_target = sort_points(filler, pos_target, p_len(pos_target));
	while (sorted_target[++i])
	{
		if (check_pos(filler, sorted_target[i]) == 1)
		{
			result = make_point(sorted_target[i]->x, sorted_target[i]->y, 0);
			break ;
		}
	}
	free_point_list(sorted_target);
	return (result);
}

void		shoot(t_struct **filler)
{
	int		i;
	t_point *shoot;

	i = -1;
	while ((*filler)->my_points[++i])
	{
		shoot = can_position_accept_piece(filler, (*filler)->my_points[i]);
		if (shoot)
		{
			ft_printf("%d %d\n", shoot->y, shoot->x);
			if ((*filler)->mid_reached == 1)
			{
				(*filler)->main_dir *= -1;
				(*filler)->strat_y *= -1;
				(*filler)->strat_x *= -1;
			}
			(*filler)->grid_init = RESET_GRID;
			(*filler)->next_action = REINIT;
			(*filler)->turn++;
			return ;
		}
	}
	ft_printf("%d %d\n", 0, 0);
}
