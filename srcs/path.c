/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:17:46 by ahorak            #+#    #+#             */
/*   Updated: 2018/09/25 10:17:54 by ahorak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room		*end_find(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (tmp->is_end)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room		*begin_find(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (tmp->start)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
