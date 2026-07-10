/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 13:57:08 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/10 17:25:06 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

static int	ft_str_format(char *string, char *sub_string)
{
	int	start;
	int	k;
	int	len_sub;
	int	len_string;

	if (!sub_string || !sub_string[0] || !string || !string[0])
		return (0);
	len_sub = ft_strlen(sub_string);
	len_string = ft_strlen(string);
	start = len_string - len_sub;
	k = 0;
	while (string[start])
	{
		if (string[start++] == sub_string[k++])
		{
			if (sub_string[k] == '\0')
				return (1);
		}
		else
		{
			start = start - k + 1;
			k = 0;
		}
	}
	return (0);
}

static int	map_invalid_format(char *map_str)
{
	if (!map_str || !map_str[0])
	{
		display_error("Empty map.");
		return (1);
	}
	if (!ft_str_format(map_str, ".cub"))
	{
		display_error("Invalid map format, please use '.cub'");
		return (1);
	}
	return (0);
}

int	args_not_valid(int ac, char **av)
{
	if (ac != 2)
	{
		display_error("We accept only one arg that must be in .cub");
		return (1);
	}
	if (map_invalid_format(av[1]))
		return (1);
	return (0);
}

