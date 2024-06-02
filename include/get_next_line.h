/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:11:23 by habu-zua          #+#    #+#             */
/*   Updated: 2024/05/25 14:20:02 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define GNL_ERROR -1
# define GNL_EOF 0
# define GNL_LINE_READ 1

int		get_next_line(int fd, char **line);
int		ft_strlen_c(char *str, char c);
int		ft_is_c(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup_c(char *str, char c);
char	*ft_strcut_c(char *str, char c);
char	*ft_strchr(char *s, char c);
#endif
