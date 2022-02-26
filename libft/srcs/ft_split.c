/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:59:52 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 15:59:54 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	split_cnt(char const *s, char c)
{
	size_t	cnt;
	char	*pos;

	cnt = 0;
	pos = ft_strchr(s, c);
	if (c == 0)
		return (1);
	if (pos != s)
		cnt++;
	if (pos != NULL)
		cnt += split_cnt(pos + 1, c);
	else
	{
		while (*s)
			s++;
		s--;
		if (*s == c)
			cnt--;
	}
	return (cnt);
}

static	void	free_malloc(char **ptr_ptr, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(ptr_ptr[j]);
		j++;
	}
}

static	int	set_string(char **ptr_ptr, size_t cnt, char const *s, char c)
{
	size_t	i;
	char	*split_pos;

	i = 0;
	while (i < cnt)
	{
		split_pos = ft_strchr(s, c);
		if (split_pos == NULL)
			split_pos = (char *)s + ft_strlen(s);
		if (s != split_pos)
		{
			ptr_ptr[i] = (char *)malloc(sizeof(char) * (split_pos - s + 1));
			if (ptr_ptr[i] == NULL)
			{
				free_malloc(ptr_ptr, i + 1);
				return (0);
			}
			else
				ft_strlcpy(ptr_ptr[i++], s, (split_pos - s + 1));
		}
		if (split_pos != NULL)
			s = split_pos + 1;
	}
	ptr_ptr[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_ptr;
	size_t	cnt;

	if (s == NULL || (*s == '\0' && c == '\0') || *s == '\0')
	{
		ptr_ptr = (char **)malloc(sizeof(char *) * 1);
		if (ptr_ptr == NULL)
			return (NULL);
		ptr_ptr[0] = NULL;
		return (ptr_ptr);
	}
	cnt = split_cnt(s, c);
	ptr_ptr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (ptr_ptr == NULL)
		return (NULL);
	if (!set_string(ptr_ptr, cnt, s, c))
	{
		free(ptr_ptr);
		return (NULL);
	}
	return (ptr_ptr);
}

// int main()
// {
//     // char const s[] = "ababa";
//     // char c = 'b';
//     // printf("3: \n");
//     // ft_split(s, c);
//     // char const s2[] = "baba";
//     // printf("2: \n");
//     // ft_split(s2, c);
//     // char const s3[] = "babab";
//     // printf("2: \n");
//     // ft_split(s3, c);
//     // char const s4[] = "babbab";
//     // printf("2: \n");
//     // ft_split(s4, c);
//     // char const s5[] = "abab";
//     // printf("2: \n");
//     // ft_split(s5, c);
//     char const s6[] = "      split       this for   me  !       ";
//     printf("5: \n");
//     ft_split(s6, ' ');
// }
//#include "stdio.h"
//  int	main(void)
//  {
//  	int		index;
//  	char	**tab;
//  	tab = ft_split("AxBxCCCxDDDDxEExxxF", 'x');
//  	index = 0;
//  	while (tab[index])
//  	{
//         //printf("%s\n",tab[index]);
//  		free(tab[index++]);
//  	}
//  	free(tab);
//  	while (1);
//  }
