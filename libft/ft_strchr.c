/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:20:14 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/21 20:20:10 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	res;

	res = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == res)
			return ((char *)s);
		s++;
	}
	if (res == '\0')
		return ((char *)s + ft_strlen(s));
	return (NULL);
}

/*int	main(void)
{
	char	*str;
	char	c;
	char	*found;

	c = 'o';
	str = malloc(13);
	strcpy(str, "hola buenas");
	found = ft_strchr(str, c);
	if (found != NULL)
		printf ("FOUND %c IN %s\n", c, str);
	else
		printf ("ERR\n");
	return (0);
}*/
