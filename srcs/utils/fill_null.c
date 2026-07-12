/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:47:41 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/12 16:19:48 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
