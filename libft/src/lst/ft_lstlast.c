/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:36:04 by akostian          #+#    #+#             */
/*   Updated: 2024/04/15 13:41:14 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node->next)
		node = node->next;
	return (node);
}

/* 
#include <stdio.h>

int	main()
{
	t_list	*a1;
	t_list	*a2;
	t_list	*a3;
	int		b1;
	int		b2;
	int		b3;

	b1 = 42;
	b2 = 43;
	b3 = 44;
	a1 = ft_lstnew(&b1);
	a2 = ft_lstnew(&b2);
	a3 = ft_lstnew(&b3);

	a1->next = a2;
	a2->next = a3;

	printf("%d\n", *(int *)(a1->content));
	printf("%d\n", *(int *)ft_lstlast(a1)->content);
} */