/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:12:40 by akostian          #+#    #+#             */
/*   Updated: 2024/04/15 13:23:10 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*node;

	length = 0;
	node = lst;
	while (node)
	{
		node = node->next;
		length++;
	}
	return (length);
}

/* #include <stdio.h>

int	main()
{
	t_list	*a1;
	t_list	*a2;
	t_list	*a3;
	int		b;

	b = 42;
	a1 = ft_lstnew(&b);
	b++;
	a2 = ft_lstnew(&b);
	b++;
	a3 = ft_lstnew(&b);

	a1->next = a2;
	a2->next = a3;

	printf("%d\n", *(int *)(a1->content));
	printf("%d\n", ft_lstsize(a1));
} */