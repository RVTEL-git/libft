/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:36:44 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/07 17:54:13 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

void	test_ft_lstadd_front(void)
{
	char	*str1;
	char	*str2;
	t_list	*second;
	t_list	*first;
	t_list	*new_elem;

	str1 = "world";
	str2 = "hello";
	second = ft_lstnew(str1);
	first = second;
	new_elem = ft_lstnew(str2);
	ft_lstadd_front(&first, new_elem);
	if (first == new_elem
		&& first->content == str2
		&& first->next == second)
		printf("Test OK\n");
	else
		printf("Test FAIL\n");
}

int	main(void)
{
	test_ft_lstadd_front();
	return (0);
}
