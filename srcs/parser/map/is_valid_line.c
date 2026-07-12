/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:05:50 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/12 14:07:13 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"

static int is_invalid_player(t_data *data, int y)
{
	char	c;
	int		j;

	j = 0;
	while (data->map.full_file[y][j])
	{
		c = data->map.full_file[y][j];
		if (c == 'N' || c == 'S' || c == 'E'
			|| c == 'W')
		{
			data->map.start_count++;
			data->player.y_start_p = y - data->map.begin_maze;
			data->player.x_start_p = j + 1;
			// printf("[DEBUG] player = %d %d\n", data->player.x_start_p, data->player.y_start_p);
			if (data->map.start_count > 1)
			{
				ft_display_error("Too many player's start positions, needed only one");
				free_all(data);
				return (1);
			}
		}
		j++;
	}
	return (0);
}

static int is_invalid_chr(t_data *data, int y)
{
	char	c;
	int		j;

	j = 0;
	while (data->map.full_file[y][j])
	{
		c = data->map.full_file[y][j];
		if (c != '0' && c != '1' && c != ' '
			&& c != 'N' && c != 'S' && c != 'E'
			&& c != 'W')
		{
			ft_display_error("Invalid character: requiered only 0, 1, spaces and N/S/E/W");
			free_all(data);
			return (1);
		}
		j++;
	}
	return (0);
}

/*is_valid_line
* - is a line full of whitespaces
* - is not 0, 1, empty space, N, S, E or W
* - too many player's start position
*/
int is_valid_line(t_data *data, int i)
{
	if (str_iswhitespaces(data->map.full_file[i]))
		return (1);
	if (is_invalid_chr(data, i))
		return (1);
	if (is_invalid_player(data, i))
		return (1);
	return (0);
}
