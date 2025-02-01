/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:28:57 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/21 20:20:44 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dest_len + src_len);
}

/*int	main(void)
{
	char	*str;
	char	*dest;
	size_t	size;
	size_t	total;

	str = malloc(13);
	dest = malloc(16);
	strcpy(dest, "me cago en dios");
	strcpy(str, " y yo broder");
	size = 35;
	total = ft_strlcat(dest, str, size);
	printf("Frase total despues de strlcat -> %s\n", dest);
	printf("Y su longitud es -> %zu\n", total);
	free(str);
	free(dest);
	return (EXIT_SUCCESS);
}*/
