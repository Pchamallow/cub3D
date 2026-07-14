/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:56:27 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/14 17:24:18 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	unsigned char	*cpy_nptr;
	int				nbr;
	int				sign;

	i = 0;
	cpy_nptr = (unsigned char *)nptr;
	nbr = 0;
	sign = 1;
	while ((cpy_nptr[i] >= 9 && cpy_nptr[i] <= 13) || cpy_nptr[i] == ' ')
		i++;
	if (cpy_nptr[i] == '-' || cpy_nptr[i] == '+')
	{
		if (cpy_nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (cpy_nptr[i] >= '0' && cpy_nptr[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (cpy_nptr[i] - '0');
		i++;
	}
	return (nbr * sign);
}

long	ft_atol(char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
			i++;
		}
		else
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

long long	ft_atoll(char *str)
{
	long long	result;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
			i++;
		}
		else
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
