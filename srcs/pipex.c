/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightvision <nightvision@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:06:30 by nightvision       #+#    #+#             */
/*   Updated: 2025/02/01 22:36:13 by nightvision      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	childs(char **argv, char **envp, int *fd)
{
	int input;

	input = open(argv[1], O_RDONLY, 0777); //0777 es un permiso general en el que todo vale
	if (input == -1)
		disp_error();
	dup2(fd[1], STDOUT_FILENO); //Recibe los datos de input (STDIN)
	dup2(input, STDIN_FILENO); //Lo que haya en input se lo pasa al fd 1 (STDOUT)
	close(fd[0]);
	exec(argv[2], envp); //Ejecuta el argumento 2 de parametro y lo compara con las ENVP
}

void	parents(char **argv, char **envp, int *fd)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output == -1)
		disp_error();
	dup2(fd[0], STDOUT_FILENO);
	dup2(output, STDIN_FILENO);
	close(fd[1]);
	exec(argv[3], envp);
}