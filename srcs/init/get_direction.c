/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:28:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/30 10:10:46 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

static int	len_path(t_data *data, int i, int *j)
{
	int	len_dir;

	len_dir = 0;
	while (data->map.full_file[i][*j]
		&& !is_space_or_nl(data->map.full_file[i][*j]))
	{
		len_dir++;
		*j += 1;
	}
	if (len_dir == 0)
	{
		print_invalid_args();
		return (-1);
	}
	while (is_space_or_nl(data->map.full_file[i][*j]))
		*j += 1;
	if (data->map.full_file[i][*j])
	{
		ft_display_error("Content after path argument forbidden");
		return (-1);
	}
	return (len_dir);
}

/* dir_handle_error
* no spaces between the dir and the path = error
* skip spaces
* no character or "./" = error
*/
static void	dir_handle_error(t_data *data, int i, int *j)
{
	if (data->map.full_file[i][*j] != ' ')
	{
		print_invalid_args();
		*j = -1;
		return ;
	}
	while (data->map.full_file[i][*j] && (data->map.full_file[i][*j] == ' '))
		*j += 1;
	if (!data->map.full_file[i][*j] || !data->map.full_file[i][*j + 1])
	{
		print_invalid_args();
		*j = -1;
		return ;
	}
}

static int	search_direction(t_data *data, int i, char *dir, char **ret)
{
	char	**file;
	int		len_dir;
	int		start;
	int		j;

	j = 2;
	file = data->map.full_file;
	if (ft_strncmp(file[i], dir, 2) != 0)
		return (0);
	dir_handle_error(data, i, &j);
	if (j == -1)
		return (-1);
	start = j;
	len_dir = len_path(data, i, &j);
	if (len_dir == -1)
		return (-1);
	*ret = ft_substr(file[i], start, len_dir);
	if (!*ret)
	{
		ft_display_error("Get direction - allocation memory failed");
		return (-1);
	}
	data->is_find += 1;
	return (1);
}

static int	error_directions(t_data *data, char *dir, int *i)
{
	if (*i == data->map.begin_maze - 1)
	{
		if (!data->is_find)
		{
			ft_printf_fd(2, RED "Error\n");
			ft_printf_fd(2, "Before the maze, missing at least one"
				" argument: %s, usage: [%s] [./path]", dir, dir);
			ft_printf_fd(2, "\n" RESET);
			return (1);
		}
		else if (data->is_find == 1)
			return (0);
		else if (data->is_find > 1)
		{
			ft_printf_fd(2, RED "Error\n");
			ft_printf_fd(2, "Too many argument :"
				" %s, usage: [%s] [./path]", dir, dir);
			ft_printf_fd(2, "\n" RESET);
			return (1);
		}
	}
	return (0);
}

/* get_direction
* only space are allowed between informations
* Information have to be seperated by at least one space
*/
static char	*get_direction(t_data *data, char *dir)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	ret = NULL;
	tmp = NULL;
	data->is_find = 0;
	while (data->map.full_file[i] && i < data->map.begin_maze)
	{
		if (search_direction(data, i, dir, &tmp) == -1
			|| erase_cpy(&ret, &tmp)
			|| error_directions(data, dir, &i))
		{
			if (ret)
				free(ret);
			return (NULL);
		}
		else
			i++;
	}
	return (ret);
}

int	get_all_directions(t_data *data)
{
	data->north.path = get_direction(data, "NO");
	if (!data->north.path)
		return (1);
	data->south.path = get_direction(data, "SO");
	if (!data->south.path)
		return (1);
	data->weast.path = get_direction(data, "WE");
	if (!data->weast.path)
		return (1);
	data->east.path = get_direction(data, "EA");
	if (!data->east.path)
		return (1);
	return (0);
}
