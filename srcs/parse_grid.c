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
				my_points[my_pt] = make_point(x, y, my_pt);
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
		point = make_point(0, 0, 0);
	else if ((*filler)->strat == GO_LD)
		point = make_point(0, (*filler)->size[1] - 1, 0);
	else if ((*filler)->strat == GO_RU)
		point = make_point((*filler)->size[0] - 1, 0, 0);
	else if ((*filler)->strat == GO_RD)
		point = make_point((*filler)->size[0] - 1, (*filler)->size[1] - 1, 0);
	else if ((*filler)->strat == GO_MID)
		point = make_point((*filler)->size[0] / 2, (*filler)->size[1] / 2, 0);
	return point;
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

int			is_better(t_point *opti, t_point *best, t_point *current)
{
	int e_y_current;
	int e_x_current;
	int e_y_best;
	int e_x_best;

	// ft_printf_fd(2, "\nIS BETTER OPTI x:%2d y:%2d id:%2d\n", opti->x, opti->y, opti->id);
	// ft_printf_fd(2, "IS BETTER BEST x:%2d y:%2d id:%2d\n", best->x, best->y, best->id);
	// ft_printf_fd(2, "IS BETTER CURRENT x:%2d y:%2d id:%2d\n", current->x, current->y, current->id);
	e_y_current = opti->y - current->y;
	e_x_current = opti->x - current->x;
	e_y_best = opti->y - best->y;
	e_x_best = opti->x - best->x;
	// ft_printf_fd(2, "result ex_c:%2d ey_c:%2d ex_b:%2d ey_b:%2d\n", e_x_current, e_y_current, e_x_best, e_y_best);
	if (e_y_current >= e_y_best && e_x_current >= e_x_best)
		return 1;
	return 0;
}

t_point		*find_best(t_point *opti, t_point **sorted, t_point **list)
{
	t_point *best;
	int 	i;

	i = -1;
	while (list[++i]) {
		if (!includes(list[i]->id, sorted)) {
			if (best->x == 999) {
				best->x = list[i]->x;
				best->y = list[i]->y;
				best->id = list[i]->id;
			}
			else if (is_better(opti, best, list[i])) {
				best->x = list[i]->x;
				best->y = list[i]->y;
				best->id = list[i]->id;
			}
		}
	}
	ft_printf_fd(2, "Best found at x: %2d, y: %2d id: %2d for opti: x: %2d y: %2d\n", best->x, best->y, best->id, opti->x, opti->y);
	if (best->x != 999)
		return best;
	free(best);
	return NULL;
}

t_point	**sort_points(t_struct **filler, t_point **list, int nb)
{
	char	*opti;
	t_point *best;
	t_point	**sorted;
	int		id;
	int 	i;

	if (!(sorted = (t_point**)ft_memalloc(sizeof(t_point*) * (nb + 1))))
		error_handling("MALLOC");
	opti = get_optimun(filler);
	i = -1;
	while (++i < nb) {
		best = find_best(opti, sorted, list);
		sorted[i] = best;
	}
	free_point_list(list, "for sort");
	return sorted;
}

void	is_middle_reached(t_struct **filler)
{
	int who;
	int x;
	int middle_y;

	if ((*filler)->strat != GO_MID)
		return;
	middle_y = (*filler)->size[1] / 2;
	x = -1;
	ft_printf_fd(2, "CHECK MID line: %s\n", (*filler)->grid[middle_y]);
	while ((*filler)->grid[middle_y][++x]) {
		if (who_is_it((*filler)->grid[middle_y][x], (*filler)->player_num) == 1) {
			(*filler)->strat = GO_LD;
			ft_printf_fd(2, "CHECK MID line: %s\n", (*filler)->grid[middle_y]);
			// exit(0);
		}
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
		is_middle_reached(filler);
		get_my_points(filler);
		(*filler)->my_points = sort_points(filler, (*filler)->my_points, (*filler)->my_pt_nb);
		// print_point_list((*filler)->my_points, "sorted My point list");
		(*filler)->next_action = PARSE_PIECE_SIZE;
	}
}
