/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 09:36:44 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/12 19:06:09 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"

static void	*init_window(t_data *data)
{
	void	*ptr;

	data->height = HEIGHT_WINDOW;
	data->width = WIDTH_WINDOW;
	ptr = mlx_new_window(data->mlx, data->width, data->height, "cub3d");
	return (ptr);
}

int	ft_init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_mlx_error();
		return (1);
	}
	data->win = init_window(data);
	if (!data->win)
	{
		ft_mlx_error();
		return (1);
	}
	ft_init_hooks(data);
	return (0);
}

static char *get_direction(t_data *data, char *dir)
{
	char	**file;
	int		i;
	int		j;
	int		len_dir;
	char	*ret;
	
	file = data->map.full_file;
	i = 0;
	len_dir = 0;
	while (file[i])
	{
		j = 2;
		if (ft_strnstr(file[i], dir, 2)) // voir protection coller NO et son path ok ou non
		{
			while (file[i][j] && (file[i][j] == ' '))
				j++;
			while (file[i][j++] && (file[i][j] != ' ' || file[i][j] != '\n'))
				len_dir++;
			ret = ft_substr(file[i], j - len_dir - 1, len_dir);
			// ft_printf_fd(2, "ret = %s", ret);
			return (ret);
		}
		i++;
	}
	return NULL;
}

static int	init_rgb(t_data *data)
{
	char **floor;
	char **ceiling;
	
	floor =ft_split_rgb(data, "F");
	if (!floor)
		return (1);
	ceiling = ft_split_rgb(data, "C");
	if (!ceiling)
		return (1);
	data->ceiling.r = ft_atol(ceiling[0]);
	data->ceiling.g = ft_atol(ceiling[1]); 
	data->ceiling.b = ft_atol(ceiling[2]); 

	data->floor.r = ft_atol(floor[0]); 
	data->floor.g = ft_atol(floor[1]); 
	data->floor.b = ft_atol(floor[2]); 
	// ajouter securite max et min
	free_map(floor);
	free_map(ceiling);
	return (0);
}

int	ft_init_data(t_data *data)
{
	if (init_full_file(data))
		return (1);
	// rajouter print message error si direction null
	data->direction.no = get_direction(data, "NO");
	data->direction.so = get_direction(data, "SO");
	data->direction.we = get_direction(data, "WE");
	data->direction.ea = get_direction(data, "EA");
	if (init_rgb(data))
		return (1);

	// print_array(data->map.full_file);
	// ft_printf_fd(2, "-------\n");

	if (init_maze(data))
		return (1);
	
	// ft_printf_fd(2, "\n[DEBUG] map after check walls :\n");
	// print_array(data->map.maze);
	// ft_printf_fd(2, "-------\n");

	if (is_valid_maze(data))
		return (1);

	

	return (0);
}
