/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:55:28 by marcgar2          #+#    #+#             */
/*   Updated: 2025/02/09 21:43:24 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_bonus(char *argv, char **envp)
{
	pid_t	pid_nbr; //Numero de proceso (los PID)
	int		fd[2];
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

void	here_doc(char *lim, int argc) //ALgo parecido al split, pero el lim es el END
{
	pid_t	process; //El PID del proceso hijo
	int		fd[2]; //Los dos extremos del pipe
	char	*line; //Para el here_doc
	
	check_pipe(argc, fd); //Comprueba si la pipe se puede hacer
	process = fork(); //Crea el proceso hijo a partir de aqui
	if (process == 0)
	{
		close(fd[0]); //Cerramos el otro extremo ya que solo escribimos en la parte final
		while (get_next_line((char **)line))
		{
			if(ft_strncmp(lim, line, ft_strlen(line)) == 0) //Si lo que haya en la linea ES el delimitador (== 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line)); //Sino, sigue escribiendo en fd[1] en la misma linea, con la misma long
		}
	}
	else
	{
		close(fd[1]); //Cierra el final
		dup2(fd[0], STDIN_FILENO); //Redirije a la entrada estandar
		wait(NULL); //Esperar al hijo que termine de hacer lo suyo
	}
}


int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0) //Si se detecta here_doc
		{
			i = 3;
			filein = open_file_mode(argv[argc - 1], 0); //Abre el archivo en modo append
			here_doc(argv[2], argc); //El caracter delim, va a ser lo que este en la segunda pos	
		}
		else
		{
			i = 2;
			fileout = open_file_mode(argv[argc - 1], 1); //Se abre en O_TRUNC
			filein = open_file_mode(argv[1], 2); //se abre en O_RDONLY
			dup2(filein, STDIN_FILENO); //Redirige la entrada estandar al archivo de entrada
		}
		while (i < argc - 2) //Mientras que haya argumentos
			child_bonus(argv[i++], envp); //Genera un proceso nuevo en cada pipeline
		dup2(fileout, STDOUT_FILENO);//Redirigimos la salida estandar al archivo de salida
		exec(argv[argc - 2], envp); //Ejecutamos lo que tenemos en los argumentos sin contar el nmombre y el delim
	}
	use();
}
