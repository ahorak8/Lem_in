/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:13:49 by ahorak            #+#    #+#             */
/*   Updated: 2018/09/25 10:13:52 by ahorak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	tab_len(char **array)
{
	int		len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

static char	**get_link(char **line)
{
	char **link;

	link = NULL;
	if ((*line)[0] == '#' && (*line)[1] != '#')
	{
		free2(line);
		if (get_next_line(0, line) < 1 && (!has_this_char(line, '-')))
			return (NULL);
	}
	link = ft_strsplit(*line, '-');
	if (tab_len(link) != 2 || ft_strcmp(link[0], link[1]) == 0)
	{
		while (*link)
			free2(link++);
		link = NULL;
	}
	return (link);
}

int			make_link(t_room **room, char **line)
{
	char	**tub;
	t_room	*tmp;
	t_room	*tmp2;

	tmp = *room;
	tmp2 = *room;
	if ((tub = get_link(line)))
	{
		while (ft_strcmp(tub[0], tmp->ident))
		{
			if ((tmp = tmp->next) == NULL)
				return (0);
		}
		while (ft_strcmp(tub[1], tmp->ident) != 0)
		{
			if ((tmp2 = tmp2->next) == NULL)
			{
				if ((tmp2 = tmp2->next) == NULL)
					return (0);
			}
		}
		add_link_end_2(&tmp->link, tmp2, &tmp2->link, tmp);
		return (1);
	}
	return (0);
}
