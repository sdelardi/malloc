/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:05:19 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/19 19:32:02 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	swap_tiny(t_tiny **start, t_tiny **prev, t_tiny **next,
		t_tiny **second)
{
	*prev = (*start)->prev;
	*next = (*start)->next;
	*second = (*next)->next;
	if (*prev)
		(*prev)->next = *next;
	else
		g_a.ttail = *next;
	if (*second)
		(*second)->prev = *start;
	else
		g_a.thead = *start;
	(*start)->prev = *next;
	(*start)->next = *second;
	(*next)->prev = *prev;
	(*next)->next = *start;
}

void		sort_tiny(void)
{
	t_tiny *start;
	t_tiny *prev;
	t_tiny *next;
	t_tiny *second;
	int		sort;

	sort = 1;
	start = g_a.ttail;
	while (sort)
	{
		sort = 0;
		while (start)
		{
			if (start->next != NULL && start->next < start)
			{
				sort = 1;
				swap_tiny(&start, &prev, &next, &second);
			}
			start = start->next;
		}
	}
}
