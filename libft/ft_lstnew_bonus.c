/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:24:18 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/11 15:09:29 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
/*int	main(void)
{
	char	*str;
	t_list	*nuevo_nodo;

	str = malloc(20);
	if (!str)
		return (1);
	nuevo_nodo = ft_lstnew((void *)str);
	strcpy(str, "Que es esto");
	printf("Contenido dentro del nodo -> %s\n", (char *)nuevo_nodo->content);
	free(str);
	free(nuevo_nodo);
	return (0);
}*/