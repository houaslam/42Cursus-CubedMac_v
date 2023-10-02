/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:49:56 by fadermou          #+#    #+#             */
/*   Updated: 2023/10/01 14:50:56 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update(char *sta_st)
{
	int		i;
	int		j;
	char	*st;

	j = 0;
	i = 0;
	while (sta_st[i] != '\n' && sta_st[i])
		i++;
	if (!sta_st[i])
	{
		free(sta_st);
		return (NULL);
	}
	st = malloc(sizeof(char) * (ft_stlen(sta_st) - i));
	if (!st)
		return (NULL);
	i++;
	while (sta_st[i])
		st[j++] = sta_st[i++];
	st[j] = '\0';
	free (sta_st);
	return (st);
}

char	*st_n(char *sta_st)
{
	int		i;
	char	*st;

	i = 0;
	if (!sta_st[i])
		return (NULL);
	while (sta_st[i] && sta_st[i] != '\n')
		i++;
	st = malloc(sizeof(char) * (i + 2));
	if (!st)
		return (NULL);
	i = 0;
	while (sta_st[i] != '\n' && sta_st[i])
	{
		st[i] = sta_st[i];
		i++;
	}
	if (sta_st[i] == '\n')
	{
		st[i] = sta_st[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}

char	*read_nd_join(char *st, int fd)
{
	int		read_b;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_b = 1;
	while (!ft_stchr(st, '\n') && read_b != 0)
	{
		read_b = read(fd, buff, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(buff);
			free(st);
			return (NULL);
		}
		buff[read_b] = '\0';
		st = ft_stjoin(st, buff);
	}
	free (buff);
	return (st);
}

char	*get_next_line(int fd)
{
	static char	*sta_st;
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sta_st = read_nd_join(sta_st, fd);
	if (!sta_st)
		return (NULL);
	ret_line = st_n(sta_st);
	sta_st = update(sta_st);
	return (ret_line);
}
