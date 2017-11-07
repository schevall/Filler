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

	ft_printf_fd(2, "parse_grid_size: line: %s\n", line);
	tab = ft_strsplit_whitespace(line);
	(*filler)->size[0] = ft_atoi(tab[2]);
	(*filler)->size[1] = ft_atoi(tab[1]);
	(*filler)->next_action = SKIP_HEADER;
}

void	get_my_points(t_struct **filler)
{
	int x;
	int y;
	t_point **my_points;
	int	my_pt;

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
	{
		if (my_points[0]->x > (*filler)->size[0] / 2)
		{
			(*filler)->start = 1;
			(*filler)->strat_x = -1;
			(*filler)->strat_y = -1;
		}
	}
	(*filler)->my_pt_nb = my_pt;
	(*filler)->my_points = my_points;
}


void	strat_planner(t_struct **filler)
{
	int i;

	if ((*filler)->mid_reached)
		return;
	i = -1;
	// ft_printf_fd(2, "CHECK MID line: %s\n", (*filler)->grid[middle_y]);
	while ((*filler)->my_points[++i]) {
		if ((*filler)->my_points[i]->y == (*filler)->size[1] / 2)
			(*filler)->mid_reached = 1;
	}
}

void	parse_grid_state(char *line, t_struct **filler)
{
	int current_y;
	char **tab;

	if ((*filler)->grid_init == INIT_GRID) {
		(*filler)->grid = new_grid((*filler)->size[1]);
		(*filler)->grid_init = KEEP_GRID;
	}
	else if ((*filler)->grid_init == RESET_GRID) {
		ft_strdel_tab((*filler)->grid);
		(*filler)->grid = new_grid((*filler)->size[1]);
		(*filler)->grid_init = KEEP_GRID;
	}
	tab = ft_strsplit_whitespace(line);
	current_y = ft_atoi(tab[0]);
	(*filler)->grid[current_y] = ft_strdup(tab[1]);
	if (current_y == (*filler)->size[1] - 1) {
		print_grid(filler);
		get_my_points(filler);
		strat_planner(filler);
		(*filler)->my_points = sort_points(filler, (*filler)->my_points, p_len((*filler)->my_points));
		// print_point_list((*filler)->my_points, "sorted My point list");
		(*filler)->next_action = PARSE_PIECE_SIZE;
	}
}
