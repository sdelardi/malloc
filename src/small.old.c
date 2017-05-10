/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:38:36 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/10 10:09:47 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_alloc	*new_alloc_s(size_t size)
{
	t_alloc *alloc;

	alloc = (void *)mmap(0, sizeof(t_alloc), PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	alloc->size = size;
	alloc->next = NULL;
	if (g_a.shead->mem_left < size)
		new_small_zone(1);
	alloc->data = g_a.shead->data + g_a.shead->size - g_a.shead->mem_left;
	g_a.shead->mem_left -= (alloc->size + 1);
	alloc->prev = (!g_a.atail) ? NULL : g_a.ahead;
	if (!g_a.atail)
	{
		g_a.ahead = alloc;
		g_a.atail = alloc;
	}
	else
	{
		g_a.ahead->next = alloc;
		g_a.ahead = g_a.ahead->next;
	}
	return (alloc);
}

void	*new_small_zone(char mode)
{
	t_small	*zone;
	size_t	size;

	size = getpagesize() * 5;
	zone = (void *)mmap(0, sizeof(t_small), PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->data = (void *)mmap(0, sizeof(char) * size, PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->size = size;
	zone->mem_left = size;
	zone->next = NULL;
	zone->prev = (mode == 0) ? NULL : g_a.shead;
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
	return (zone);
}

int		is_first_small(void)
{
	int		i;
	t_small	*start;

	start = g_a.stail;
	i = 0;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}

void	*map_small(size_t size)
{
	t_small	*zone;
	t_alloc	*alloc;

	zone = NULL;
	alloc = NULL;
	if (!is_first_small())
	{
		zone = new_small_zone(0);
		alloc = new_alloc_s(size);
	}
	else
		alloc = new_alloc_s(size);
	return (alloc->data);
}
