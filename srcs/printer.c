/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

void	print_piece(t_piece *piece, char *str)
{
	int i;
	int x;
	int y;

	i = 0;
	y = -1;
	ft_printf_fd(2, "About to print piece: %s\n", str);
	ft_printf_fd(2, "About to print piece: pt_nb:%d, size: %d %d\n",
	piece->pt_nb, piece->size[0], piece->size[1]);
	while (++y < piece->size[1])
	{
		x = -1;
		while (++x < piece->size[0])
		{
			if (piece->points[i] && piece->points[i]->y == y &&
				piece->points[i]->x == x)
			{
				ft_printf_fd(2, "*");
				i++;
			}
			else
				ft_printf_fd(2, ".");
		}
		ft_printf_fd(2, "\n");
	}
}

void	print_grid(t_struct **filler)
{
	int *size;
	int y;

	size = (*filler)->size;
	y = -1;
	ft_printf_fd(2, "About to print grid size: y:%d, x:%d\n", size[1], size[0]);
	while (++y < size[1])
		ft_printf_fd(2, "%s\n", (*filler)->grid[y]);
}

void	print_point_list(t_point **l, char *str)
{
	int i;

	i = -1;
	ft_printf_fd(2, "\nAbout to print point list: %s\n", str);
	while (l[++i])
		ft_printf_fd(2, "x:%2d, y:%2d, id:%2d\n", l[i]->x, l[i]->y, l[i]->id);
}
