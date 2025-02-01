/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:23:27 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/27 14:31:48 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*real_s;
	size_t	i;
	char	*s1;

	s1 = (char *)s;
	real_s = (char *)malloc(ft_strlen(s1) + 1);
	i = 0;
	if (s1 == NULL || real_s == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		real_s[i] = s1[i];
		i++;
	}
	real_s[i] = '\0';
	return (real_s);
}

/*int	main(void)
{
	char	*src;
	char	*dest;

	src = malloc(14);
	strcpy (src, "putos vecinos");
	dest = ft_strdup(src);
	printf("Resultado final -> %s\n", dest);
	free(dest);
	free(src);
	return (0);
}*/
