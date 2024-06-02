/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:46:27 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 17:00:56 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_parse_map_line_updown(t_info *info_map)
{
	int		i;
	int		n;

	i = 0;
	while (info_map->map[0][i])
	{
		if (info_map->map[0][i] != '1' && info_map->map[0][i] != '2')
			return (0);
		i++;
	}
	i = 0;
	while (info_map->map[i])
		i++;
	i--;
	info_map->len_map = i;
	n = 0;
	while (info_map->map[i][n])
	{
		if (info_map->map[i][n] != '1' && info_map->map[i][n] != '2')
			return (0);
		n++;
	}
	return (1);
}

void	ft_get_len_line(t_info *info_map, t_len_map *len, int line)
{
	len->l1 = ft_strlen(info_map->map[line]);
	len->l2 = ft_strlen(info_map->map[line + 1]);
	len->check = len->l1 - len->l2;
}

int	ft_check_line1(t_info *info_map, t_len_map *len, int line)
{
	if (info_map->map[line][0] != '1')
		return (0);
	len->l1 = len->l1 - len->check;
	while (info_map->map[line][len->l1])
	{
		if (info_map->map[line][len->l1] != '1')
			return (0);
		len->l1++;
	}
	if (info_map->map[line + 1][0] != '1' ||
	info_map->map[line + 1][len->l2 - 1] != '1')
		return (0);
	return (1);
}

int	ft_check_line2(t_info *info_map, t_len_map *len, int line)
{
	if (info_map->map[line + 1][0] != '1')
		return (0);
	len->check *= -1;
	len->l2 = len->l2 - len->check;
	while (info_map->map[line + 1][len->l2])
	{
		if (info_map->map[line + 1][len->l2] != '1')
			return (0);
		len->l2++;
	}
	if (info_map->map[line][0] != '1' ||
	info_map->map[line][len->l1 - 1] != '1')
		return (0);
	return (1);
}

int	ft_parse_map_line_between(t_info *info_map, t_len_map *len)
{
	int		line;

	line = 0;
	while (info_map->map[line + 1] != NULL)
	{
		ft_get_len_line(info_map, len, line);
		if (len->check == 0)
		{
			if (info_map->map[line][0] != '1' ||
			info_map->map[line][len->l1 - 1] != '1')
				return (0);
		}
		else if (len->check >= 1)
		{
			if (!ft_check_line1(info_map, len, line))
				return (0);
		}
		else if (len->check < 0)
		{
			if (!ft_check_line2(info_map, len, line))
				return (0);
		}
		line++;
	}
	return (1);
}
