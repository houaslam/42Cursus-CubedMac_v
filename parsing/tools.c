/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:09:29 by macbookair        #+#    #+#             */
/*   Updated: 2023/10/04 23:29:10 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	put_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_is_valid(char c)
{
	if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '0' && c != '1'
		&& c != ' ' && c != 'D')
		return (1);
	return (0);
}

int	ft_is_player(char c)
{
	if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '0' && c != 'D')
		return (1);
	return (0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
