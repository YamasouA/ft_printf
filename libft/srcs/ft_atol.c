/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:51:49 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 16:06:52 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	space(const char *str)
{
	if (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		return (1);
	else
		return (0);
}

static	int	overflow(const char str, long i, int sign)
{
	long long	temp;

	temp = i * 10 + sign * (str - '0');
	temp -= sign * (str - '0');
	temp /= 10;
	if (temp == i)
		return (1);
	else
		return (0);
}

long long	ft_atol(const char *str)
{
	long long	i;
	int		sign;

	i = 0;
	sign = 1;
	while (space(str))
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (*str >= '0' && *str <= '9')
	{
		if (overflow(*str, i, sign))
			i = sign * (*str - '0') + i * 10;
		else if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
		str++;
	}
	return (i);
}
