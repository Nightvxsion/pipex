/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:05:40 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/08 19:07:55 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*result;
	char			c_copy;

	c_copy = (char)c;
	result = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c_copy)
			result = (char *)&s[i];
		i++;
	}
	if (s[i] == c_copy)
		return ((char *)&s[i]);
	return (result);
}

/*int	main(void)
{
	char	*str;
	char	c;
	char	*found;

	str = malloc(20);
	c = 'u';
	strcpy(str, "hola buenas");
	found = ft_strrchr(str, c);
	if (found != NULL)
		printf("FOUND %s IN %s\n", found, str);
	else
		printf("ERR\n");
	free(str);
	return (0);
}*/
