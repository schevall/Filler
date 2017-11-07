/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

t_point		*get_optimun(t_struct **filler)
{
	int x;
	int y;

	x = (*filler)->size[0];
	y = (*filler)->size[1];
	if (!(*filler)->mid_reached)
		return make_point( x / 2, y / 2, -1);
	else if ((*filler)->strat_y == 1 && (*filler)->strat_x == 1)
		return make_point( x - 1, y - 1, -1);
	else if ((*filler)->strat_y == -1 && (*filler)->strat_x == -1)
		return make_point( 0 , 0 , -1);
	else if ((*filler)->strat_y == 1 && (*filler)->strat_x == -1)
		return make_point( 0 , y - 1, -1);
	return make_point( x - 1, 0 , -1);
}

int			includes(int id, t_point **sorted)
{
	int i;

	i = -1;
	if (!sorted[0])
		return 0;
	while (sorted[++i]) {
		if (sorted[i]->id == id)
			return 1;
	}
	return 0;
}

int			is_better(t_point *o, t_point *b, t_point *c, t_struct **filler)
{
	int e_best;
	int e_cur;

	e_best = ft_sqrt(ft_power(o->x - b->x, 2) + ft_power(o->y - b->y, 2));
	e_cur = ft_sqrt(ft_power(o->x - c->x, 2) + ft_power(o->y - c->y, 2));

	ft_printf_fd(2, "\nis better ecart_on_best: %4d\n", e_best);
	ft_printf_fd(2, "is better ecart_on_current: %4d\n", e_cur);
	return e_cur <= e_best;
}

t_point	*find_best(t_point *opti, t_point **sorted, t_point **list, t_struct **filler)
{
	t_point *best;
	int 	i;

	i = -1;
	best = make_point(list[0]->x, list[0]->y, list[0]->id);
	while (list[++i]) {
		if (!includes(list[i]->id, sorted))
		{
			if (is_better(opti, best, list[i], filler))
			{
				best->x = list[i]->x;
				best->y = list[i]->y;
				best->id = list[i]->id;
			}
		}
	}
	return best;
	// ft_printf_fd(2, "Best found at x: %2d, y: %2d id: %2d for opti: x: %2d y: %2d\n", best->x, best->y, best->id, opti->x, opti->y);
}

t_point	**sort_points(t_struct **filler, t_point **list, int nb)
{
	t_point	*opti;
	t_point *best;
	t_point	**sort;
	int		id;
	int 	i;

	if (!(sort = (t_point**)ft_memalloc(sizeof(t_point*) * (nb + 1))))
		error_handling("MALLOC");
	opti = get_optimun(filler);
	i = -1;
	// ft_printf_fd(2, "SORT POINT: nb: %2d\n", nb);
	while (++i < nb) {
		best = find_best(opti, sort, list, filler);
		sort[i] = best;
	}
	free_point_list(list, "for sort");
	// ft_printf_fd(2, "\nBEST RESULT: x: %2d y%2d \n\n", sort[0]->x, sort[0]->y);
	return sort;
}
