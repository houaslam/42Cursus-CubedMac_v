/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:29:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/07 12:51:31 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PP_HEIGHT 1000
# define PP_WIDTH 1600
# define UNIT 64
# define VIEW_D 60
# define GREY 0x414141
# define RED 0xFF0000
# define BLOOD 0xaf0404
# define BLACK 0x252525

enum {
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	DO = 4,
	F = 5,
	C = 6,
	ARROW_LEFT = 123,
	ARROW_UP = 126,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	LEFT = 0,
	UP = 13,
	RIGHT = 2,
	DOWN = 1,
	FIRE = 3,
	SPACE = 49,
	DESTROY = 53,
	SPEED = 30,
	MINI_UNIT = 15,
	DOOR = 111,
	WALL = 222,
};


typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_wall
{
	double				x;
	double				y;
	double				step_x;
	double				step_y;
}						t_wall;

typedef struct s_ray
{
	double				v_distance;
	float				alpha;
	float				ang;
	float				cast;
	int					d_x;
	int					d_y;
	double				distance;
	int					up;
	int					down;
	int					right;
	int					left;
	int					content;
}						t_ray;

typedef struct s_player
{
	double				x;
	double				y;
	double				u_x;
	double				u_y;
	int					rot_speed;
	int					mov_speed;
}						t_player;

typedef struct s_minimap
{
	int					height;
	int					width;
	t_player			mini_p;
	void				*player;
	float				x;
	float				y;
}						t_minimap;

typedef struct s_map
{
	char				**map;
	int					m_x;
	int					m_y;
	int					n_v;
	int					n_h;
	int					vert;
	float				wall_h;
	t_ray				r;
	t_wall				h;
	t_wall				v;
	t_player			p;
	t_minimap			minimap;
	t_data				img;
	t_data				mini;
	struct s_directions	*directions;
	struct s_textures	*textures;
	struct s_window		*window;
}						t_map;

typedef struct s_textures
{
	void				*img;
	int					h;
	int					w;
	int					*add;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	struct s_map		*map;
}						t_textures;

typedef struct s_directions
{
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*door;
	long long			f;
	long long			c;
	struct s_map		*map;
}						t_directions;

typedef struct s_window
{
	void				*mlx;
	void				*mlx_win;
	struct s_map		*map;
	bool				s_animation;
}						t_window;

#endif