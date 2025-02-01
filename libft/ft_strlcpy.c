/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:27:01 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/21 20:55:05 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*int	main(void)
{
	char	*src;
	char	*dest;
	size_t	len;

	src = malloc(18);
	dest = malloc(18);
	strcpy(src, "Larga vida a paco");
	len = ft_strlcpy(dest, src, 8);
	printf("Despues de strlcpy -> %s\n", dest);
	free(src);
	free(dest);
	return (EXIT_SUCCESS);
}*/
