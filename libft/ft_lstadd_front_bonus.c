/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:36:14 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/11 15:11:09 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*nodo1;
	t_list	*nuevo_nodo;

	nodo1 = ft_lstnew("Primer nodo");
	nuevo_nodo = ft_lstnew("Nodo al frente");
	nodo1->next = nuevo_nodo;
	ft_lstadd_front(&nodo1, nuevo_nodo);
	printf("\nContenido despues de añadir al frente\n");
	printf("- %s\n", (char *)nodo1->content);
	printf("- %s\n", (char *)nodo1->next->content);
	free(nodo1);
	return (0);
}*/