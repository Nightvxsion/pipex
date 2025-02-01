/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:11:53 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/11 18:08:56 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	t_list	*nodo1 = ft_lstnew("Nodo 1");
	t_list	*nodo2 = ft_lstnew("Nodo 2");

	nodo1->next = nodo2;
	int size = ft_lstsize(nodo1);
	printf("Tamaño de la lista -> %d\n", size);
	free(nodo1);
	free(nodo2);
	return (0);
}*/