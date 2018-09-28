/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:11:48 by ahorak            #+#    #+#             */
/*   Updated: 2018/09/25 10:11:52 by ahorak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char		*name(int num)
{
	char	str[2];
	char	*ret;

	str[0] = 'L';
	str[1] = '\0';
	ret = ft_strjoin(str, ft_itoa(num));
	return (ret);
}

static void		start_lem(t_lem **lem, int num, t_room *start)
{
	*lem = (t_lem *)malloc(sizeof(lem));
	(*lem)->next = NULL;
	(*lem)->name = name(num);
	(*lem)->room = start;
	(*lem)->path = NULL;
	(*lem)->moves = 0;
}

t_lem			*create_lem(t_room **rooms)
{
	t_room	*start;
	t_lem	*lem;
	t_lem	*lem_start;
	int		i;

	i = 1;
	start = *rooms;
	start_lem(&lem, i, start);
	lem_start = lem;
	i++;
	while (i <= start->lemnum)
	{
		start_lem(&lem->next, i, start);
		lem = lem->next;
		i++;
	}
	return (lem_start);
}
