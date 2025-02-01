/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:02:45 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/04 19:43:31 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str1;
	size_t	i;
	size_t	len;

	i = 0;
	str1 = 0;
	len = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len > i && ft_strchr(set, s1[len - 1]))
		len--;
	str1 = ft_substr(s1, i, len - i);
	return (str1);
}

/*int	main(void)
{
	char	*total;

	total = ft_strtrim("   ***Hola Mundo***   ", " *");
	printf("resultado total del trim -> %s\n", total);
	free(total);
	return (0);
}*/
