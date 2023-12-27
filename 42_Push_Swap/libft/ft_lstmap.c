/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay  <ahtuncay@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:09:25 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/12/18 15:43:23 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst -> content);
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		del(content);
		ft_lstclear(&new_node, del);
		return (NULL);
	}
	new_node -> next = ft_lstmap(lst -> next, f, del);
	return (new_node);
}
