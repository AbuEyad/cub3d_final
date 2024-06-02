/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:05:03 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 18:02:18 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_expose(t_storage *s)
{
	int		i;

	i = 0;
	s->mlx->img = mlx_new_image(s->mlx->ptr, s->info->rx, s->info->ry);
	s->mlx->data_img = mlx_get_data_addr(s->mlx->img, &s->mlx->bpixel,
			&s->mlx->size_line, &s->mlx->endian);
	s->mlx->bpixel = s->mlx->bpixel / 8;
	while (i < s->info->rx *(s->info->ry) / 2)
		*(int *)&s->mlx->data_img[i++ *s->mlx->bpixel] = s->info->colorc;
	while (i < s->info->rx * (s->info->ry))
		*(int *)&s->mlx->data_img[i++ *s->mlx->bpixel] = s->info->colorf;
	ft_raycaster(s, s->ray);
	free(s->zbuffer);
	if (s->info->rx >= 150 && s->info->ry >= 150)
		ft_draw_mini_map(s);
	ft_player_pos_cam(s, s->player);
	mlx_put_image_to_window(s->mlx->ptr, s->mlx->win, s->mlx->img, 0, 0);
	mlx_destroy_image(s->mlx->ptr, s->mlx->img);
	if (s->move->esc == 1)
		ft_exit_prog(s);
	return (0);
}

void	ft_init1(t_move	*move, t_player *player, t_ray *ray)
{
	ft_init_struct_move(move);
	ft_init_struct_player(player);
	ft_init_struct_ray(ray);
}

int	ft_management_program(t_info *map, t_mlx *mlx)
{
	t_move		move;
	t_player	player;
	t_ray		ray;
	t_storage	storage;
	t_texture	texture[5];

	ft_init1(&move, &player, &ray);
	ft_fill_storage(&move, &ray, &storage);
	ft_init_storage(map, mlx, &player, &storage);
	ft_init_pos_player(&storage, &player);
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		return (ft_mgt_error(9, "Error\n: init fail"));
	mlx->win = mlx_new_window(mlx->ptr, map->rx, map->ry, "Cub3d");
	if (!(mlx->win))
		return (ft_mgt_error(9, "Error\n: windows fail"));
	if ((ft_init_texture(&storage, texture, 64, 64) == 0))
		return (0);
	mlx_hook(mlx->win, KEYPRESS_EVENT, KEYPRESS_MASK, ft_keypress, &move);
	mlx_hook(mlx->win, KEYRELEASE_EVENT, KEYRELEASE_MASK, ft_keyrelease, &move);
	mlx_hook(mlx->win, 17, 0, ft_exit_prog, &storage);
	mlx_loop_hook(mlx->ptr, ft_expose, &storage);
	mlx_loop(mlx->ptr);
	return (0);
}

int	ft_init_program(char **av, t_mlx mlx)
{
	t_info		info_map;

	ft_init_struct_infomap(&info_map);
	if (!ft_read_management(av[1], &info_map))
		return (0);
	ft_check_len_map(&info_map);
	ft_management_program(&info_map, &mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.ptr = 0;
	if (ac < 2)
		ft_mgt_error(-1, "");
	else if (ac > 3)
		ft_mgt_error(0, "");
	else if (ac == 2)
		ft_init_program(av, mlx);
	return (0);
}
