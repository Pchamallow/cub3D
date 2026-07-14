/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 16:26:33 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/14 11:56:26 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"
#include <fcntl.h>

void	print_invalid_args(void)
{
	ft_display_error("Invalid format direction detected, "
		"usage: [direction (2 letters)] [./path]");
}

int	is_space_or_nl(char c)
{
	if (c && (c == ' ' || c == '\n'))
		return (1);
	return (0);
}

int	is_arg(char *str)
{
	if (!ft_strncmp(str, "NO", 2)
		|| !ft_strncmp(str, "SO", 2)
		|| !ft_strncmp(str, "WE", 2)
		|| !ft_strncmp(str, "EA", 2)
		|| !ft_strncmp(str, "F", 1)
		|| !ft_strncmp(str, "C", 1))
		return (1);
	return (0);
}

int	open_fd(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		ft_display_perror();
		return (1);
	}
	return (0);
}
