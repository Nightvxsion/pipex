/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nightvision <nightvision@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:19:07 by nightvision       #+#    #+#             */
/*   Updated: 2025/02/01 22:36:13 by nightvision      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*path(char *cmd, char **envp)
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
		def_path
	}
}