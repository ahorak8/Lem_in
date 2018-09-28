/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:17:04 by ahorak            #+#    #+#             */
/*   Updated: 2018/09/25 10:17:13 by ahorak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int			listlen(t_link *back)
{
	t_link	*cpy;
	int		i;

	i = 0;
	cpy = back;
	while (cpy)
	{
		cpy = cpy->next;
		i++;
	}
	return (i);
}

void				num_paths(t_room **room)
{
	t_room	*start;
	t_room	*end;
	int		first;
	int		last;

	if ((start = begin_find(room)))
	{
		if ((end = end_find(room)))
		{
			first = listlen(start->link);
			last = listlen(end->link);
			if (first > last)
				end->paths_needed = first;
			else
				end->paths_needed = last;
			return ;
		}
	}
	error();
	exit(0);
}
