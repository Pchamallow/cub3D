/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_maze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 09:25:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/12 09:35:19 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	is_valid_maze(t_data *data)
{
	// regarder s il y en des lignes vides
	// ou avec des whistoaces entre deux lignes du mze

	if (!is_player_start(data))
	{
		// message errreur pas player start trouve
		return (1);
	}
	
	return (0);
}