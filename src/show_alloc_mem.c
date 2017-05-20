/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:26:45 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/20 11:55:47 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	show_alloc_t(t_tiny *zone, size_t size)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		if ((zone->alloc)[i].data >= zone->data && (zone->alloc)[i].data < zone->data + size && (zone->alloc)[i].is_empty == 0)
		{
			printf("%p", (zone->alloc)[i].data);
			printf(" - %p", (zone->alloc)[i].data + (zone->alloc)[i].size);
			printf(" : %zu octets\n", (zone->alloc)[i].size);
		}
		i++;
	}
}

void	show_alloc_s(t_small *zone, size_t size)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		if ((zone->alloc)[i].data >= zone->data && (zone->alloc)[i].data < zone->data + size && (zone->alloc)[i].is_empty == 0)
		{
			printf("%p", (zone->alloc)[i].data);
			printf(" - %p", (zone->alloc)[i].data + (zone->alloc)[i].size);
			printf(" : %zu octets\n", (zone->alloc)[i].size);
		}
		i++;
	}
}

void	show_alloc_mem(void)
{
	t_sort	*start;

	sort_alloc();
	start = g_a.sotail;
	while (start)
	{
		if (start->type == 1)
		{
			printf("LARGE : %p\n", (t_large *)(start->large));
			printf("%p", (t_large *)(start->large)->data);
			printf(" - %p", (t_large *)(start->large)->data + start->size);
			printf(" : %zu octets\n", start->size);
		}
		else if (start->type == 2 && start->size == (size_t)getpagesize() * 5)
		{
			printf("TINY : %p\n", (t_tiny *)(start->tiny));
			show_alloc_t((t_tiny *)(start->tiny), start->size);
		}
		else if (start->type == 3 && start->size == (size_t)getpagesize() * 100)
		{
			printf("SMALL : %p\n", (t_small *)(start->small));
			show_alloc_s((t_small *)(start->small), start->size);
		}
		start = start->next;
	}
	end_sort();
}
