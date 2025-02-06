/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:06:31 by marcgar2          #+#    #+#             */
/*   Updated: 2025/02/06 08:51:57 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	use(void)
{
	ft_putstr_fd("\e[1;31mBAD ARGUMENT!\n\e[0m", 2);
	ft_putstr_fd("Usage: ./pipex <file_1> <cmd_1> <cmd_2> <....> <file_2>\n", 1);
	ft_putstr_fd("		 ./pipex \"here_doc\" <RANDOM_WORD> <cmd_1> <cmd_2> <....> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

int	open_file_mode(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777); // La informacion LA ANEXA (O_APPEND) con la que ya hay
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777); // La informacion SE BORRA Y SE PONE (O_TRUNC) la nueva
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777); // Si es 2, entonces el archivo solo se lee
	if (i == -1)
		disp_error();
	return (file);
}