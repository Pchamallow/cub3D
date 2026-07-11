/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 13:57:08 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/11 16:30:55 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

static int	ft_str_format(char *str, char *sub)
{
	size_t	len;
	size_t	sub_len;

	if (!str || !sub || !sub[0])
		return (0);
	len = ft_strlen(str);
	sub_len = ft_strlen(sub);
	if (len <= sub_len || str[len - sub_len - 1] == '/')
		return (0);
	if (ft_strncmp(str + len - sub_len, sub, sub_len + 1) == 0)
		return (1);
	return (0);
}

static int	map_invalid_format(char *map_str)
{
	if (!map_str || !map_str[0])
	{
		ft_display_error("Empty map.");
		return (1);
	}
	if (!ft_str_format(map_str, ".cub"))
	{
		ft_display_error("Invalid map format, please use '.cub'");
		return (1);
	}
	return (0);
}

int	ft_args_not_valid(int ac, char **av)
{
	if (ac != 2)
	{
		ft_display_error("We accept only one arg that must be in .cub");
		return (1);
	}
	if (map_invalid_format(av[1]))
		return (1);
	return (0);
}
