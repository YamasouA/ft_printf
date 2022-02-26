/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:56:03 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 15:56:05 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}
