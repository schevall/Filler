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

typedef struct	s_point
{
	int x;
	int y;
	int id;
}				t_point;

typedef struct	s_piece
{
	int			pt_nb;
	int			size[2];
	t_point		**points;
}				t_piece;

typedef struct	s_struct
{
	int			player_num;
	int			next_action;
	int			piece_line;
	t_piece		*piece;
	int			size[2];
	char		**grid;
	t_point		**my_points;
	int			my_pt_nb;
	int			grid_init;
	char		main_dir;
	int			strat_x;
	int			strat_y;
	int			start;
	int			mid_reached;
	int			turn;
	int			break_turn;
}				t_struct;

char			**new_grid(int nb);
int				p_len(t_point **list);
void			parse_player(char *line, t_struct **filler);
void			parse_grid_size(char *line, t_struct **filler);
void			parse_grid_state(char *line, t_struct **filler);
void			parse_piece_size(char *line, t_struct **filler);
void			parse_piece_state(char *line, t_struct **filler);
int				who_is_it(char grid_pt, int player);
t_point			*make_point(int x, int y, int id);
t_point			**make_point_list(int nb);
int				count_me_on_map(t_struct **filler);
t_point			**sort_points(t_struct **filler, t_point **list, int nb);
int				is_better(t_point *b, t_point *c, t_struct **filler);
void			shoot(t_struct **filler);
void			reinit_filler(t_struct **filler);
void			free_all(t_struct *filler);
void			free_point_list(t_point **points);
void			error_handling(char *reason);
void			print_piece(t_piece *piece, char *str);
void			print_grid(t_struct **filler);
void			print_point_list(t_point **list, char *str);

typedef enum e_actions	t_actions;
enum	e_actions
{
	SHOOT,
	PARSE_PLAYER,
	PARSE_GRID_SIZE,
	SKIP_HEADER,
	PARSE_GRID_STATE,
	PARSE_PIECE_SIZE,
	PARSE_PIECE_STATE,
	INIT_GRID,
	RESET_GRID,
	KEEP_GRID,
	REINIT,
};

#endif
