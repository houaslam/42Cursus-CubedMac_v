/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:57:23 by fadermou          #+#    #+#             */
/*   Updated: 2023/09/22 13:07:20 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <string.h>
# include <stdlib.h>
# include "../cube.h"
# include "../external_outils/libft/libft.h"
# include "../external_outils/get_next_line/get_next_line.h"

void	player_position(t_map **map, int i);
void    parsing(t_map *map, char **av);
void    map_dimension(t_map **map, int i);
void	read_map(t_map **map, char **av);
void	cardinal_directions(t_map **map, int *s);
void	fill_struct(t_directions **dir, char *crdl, int index);
void    map_parsing(t_map **map);
// void	ea_and_colors(char **str, t_directions *dir, int *s, int i);
int 	ea_and_colors(char *str, t_directions *dir, int *s, int i);
int     ft_is_space(char c);
char	*ft_dup(char *str);
int     skipp_spaces(char *str, char to_find);
void	check_cardinal(t_directions *dir);
void    rgb_parse(char *str);
//      TOOLS
void	put_error(char *str);
int	    str_lenght(char **str);
void	ft_free(char **str);

#endif
