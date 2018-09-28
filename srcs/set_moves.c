/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:19:17 by ahorak            #+#    #+#             */
/*   Updated: 2018/09/25 10:19:34 by ahorak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char		*room_num(t_store *path, int move)
{
	t_store	*tmp;

	tmp = path;
	while (tmp && move)
	{
		move--;
		tmp = tmp->next;
	}
	return (tmp->ident);
}

static t_room	*room_find(char *name, t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (ft_strcmp(tmp->ident, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
