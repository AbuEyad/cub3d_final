/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:20:02 by habu-zua          #+#    #+#             */
/*   Updated: 2024/05/31 16:36:07 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_strlen_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_is_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_info(char **storage_read, char **line, char c)
{
	void	*tmp;

	tmp = *storage_read;
	*line = ft_strdup_c(*storage_read, c);
	*storage_read = ft_strcut_c(*storage_read, c);
	free(tmp);
	if (c == '\n')
		return (GNL_LINE_READ);
	else if (c == '\0')
		return (GNL_EOF);
	return (0);
}

int	ft_file_reading(int fd, char **storage_read, char **line)
{
	int			ret_read;
	char		*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	ret_read = read(fd, buf, BUFFER_SIZE);
	while (ret_read)
	{
		if (ret_read == -1)
			break ;
		buf[ret_read] = '\0';
		*storage_read = ft_strjoin(*storage_read, buf);
		if ((*storage_read) && ft_is_c(buf, '\n') == 1)
			break ;
		ret_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (ret_read >= 0 && ft_is_c(*storage_read, '\n') == 1)
		return (ft_get_info(storage_read, line, '\n'));
	if (ret_read == 0 && BUFFER_SIZE > 0)
		return (ft_get_info(storage_read, line, '\0'));
	return (GNL_ERROR);
}

int	get_next_line(int fd, char **line)
{
	static char	*storage_read[250];

	if (line == NULL)
		return (GNL_ERROR);
	if (fd >= 0 && !(storage_read[fd]))
	{
		storage_read[fd] = (char *)malloc(1);
		if (!storage_read[fd])
			return (0);
		storage_read[fd][0] = '\0';
	}
	if (fd >= 0 && ft_is_c(storage_read[fd], '\n') == 1)
		return (ft_get_info(&storage_read[fd], line, '\n'));
	if (fd >= 0)
		return (ft_file_reading(fd, &storage_read[fd], line));
	return (GNL_ERROR);
}
