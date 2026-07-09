/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:21:36 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/09 16:42:20 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../lib/libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

void	*calloc_modifs(size_t nmemb, size_t size);
void	bzero_modifs(void *s, size_t n);
char	*strdup_modifs(char *src);
char	*strjoin_modifs(char *s1, char *s2);
char	*substr_modifs(char *s, unsigned int start, size_t len);
size_t	strlen_modifs(const char *s);
char	*get_next_line(int fd);
int		end_gnl(char *line, int fd);

#endif
