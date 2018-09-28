/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorak <ahorak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:06:18 by ahorak            #+#    #+#             */
/*   Updated: 2018/09/25 10:11:00 by ahorak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_room_end(t_room **start, t_room *newer)
{
	t_room		*tmp;

	if (start == NULL)
		*start = newer;
	else
	{
		tmp = *start;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newer;
		newer->next = NULL;
	}
}

static t_link	*new_link(t_room *newer)
{
	t_link		*newlink;

	newlink = (t_link *)malloc(sizeof(t_link));
	newlink->next = NULL;
	newlink->room = newer;
	return (newlink);
}

void	add_link_end(t_link **start, t_room *newer)
{
	t_link		*tmp;

	if (*start == NULL || (*start)->room == NULL)
		*start = new_link(newer);
	else
	{
		tmp = *start;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->room->ident, newer->ident) == 0)
				return ;
			tmp = tmp->next;
		}
		if (ft_strcmp(tmp->room->ident, newer->ident) == 0)
			return ;
		tmp->next = new_link(newer);
	}
}

void	add_link_end_2(t_link **s, t_room *n, t_link **s_2, t_room *n_2)
{
	add_link_end(s, n);
	add_link_end(s_2, n_2);
}
