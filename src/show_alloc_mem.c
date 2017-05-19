/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:26:45 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/19 10:07:58 by sdelardi         ###   ########.fr       */
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
	t_large *start;
	t_tiny	*tiny;
	t_small *small;

	sort_large();
	sort_tiny();
	sort_small();
	start = g_a.ltail;
	while (start)
	{
		printf("LARGE : %p\n", start);
		printf("%p", start->data);
		printf(" - %p", start->data + start->size);
		printf(" : %zu octets\n", start->size);
		start = start->next;
	}
	tiny = g_a.ttail;
	while (tiny)
	{
		printf("TINY : %p\n", tiny);
		show_alloc_t(tiny, tiny->size);
		tiny = tiny->next;
	}
	small = g_a.stail;
	while (small)
	{
		printf("SMALL : %p\n", small);
		show_alloc_s(small, small->size);
		small = small->next;
	}
}
