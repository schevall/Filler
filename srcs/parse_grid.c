/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

void	parse_grid_size(char *line, t_struct **filler)
{
	char **tab;

	tab = ft_strsplit_whitespace(line);
	(*filler)->size[0] = ft_atoi(tab[2]);
	(*filler)->size[1] = ft_atoi(tab[1]);
	(*filler)->next_action = SKIP_HEADER;
}

void	init_strat(t_struct **filler, t_point **points)
{
	if (points[0]->x > (*filler)->size[0] / 2)
	{
		(*filler)->start = 1;
		(*filler)->strat_x = -1;
		(*filler)->strat_y = -1;
	}
	if ((*filler)->size[0] <= 20)
		(*filler)->break_turn = 1;
	else if ((*filler)->size[0] <= 50)
		(*filler)->break_turn = 3;
	else
		(*filler)->break_turn = 4;
}

void	get_my_points(t_struct **filler)
{
	int		x;
	int		y;
	t_point **my_points;
	int		my_pt;

	my_points = make_point_list(count_me_on_map(filler));
	my_pt = 0;
	y = -1;
	while (++y < (*filler)->size[1])
	{
		x = -1;
		while (++x < (*filler)->size[0])
		{
			if (who_is_it((*filler)->grid[y][x], (*filler)->player_num) == 1)
			{
				my_points[my_pt] = make_point(x, y, my_pt);
				my_pt++;
			}
		}
	}
	if (!(*filler)->turn)
		init_strat(filler, my_points);
	(*filler)->my_pt_nb = my_pt;
	(*filler)->my_points = my_points;
}

void	strat_planner(t_struct **filler)
{
	if ((*filler)->mid_reached == 1)
		return ;
	if ((*filler)->turn >= (*filler)->break_turn)
	{
		(*filler)->strat_y *= -1;
		(*filler)->main_dir *= -1;
		(*filler)->mid_reached = 1;
	}
	return ;
}

void	parse_grid_state(char *line, t_struct **filler)
{
	int		current_y;
	char	**tab;

	if ((*filler)->grid_init == INIT_GRID)
	{
		(*filler)->grid = new_grid((*filler)->size[1]);
		(*filler)->grid_init = KEEP_GRID;
	}
	else if ((*filler)->grid_init == RESET_GRID)
	{
		ft_strdel_tab((*filler)->grid);
		(*filler)->grid = new_grid((*filler)->size[1]);
		(*filler)->grid_init = KEEP_GRID;
	}
	tab = ft_strsplit_whitespace(line);
	current_y = ft_atoi(tab[0]);
	(*filler)->grid[current_y] = ft_strdup(tab[1]);
	if (current_y == (*filler)->size[1] - 1)
	{
		get_my_points(filler);
		strat_planner(filler);
		(*filler)->my_points = sort_points(filler, (*filler)->my_points,
		p_len((*filler)->my_points));
		(*filler)->next_action = PARSE_PIECE_SIZE;
	}
}
