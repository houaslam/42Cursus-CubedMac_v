# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hajarouaslam <hajarouaslam@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 12:53:10 by houaslam          #+#    #+#              #
#    Updated: 2023/10/02 21:55:53 by hajarouasla      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
CC =  gcc -Wall -Werror -Wextra #-fsanitize=address -g3  
CFLAGS = -I/usr/include -Imlx_linux -O3 -Wall -Werror -Wextra 
EXTRA_FLAGS =  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

E_SRCS = external_outils/libft/ft_atoi.c \
       	 external_outils/libft/ft_isprint.c \
    	 external_outils/libft/ft_putchar_fd.c \
 		 external_outils/libft/ft_strdup.c \
		 external_outils/libft/ft_strncmp.c \
		 external_outils/libft/ft_bzero.c \
      	 external_outils/libft/ft_itoa.c \
       	 external_outils/libft/ft_putendl_fd.c \
 		 external_outils/libft/ft_striteri.c \
   		 external_outils/libft/ft_strnstr.c \
		 external_outils/libft/ft_calloc.c \
      	 external_outils/libft/ft_memchr.c \
      	 external_outils/libft/ft_putnbr_fd.c \
		 external_outils/libft/ft_strjoin.c \
    	 external_outils/libft/ft_strrchr.c \
		 external_outils/libft/ft_isalnum.c \
    	 external_outils/libft/ft_memcmp.c \
     	 external_outils/libft/ft_putstr_fd.c \
  		 external_outils/libft/ft_strlcat.c \
    	 external_outils/libft/ft_strtrim.c \
		 external_outils/libft/ft_isalpha.c \
    	 external_outils/libft/ft_memcpy.c \
     	 external_outils/libft/ft_split.c \
      	 external_outils/libft/ft_strlcpy.c \
    	 external_outils/libft/ft_substr.c \
		 external_outils/libft/ft_isascii.c \
    	 external_outils/libft/ft_memmove.c \
    	 external_outils/libft/ft_strchr.c \
     	 external_outils/libft/ft_strlen.c \
     	 external_outils/libft/ft_tolower.c \
		 external_outils/libft/ft_isdigit.c \
    	 external_outils/libft/ft_memset.c \
     	 external_outils/libft/ft_strmapi.c \
    	 external_outils/libft/ft_toupper.c \

R_SRCS = 	raycasting/distances.c \
			raycasting/raycasting.c \
	    	raycasting/player.c \
	    	raycasting/quadrant.c \

REND_SRCS = rendering/render_setup.c \
	    	rendering/minimap.c \
	    	rendering/mini_quadrant.c \
			rendering/loads_textures.c \
	    	rendering/animation.c \

P_SRCS = parsing/cardinal_directions2.c \
		parsing/cardinal_directions.c \
		parsing/player_position.c \
		parsing/map_dimension.c \
		parsing/map_parsing.c \
		parsing/read_map.c \
		parsing/parsing.c \
		parsing/rgb_parse.c \
		main.c

O_SRCS = external_outils/get_next_line/get_next_line.c \
		 external_outils/get_next_line/get_next_line_utils.c \
		 

OBJ =  ${P_SRCS:.c=.o} ${T_SRCS:.c=.o} ${O_SRCS:.c=.o} ${R_SRCS:.c=.o} ${REND_SRCS:.c=.o} ${E_SRCS:.c=.o}

all : ${NAME}

$(NAME): $(OBJ)
	gcc $(OBJ) libmlx.a  -framework OpenGL -framework AppKit -o $(NAME)


clean :
	rm -rf ${OBJ}
fclean : clean
	rm -rf ${NAME}

re : fclean all

push :
	git add .
	git commit -m cube
	git push
