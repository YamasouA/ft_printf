/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:58:49 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 15:58:51 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr(long n, int fd)
{
	char	s;

	s = '0';
	if (n <= 9)
	{
		s += n;
		write(fd, &s, 1);
	}
	else
	{
		ft_putnbr(n / 10, fd);
		s += n % 10;
		write(fd, &s, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = (long)n;
	if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr(ln, fd);
}
