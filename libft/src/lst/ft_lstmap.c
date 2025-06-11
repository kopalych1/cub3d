/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:06:05 by akostian          #+#    #+#             */
/*   Updated: 2024/04/15 15:40:55 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*node_next;
	t_list	*new_lst;

	node = lst;
	new_lst = ft_lstnew(f(node->content));
	while (node)
	{
		node_next = node->next;
		if (node_next)
			ft_lstadd_back(&new_lst, ft_lstnew(f(node_next->content)));
		ft_lstdelone(node, del);
		node = node_next;
	}
	return (new_lst);
}
/* 
#include <stdio.h>

void *double_int(void *content)
{
	int	*value;
	int	*result;

	value = (int *)content;
	result = malloc(sizeof(int));
	if (result)
		*result = *value * 2;
	return result;
}
void delete_int(void *content)
{
	int *value = (int *)content;
	free(value);
}
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

	// printf("%d\n", *(int *)(head->content));
	// ft_lstmap(head, double_int, delete_int);
	ft_lstiter(ft_lstmap(head, double_int, delete_int), print_int_node_content);
} */