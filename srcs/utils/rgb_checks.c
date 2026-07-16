/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:14:01 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/16 15:04:11 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../include/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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
	int		count;

	file = data->map.full_file;
	i = 0;
	count = 0;
	while (file[i])
	{
		if (!ft_strncmp(file[i], e, ft_strlen(e)))
			count++;
		i++;
	}
	if (count > 1)
	{
		ft_display_error("multiple same rgb detected,"
			" please use only one C and one F");
		return (1);
	}
	return (0);
}
