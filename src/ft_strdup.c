/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:52:31 by sdelardi          #+#    #+#             */
/*   Updated: 2015/12/11 15:51:48 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	s2 = ft_strnew(ft_strlen(s1));
	if (s2 != NULL)
		ft_strcpy(s2, s1);
	return (s2);
}
