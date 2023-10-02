
#include "parsing.h"

long long	ft_condition(char *str, int i)
{
	if (i == 0)
		return (ft_atoi(str) << 16);
	if (i == 1)
		return (ft_atoi(str) << 8);
	if (i == 2)
		return (ft_atoi(str));
	return (0);
}

int	ft_int_dup(char *str)
{
	char	*tmp;
	char	**spl;
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

int	ea_and_colors(char *str, t_directions *dir, int *s, int i)
{
	(void)i;
    if (!ft_strcmp(str, "EA"))
	{
		if (dir->ea)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		return (EA);
	}
	else if (!ft_strcmp(str, "F"))
	{
		if (dir->f != -1)
			put_error("TOO MANY F COLORS");////F ??
		return (F);//// protect numb
	}
	else if (!ft_strcmp(str, "C"))
	{
		if (dir->c != -1)////repars it
			put_error("TOO MANY C COLORS");////C ??
		return (C);//// protect numb
	}
	else if (!*s && skipp_spaces(str, '1'))
	{
		check_cardinal(dir);
		*s = i;
	}
	else if (!ft_strcmp(str, ";"))
		return (-2);
	else if (!skipp_spaces(str, '1'))
	{
		put_error("MAP NOT VALID");
	}
	return (-2);
}

void	fill_struct(t_directions **dir, char *crdl, int index)
{
	if (!crdl || !*crdl)
		return;
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
