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

static	size_t	count(unsigned long n)
{
	size_t		cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		cnt++;
		n /= 16;
	}
	return (cnt);
}

static	void	add_list(char *ptr, unsigned long n, size_t pos, char *base)
{
	if (n <= 15)
		ptr[pos] = n + '0';
	else
	{
		add_list(ptr, n / 15, pos - 1);
		ptr[pos] = n % 15 + '0';
	}
}

char	*ft_ultoa(unsigned long n, char *base)
{
	size_t		len;
	char	*ptr;
	char	*ptr_cpy;

	len = count(n);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr_cpy = ptr;
	add_list(ptr, n, len - 1, base);
	ptr += len;
	*ptr = '\0';
	return (ptr_cpy);
}