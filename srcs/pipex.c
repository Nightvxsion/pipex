/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:06:30 by nightvision       #+#    #+#             */
/*   Updated: 2025/04/24 15:34:34 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	childs(char **argv, char **envp, int *fd)
{
	int	input;

	input = open(argv[1], O_RDONLY, 0777);
	if (input == -1)
		disp_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(input, STDIN_FILENO);
	close(input);
	close(fd[0]);
	close(fd[1]);
	exec(argv[2], envp);
	exit(127);
}

void	parents(char **argv, char **envp, int *fd)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output == -1)
		disp_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(output);
	close(fd[0]);
	close(fd[1]);
	exec(argv[3], envp);
	exit(127);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid_proc;

	if (argc != 5)
	{
		ft_putstr_fd("\e[1;31mBAD ARGUMENT!\n\e[0m", 2);
		ft_putstr_fd("Use: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		return (1);
	}
	if (pipe(fd) == -1)
		disp_error();
	pid_proc = fork();
	if (pid_proc == -1)
		disp_error();
	if (pid_proc == 0)
		childs(argv, envp, fd);
	else
	{
		close(fd[1]);
		waitpid(pid_proc, NULL, 0);
		parents(argv, envp, fd);
		close(fd[0]);
	}
}
