/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:55:06 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/22 10:04:25 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	*src;
	char	*dest;

	dest = malloc(10);
	src = malloc(10);
	strcpy(src, "olaaaaaaa");
	ft_memcpy(dest, src, strlen(src) + 1);
	printf("Destino despues de memcpy -> %s\n", dest);
	free(src);
	free(dest);
	return (0);
}*/
