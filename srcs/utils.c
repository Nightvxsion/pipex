/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:19:07 by nightvision       #+#    #+#             */
/*   Updated: 2025/04/30 17:36:05 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_path(char **sub_paths)
{
	int	i;

	i = 0;
	while (sub_paths[i])
		free(sub_paths[i++]);
	free(sub_paths);
}

char	*look_for_path(char *cmd, char **envp)
{
	char	**sub_paths;
	char	*def_path;
	int		i;
	char	*path_slash;

	i = 0;
	if (cmd[0] == '/' || cmd[0] == '.' || !envp)
		if (access(cmd, F_OK) == 0)
			return (cmd);
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	sub_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (sub_paths[i])
	{
		path_slash = ft_strjoin(sub_paths[i++], "/");
		def_path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (access(def_path, F_OK) == 0)
			return (def_path);
		free(def_path);
	}
	free_path(sub_paths);
	return (0);
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
		perror(command[0]);
		while (command[++i])
			free(command[i]);
		free(command);
		exit(127);
	}
	if (execve(path, command, envp) == -1)
		disp_error("execve", 127);
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
