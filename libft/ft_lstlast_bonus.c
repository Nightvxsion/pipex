/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:24:47 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/11 15:52:10 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (!lst)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/*int	main(void)
{
	t_list	*nodo1 = ft_lstnew("Nodo 1");
	t_list	*nodo2 = ft_lstnew("Nodo 2");
	t_list	*last;

	nodo1->next = nodo2;
	last = ft_lstlast(nodo1);
	printf("Tamaño de la lista -> %s\n", (char *)last->content);
	free(nodo1);
	free(nodo2);
	return (0);
}*/
