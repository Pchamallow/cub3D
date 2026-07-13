/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:47:41 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/13 14:57:48 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"
#include <stdlib.h>

int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	is_whitespace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	str_iswhitespaces(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (0);
	while (s && s[i])
	{
		if (!is_whitespace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_tabs(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\t' || str[i][j] == '\v'
				|| str[i][j] == '\f' || str[i][j] == '\r')
			{
				ft_printf_fd(2, RED "Error\n");
				ft_printf_fd(2, "A forbidden whitespaces is detected on line %d, only space are allowed", i);
				ft_printf_fd(2, "\n" RESET);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	fill_null(char **array, int len)
{
	int	i;

	i = 0;
	while (i < len + 1)
	{
		array[i] = NULL;
		i++;
	}
}
