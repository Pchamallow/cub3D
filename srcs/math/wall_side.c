/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:59:10 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/24 11:00:48 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_abs(double nb)
{
	if (nb < 0)
		nb = nb *-1;
	return (nb);
}

// cherche le rayon qui va vers les lignes verticales
// chercher les rayon vers les lignes horizontal
// si rayon horizontal < rayon vertical = c est de face
void	is_side(t_data *data)
{
	// tester echanger x et y
	double playerx = data->player.pos_y;
	double playery = data->player.pos_x;
	double	dx = data->render.wall_x - playerx;
	double	dy = data->render.wall_y - playery;
	double steps;

	if (ft_abs(dx) > ft_abs(dy))
		steps = ft_abs(dx);
	else
		steps = ft_abs(dy);

	double Xinc = dx / steps;
	double Yinc = dy / steps;
	// printf("is_side -> Xinc = %f, Yinc %f\n", Xinc, Yinc);

	if (Xinc < Yinc)
		data->render.wall_side = 1;
	else
		data->render.wall_side = 0;
	

	// float x = playerx;
	// float y = playery;

	// double i = 0;
	// while (i <= steps)
	// {
		
	// 	i++;
	// }
}
