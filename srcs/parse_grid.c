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

	my_points = make_point_list(count_me_on_map(filler));
	my_pt = 0;
	y = -1;
	while (++y < (*filler)->size[1]){
		x = -1;
		while (++x < (*filler)->size[0]) {
			if (who_is_it((*filler)->grid[y][x], (*filler)->player_num) == 1) {
				ft_printf_fd(2, "get_my_points: my_pt: %d\n", my_pt);
				my_points[my_pt] = make_point(x, y);
				my_pt++;
			}
		}
	}
	(*filler)->my_pt_nb = my_pt;
	(*filler)->my_points = my_points;
	ft_printf_fd(2, "get_my_points pt_nb: %d\n", my_pt);
}
// GO_LU, // 0
// GO_LD, // 1
// GO_RU, // 3
// GO_RD, //

t_point	*get_optimun(t_struct **filler)
{
	t_point *point;

	if ((*filler)->strat == GO_LU)
		point = make_point(0, 0);
	else if ((*filler)->strat == GO_LD)
		point = make_point(0, (*filler)->size[1] - 1);
	else if ((*filler)->strat == GO_RU)
		point = make_point((*filler)->size[0] - 1, 0);
	else if ((*filler)->strat == GO_RD)
		point = make_point((*filler)->size[0] - 1, (*filler)->size[1] - 1);
	else if ((*filler)->strat == GO_MID)
		point = make_point((*filler)->size[0] / 2, (*filler)->size[1] / 2);
	return point;
}

void	sort_my_points(t_struct **filler)
{
	t_point **my_points;
	t_point	*opti;
	int i;

	if ((*filler)->my_pt_nb == 1)
		return;
	my_points = make_point_list((*filler)->my_pt_nb);
	opti = get_optimun(filler);
	i = -1;
	while (++i < (*filler)->my_pt_nb) {
		
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
		ft_printf_fd(2, "PARSE_GRID_STATE RESET\n");
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
		sort_my_points(filler);
		(*filler)->next_action = PARSE_PIECE_SIZE;
	}
}
