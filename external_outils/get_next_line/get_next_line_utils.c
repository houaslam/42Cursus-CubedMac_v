/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:48:02 by fadermou          #+#    #+#             */
/*   Updated: 2023/10/01 14:53:55 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_stlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_stchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(unsigned char)c)
		return ((char *)(s + ft_stlen(s)));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

// char	*ft_stdup(char *st)
// {
// 	int		i;
// 	char	*dup;

// 	i = -1;
// 	dup = malloc(sizeof(char) * ft_stlen(st) + 1);
// 	if (!dup)
// 		return (NULL);
// 	while (st[++i])
// 		dup[i] = st[i];
// 	dup[i] = '\0';
// 	return (dup);
// }

char	*ft_stjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*st;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	st = malloc((ft_stlen(s1) + ft_stlen(s2) + 1) * sizeof(char));
	if (st == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			st[i] = s1[i];
	while (s2[c] != '\0')
		st[i++] = s2[c++];
	st[ft_stlen(s1) + ft_stlen(s2)] = '\0';
	free(s1);
	return (st);
}
