/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:41:47 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/27 14:31:06 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*int	main(void)
{
	char	*str;
	size_t	leng;

	str = malloc(30);
	strcpy(str, "Hola putas de mierd");
	leng = ft_strlen(str);
	printf("La longitud de la cadena %s es -> %zu\n", str, leng);
	return (0);
}*/
