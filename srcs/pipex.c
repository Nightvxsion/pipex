/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:06:30 by nightvision       #+#    #+#             */
/*   Updated: 2025/05/07 16:23:31 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	chararr_print(char **argv)
{
	while (*argv)
	{
		dprintf(1, "%s\n", *argv);
		argv++;
	}
}

void	first_child(char **argv, char **envp, int *fd)
{
	int	input;

	input = open(argv[1], O_RDONLY, 0777);
	if (input == -1)
		disp_error(NULL, EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(input, STDIN_FILENO);
	close(input);
	close(fd[0]);
	close(fd[1]);
	exec(argv[2], envp);
	exit(127);
}

void	second_child(char **argv, char **envp, int *fd)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output == -1)
		disp_error(NULL, EXIT_FAILURE);
	dup2(fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(output);
	close(fd[0]);
	close(fd[1]);
	exec(argv[3], envp);
	exit(127);
}

void	parent_proc(int *fd, pid_t *pid, int *status)
{
	close(fd[1]);
	close(fd[0]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid_proc[2];
	pid_t	pid[2];
	int		status;

	status = 0;
	if (argc != 5)
		use(EXIT_FAILURE);
	if (pipe(fd) == -1)
		disp_error("Error creating pipe", EXIT_FAILURE);
	pid_proc[0] = fork();
	if (pid_proc[0] == -1)
		disp_error("Error on first child fork", EXIT_FAILURE);
	else if (pid_proc[0] == 0)
		first_child(argv, envp, fd);
	else
	{
		pid_proc[1] = fork();
		if (pid_proc[1] == -1)
			disp_error("Error on second child fork", EXIT_FAILURE);
		else if (pid_proc[1] == 0)
			second_child(argv, envp, fd);
		else
			parent_proc(fd, pid, &status);
	}
	return (WEXITSTATUS(status));
}
