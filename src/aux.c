/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 09:08:53 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/23 10:54:35 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	aux_tiny(t_tiny **new, char mode)
{
	t_tiny	*zone;
	int		i;

	i = -1;
	zone = *new;
	if (mode == 0)
	{
		g_a.thead = zone;
		g_a.ttail = zone;
	}
	else
	{
		g_a.thead->next = zone;
		g_a.thead = g_a.thead->next;
	}
	while (++i <= 250)
	{
		(zone->alloc)[i].data = NULL;
		(zone->alloc)[i].is_empty = 1;
		(zone->alloc)[i].size = 0;
	}
}

void	aux_small(t_small **new, char mode)
{
	t_small *zone;
	int		i;

	i = -1;
	zone = *new;
	if (mode == 0)
	{
		g_a.shead = zone;
		g_a.stail = zone;
	}
	else
	{
		g_a.shead->next = zone;
		g_a.shead = g_a.shead->next;
	}
	while (++i <= 250)
	{
		(zone->alloc)[i].data = NULL;
		(zone->alloc)[i].is_empty = 1;
		(zone->alloc)[i].size = 0;
	}
}

void	init_tiny(t_tiny **new)
{
	t_tiny *tiny;

	tiny = *new;
	if (tiny->prev)
		tiny->prev->next = tiny->next;
	else
		g_a.ttail = tiny->next;
	if (tiny->next)
		tiny->next->prev = tiny->prev;
	else
		g_a.thead = tiny->prev;
	tiny->prev = NULL;
	tiny->next = NULL;
	munmap(tiny, sizeof(t_tiny) + tiny->size);
	tiny = NULL;
}

void	init_small(t_small **new)
{
	t_small *small;

	small = *new;
	if (small->prev)
		small->prev->next = small->next;
	else
		g_a.stail = small->next;
	if (small->next)
		small->next->prev = small->prev;
	else
		g_a.shead = small->prev;
	small->prev = NULL;
	small->next = NULL;
	munmap(small, sizeof(t_small) + small->size);
	small = NULL;
}

void	del_large(void *ptr)
{
	t_large *start;

	start = g_a.ltail;
	while (start)
	{
		if (start->data == ptr)
		{
			if (start->prev)
				start->prev->next = start->next;
			else
				g_a.ltail = start->next;
			if (start->next)
				start->next->prev = start->prev;
			else
				g_a.lhead = start->prev;
			start->prev = NULL;
			start->next = NULL;
			munmap(start, sizeof(t_large) + start->size);
			start = NULL;
			return ;
		}
		start = start->next;
	}
}
