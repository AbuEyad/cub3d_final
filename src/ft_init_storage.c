/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_storage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:06:23 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 13:41:26 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_storage(t_info *info_map, t_mlx *mlx, t_player *player,
t_storage *storage)
{
	storage->info = info_map;
	storage->mlx = mlx;
	storage->player = player;
	player->pos_x = storage->info->player_x + 0.5;
	player->pos_y = storage->info->player_y + 0.5;
}

void	ft_fill_storage(t_move *move, t_ray *ray, t_storage *storage)
{
	storage->move = move;
	storage->ray = ray;
}
