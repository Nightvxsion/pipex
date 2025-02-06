/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:55:28 by marcgar2          #+#    #+#             */
/*   Updated: 2025/02/06 12:52:26 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void    child_bonus(char *argv, char **envp)
{
	pid_t   pid_nbr; //Numero de proceso (los PID)
	int     fd[2];
	if (pipe(fd) == -1) //Si al pasar el proceso por tuberia, da error fd == -1
		disp_error();
	pid_nbr = fork(); //En este punto hacemos un proceso hijo (child process) del principal
	if (pid_nbr == -1)
		disp_error();
	if (pid_nbr == 0)
	{
		close(fd[0]); //cERRAMOS TEMPORALMENTE 0
		dup2(fd[1], STDOUT_FILENO); //Duplicamos la entrada al pipe 1, la de salida
		exec(argv, envp); //Ejecutamos lo que haya en los argumentos y en las variables de entorno
	}
    else
	{
    	close(fd[1]);
    	dup2(fd[0], STDIN_FILENO);
    	waitpid(pid_nbr, NULL, 0); // Suspende el proceso al que llama (pid_nbr) en NULL
	}
}

void    here_doc(char *lim, int argc) //ALgo parecido al split, pero el lim es el END
{
	pid_t	*process; //El PID del proceso hijo
	int		fd[2]; //Los dos extremos del pipe
	char	*line; //Para el here_doc
	
	if (argc < 6) //Si hay menos de 6 argumentos o esta "mal usado"
		use();
	if (pipe(fd) == -1) //SI la pipe encuentra un error
		disp_error();
	process = fork(); //Crea el proceso hijo a partir de aqui
	if (process == 0)
	{
		
	}
}