/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:16:13 by marcgar2          #+#    #+#             */
/*   Updated: 2025/02/07 10:06:18 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!f || !s)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/*int main(void)
{
	char str[] = "hola mundo";

	printf("Antes: %s\n", str);
	ft_striteri(str, cambiar_a_mayuscula_si_impar);
	printf("Después: %s\n", str);

	return 0;
}*/
