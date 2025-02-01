/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:22:31 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/22 09:55:04 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*a;
	unsigned const char	*b;
	size_t				i;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	if (n)
	{
		while (n--)
		{
			if (*a++ != *b++)
				return (*(--a) - *(--b));
		}
	}
	return (0);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;
	int		total;

	str1 = malloc(11);
	str2 = malloc(11);
	strcpy (str1, "Hols putas");
	strcpy (str2, "Hola putas");
	total = ft_memcmp (str1, str2, 11);
	printf("Total comparison of str1 and str2 -> %d\n", total);
	free (str1);
	free (str2);
	return (0);
}*/
