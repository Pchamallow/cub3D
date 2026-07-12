/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_maze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 09:25:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/12 13:59:07 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	is_valid_maze(t_data *data)
{
	// regarder s il y en des lignes vides
	// ou avec des whistoaces entre deux lignes du mze
	if (!data->map.start_count)
	{
		// message errreur pas player start trouve
		ft_display_error("Player start is missing");
		free_all(data);
		return (1);
	}
	if (check_walls(data))
		return (1);
	
	return (0);
}