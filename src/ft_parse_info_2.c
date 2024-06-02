/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:54:21 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 18:02:18 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_get_pos_player(t_info *info_map, int i, int x)
{
	if (info_map->player_start == '0')
	{
		info_map->player_x = x;
		info_map->player_y = i;
		info_map->player_start = info_map->map[i][x];
		info_map->map[i][x] = '0';
	}
	else
		return (ft_mgt_error(7, ""));
	return (1);
}
