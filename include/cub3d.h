/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:50:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/11 11:34:16 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "macro.h"

typedef struct s_map
{
	char	**full_map;
	char	**maze_map;
	char	*file_name;
	int		width;
	int		height;
	int		lines;
	int		columns;
}				t_map;

typedef struct s_direction
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}				t_direction;

typedef struct s_image
{
	char 	*path;
	void	*image;
	int		value;
	int		width;
	int		height;
	int		check;
}			t_image;

typedef struct s_player
{
	int	x_start_p;
	int	y_start_p;
	int	pos_x;
	int	pos_y;
}			t_player;

typedef struct s_color
{
	int				R;
	int				G;
	int				B;
} 			t_color;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				max_width;
	int				max_height;
	t_color			ceiling;
	t_color			floor;
	t_player		player;
	t_image			image;
	t_map			map;
	t_direction	direction;
}			t_data;

// =============================
// FUNCTIONS
// =============================

// Parser

int		args_not_valid(int ac, char **av);
int		init_full_map(t_data *data);
int		get_columns(char *file);
int		get_lines(char *file);

// Error

void	display_error(char *error_msg);
void	display_perror(void);
int		mlx_error(void);

// free

void	free_all(t_data *data);

#endif
