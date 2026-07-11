/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 12:48:48 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/11 16:36:16 by pswirgie         ###   ########.fr       */
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

int	get_columns(char *file)
{
	int		fd;
	char	*line;
	int		max_len;

	max_len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line)
	{
		if (max_len <= len_no_newline(line))
			max_len = len_no_newline(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (max_len);
}

int	get_lines(char *file)
{
	int		fd;
	char	*line;
	int		end;

	end = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line)
	{
		end++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (end);
}
