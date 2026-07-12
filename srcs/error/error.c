/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:35:08 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/12 17:02:19 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

void	ft_display_error(char *error_msg)
{
	ft_printf_fd(2, RED "Error\n");
	ft_putstr_fd(error_msg, 2);
	ft_printf_fd(2, "\n" RESET);
}

void	ft_display_perror(void)
{
	ft_printf_fd(2, RED "Error\n");
	perror("Message from perror ");
	ft_printf_fd(2, RESET);
}

int	ft_mlx_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("MLX failed\n", 2);
	return (1);
}
