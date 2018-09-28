/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorak <ahorak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 08:05:04 by ahorak            #+#    #+#             */
/*   Updated: 2018/09/25 08:33:30 by ahorak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

typedef struct				s_store
{
	struct s_store			*back;
	struct s_store			*next;
	char					*ident;
}							t_store;

typedef struct				s_route
{
	struct s_store			*route;
	struct s_route			*next;
	struct s_route			*compat;
	struct s_route			*check;
	int						overlap;
}							t_route;

typedef struct				s_link
{
	struct s_link			*next;
	struct s_room			*room;
}							t_link;

typedef struct				s_room
{
	struct s_room			*next;
	char					*ident;
	char					*pos_x;
	char					*pos_y;
	int						start;
	int						is_end;
	t_link					*link;
	t_link					*start_link;
	t_store					*back;
	int						paths_needed;
	t_route					*paths;
}							t_room;

typedef struct				s_lem
{
	char					*name;
	struct s_lem			*next;
	t_room					*room;
	t_store					*path;
	int						moves;
}							t_lem;

void		error(void);

int			is_number(char *str);
int			has_this_char(char **line, char a);
int			elem_num(t_store *back);

t_room		*end_find(t_room **room);
t_room		*begin_find(t_room **room);

t_room		*get_room(void);
int			make_link(t_room **room, char **line);
void		add_room_end(t_room **start, t_room *newer);
void		add_link_end(t_link **start, t_room *newer);
void		add_link_end_2(t_link **s, t_room *n, t_link **s_2, t_room *n_2);

t_lem		*create_lem(t_room **rooms);
void		num_paths(t_room **room);

#endif
