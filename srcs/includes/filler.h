/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <unistd.h>

typedef struct s_point
{
	int x;
	int y;
}				t_point;

typedef struct s_piece
{
	int			pt_nb; // point number
	int			size[2]; // size x y of the piece sent by vm
	t_point 	**points; // point coordinates of the piece
}				t_piece;

typedef struct s_struct
{
	int			player_num; // 1 if first player, 2 if second
	int			next_action; // see enums
	int 		piece_line; // current line to parse of the piece sent by vm
	t_piece		*piece; // current piece to play
	int			size[2]; // sent by plateau type line from vm
	char		**grid; // current state of the grid
	t_point		**my_points;
	int			my_pt_nb;
	int			grid_init;
	int			strat;
}				t_struct;

void			parse_player(char *line, t_struct **filler);
void			parse_grid_size(char *line, t_struct **filler);
void			parse_grid_state(char *line, t_struct **filler);
void			parse_piece_size(char *line, t_struct **filler);
void			parse_piece_state(char *line, t_struct **filler);
int			 	who_is_it(char grid_pt, int player);
t_point			*make_point(int x, int y);
t_point			**make_point_list(int nb);
int				count_me_on_map(t_struct **filler);
void			shoot(t_struct **filler);
void			reinit_filler(t_struct **filler);
void			free_point_list(t_point **points, char *str);
void			error_handling(char *reason);

void			print_piece(t_piece *piece, char *str);
void			print_grid(t_struct **filler);

typedef enum Actions Actions;
enum Actions
{
	SHOOT, // 0
	PARSE_PLAYER, // 1
	PARSE_GRID_SIZE, // 2
	SKIP_HEADER, // 3
	PARSE_GRID_STATE, // 4
	PARSE_PIECE_SIZE, // 5
	PARSE_PIECE_STATE, // 6
	INIT_GRID, // 7
	RESET_GRID, //8
	KEEP_GRID, // 9
	REINIT, // 10,
};

typedef enum Strat Strat;
enum Strat
{
	GO_LU, // 0
	GO_LD, // 1
	GO_RU, // 2
	GO_RD, // 3
	GO_MID,
};

#endif
