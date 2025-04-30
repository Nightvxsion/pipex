/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:42:03 by marcgar2          #+#    #+#             */
/*   Updated: 2025/04/30 17:33:15 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	disp_error(char *msg, int errno)
{
	perror("\e[1;31mERROR");
	if (msg)
	{
		perror(msg);
	}
	exit(errno);
}

void	use(int errno)
{
	ft_putstr_fd("\e[1;31mBAD ARGUMENT!\n\e[0m", 2);
	ft_putstr_fd("Usage: ./pipex <file_1> <cmd_1> <cmd_2> <file_2>\n", 1);
	exit(errno);
}
