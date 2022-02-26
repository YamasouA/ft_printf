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

static	int	count(int n)
{
	long	n_cpy;
	int		cnt;

	n_cpy = (long)n;
	cnt = 0;
	if (n_cpy == 0)
		return (1);
	if (n_cpy < 0)
	{
		n_cpy *= -1;
		cnt++;
	}
	while (n_cpy > 0)
	{
		cnt++;
		n_cpy /= 10;
	}
	return (cnt);
}

static	void	add_list(char *ptr, long n, int pos)
{
	if (n <= 9)
		ptr[pos] = n + '0';
	else
	{
		add_list(ptr, n / 10, pos - 1);
		ptr[pos] = n % 10 + '0';
	}
}

char	*ft_itoa(int n)
{
	long	n_cpy;
	int		len;
	char	*ptr;
	char	*ptr_cpy;

	n_cpy = (long)n;
	len = count(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr_cpy = ptr;
	if (n_cpy < 0)
	{
		n_cpy *= -1;
		ptr[0] = '-';
	}
	add_list(ptr, n_cpy, len - 1);
	ptr += len;
	*ptr = '\0';
	return (ptr_cpy);
}

// #include "stdio.h"
// int main()
// {
//     int i = 0;
//     int j = -2;
//     printf("%d: %s\n", i, ft_itoa(i));
//     printf("%d: %s\n", j, ft_itoa(j));
// }
