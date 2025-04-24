/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:19:07 by nightvision       #+#    #+#             */
/*   Updated: 2025/04/24 15:35:40 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*look_for_path(char *cmd, char **envp)
{
	char	**sub_paths;
	char	*def_path;
	int		i;
	char	*path_slash;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	sub_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (sub_paths[i])
	{
		path_slash = ft_strjoin(sub_paths[i], "/");
		def_path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (access(def_path, F_OK) == 0)
			return (def_path);
		free(def_path);
		i++;
	}
	i = -1;
	while (sub_paths[++i])
		free(sub_paths[i]);
	free(sub_paths);
	return (0);
}

void	disp_error(void)
{
	perror("\e[1;31mERROR");
	exit(EXIT_FAILURE);
}

void	exec(char *argv, char **envp)
{
	char	**command;
	char	*path;
	int		i;

	i = -1;
	command = ft_split(argv, ' ');
	empty_cmd(command);
	path = look_for_path(command[0], envp);
	if (!path)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		exit(127);
	}
	if (execve(path, command, envp) == -1)
	{
		perror("execve");
		exit(127);
	}
}

void	empty_cmd(char **command)
{
	if (!command || !command[0])
	{
		ft_putstr_fd("Invalid command\n", 2);
		if (command)
			free(command);
		exit(127);
	}
}

void	use(void)
{
	ft_putstr_fd("\e[1;31mBAD ARGUMENT!\n\e[0m", 2);
	ft_putstr_fd("Usage: ./pipex <file_1> <cmd_1> <cmd_2> <file_2>\n", 1);
	exit(EXIT_SUCCESS);
}
