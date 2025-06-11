/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:42:28 by akostian          #+#    #+#             */
/*   Updated: 2024/04/15 13:52:12 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	while (node->next)
		node = node->next;
	node->next = new;
}

/* 
#include <stdio.h>

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
} */