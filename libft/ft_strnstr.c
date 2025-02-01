/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:11:08 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/25 19:08:30 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < n)
	{
		j = 0;
		while (big[i + j] == little [j] && (i + j) < n)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*str;
	char	*substr;
	char	*total;
	size_t	i;

	str = malloc(20);
	substr = malloc(10);
	i = 20; // This is the length of the search
	strcpy(str, "me cago en cristo");
	strcpy(substr, "u");
	total = ft_strnstr(str, substr, i);
	if (total != NULL)
		printf("Found :>\n");
	else
		printf("Not found :<\n");
	return(0);
}*/
