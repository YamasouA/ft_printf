/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:02:41 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 16:02:44 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp_s;
	size_t	len;

	temp_s = (char *)s;
	while (*temp_s)
		temp_s++;
	if (c == 0)
		return (temp_s);
	temp_s--;
	len = ft_strlen(s);
	while (len--)
	{
		if (*temp_s == (const char)c)
			return (temp_s);
		temp_s--;
	}
	return (NULL);
}
