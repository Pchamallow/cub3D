/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:21:40 by pswirgie          #+#    #+#             */
/*   Updated: 2026/02/07 12:12:12 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*calloc_modifs(size_t nmemb, size_t size)
{
	char	*tab;

	if ((nmemb * size) > ((size_t)-1))
		return (NULL);
	tab = (char *)malloc(sizeof(char) * (nmemb * size));
	if (tab == NULL)
		return (NULL);
	bzero_modifs(tab, (nmemb * size));
	return (tab);
}

void	bzero_modifs(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *) s;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
	s = tmp;
}

char	*strdup_modifs(char *src)
{
	char	*create_tab;
	int		i;

	i = 0;
	create_tab = (char *)malloc(sizeof(char) * (strlen_modifs(src) + 1));
	if (create_tab == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		create_tab[i] = src[i];
		i++;
	}
	create_tab[i] = '\0';
	return (create_tab);
}

char	*strjoin_modifs(char *s1, char *s2)
{
	char	*tab;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = strlen_modifs(s1) + strlen_modifs(s2);
	tab = calloc_modifs(len + 1, 1);
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	return (tab);
}

char	*substr_modifs(char *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		len_s;
	char		*sb;

	i = (size_t) start;
	j = 0;
	len_s = strlen_modifs(s);
	if (start >= len_s)
	{
		sb = (char *)calloc_modifs(sizeof(char), 1);
		return (sb);
	}
	if (len > len_s - start)
		len = len_s - start;
	sb = (char *)calloc_modifs(sizeof(char), len + 1);
	if (sb == NULL)
		return (NULL);
	while (s[i] && j < len)
		sb[j++] = s[i++];
	sb[j] = '\0';
	return (sb);
}
