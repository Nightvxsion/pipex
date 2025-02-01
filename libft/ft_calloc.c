/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:22:03 by marcgar2          #+#    #+#             */
/*   Updated: 2024/09/27 23:28:28 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t item, size_t size)
{
	void	*total;

	total = malloc(item * size);
	if (!total)
		return (NULL);
	else
	{
		ft_bzero(total, (item * size));
		return (total);
	}
}

/*int	main(void)
{
	size_t	num_item;
	size_t	size_item;
	int		*arr;

	num_item = 2;
	size_item = (sizeof(int));
	arr = (int *)ft_calloc(num_item, size_item);
	printf("CALLOC result 1 -> %d\n CALLOC result 2 -> %d\n", arr[0], arr[1]);
	free (arr);
	return (0);
}*/
