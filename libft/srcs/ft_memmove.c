/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:57:33 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 15:57:35 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (n <= 0 || (!dst && !src))
		return (dst);
	if (dst > src)
	{
		temp_src += n - 1;
		temp_dst += n - 1;
	}
	while (n--)
	{
		if (dst > src)
			*temp_dst-- = *temp_src--;
		else
			*temp_dst++ = *temp_src++;
	}
	return (dst);
}
