/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:15:59 by ahorak            #+#    #+#             */
/*   Updated: 2018/09/25 10:16:09 by ahorak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	error(void)
{
	ft_putstr(RED"Error");
	exit(-1);
}

int		has_this_char(char **line, char a)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	str = *line;
	if (str[0] == '#')
		return (0);
	while (str[++i])
	{
		if (str[i] == a)
			j++;
	}
	return (j);
}

int		is_number(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' & str[i] <= '9'))
			return (0);
	}
	return (1);
}

int			elem_num(t_store *back)
{
	t_store	*tmp;
	int		i;

	i = 0;
	tmp = back;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
