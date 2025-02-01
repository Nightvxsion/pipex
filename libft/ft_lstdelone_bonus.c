/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:01:29 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/11 18:06:56 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
/*int	main(void)
{
	t_list	*node;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (1);
	node->content = malloc(sizeof(char) * 20);
	if (!node->content)
	{
		free(node);
		return (1);
	}
	sprintf((char *)node->content, "Hola Mundo");
	printf("Contenido antes de eliminar: %s\n", (char *)node->content);
	ft_lstdelone(node, del);
	printf("Nodo eliminado\n");
	return (0);
}*/
