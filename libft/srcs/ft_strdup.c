/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:00:17 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 16:00:18 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*sp;

	len = ft_strlen(s1);
	sp = (char *)malloc(len + 1);
	if (sp == NULL)
		return (NULL);
	ft_strlcpy(sp, s1, len + 1);
	return (sp);
}
