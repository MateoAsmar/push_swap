/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:38:27 by masmar            #+#    #+#             */
/*   Updated: 2024/08/06 12:38:29 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "limits.h"

// Normal atoi
int	ft_atoi(const char	*nptr, int *error_limits)
{
	long long int	val;
	int				signe;

	*error_limits = 0;
	val = 0;
	signe = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+' )
	{
		if (*nptr == '-')
			signe = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		val = val * 10 + signe * (*nptr - '0');
		if (val > INT_MAX || val < INT_MIN
			|| (!val && (*nptr == '-' || *nptr == '+')))
			*error_limits = 1;
		nptr++;
	}
	if (*nptr && *nptr != ' ' && !(*nptr >= '0' && *nptr <= '9'))
		*error_limits = 1;
	return (val);
}

// Normal strlen
size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
  