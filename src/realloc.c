/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:27:44 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/19 18:35:10 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*stretch(void *ptr, size_t old, size_t size)
{
	t_alloc	*alloc;
	t_small	*small;
	t_tiny	*tiny;

	alloc = find_alloc(ptr);
	if (size < old)
	{
		alloc->size = size;
		munmap(ptr + size, old - size);
		return (ptr);
	}
	if ((tiny = find_tiny(ptr)))
	{
		alloc->size = size;
		tiny->size += (size - old);
		tiny->mem_left -= (size - old);
		return (ptr);
	}
	else if ((small = find_small(ptr)))
	{
		alloc->size = size;
		small->size += (size - old);
		small->mem_left -= (size - old);
		return (ptr);
	}
	return (NULL);
}

int		not_enough_size(void *ptr, size_t old, size_t size)
{
	t_alloc	*alloc;
	t_small	*small;
	t_tiny	*tiny;

	alloc = NULL;
	small = NULL;
	tiny = NULL;
	if (old > size)
		return (0);
	if (old <= (size_t)(getpagesize() / 16))
	{
		tiny = find_tiny(ptr);
		if (tiny->mem_left >= (size - old))
			return (0);
	}
	else if (old <= (size_t)(getpagesize() / 2))
	{
		small = find_small(ptr);;
		if (small->mem_left >= (size - old))
			return (0);
	}
	return (1);
}

int		not_same_part(size_t old_size, size_t size)
{
	size_t n;
	size_t  m;

	n = getpagesize() / 16;
	m = getpagesize() / 2;
	if (old_size > m || size > m)
		return (1);
	if (size > n && old_size <= n)
		return (1);
	if (size <= n && old_size > n)
		return (1);
	return (0);
}

size_t	find_size(void *ptr)
{
	t_alloc	*alloc;
	t_large *large;

	if ((alloc = find_alloc(ptr)))
		return (alloc->size);
	else if ((large = find_large(ptr)))
		return (large->size);
	else
		return (0);
}

void	*ft_realloc(void *ptrm, size_t size)
{
	size_t	old;
	void	*new;

	new = NULL;
	if (ptrm == NULL)
	{
		ptrm = ft_malloc(size);
		return (ptrm);
	}
	old = find_size(ptrm);
	if (old == size)
		return (ptrm);
	if (not_same_part(old, size) || not_enough_size(ptrm, old, size))
	{
		new = ft_malloc(size);
		new = copy_datas(ptrm, old, new);
		ft_free(ptrm);
		return (new);
	}
	else
		return (stretch(ptrm, old, size));
}
