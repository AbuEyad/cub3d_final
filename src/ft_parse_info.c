/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:00:48 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 18:02:18 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_extension(char *s)
{
	int		i;
	int		n;
	char	*cub;

	i = 0;
	cub = ".cub";
	while (s[i])
	{
		n = 0;
		while (s[i + n] == cub[n] && cub[n])
		{
			if (s[i + n + 1] == '\0' && cub[n + 1] == '\0')
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

int	ft_check_open_texture(t_info *info_map)
{
	if ((open(info_map->north_t, O_RDONLY)) == -1)
		return (0);
	if ((open(info_map->south_t, O_RDONLY)) == -1)
		return (0);
	if ((open(info_map->east_t, O_RDONLY)) == -1)
		return (0);
	if ((open(info_map->west_t, O_RDONLY)) == -1)
		return (0);
	return (1);
}

int	ft_parse_info(t_info *info_map)
{
	if (info_map->colorf < 0 || info_map->colorc < 0)
	{
		ft_putstr("Error\n: color ");
		ft_mgt_error(9, "floor or ceil have to >= 0 && < 256\n");
		return (0);
	}
	if (!ft_check_open_texture(info_map))
	{
		ft_mgt_error(9, "Error\n: open(texture) failed\n");
		return (0);
	}
	return (1);
}

int	ft_check_map(t_info *info_map)
{
	int	i;
	int	x;

	i = 0;
	while (info_map->map[i])
	{
		x = 0;
		while (info_map->map[i][x])
		{
			if (info_map->map[i][x] != '0' && info_map->map[i][x] != '1' &&
			info_map->map[i][x] != 'N' && info_map->map[i][x] != 'S' &&
			info_map->map[i][x] != 'E' && info_map->map[i][x] != 'W' &&
			info_map->map[i][x] != '2')
				return (ft_mgt_error(6, ""));
			if (info_map->map[i][x] == 'N' || info_map->map[i][x] == 'S' ||
			info_map->map[i][x] == 'E' || info_map->map[i][x] == 'W')
				if (!(ft_get_pos_player(info_map, i, x)))
					return (0);
			x++;
		}
		i++;
	}
	if (info_map->player_start == '0')
		return (ft_mgt_error(8, ""));
	return (1);
}

int	ft_parse_management(t_info *info_map, t_len_map *len)
{
	if (!open_zero(info_map->map))
	{
		ft_mgt_error(9, "Error\n: open zero");
		return (0);
	}
	if (!ft_parse_info(info_map))
		return (0);
	if (!ft_parse_map_line_updown(info_map)
		|| !ft_parse_map_line_between(info_map, len))
	{
		ft_mgt_error(5, "");
		return (0);
	}
	if (!ft_check_map(info_map))
		return (0);
	return (1);
}
