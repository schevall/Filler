/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_better.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

int		dir_is_y_sort(t_struct **filler, int ex, int ey)
{
	if ((*filler)->strat_y == 1 && ey <= 0)
	{
		if (ey < 0)
			return (1);
		if ((*filler)->strat_x == 1 && ex <= 0)
			return (1);
		else if ((*filler)->strat_x == -1 && ex >= 0)
			return (1);
	}
	else if ((*filler)->strat_y == -1 && ey >= 0)
	{
		if (ey > 0)
			return (1);
		if ((*filler)->strat_x == 1 && ex <= 0)
			return (1);
		else if ((*filler)->strat_x == -1 && ex >= 0)
			return (1);
	}
	return (0);
}

int		dir_is_x_sort(t_struct **filler, int ex, int ey)
{
	if ((*filler)->strat_x == 1 && ex <= 0)
	{
		if (ex < 0)
			return (1);
		if ((*filler)->strat_y == 1 && ey <= 0)
			return (1);
		else if ((*filler)->strat_y == -1 && ey >= 0)
			return (1);
	}
	else if ((*filler)->strat_x == -1 && ex >= 0)
	{
		if (ex > 0)
			return (1);
		if ((*filler)->strat_y == 1 && ey <= 0)
			return (1);
		else if ((*filler)->strat_y == -1 && ey >= 0)
			return (1);
	}
	return (0);
}

int		is_better(t_point *b, t_point *c, t_struct **filler)
{
	int ex;
	int ey;

	ex = b->x - c->x;
	ey = b->y - c->y;
	if ((*filler)->main_dir == 1)
		return (dir_is_y_sort(filler, ex, ey));
	else
		return (dir_is_x_sort(filler, ex, ey));
}
