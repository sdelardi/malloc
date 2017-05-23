/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:04:55 by sdelardi          #+#    #+#             */
/*   Updated: 2015/12/11 15:52:12 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strnew(size_t size)
{
	char			*ptr;
	unsigned int	i;

	ptr = malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
