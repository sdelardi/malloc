/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 08:09:31 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/23 09:44:48 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void		swap_sort(t_sort **start, t_sort **prev, t_sort **next,
		t_sort **second)
{
	*prev = (*start)->prev;
	*next = (*start)->next;
	*second = (*next)->next;
	if (*prev)
		(*prev)->next = *next;
	else
		g_a.sotail = *next;
	if (*second)
		(*second)->prev = *start;
	else
		g_a.sohead = *start;
	(*start)->prev = *next;
	(*start)->next = *second;
	(*next)->prev = *prev;
	(*next)->next = *start;
}

void			sort_sort(void)
{
	t_sort	*start;
	t_sort	*prev;
	t_sort	*next;
	t_sort	*second;
	int		sort;

	sort = 1;
	while (sort)
	{
		sort = 0;
		start = g_a.sotail;
		while (start)
		{
			if (start->next != NULL && start->next->addr < start->addr)
			{
				sort = 1;
				swap_sort(&start, &prev, &next, &second);
			}
			start = start->next;
		}
	}
}

void			new_sort(void *data, size_t size, void *alloc, int type)
{
	t_sort	*new;

	new = (void *)mmap(0, sizeof(t_sort), PROT_READ |
			PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0);
	new->data = data;
	new->size = size;
	new->addr = alloc;
	if (type == 1)
		new->large = (t_large *)alloc;
	else if (type == 2)
		new->tiny = (t_tiny *)alloc;
	else if (type == 3)
		new->small = (t_small *)alloc;
	new->type = type;
	new->next = NULL;
	aux_sort(&new);
}

void			end_sort(void)
{
	t_sort	*start;

	start = g_a.sotail;
	while (start)
	{
		g_a.sotail = start->next;
		munmap(start, sizeof(t_sort));
		start = g_a.sotail;
	}
	g_a.sotail = NULL;
	g_a.sohead = NULL;
}

void			sort_alloc(void)
{
	t_large	*large;
	t_tiny	*tiny;
	t_small	*small;

	large = g_a.ltail;
	small = g_a.stail;
	tiny = g_a.ttail;
	while (large)
	{
		new_sort(large->data, large->size, large, 1);
		large = large->next;
	}
	while (tiny)
	{
		new_sort(tiny->data, tiny->size, tiny, 2);
		tiny = tiny->next;
	}
	while (small)
	{
		new_sort(small->data, small->size, small, 3);
		small = small->next;
	}
	sort_sort();
}
