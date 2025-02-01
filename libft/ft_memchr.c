/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:28:14 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/21 23:59:05 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *)&src[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*str;
	char	c;
	char	*total;

	str = malloc(16);
	c = 'i';
	strcpy(str, "me cago en todo");
	total = ft_memchr(str, c, 10);
	if (total != NULL)
		printf("Se ha encontrado %c en %s", c, str);
	else
		printf("A tomar por culo Borja, muy bien");
	return (EXIT_SUCCESS);
}
*/