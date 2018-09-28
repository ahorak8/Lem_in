/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:18:02 by ahorak            #+#    #+#             */
/*   Updated: 2018/09/25 10:18:15 by ahorak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_room		*create_room(char **input, int pathway, int num)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	room->ident = input[0];
	room->pos_x = input[1];
	room->pos_y = input[2];
	room->next = NULL;
	room->start = 0;
	room->is_end = 0;
	room->lemnum = 0;
	room->link = NULL;
	room->back = NULL;
	room->paths = NULL;
	if (pathway == 1)
	{
		room->start = 1;
		room->lemnum = num;
	}
	else if (pathway == 2)
		room->is_end = 1;
	return (room);
}

static void			free_get_next(char **line)
{
	free2(line);
	get_next_line(0, line);
}

static t_room		*read_in(char **line, int num)
{
	char	**input;
	t_room	*room;
	int		pathway;

	pathway = 0;
	while ((*line)[0] == '#' && (*line)[1] != '#')
		free_get_next(line);
	if (ft_strcmp(*line, "##start") == 0 || ft_strcmp(*line, "##end") == 0)
	{
		if ((*line)[2] == 's')
			pathway = 1;
		else
			pathway = 2;
		free_get_next(line);
	}
	if (has_this_char(line, ' ') == 2)
	{
		input = ft_strsplit(*line, ' ');
		if (is_number(input[1]) && is_number(input[2]))
		{
			room = create_room(input, pathway, num);
			return (room);
		}
	}
	return (NULL);
}

static void			ret_free(int ret, char *line, t_room *start)
{
	ret = make_link(&start, &line);
	free(line);
}

t_room				*get_room(void)
{
	t_room	*room;
	t_room	*start;
	char	*line;
	int		num;
	int		ret;

	num = 0;
	start = NULL;
	while (get_next_line(0, &line) > 0 && (!has_this_char(&line, '-')))
	{
		if (has_this_char(&line, ' ') == 0 && (!has_this_char(&line, '-')))
			num = ft_atoi(line);
		else if ((room = read_in(&line, num)))
			add_room_end(&start, room);
		else
			return (start);
		free(line);
	}
	ret_free(ret, line, start);
	while (ret && get_next_line(0, &line) > 0 && ft_strcmp(line, " ") != 0)
	{
		ret_free(ret, line, start);
	}
	return (start);
}
