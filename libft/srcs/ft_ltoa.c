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
	size_t		cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		cnt++;
	while (n != 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*ft_ltoa(long long n)
{
	size_t		len;
	char	*ptr;
    int index;
    int sign;

    sign = n < 0;
	len = count(n);
	ptr = (char *)calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
    while (len-->0)
    {
        index = - (n % 10);
        if (n > 0)
            index = n % 10;
        ptr[len] = "0123456789"[index];
        n /= 10;
    }
    if (sign)
		ptr[0] = '-';
	return (ptr);
}


