/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:41:10 by marcgar2          #+#    #+#             */
/*   Updated: 2025/04/24 15:36:23 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

//UTILS
char	*look_for_path(char *cmd, char **envp);
void	disp_error(void);
void	exec(char *argv, char **envp);
void	empty_cmd(char **command);

//PIPEX
void	childs(char **argv, char **envp, int *fd);
void	parents(char **argv, char **envp, int *fd);

//UTILS BONUS
void	use(void);
int		open_file_mode(char *argv, int i);
char	*get_next_line(int fd);
#endif