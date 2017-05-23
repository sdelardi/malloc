/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:02:56 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/23 09:10:54 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	del_segment_tiny(void *ptr)
{
	t_tiny	*tiny;

	tiny = g_a.ttail;
	if (tiny == NULL || tiny->next == NULL)
		return ;
	while (tiny)
	{
		if (ptr >= (void *)(tiny->data)
		&& ptr < (void *)(tiny->data + tiny->size))
		{
			if (find_alloc(ptr) == NULL)
				init_tiny(&tiny);
			break ;
		}
		tiny = tiny->next;
	}
}

void	del_segment_small(void *ptr)
{
	t_small *small;

	small = g_a.stail;
	if (small == NULL || small->next == NULL)
		return ;
	while (small)
	{
		if (ptr >= (void *)small->data
		&& ptr < (void *)small->data + small->size)
		{
			if (find_alloc(ptr) == NULL)
				init_small(&small);
			break ;
		}
		small = small->next;
	}
}

void	del_alloc(void *ptr)
{
	t_alloc *start;

	start = find_alloc(ptr);
	if (start)
	{
		start->is_empty = 1;
		if (start->size <= (size_t)(getpagesize() / 20))
			del_segment_tiny(ptr);
		else if (start->size <= (size_t)(getpagesize()))
			del_segment_small(ptr);
		return ;
	}
}

int		is_alloc(void *ptr, int *mode)
{
	t_alloc *alloc;
	t_large *large;

	alloc = find_alloc(ptr);
	if (alloc)
	{
		if (alloc->size <= (size_t)(getpagesize() / 20))
			*mode = 1;
		else
			*mode = 2;
		return (1);
	}
	large = g_a.ltail;
	while (large)
	{
		if (ptr == large->data)
			return (1);
		large = large->next;
	}
	return (0);
}

void	free(void *ptr)
{
	int mode;

	mode = 0;
	if (is_alloc(ptr, &mode))
	{
		if (mode == 1 || mode == 2)
			del_alloc(ptr);
		else
			del_large(ptr);
		ptr = NULL;
	}
	return ;
}
