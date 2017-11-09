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

int		includes(int id, t_point **sorted)
{
	int i;

	i = -1;
	if (!sorted[0])
		return (0);
	while (sorted[++i])
	{
		if (sorted[i]->id == id)
			return (1);
	}
	return (0);
}

t_point	*get_counter_opti(t_struct **filler)
{
	int x;
	int y;

	x = (*filler)->strat_x * -1000;
	y = (*filler)->strat_y * -1000;
	return (make_point(x, y, -1));
}

t_point	*find_best(t_point **sorted, t_point **list, t_struct **filler)
{
	t_point *best;
	int		i;

	i = -1;
	best = get_counter_opti(filler);
	while (list[++i])
	{
		if (!includes(list[i]->id, sorted))
		{
			if (is_better(best, list[i], filler))
			{
				best->x = list[i]->x;
				best->y = list[i]->y;
				best->id = list[i]->id;
			}
		}
	}
	return (best);
}

t_point	**sort_points(t_struct **filler, t_point **list, int nb)
{
	t_point *best;
	t_point	**sort;
	int		i;

	if (!(sort = (t_point**)ft_memalloc(sizeof(t_point*) * (nb + 1))))
		error_handling("MALLOC");
	i = -1;
	while (++i < nb)
	{
		best = find_best(sort, list, filler);
		sort[i] = best;
	}
	free_point_list(list, "for sort");
	return (sort);
}
