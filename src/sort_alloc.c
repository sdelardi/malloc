/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:09:00 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/19 19:29:23 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	swap_alloc(t_alloc **start, t_alloc **prev, t_alloc **next,
		t_alloc **second)
{
	*prev = (*start)->prev;
	*next = (*start)->next;
	*second = (*next)->next;
	if (*prev)
		(*prev)->next = *next;
	else
		g_a.atail = *next;
	if (*second)
		(*second)->prev = *start;
	else
		g_a.ahead = *start;
	(*start)->prev = *next;
	(*start)->next = *second;
	(*next)->prev = *prev;
	(*next)->next = *start;
}

void	sort_alloc(void)
{
	t_alloc *start;
	t_alloc *prev;
	t_alloc *next;
	t_alloc *second;
	int		sort;

	sort = 1;
	start = g_a.atail;
	while (sort)
	{
		sort = 0;
		while (start)
		{
			if (start->next != NULL && start->next < start)
			{
				sort = 1;
				swap_alloc(&start, &prev, &next, &second);
			}
			start = start->next;
		}
	}
}
