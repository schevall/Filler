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

static char	**new_grid(int x, int y)
{
	int		i;
	char	**tab;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (y + 1))))
		error_handling("MALLOC");
	return (tab);
}

void	parse_grid_size(char *line, t_struct **filler)
{
	char **tab;

	tab = ft_strsplit_whitespace(line);
	(*filler)->size[0] = ft_atoi(tab[2]);
	(*filler)->size[1] = ft_atoi(tab[1]);
	(*filler)->next_action = SKIP_HEADER;
}

void	parse_grid_state(char *line, t_struct **filler)
{
	int current_y;
	char **tab;
	size_t len;

	if ((*filler)->grid_init == INIT_GRID) {
		(*filler)->grid = new_grid((*filler)->size[0], (*filler)->size[1]);
		(*filler)->grid_init = KEEP_GRID;
	}
	else if ((*filler)->grid_init == RESET_GRID) {
		ft_strdel_tab((*filler)->grid);
		(*filler)->grid = new_grid((*filler)->size[0], (*filler)->size[1]);
		(*filler)->grid_init = KEEP_GRID;
	}
	tab = ft_strsplit_whitespace(line);
	current_y = ft_atoi(tab[0]);
	// ft_printf_fd(2, "to cpy %s\n", tab[1]);
	(*filler)->grid[current_y] = ft_strdup(tab[1]);
	// ft_printf_fd(2, "current line y: %*d => %s\n", 2, current_y, (*filler)->grid[current_y]);
	if (current_y == (*filler)->size[1] - 1) {
		print_grid(filler);
		(*filler)->next_action = PARSE_PIECE_SIZE;
	}
}
