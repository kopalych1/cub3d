/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:54:58 by akostian          #+#    #+#             */
/*   Updated: 2024/04/15 15:03:53 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	node = lst;
	while (node)
	{
		f(node->content);
		node = node->next;
	}
}
/* 
#include <stdio.h>

void	print_int_node_content(void *content)
{
	int *value;

	value = (int *)content;
	printf("iter: %d\n", *value);
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
	ft_lstiter(head, print_int_node_content);
} */