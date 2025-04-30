/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:41:10 by marcgar2          #+#    #+#             */
/*   Updated: 2025/04/30 17:37:01 by marcgar2         ###   ########.fr       */
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

//UTILS
char	*look_for_path(char *cmd, char **envp);
void	exec(char *argv, char **envp);
void	empty_cmd(char **command);
void	use(int errno);
int		open_file_mode(char *argv, int i);

//ERRORS
void	disp_error(char *msg, int errno);

//PIPEX
void	first_child(char **argv, char **envp, int *fd);
void	second_child(char **argv, char **envp, int *fd);

#endif