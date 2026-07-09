/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:14:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/09 16:43:01 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int main (int ac, char **av)
{
	char	*line;
	int	fd;

	(void)av;
	if (ac != 1)
		return (1); // message error to print

	fd = open("/home/pswirgie/Documents/04_Milestone_04/cub3d/assets/minimalist.cub", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	printf("%s\n", line);
	end_gnl(line, fd);
}
