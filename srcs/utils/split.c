/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 19:01:41 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/12 19:05:56 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

char	**ft_split_rgb(t_data *data, char *e)
{
	char	**file;
	int		i;
	int		j;
	char	**rgb;

	file = data->map.full_file;
	i = 0;
	while (file[i])
	{
		j = 1;
		if (!ft_strncmp(file[i], e, 1)
			&& (file[i][j] == ' ' || ft_isdigit(file[i][j])))
			// voir si besoin securiser contre collage F et RGB
		{
			while (file[i][j] && (file[i][j] == ' '))
				j++;
			rgb = ft_split(&file[i][j], ',');
			return rgb;
		}
		i++;
	}
	return (0);
}
