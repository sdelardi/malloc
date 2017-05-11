/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:23:31 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/11 11:52:18 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*new_alloc_t(size_t size, t_tiny *zone)
{
	void	*ptr;
	int		i;

	i = 0;
	while ((zone->alloc)[i].is_empty == 0 && i <= 250)
		i++;
	(zone->alloc)[i].is_empty = 0;
	(zone->alloc)[i].size = size;
	ptr = zone->data + (zone->size - zone->mem_left);
	zone->mem_left = (size < 16) ? zone->mem_left - 16 : zone->mem_left - size;
	return (ptr);
}

void	*new_tiny_zone(char mode)
{
	t_tiny	*zone;
	size_t	size;
	int		i;

	i = -1;
	size = getpagesize();
	zone = (void *)mmap(0, sizeof(char) * size + sizeof(t_tiny), PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->data = (void *)(zone + sizeof(t_tiny));
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
	while (++i <= 250)
	{
		(zone->alloc)[i].is_empty = 1;
		(zone->alloc)[i].size = 0;
	}
	return (zone);
}

t_tiny	*is_first_tiny(void)
{
	t_tiny	*start;

	start = g_a.ttail;
	if (!start)
		return (NULL);
	while (start->next)
		start = start->next;
	return (start);
}

void	*map_tiny(size_t size)
{
	t_tiny	*zone;
	void	*ptr;

	zone = NULL;
	if ((zone = is_first_tiny()) == NULL)
	{
		zone = new_tiny_zone(0);
		ptr = new_alloc_t(size, zone);
	}
	else
		ptr = new_alloc_t(size, zone);
	return (ptr);
}
