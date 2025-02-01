/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:39:09 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/22 00:18:18 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (n == 0)
		return ;
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	main(void)
{
	char *str = malloc(15);
	strcpy(str, "Putas de mierda");
	printf("Antes de bzero -> %s\n", str);
	ft_bzero(str, 5);
	printf("Despues de bzero -> %s\n", str);
	free(str);
	return (0);
}*/