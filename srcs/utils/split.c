/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 19:01:41 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/13 15:30:22 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

static int	is_invalid_numbers(char *file, int *j, int *nb)
{
	while (file[*j] && ft_isdigit(file[*j]))
		*j += 1;
	*j += skip_spaces(&file[*j]);
	if (*nb < 3 && file[*j] != ',')
	{
		ft_display_error("Invalid format element RGB detected, usage: [e] [R], [G], [B]");
		return (1);
	}
	else if (*nb == 3)
	{
		*j += skip_spaces(&file[*j]);
		if (file[*j] && file[*j] != '\n')
		{
			ft_display_error("Content after element RGB detected, usage: [e] [R], [G], [B]");
			return (1);
		}
	}
	return (0);
}

/* is_valid_rgb
* - check format : [digit] [,] [digit] [,] [digit]
* (can be seperated by spaces)
* - check have 3 numbers
* - after RGB = spaces or end of file
*/
static int	is_invalid_rgb(char *file, int j)
{
	int	nb;

	nb = 0;
	while (file[j])
	{
		if (nb == 3)
			return (0);
		if (ft_isdigit(file[j]))
		{
			nb++;
			if (is_invalid_numbers(file, &j, &nb))
				return (1);
		}
		j++;
	}
	if (nb != 3)
	{
		ft_display_error("Invalid format element RGB detected, usage: [e] [R], [G], [B]");
		return (1);
	}
	return (0);
}


static char **get_rgb(char *file, int *j)
{
	char	**rgb;

	rgb = NULL;
	if (file[*j] && file[*j] == ' ')
	{
		*j += skip_spaces(&file[*j]);
		if (!file[*j] || !ft_isdigit(file[*j]))
		{
			ft_display_error("Missing RGB, usage: [e] [R], [G], [B]");
			return (NULL);
		}
		if (is_invalid_rgb(file, *j))
			return (NULL);
		rgb = ft_split(&file[*j], ',');
		if (!rgb)
			ft_display_error("Split RGB - allocation memory failed");
		return (rgb);
	}
	return (rgb);
}

/*ft_split_rgb
* take rgb for ceiling and floor
* element and content must be separated by a space else error
*/
char	**ft_split_rgb(t_data *data, char *e)
{
	char	**file;
	char	**rgb;
	int		i;
	int		j;
	int		nb;

	file = data->map.full_file;
	i = 0;
	nb = 0;
	while (file[i])
	{
		j = 1;
		if (!ft_strncmp(file[i], e, 1))
		{
			if (!file[i][j] || (file[i][j] && file[i][j] != ' '))
			{
				ft_display_error("Invalid format element RGB detected, usage: [e] [R], [G], [B]");
				return (NULL);
			}
			rgb = get_rgb(file[i], &j);
			return (rgb);
		}
		i++;
	}
	return (NULL);
}
