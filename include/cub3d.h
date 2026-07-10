/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:50:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/10 13:34:31 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/minilibx-linux/mlx_int.h"
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

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

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				max_width;
	int				max_height;
	t_player		player;
	t_image			image;
	t_map			map;
	t_direction	direction;
}			t_data;


int	init_full_map(t_data *data);
int	get_columns(char *file);
int	get_lines(char *file);


#endif