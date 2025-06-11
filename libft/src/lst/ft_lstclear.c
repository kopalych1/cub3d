/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:06:39 by akostian          #+#    #+#             */
/*   Updated: 2024/04/15 14:53:12 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*node_next;

	node = *lst;
	while (node)
	{
		node_next = node->next;
		ft_lstdelone(node, del);
		node = node_next;
	}
	*lst = NULL;
}

/* 
#include <stdio.h>

void	delete(void *content)
{
	content = 0;
}

int	main()
{
	t_list	*head;
	int		b1 = 42;
	int		b2 = 43;
	int		b3 = 44;
	int		b4 = 45;
	int		b5 = 46;

	head = ft_lstnew(&b1);

	ft_lstadd_back(&head, ft_lstnew(&b2));
	ft_lstadd_back(&head, ft_lstnew(&b3));
	ft_lstadd_back(&head, ft_lstnew(&b4));
	ft_lstadd_back(&head, ft_lstnew(&b5));

	printf("%d\n", *(int *)(head->content));
	printf("%d\n", *(int *)ft_lstlast(head)->content);
	ft_lstclear(&(head->next->next->next), delete);
}*/