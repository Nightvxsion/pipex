/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:10:27 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/27 14:25:51 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *)a;
	while (i < n)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (a);
}

/*int	main(void)
{
	char	*str;

	str = malloc(50);
	strcpy(str, "chuquillo majonero");
	ft_memset(str, '?', 11);
	printf("%s\n", str);
	return (0);
}*/
