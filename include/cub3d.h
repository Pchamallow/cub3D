/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:50:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/14 10:18:53 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "macro.h"

# define RED "\033[38;5;1m"
# define RESET "\x1b[0m"

typedef struct s_map
{
	char		**full_file;
	char		**maze;
	char		*file_name;
	int			width;
	int			height;
	int			lines;
	int			columns;
	int			wall_missing;
	int			start_count;
	int			begin_maze;
}				t_map;

typedef struct s_direction
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}				t_direction;

typedef struct s_image
{
	char			*path;
	void			*image;
	int				value;
	int				width;
	int				height;
	int				check;
}			t_image;

typedef struct s_player
{
	int				x_start_p;
	int				y_start_p;
	int				pos_x;
	int				pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}			t_player;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}			t_color;

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
	t_direction		direction;
}			t_data;

// =============================
// FUNCTIONS
// =============================

// Parser

int		ft_args_not_valid(int ac, char **av);

// Init data

int		ft_init_game(t_data *data);
int		ft_init_data(t_data *data);
int		init_full_file(t_data *data);
int		get_lines_columns(t_data *data);
// int		is_player_start(t_data *data);
int		check_walls(t_data *data);
int		get_all_directions(t_data *data);

// Events

int		close_esc(int keycode, t_data *data);
int		close_window(t_data *data);
int		handle_keypress(int keycode, void *param);
void	ft_init_hooks(t_data *data);
int		init_maze(t_data *data);
int		is_valid_maze(t_data *data);
int		is_invalid_line(t_data *data, int i);
int		init_maze_content(t_data *data, int after_args);

// Error

void	ft_display_error(char *error_msg);
void	ft_display_perror(void);
int		ft_mlx_error(void);

// Free

void	free_all(t_data *data);
void	free_map(char **map);

// Utils

void	fill_null(char **array, int len);
int		is_whitespace(char c);
int		str_iswhitespaces(char *s);
char	**ft_split_rgb(t_data *data, char *e);
int		is_tabs(char **str);
int		skip_spaces(char *str);
int		open_fd(char *file, int *fd);
int		is_arg(char *str);

// Debug

void	print_array(char **array);
void	print_directions(t_data *data);
void	print_rgb(t_data *data);

#endif
