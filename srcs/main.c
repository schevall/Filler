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

t_struct *init_struct(t_struct *filler)
{
	t_piece *piece;
	t_point *points;

	if(!(filler = (t_struct*)ft_memalloc(sizeof(t_struct))))
		error_handling("MALLOC");
	filler->piece_line = 0;
	filler->next_action = PARSE_PLAYER;
	filler->grid = NULL;
	filler->grid_init = INIT_GRID;
	if(!(piece = (t_piece*)ft_memalloc(sizeof(t_piece))))
		error_handling("MALLOC");
	filler->piece = piece;
	if(!(points = (t_point*)ft_memalloc(sizeof(t_point) * 100)))
		error_handling("MALLOC");
	filler->piece->points = points;
	filler->piece->pt_nb = 0;
	return filler;
}

void init_player(char *line, t_struct **filler)
{
	char **tab;

	tab =ft_strsplit_whitespace(line);
	(*filler)->player_num = (int)(tab[2][1] - 48);
	(*filler)->next_action = PARSE_GRID_SIZE;
}

void	shoot(t_struct **filler)
{
	int y;
	int x;
	int coord[2];

	y = -1;
	print_grid(filler);
	print_points(filler);
	while ((*filler)->grid[++y]) {
		x = -1;
		while ((*filler)->grid[y][++x]) {
			if ((*filler)->grid[y][x] == 'X' || (*filler)->grid[y][x] == 'x') {
				coord[0] = x - (*filler)->piece->points[0].x;
				coord[1] = y - (*filler)->piece->points[0].y;
			}
		}
	}
	ft_printf_fd(2, "About to shoot x:%d, y:%d\n", coord[0], coord[1]);
	ft_printf("%d %d\n", coord[1], coord[0]);
	(*filler)->grid_init = RESET_GRID;
	return;
}

void get_line_type(char *line, t_struct **filler)
{
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
}

int		main(int ac, char **av)
{
	char *line;
	t_struct *filler;
	char *shoot;
	int fd; //to delete
	FILE *fp;
	int turn;

	fp = fopen("./log.txt", "w");
	fd = fileno(fp);
	turn = 1;
	fd = open("./log.txt", O_WRONLY);
	filler = init_struct(filler);
	while (get_next_line(0, &line) > 0)
	{
		get_line_type(line, &filler);
		print_struct(fd, filler, turn++, line);
	}
	return (0);
}
