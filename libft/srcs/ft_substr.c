/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:03:28 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 16:03:32 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_min(size_t len, size_t len2)
{
	if (len > len2)
		return (len2);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		ptr = (char *)malloc(sizeof(char));
		if (ptr == NULL)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (get_min(len, ft_strlen(s)) + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s + start, get_min(len, ft_strlen(s)) + 1);
	return (ptr);
}
