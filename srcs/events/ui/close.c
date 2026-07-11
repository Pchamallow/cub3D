/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:11:44 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/11 16:32:46 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include <stdlib.h>

int	close_esc(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		free_all(data);
		exit(0);
	}
	return (0);
}

int	close_window(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}
