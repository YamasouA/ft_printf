/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouta </var/mail/asouta>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:55:47 by asouta            #+#    #+#             */
/*   Updated: 2021/11/03 15:55:50 by asouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*data;

	data = (t_list *)malloc(sizeof(t_list));
	if (!data)
		return (NULL);
	data->content = content;
	data->next = NULL;
	return (data);
}
