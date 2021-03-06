/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

t_struct	*init_struct(t_struct *filler)
{
	t_piece *piece;
	t_point **points;

	if (!(filler = (t_struct*)ft_memalloc(sizeof(t_struct))))
		error_handling("MALLOC");
	filler->piece_line = 0;
	filler->next_action = PARSE_PLAYER;
	filler->grid = NULL;
	filler->grid_init = INIT_GRID;
	filler->my_points = NULL;
	filler->my_pt_nb = 0;
	if (!(piece = (t_piece*)ft_memalloc(sizeof(t_piece))))
		error_handling("MALLOC");
	filler->piece = piece;
	if (!(points = (t_point**)ft_memalloc(sizeof(t_point*) * 100)))
		error_handling("MALLOC");
	filler->piece->points = points;
	filler->piece->pt_nb = 0;
	filler->start = 0;
	filler->main_dir = 1;
	filler->strat_y = 1;
	filler->strat_x = 1;
	filler->mid_reached = 0;
	filler->turn = 0;
	return (filler);
}

void		init_player(char *line, t_struct **filler)
{
	char	**tab;

	tab = ft_strsplit_whitespace(line);
	(*filler)->player_num = (int)(tab[2][1] - 48);
	(*filler)->next_action = PARSE_GRID_SIZE;
}

void		get_line_type(char *line, t_struct **filler)
{
	if ((*filler)->next_action == REINIT)
		reinit_filler(filler);
	if ((*filler)->next_action == PARSE_PLAYER)
		init_player(line, filler);
	else if ((*filler)->next_action == PARSE_GRID_SIZE)
		parse_grid_size(line, filler);
	else if ((*filler)->next_action == SKIP_HEADER)
		(*filler)->next_action = PARSE_GRID_STATE;
	else if ((*filler)->next_action == PARSE_GRID_STATE)
		parse_grid_state(line, filler);
	else if ((*filler)->next_action == PARSE_PIECE_SIZE)
		parse_piece_size(line, filler);
	else if ((*filler)->next_action == PARSE_PIECE_STATE)
		parse_piece_state(line, filler);
	if ((*filler)->next_action == SHOOT)
		shoot(filler);
}

int			main(int ac, char **av)
{
	char		*line;
	t_struct	*filler;

	filler = init_struct(filler);
	while (get_next_line(0, &line) > 0)
		get_line_type(line, &filler);
	free_all(filler);
	return (0);
}
