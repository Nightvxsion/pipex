/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:06:30 by nightvision       #+#    #+#             */
/*   Updated: 2025/02/11 07:56:40 by marcgar2         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	int		fd[2]; //FD al que actua
	pid_t	pid_proc; //PID del proceso

	if (argc == 5)
	{
		if (pipe(fd) == -1) //Si al hacer la pipe del fd da error
			disp_error();
		pid_proc = fork(); //Hacer el proceso hijo
		if (pid_proc == -1)
			disp_error();
		if (pid_proc == 0)
			childs(argv, envp, fd);
		waitpid(pid_proc, NULL, 0);
		parents(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("\e[1;31mBAD ARGUMENT!\n\e[0m", 2);
		ft_putstr_fd("Use: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}