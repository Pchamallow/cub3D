/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 12:48:48 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/13 16:30:18 by pswirgie         ###   ########.fr       */
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

static int	is_line(t_data *data, char **line, int fd)
{
	*line = get_next_line(fd);
	if (!*line)
	{
		close(fd);
		data->map.lines = 0;
		return (0);
	}
	return (1);
}

int	get_lines_columns(t_data *data)
{
	int		fd;
	char	*line;
	int		end;
	int		max_len;

	end = 0;
	max_len = 0;
	line = NULL;
	if (open_fd(data->map.file_name, &fd))
		return (1);
	if (!is_line(data, &line, fd))
		return (0);
	while (line)
	{
		if (max_len <= len_no_newline(line))
			max_len = len_no_newline(line);
		end++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map.lines = end;
	data->map.columns = max_len;
	return (0);
}
