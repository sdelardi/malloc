/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:09:27 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/10 10:08:27 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*malloc(size_t size)
{
	void	*ptr;
	size_t	n;
	size_t	m;

	n = getpagesize() / 100;
	m = getpagesize() / 20;
	ptr = NULL;
	if ((long int)size <= 0)
		printf("Are you kiddin me ?\n");
	else if (size <= n)
		ptr = map_tiny(size);
	else if (size > n && size <= m)
		ptr = map_small(size);
	else if (size > m)
		ptr = map_large(size);
	return (ptr);
}
