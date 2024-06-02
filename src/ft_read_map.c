/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:01:49 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 18:57:21 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

// char	**ft_check_last_line(char *map_tmp, char *line)
// {
// 	if (*line)
// 	{
// 		line = ft_strdup_map(line);
// 		map_tmp = ft_strjoin_point(map_tmp, line);
// 	}
// 	else
// 		free(line);
// 	return (ft_split(map_tmp, '.'));
// }

int	ft_read_map(t_info *info_map, int fd, char *line)
{
	char	*map_tmp;
	int		eflag;

	eflag = 0;
	map_tmp = (char *)malloc(sizeof(char));
	if (!map_tmp)
		return (ft_mgt_error(9, "Error\n malloc"));
	map_tmp[0] = '\0';
	line = ft_strdup_map(line);
	map_tmp = ft_strjoin_point(map_tmp, line);
	free(line);
	while ((get_next_line(fd, &line)) != 0)
	{
		if (check_empty_line(line) && !eflag)
			eflag = 1;
		if (!check_empty_line(line) && eflag)
			return (free(line), ft_mgt_error(9, "Error\n: Empty line\n"));
		line = ft_strdup_map(line);
		map_tmp = ft_strjoin_point(map_tmp, line);
		free(line);
	}
	if (*line)
	{
		line = ft_strdup_map(line);
		map_tmp = ft_strjoin_point(map_tmp, line);
	}
	else
		free(line);
	info_map->map = ft_split(map_tmp, '.');
	free(map_tmp);
	return (1);
}

int	ft_read_info(char *s, t_info *info_map)
{
	int		fd;
	char	*line;

	fd = open(s, O_RDWR);
	if (fd == -1)
		return (ft_mgt_error(2, ""));
	while (get_next_line(fd, &line) != 0 && !ft_is_wall(line))
	{
		if (!ft_get_info_map(line, info_map))
			return (free(line), 0);
		free(line);
	}
	if (info_map->info_count < 6)
		return (ft_mgt_error(9, "Error\n:some info missing"));
	if (ft_strlen(line) == 0)
		return (ft_mgt_error(9, "Error\n:map not found!"));
	if (!ft_read_map(info_map, fd, line))
		return (0);
	return (1);
}

int	ft_read_management(char *s, t_info *info_map)
{
	t_len_map	len;

	if (ft_check_extension(s) == 0)
	{
		ft_mgt_error(1, "");
		return (0);
	}
	else
	{
		if ((ft_read_info(s, info_map)) == 0)
			return (0);
		if (!ft_parse_management(info_map, &len))
			return (0);
	}
	return (1);
}
