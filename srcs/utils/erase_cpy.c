/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:31:27 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/29 15:33:36 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

/*
* Free dst, copy src to dst, free src
*/
int	erase_cpy(char **dst, char **src)
{
	if (!src || !*src)
		return (0);
	if (*dst)
		free(*dst);
	*dst = ft_strdup(*src);
	if (!*dst)
		return (1);
	if (*src)
		free(*src);
	*src = NULL;
	return (0);
}
