/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:35:08 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/11 09:41:35 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

void	display_eerror(char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putchar_fd('\n', 2);
}

void	display_perror(void)
{
	ft_putstr_fd("Error\n", 2);
	perror("Message from perror ");
}

int	ft_mlx_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("MLX failed\n", 2);
	return (1);
}
