/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:17:31 by sdelardi          #+#    #+#             */
/*   Updated: 2016/01/07 14:45:46 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_separate(char *rest, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	if (rest[i] == '\n' || rest[i] == EOF)
	{
		tmp = ft_strdup(rest + i + 1);
		ft_memset(rest, '\0', (BUFF_SIZE + 1));
		ft_strcpy(rest, tmp);
		ft_strdel(&tmp);
		while (line[i] != '\0' && i < BUFF_SIZE)
		{
			line[i] = '\0';
			i++;
		}
		return (line[i] == '\0' ? 1 : 0);
	}
	return (-1);
}

char	*ft_realloc(char *str, int n)
{
	char	*tmp;

	tmp = str;
	str = ft_strnew(ft_strlen(tmp) + n + 1);
	if (str)
	{
		ft_strcpy(str, tmp);
		free(tmp);
		return (str);
	}
	else
		return (tmp);
}

char	*parcourt_buffer(char *buffer, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
		i++;
	while (buffer[j] != '\n' && buffer[j] != EOF && j < BUFF_SIZE)
	{
		line[i] = buffer[j];
		i++;
		j++;
	}
	line[i] = '\0';
	return (buffer);
}

int		stock_rest(char *buffer, char *rest)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != EOF && i < BUFF_SIZE)
		i++;
	if (buffer[i] == EOF)
		return (0);
	else if (i == BUFF_SIZE)
		return (-1);
	else
	{
		while (rest[j] != '\0')
			j++;
		if (buffer[i] == '\n')
			i++;
		while (i < BUFF_SIZE && buffer[i] != EOF)
			rest[j++] = buffer[i++];
		while (j <= BUFF_SIZE)
			rest[j++] = '\0';
		return (1);
	}
}

int		get_next_line(int const fd, char **line)
{
	static char	rest[BUFF_SIZE * 2 + 1];
	char		buffer[BUFF_SIZE];
	int			r_value;

	if (fd == 1 || line == 0)
		return (-1);
	if (rest[0] != '\0')
	{
		*line = ft_strdup(rest);
		if ((r_value = ft_separate(rest, *line)) >= 0)
			return (r_value);
		*line = ft_realloc(*line, BUFF_SIZE);
	}
	else
		*line = ft_strnew(BUFF_SIZE + 1);
	ft_memset(buffer, '\0', BUFF_SIZE);
	ft_memset(rest, '\0', BUFF_SIZE * 2 + 1);
	while ((r_value = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		*line = ft_realloc(*line, BUFF_SIZE);
		if ((r_value = stock_rest(parcourt_buffer(buffer, *line), rest)) >= 0)
			return (r_value + ((int)(ft_memset(buffer, '\0', BUFF_SIZE)) * 0));
		ft_memset(buffer, '\0', BUFF_SIZE);
	}
	return (r_value);
}
