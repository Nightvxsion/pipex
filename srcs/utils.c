/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:19:07 by nightvision       #+#    #+#             */
/*   Updated: 2025/02/21 23:27:40 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*look_for_path(char *cmd, char **envp)
{
	char	**sub_paths; //Haremos split para dividir los diferentes path's
	char	*def_path; //Path definitivo cuando hagamos strjoin del path verdadero
	int		i;
	char	*path_slash; //Solo haremos un strjoin del path verdadero con un '/'

	i = 0;
	while(ft_strnstr(envp[i], "PATH", 4) == 0) //Mientras que exista una palabra llamada PATH ( == 0, is true)
		i++;
	sub_paths = ft_split(envp[i] + 5, ':'); //Se pone : para establecer el directorio del path
	i = 0;
	while (sub_paths[i])
	{
		path_slash = ft_strjoin(sub_paths[i], "/"); //Lo que encuentre lo une con una '/'
		def_path = ft_strjoin(path_slash, cmd); //Lo que encuentre lo une con el comando
		free(path_slash); //Liberamos memoria del directorio
		if (access(def_path, F_OK) == 0) //Si el path simplemente existe
			return (def_path);
		free(def_path);
		i++;
	}
	i = -1;
	while(sub_paths[++i]) //Iteramos sobre toda la matriz de numeros DEL SPLIT
		free(sub_paths[i]); // Eliminamos 1 a 1 los numeros de dentro
	free(sub_paths); // Liberamos la matriz/variable principal
	return (0);
}

void	disp_error(void)
{
	perror("\e[1;31mERROR"); //Mensaje de error simple
	exit(EXIT_FAILURE); // Return -1
}

void	exec(char *argv, char **envp)
{
	char 	**command;
	char	*path;
	int		i;

	i = -1;
	command = ft_split(argv, ' '); //Hace un split para dividir los argumentos del comando
	empty_cmd(command);
	path = look_for_path(command[0], envp); //Comprobar la existencia del comando de la primera pos de envp
	if (!path)
	{
		while(command[++i])
			free(command[i]);
		free(command);
		exit(127);
	}
	if (execve(path, command, envp) == -1) //Si en el momento de la ejecucion del PATH, comando y ENVP hay un err
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
	ft_putstr_fd("Usage: ./pipex <file_1> <cmd_1> <cmd_2> <....> <file_2>\n", 1);
	ft_putstr_fd("		 ./pipex \"here_doc\" <RANDOM_WORD> <cmd_1> <cmd_2> <....> <file>\n", 1);
	exit(EXIT_SUCCESS);
}