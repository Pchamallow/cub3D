/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 19:01:41 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/13 14:55:59 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

// bouger index j ? pas forcmemnt vu qu ob va lire toute la string ici
static int	is_rgb()
{
	int		nb;
	nb = 0;
	while (file[i][j])
	{
		if (ft_isdigit(file[i][j]))
		{
			nb++;
			while (file[i][j] && ft_isdigit(file[i][j]))
				j++;
			j = skip_spaces
		}
		
	}
}

// verfier qu on a bien le r et g et b pour le floor et celing

/*ft_split_rgb
* take rgb for ceiling and floor
* element and content must be separated by a space else error
*/
char	**ft_split_rgb(t_data *data, char *e)
{
	char	**file;
	int		i;
	int		j;
	int		nb;
	char	**rgb;

	file = data->map.full_file;
	i = 0;
	nb = 0;
	while (file[i])
	{
		j = 1;
		if (!ft_strncmp(file[i], e, 1))
		{
			if (!file[i][j])
			{
				ft_display_error("For a element RGB is missing, usage: [e] [R], [G], [B]");
				return (NULL);
			}
			if (file[i][j] && file[i][j] != ' ')
			{
				ft_display_error("Invalid element RGB detected, usage: [e] [R], [G], [B]");
				return (NULL);
			}
			if (file[i][j] && file[i][j] == ' ')
			{
				while (file[i][j] && (file[i][j] == ' '))
					j++;
				if (!file[i][j] || !ft_isdigit(file[i][j]))// qu il y ait bien et digit et 3 chiffres
				{
					ft_display_error("Missing RGB, usage: [e] [R], [G], [B]");
					return (NULL);
				}
				is_rgb(file[i], j);
				rgb = ft_split(&file[i][j], ',');
				if (!rgb)
					ft_display_error("Split RGB - allocation memory failed");
				return (rgb);
			}
		}
		i++;
	}
	return (NULL);
}
