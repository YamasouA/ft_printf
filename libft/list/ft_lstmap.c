/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:55:37 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 15:55:38 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*base_lst;
	t_list	*add_lst;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	base_lst = ft_lstnew(f(lst->content));
	if (base_lst == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst != NULL)
	{
		add_lst = ft_lstnew(f(lst->content));
		if (add_lst == NULL)
		{
			ft_lstclear(&base_lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&base_lst, add_lst);
	}
	return (base_lst);
}
