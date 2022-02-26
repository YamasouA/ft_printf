/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:00:42 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 16:05:16 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_join;
	char	*ptr_cpy;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s_join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ptr_cpy = s_join;
	if (s_join == NULL)
		return (NULL);
	ft_strlcpy(s_join, s1, ft_strlen(s1) + 1);
	ft_strlcat(s_join, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (ptr_cpy);
}
