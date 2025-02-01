/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:08:27 by marcgar2          #+#    #+#             */
/*   Updated: 2024/10/04 19:40:15 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	to_upper(unsigned int index, char c)
{
	if (islower(c))
		return (c - 32);
	return (c);
}

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}

/*int	main(void)
{
	char	*str;
	char	*res;

	str = malloc(25);
	strcpy(str, "today is my birthday");
	res = ft_strmapi(str, to_upper);
	if (res)
	{
		printf("Original string -> %s\n", str);
		printf("Modified string -> %s\n", res);
		free(res);
	}
	else
		printf("Algo has hecho mal broder :c\n");
	free(str);
	return (0);
}*/
