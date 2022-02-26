/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:03:03 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 16:03:04 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_start_pos(char const *s1, char const *set)
{
	int			flag;
	char const	*set_cpy;

	flag = 1;
	set_cpy = set;
	while (flag)
	{
		flag = 0;
		set = set_cpy;
		while (*set)
		{
			if (*s1 == *set)
			{
				s1++;
				flag = 1;
				break ;
			}
			set++;
		}
	}
	return ((char *)s1);
}

static	char	*get_end_pos(char const *s1, char const *set)
{
	int			flag;
	char const	*set_cpy;

	flag = 1;
	while (*s1)
		s1++;
	s1--;
	set_cpy = set;
	while (flag)
	{
		flag = 0;
		set = set_cpy;
		while (*set)
		{
			if (*s1 == *set)
			{
				s1--;
				flag = 1;
				break ;
			}
			set++;
		}
	}
	s1++;
	return ((char *)s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*start_pos;
	char	*end_pos;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_pos = get_start_pos(s1, set);
	end_pos = get_end_pos(s1, set);
	if (start_pos >= end_pos)
		end_pos = start_pos;
	ptr = (char *)malloc(sizeof(char) * ((end_pos - start_pos) + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, start_pos, (end_pos - start_pos) + 1);
	return (ptr);
}

// #include "stdio.h"
// int main()
// {
//     char const s1[] = "aaaaaa";
//     char const set[] = "a";
//     char *ans = ft_strtrim(s1, set);
//     printf("len: %zu\n", ft_strlen(s1));
//     printf("len after: %zu\n", ft_strlen(ans));
//     printf("%s", ans);
// }
