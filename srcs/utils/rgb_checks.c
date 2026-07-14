/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:14:01 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/14 17:40:27 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/cub3d.h"

int	secure_rgb(long rgb)
{
	if (rgb < 0 || rgb > 255)
	{
		ft_display_error("rgb not between 0 and 255");
		return (-1);
	}
	return (rgb);
}

int	check_double_rgb(t_data *data, char *e)
{
	char	**file;
	int		i;
	int		exist;

	file = data->map.full_file;
	i = 0;
	while (file[i])
	{
		if (exist)
		{
			ft_display_error("multiple same rgb detected, \
				please use only one C and one F");
			return (1);
		}
		if (!ft_strncmp(file[i], e, 1))
			exist = 1;
		i++;
	}
	return (0);
}