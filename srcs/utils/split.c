/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 19:01:41 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/13 15:42:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

static void	print_invalid_rgb(void)
{
	ft_display_error("Invalid format element RGB detected, "
		"usage: [e] [R], [G], [B]");
}

static int	is_invalid_numbers(char *file, int *j, int *nb)
{
	int	len;

	len = 0;
	while (file[*j] && ft_isdigit(file[*j]))
	{
		len++;
		*j += 1;
	}
	*j += skip_spaces(&file[*j]);
	if (len > 3 || (*nb < 3 && (file[*j] != ','
				|| !ft_isdigit(file[*j + 1 + skip_spaces(&file[*j + 1])]))))
	{
		print_invalid_rgb();
		return (1);
	}
	if (*nb == 3 && file[*j] && file[*j] != '\n')
	{
		ft_display_error("Content after element RGB"
			" detected, usage: [e] [R], [G], [B]");
		return (1);
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
		print_invalid_rgb();
		return (1);
	}
	return (0);
}

static char	**get_rgb(char *file, int *j)
{
	char	**rgb;

	if (file[*j] != ' ')
	{
		print_invalid_rgb();
		return (NULL);
	}
	*j += skip_spaces(&file[*j]);
	if (!file[*j] || !ft_isdigit(file[*j]))
	{
		print_invalid_rgb();
		return (NULL);
	}
	if (is_invalid_rgb(file, *j))
		return (NULL);
	rgb = ft_split(&file[*j], ',');
	if (!rgb)
		ft_display_error("Split RGB - allocation memory failed");
	return (rgb);
}

/*ft_split_rgb
* take rgb for ceiling and floor
* element and content must be separated by a space else error
*/
char	**ft_split_rgb(t_data *data, char *e)
{
	char	**file;
	int		i;
	int		j;

	file = data->map.full_file;
	i = 0;
	while (file[i])
	{
		j = 1;
		if (!ft_strncmp(file[i], e, 1))
			return (get_rgb(file[i], &j));
		i++;
	}
	ft_printf_fd(2, RED "Error\n");
	ft_printf_fd(2, "Missing element: %s,"
		" usage: [%s] [R], [G], [B]", e, e);
	ft_printf_fd(2, "\n" RESET);
	return (NULL);
}
