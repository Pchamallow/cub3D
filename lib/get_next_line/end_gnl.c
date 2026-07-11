/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:58:13 by pswirgie          #+#    #+#             */
/*   Updated: 2026/02/07 12:58:13 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
* End get next line without leaks
* 1. use gnl
* fd = open(name_file, O_RDONLY);
* 	if (fd < 0)
*		return (1);
*	line = get_next_line(fd);
* 2. read until end
* end_gnl(line, fd);
*/

int	end_gnl(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

