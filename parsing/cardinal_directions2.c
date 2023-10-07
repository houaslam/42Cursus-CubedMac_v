/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_directions2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:20:59 by macbookair        #+#    #+#             */
/*   Updated: 2023/10/04 23:28:16 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_int_dup(char *str)
{
	char		*tmp;
	char		**spl;
	long long	i;
	long long	res;

	i = 0;
	res = 0;
	tmp = NULL;
	rgb_parse(str);
	spl = ft_split(str, ',');
	while (spl[i])
	{
		tmp = ft_dup(spl[i]);
		if (ft_atoi(tmp) > 255)
			put_error("INVALID RGdB");
		res += ft_condition(tmp, i);
		free(tmp);
		i++;
	}
	if (i != 3)
		put_error("INVALID RGB");
	ft_free(spl);
	return (res);
}

int	skipp_spaces(char *str, char to_find)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == to_find)
		return (1);
	if (!str[i])
		return (-1);
	return (0);
}

void	get_start_of_map(t_directions *dir, int *s, int i)
{
	check_cardinal(dir);
	*s = i;
}

int	ea_and_colors(char *str, t_directions *dir, int *s, int i)
{
	if (!ft_strcmp(str, "EA"))
	{
		if (dir->ea)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		return (EA);
	}
	else if (!ft_strcmp(str, "F"))
	{
		if (dir->f != -1)
			put_error("TOO MANY F COLORS");
		return (F);
	}
	else if (!ft_strcmp(str, "C"))
	{
		if (dir->c != -1)
			put_error("TOO MANY C COLORS");
		return (C);
	}
	else if (!*s && skipp_spaces(str, '1'))
		get_start_of_map(dir, s, i);
	else if (!ft_strcmp(str, ";"))
		return (-2);
	else if (!skipp_spaces(str, '1'))
		put_error("MAP NOT VALID");
	return (-2);
}

void	fill_struct(t_directions **dir, char *crdl, int index)
{
	if (!crdl || !*crdl)
		return ;
	if (index == NO)
		(*dir)->no = ft_dup(crdl);
	else if (index == SO)
		(*dir)->so = ft_dup(crdl);
	else if (index == WE)
		(*dir)->we = ft_dup(crdl);
	else if (index == EA)
		(*dir)->ea = ft_dup(crdl);
	else if (index == F)
		(*dir)->f = ft_int_dup(crdl);
	else if (index == C)
		(*dir)->c = ft_int_dup(crdl);
}
