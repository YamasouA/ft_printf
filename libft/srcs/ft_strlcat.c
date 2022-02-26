/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:00:58 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 16:01:00 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_min(size_t a, size_t b)
{
	if (a >= b)
		return (b);
	return (a);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		n;
	size_t		len;
	const char	*temp_src;
	char		*temp_dst;

	temp_dst = dst;
	temp_src = src;
	len = ft_min(ft_strlen(dst), dstsize);
	temp_dst = dst + len;
	n = dstsize - len;
	if (n == 0)
		return (len + ft_strlen(src));
	while (*temp_src)
	{
		if (n == 1)
			break ;
		*temp_dst++ = *temp_src++;
		n--;
	}
	*temp_dst = '\0';
	return (len + ft_strlen(src));
}
