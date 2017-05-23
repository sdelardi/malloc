/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:23:31 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/23 09:50:08 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*new_alloc_t(size_t size, t_tiny *zone)
{
	void	*ptr;
	int		i;

	i = 0;
	while ((zone->alloc)[i].data != NULL && i <= 250)
	{
		if ((zone->alloc)[i].is_empty == 1 && size <= (zone->alloc)[i].size)
		{
			(zone->alloc)[i].is_empty = 0;
			(zone->alloc)[i].size = size;
			ptr = (zone->alloc)[i].data;
			return (ptr);
		}
		i++;
	}
	(zone->alloc)[i].is_empty = 0;
	(zone->alloc)[i].size = size;
	if (zone->size == zone->mem_left)
		(zone->alloc)[i].data = zone->data;
	else
		(zone->alloc)[i].data = zone->data + (zone->size - zone->mem_left) + 1;
	ptr = (zone->alloc)[i].data;
	zone->mem_left = (size < 16) ?
	zone->mem_left - 16 : zone->mem_left - (size + 1);
	return (ptr);
}

void	*new_tiny_zone(char mode)
{
	t_tiny	*zone;
	size_t	size;
	int		i;

	i = -1;
	size = getpagesize() * 5;
	zone = (void *)mmap(0, sizeof(char) * size + sizeof(t_tiny), PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	zone->data = (void *)zone + sizeof(t_tiny);
	zone->size = size;
	zone->mem_left = size;
	zone->next = NULL;
	zone->prev = (mode == 0) ? NULL : g_a.thead;
	aux_tiny(&zone, mode);
	return (zone);
}

int		is_full_t(t_tiny *zone, size_t size)
{
	int i;

	i = 0;
	if (zone->mem_left < 16 || zone->mem_left < size)
		return (1);
	while ((zone->alloc)[i].data != NULL)
		i++;
	if (i == 251)
		return (1);
	return (0);
}

void	*map_tiny(size_t size)
{
	t_tiny	*zone;
	void	*ptr;

	zone = g_a.thead;
	if (zone == NULL)
	{
		zone = new_tiny_zone(0);
		ptr = new_alloc_t(size, zone);
	}
	else if (is_full_t(zone, size))
	{
		zone = new_tiny_zone(1);
		ptr = new_alloc_t(size, zone);
	}
	else
		ptr = new_alloc_t(size, zone);
	return (ptr);
}
