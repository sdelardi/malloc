/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:06:06 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/19 19:31:44 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	swap_small(t_small **start, t_small **prev, t_small **next,
		t_small **second)
{
	*prev = (*start)->prev;
	*next = (*start)->next;
	*second = (*next)->next;
	if (*prev)
		(*prev)->next = *next;
	else
		g_a.stail = *next;
	if (*second)
		(*second)->prev = *start;
	else
		g_a.shead = *start;
	(*start)->prev = *next;
	(*start)->next = *second;
	(*next)->prev = *prev;
	(*next)->next = *start;
}

void		sort_small(void)
{
	t_small *start;
	t_small *prev;
	t_small *next;
	t_small *second;
	int		sort;

	sort = 1;
	start = g_a.stail;
	while (sort)
	{
		sort = 0;
		while (start)
		{
			if (start->next != NULL && start->next < start)
			{
				sort = 1;
				swap_small(&start, &prev, &next, &second);
			}
			start = start->next;
		}
	}
}
