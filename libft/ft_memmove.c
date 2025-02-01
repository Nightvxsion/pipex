/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:37:22 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/04 20:11:10 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (!d && !s)
		return (NULL);
	if (d < s)
		return (ft_memcpy(d, s, n));
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (d);
}

/*int	main(void)
{
	char	*str;

	str = malloc(10);
	strcpy(str, "1234");
	ft_memmove(str + 3, str, 10);
	printf("Output despues de memmmove -> %s\n", str);
	free(str);
	return (0);
}*/
