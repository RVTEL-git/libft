/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:46:14 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/09 18:26:02 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new_l;
	t_list	*new_c;

	if (!lst || !f || !del)
		return (NULL);
	curr = lst;
	new_l = NULL;
	while (curr != NULL)
	{
		new_c = ft_lstnew(f(curr->content));
		if (!new_c)
		{
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, new_c);
		curr = curr->next;
	}
	return (new_l);
}
