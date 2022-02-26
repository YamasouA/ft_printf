/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:54:45 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 16:45:58 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*lst_pos;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	lst_pos = *lst;
	while (lst_pos != NULL)
	{
		temp = lst_pos;
		lst_pos = lst_pos->next;
		ft_lstdelone(temp, del);
	}
	free(*lst);
	*lst = NULL;
}