#include "./includes/filler.h"


void	print_struct(int fd, t_struct *filler, int turn, char *line)
{
	int i;

	i = -1;
	ft_printf_fd(fd, "\nturn :%d\n", turn);
	ft_printf_fd(fd, "player_num: %d\n", filler->player_num);
	ft_printf_fd(fd, "Next action: %d\n", filler->next_action);
	ft_printf_fd(fd, "piece_line: %d\n\n", filler->piece_line);
	if (filler->next_action == PARSE_PIECE_SIZE || filler->next_action == PARSE_PIECE_STATE) {
		ft_printf_fd(fd, "\nCURRENT PIECE STATE\n");
		ft_printf_fd(fd, "piece_pt_nb: %d\n", filler->piece->pt_nb);
		ft_printf_fd(fd, "piece_size: x:%d, y:%d\n", filler->piece->size[0], filler->piece->size[1]);
		while(++i < filler->piece->pt_nb)
			ft_printf_fd(fd, "piece_point n[%d]: x:%d, y:%d\n", i, filler->piece->points[i].x, filler->piece->points[i].y);
	}
}

void	print_points(t_struct **filler)
{
	t_point *points = (*filler)->piece->points;
	int pt_nb = (*filler)->piece->pt_nb;
	int *size = (*filler)->piece->size;
	int i;
	int x;
	int y;

	i = 0;
	y = -1;
	ft_printf_fd(2, "About to print point\n");
	while (++y < size[1]) {
		x = -1;
		while(++x < size[0]) {
			if (points[i].y == y && points[i].x == x) {
				ft_printf_fd(2, "*");
				i++;
			}
			else
				ft_printf_fd(2, ".");
		}
		ft_printf_fd(2, "\n");
	}
}

void print_grid(t_struct **filler)
{
	int *size = (*filler)->size;
	int y = -1;

	ft_printf_fd(2, "About to print grid size: y:%d, x:%d\n", size[1], size[0]);
	while (++y < size[1]) {
		ft_printf_fd(2, "%s\n", (*filler)->grid[y]);
	}
}
