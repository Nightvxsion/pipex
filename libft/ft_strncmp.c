/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:22:45 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/21 20:21:07 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n && (s1[i] != '\0' || s2[i] != '\0'))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;
	int		total;

	str1 = malloc(5);
	str2 = malloc(5);
	strcpy (str1, "Hola");
	strcpy (str2, "Holb");
	total = ft_strncmp(str1, str2, 4);
	if (total == 0)
		printf ("Strings are the same\n");
	else if (total < 0)
		printf ("%s has less characters than %s\n", str1, str2);
	else
		printf ("%s has more characters than %s\n", str1, str2);
	return (0);
}*/
