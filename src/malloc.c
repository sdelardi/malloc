/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:09:27 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/06 11:31:48 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;
	size_t	n;
	size_t	m;

	n = getpagesize() / 16;
	m = getpagesize() / 2;
	ptr = NULL;
	if (size <= 0)
		printf("Are you kiddin me ?\n");
	else if (size <= n)
		printf("TINY\n");
	else if (size > n && size <= m)
		printf("SMALL\n");
	else if (size > m)
		ptr = map_large(size);
	return (ptr);
}
