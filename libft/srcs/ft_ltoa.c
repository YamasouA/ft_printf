/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:54:06 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 15:54:08 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count(long long n)
{
	long	n_cpy;
	size_t		cnt;

	n_cpy = (long)n;
	cnt = 0;
	if (n_cpy == 0)
		return (1);
	if (n_cpy < 0)
	{
		n_cpy *= -1;
		cnt++;
	}
	while (n_cpy > 0)
	{
		cnt++;
		n_cpy /= 10;
	}
	return (cnt);
}

static	void	add_list(char *ptr, long n, int pos)
{
	if (n <= 9)
		ptr[pos] = n + '0';
	else
	{
		add_list(ptr, n / 10, pos - 1);
		ptr[pos] = n % 10 + '0';
	}
}

char	*ft_ltoa(long long n)
{
	long long	n_cpy;
	size_t		len;
	char	*ptr;
	char	*ptr_cpy;

	len = count(n);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr_cpy = ptr;
	if (n_cpy < 0)
	{
		n_cpy *= -1;
		ptr[0] = '-';
	}
	add_list(ptr, n_cpy, len - 1);
	ptr += len;
	*ptr = '\0';
	return (ptr_cpy);
}

