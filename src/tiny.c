/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:23:31 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/06 14:10:42 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_alloc	*new_alloc_t(size_t size)
{
	t_alloc *alloc;

	alloc = (void *)mmap(0, sizeof(t_alloc), PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	alloc->size = size;
	alloc->next = NULL;
	if (g_a.thead->mem_left < size)
		new_tiny_zone(1);
	alloc->data = g_a.thead->data + g_a.thead->size - g_a.thead->mem_left;
	g_a.thead->mem_left -= alloc->size;
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

void	*new_tiny_zone(char mode)
{
	t_tiny	*zone;
	size_t	size;

	size = getpagesize() * 7;
	zone = (void *)mmap(0, sizeof(t_tiny), PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->data = (void *)mmap(0, size, PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->size = size;
	zone->mem_left = size;
	zone->next = NULL;
	zone->prev = (mode == 0) ? NULL : g_a.thead;
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
	return (zone);
}

int		is_first_tiny(void)
{
	int		i;
	t_tiny	*start;

	start = g_a.ttail;
	i = 0;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}

void	*map_tiny(size_t size)
{
	t_tiny	*zone;
	t_alloc	*alloc;

	zone = NULL;
	alloc = NULL;
	if (!is_first_tiny())
	{
		zone = new_tiny_zone(0);
		alloc = new_alloc_t(size);
	}
	else
		alloc = new_alloc_t(size);
	return (alloc);
}
