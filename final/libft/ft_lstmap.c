/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:35:38 by ssergiu           #+#    #+#             */
/*   Updated: 2022/05/10 18:10:00 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new_lst;
	t_list	*head;

	if (!lst)
		return (NULL);
	ptr = lst;
	new_lst = ft_lstnew(f(lst->content));
	head = new_lst;
	while (ptr->next)
	{
		ptr = ptr->next;
		new_lst->next = ft_lstnew(f(ptr->content));
		if (!new_lst->next)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		new_lst = new_lst->next;
	}
	return (head);
}
