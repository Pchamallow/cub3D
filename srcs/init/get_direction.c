/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:28:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/14 11:53:09 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

static void	print_invalid_args(void)
{
	ft_display_error("Invalid format direction detected, "
		"usage: [direction (2 letters)] [./path]");
}



static int	len_path(t_data *data, int i, int *j)
{
	int	len_dir;

	len_dir = 0;
	while (is_space_or_newline(data->map.full_file[i][*j]))
	{
		len_dir++;
		*j += 1;
	}
	if (len_dir == 0)
	{
		print_invalid_args();
		return (-1);
	}
	while (data->map.full_file[i][*j])
	{
		if (is_space_or_newline(data->map.full_file[i][*j]))
		{
			ft_display_error("Content after path argument forbidden");
			return (-1);
		}
		*j += 1;
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
	if ((data->map.full_file[i][*j]
		&& !ft_strnstr(&data->map.full_file[i][*j], "./", 2))
		|| !data->map.full_file[i][*j] || !data->map.full_file[i][*j + 1])
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
	int		j;

	j = 2;
	len_dir = 0;
	file = data->map.full_file;
	if (ft_strnstr(file[i], dir, 2))
	{
		dir_handle_error(data, i, &j);
		if (j == -1)
			return (-1);
		len_dir = len_path(data, i, &j);
		if (len_dir == -1)
			return (-1);
		*ret = ft_substr(file[i], j - len_dir - 1, len_dir);
		if (!*ret)
		{
			ft_display_error("Get direction - allocation memory failed");
			return (-1);
		}
		return (1);
	}
	return (0);
}

/* get_direction
* only space are allowed between informations
* Information have to be seperated by at least one space
*/
static char *get_direction(t_data *data, char *dir)
{
	char	**file;
	char	*ret;
	int		is_find;
	int		i;
	
	i = 0;
	file = data->map.full_file;
	ret = NULL;
	while (file[i])
	{
		is_find = search_direction(data, i, dir, &ret);
		if (is_find == -1)
			return (NULL);
		else if (is_find == 1)
			return (ret);
		else
			i++;
	}
	ft_printf_fd(2, RED "Error\n");
	ft_printf_fd(2, "Missing at least one argument: %s, usage: [%s] [./path]", dir, dir);
	ft_printf_fd(2, "\n" RESET);
	return (NULL);
}

int	get_all_directions(t_data *data)
{
	data->direction.no = get_direction(data, "NO");
	if (!data->direction.no)
		return (1);
	data->direction.so = get_direction(data, "SO");
	if (!data->direction.so)
		return (1);
	data->direction.we = get_direction(data, "WE");
	if (!data->direction.we)
		return (1);
	data->direction.ea = get_direction(data, "EA");
	if (!data->direction.ea)
		return (1);
	// print_directions(data);
	return (0);
}
