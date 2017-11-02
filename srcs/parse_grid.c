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

static char	**new_grid(int y)
{
	char	**tab;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (y + 1))))
		error_handling("MALLOC");
	return (tab);
}

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

	my_pt = 0;
	y = -1;
	ft_printf_fd(2, "get_my_points\n");
	while (++y < (*filler)->size[1]){
		x = -1;
		while (++x < (*filler)->size[0]) {
			if (who_is_it((*filler)->grid[y][x], (*filler)->player_num) == 1)
				my_pt++;
		}
	}
	ft_printf_fd(2, "get_my_points my_pt: %d\n", my_pt);
	ft_printf_fd(2, "get_my_points size: %d %d\n", (*filler)->size[0], (*filler)->size[1]);
	if (!(my_points = (t_point**)ft_memalloc(sizeof(t_point*) * (my_pt + 1))))
		error_handling("MALLOC");
	y = -1;
	my_pt = 0;
	while (++y < (*filler)->size[1]){
		x = -1;
		while (++x < (*filler)->size[0]) {
			if (who_is_it((*filler)->grid[y][x], (*filler)->player_num) == 1) {
				ft_printf_fd(2, "in while: x:%*d, y:%*d\n", 2, x, 2, y);
				my_points[my_pt] = make_point(x, y);
				my_pt++;
			}
		}
	}
	(*filler)->my_points = my_points;
	ft_printf_fd(2, "get_my_points\n");
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
	// ft_printf_fd(2, "to cpy %s\n", tab[1]);
	(*filler)->grid[current_y] = ft_strdup(tab[1]);
	// ft_printf_fd(2, "current line y: %*d => %s\n", 2, current_y, (*filler)->grid[current_y]);
	if (current_y == (*filler)->size[1] - 1) {
		print_grid(filler);
		get_my_points(filler);
		ft_printf_fd(2, "endih\n");
		(*filler)->next_action = PARSE_PIECE_SIZE;
	}
}
