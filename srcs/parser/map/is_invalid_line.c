/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:05:50 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/23 13:19:19 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"

static int	is_invalid_player(t_data *data, int y)
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
			data->player.y_start_p = y - data->map.begin_maze + 1;
			data->player.x_start_p = j + 1;
			data->player.pos_y = data->player.y_start_p;
			data->player.pos_x = data->player.x_start_p;
			// printf("[DEBUG] - start pos player =  y : %f"
			// 	"  x : %f\n", data->player.pos_y, data->player.pos_x);
			if (data->map.start_count > 1)
			{
				ft_display_error("Too many player starting"
					" positions, only one is allowed");
				return (1);
			}
		}
		j++;
	}
	return (0);
}

static int	is_invalid_chr(t_data *data, int y)
{
	char	c;
	int		j;

	j = 0;
	while (data->map.full_file[y][j])
	{
		c = data->map.full_file[y][j];
		if (c != '0' && c != '1' && c != '\n' && c != ' '
			&& c != 'N' && c != 'S' && c != 'E'
			&& c != 'W')
		{
			ft_printf_fd(2, RED "Error\n");
			if (is_whitespace(c))
				ft_printf_fd(2, RED "Invalid character"
					" found: [whitespace]\n");
			else
				ft_printf_fd(2, RED "Invalid character "
					"found: %c\n", c);
			ft_printf_fd(2, "(only 0, 1, spaces "
				"and N/S/E/W are allowed)\n" RESET);
			return (1);
		}
		j++;
	}
	return (0);
}

/*is_invalid_line
* - is a line full of whitespaces
* - is not 0, 1, empty space, N, S, E or W
* - too many player's start position
*/
int	is_invalid_line(t_data *data, int i)
{
	if (!data->map.full_file[i])
		return (0);
	if (str_iswhitespaces(data->map.full_file[i]))
	{
		ft_display_error("Invalid map: empty lines are not allowed");
		return (1);
	}
	if (is_invalid_chr(data, i))
		return (1);
	if (is_invalid_player(data, i))
		return (1);
	return (0);
}
