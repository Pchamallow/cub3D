/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 12:48:48 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/12 17:00:43 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/get_next_line/get_next_line.h"
#include "../../../lib/libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

static int	len_no_newline(char *s)
{
	long int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	get_columns(t_data *data)
{
	int		fd;
	char	*line;
	int		max_len;

	max_len = 0;
	fd = open(data->map.file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_display_perror();
		return (1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		data->map.columns = 0;
		return (0);
	}
	while (line)
	{
		if (max_len <= len_no_newline(line))
			max_len = len_no_newline(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map.columns = max_len;
	return (0);
}

int	get_lines(t_data *data)
{
	int		fd;
	char	*line;
	int		end;

	end = 0;
	fd = open(data->map.file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_display_perror();
		return (1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		data->map.lines = 0;
		return (0);
	}
	while (line)
	{
		end++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map.lines = end;
	return (0);
}
