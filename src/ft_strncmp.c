/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:59:40 by sdelardi          #+#    #+#             */
/*   Updated: 2015/12/11 15:52:05 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (*str1 && *str2 && n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	if (*str2 && *str1 == '\0' && n != 0)
		return (-*str2);
	else if (*str1 && *str2 == '\0' && n != 0)
		return (*str1);
	else
		return (0);
}
