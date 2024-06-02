/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:01:27 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 18:02:40 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_init_texture_data(t_texture *texture)
{
	texture[0].img = mlx_get_data_addr(texture[0].ptr, &texture[0].bpixel,
			&texture[0].size_line, &texture[0].endian);
	if (texture[0].img == NULL)
		return (ft_mgt_error(9, "Error \n: corruption texture north\n"));
	texture[1].img = mlx_get_data_addr(texture[1].ptr, &texture[1].bpixel,
			&texture[1].size_line, &texture[1].endian);
	if (texture[1].img == NULL)
		return (ft_mgt_error(9, "Error \n: corruption texture south\n"));
	texture[2].img = mlx_get_data_addr(texture[2].ptr, &texture[2].bpixel,
			&texture[2].size_line, &texture[2].endian);
	if (texture[2].img == NULL)
		return (ft_mgt_error(9, "Error \n: corruption texture west\n"));
	texture[3].img = mlx_get_data_addr(texture[3].ptr, &texture[3].bpixel,
			&texture[3].size_line, &texture[3].endian);
	if (texture[3].img == NULL)
		return (ft_mgt_error(9, "Error \n: corruption texture east\n"));
	return (1);
}

int	ft_init_texture(t_storage *s, t_texture *texture, int w, int h)
{
	texture[0].ptr = mlx_xpm_file_to_image(s->mlx->ptr,
			s->info->north_t, &w, &h);
	texture[1].ptr = mlx_xpm_file_to_image(s->mlx->ptr,
			s->info->south_t, &w, &h);
	texture[2].ptr = mlx_xpm_file_to_image(s->mlx->ptr,
			s->info->west_t, &w, &h);
	texture[3].ptr = mlx_xpm_file_to_image(s->mlx->ptr,
			s->info->east_t, &w, &h);
	if (!(texture[0].ptr) || !(texture[1].ptr) || !(texture[2].ptr)
		|| !(texture[3].ptr))
		return (ft_mgt_error(9, "Error \n: corruption texture\n"));
	texture[4].ptr = NULL;
	ft_init_texture_data(texture);
	s->texture = texture;
	return (1);
}

void	ft_init_value(t_storage *s, t_text_info *text_i, t_ray *ray)
{
	text_i->w = 64;
	text_i->h = 64;
	text_i->lh = (int)(s->info->ry / ray->perpwalldist);
	text_i->dr_st = -text_i->lh / 2 + s->info->ry / 2;
	if (text_i->dr_st < 0)
		text_i->dr_st = 0;
	text_i->dr_en = text_i->lh / 2 + s->info->ry / 2;
	if (text_i->dr_en >= s->info->ry)
		text_i->dr_en = s->info->ry - 1;
	if (ray->side == 0)
		text_i->wallx = s->player->pos_y + ray->perpwalldist
			* ray->raydir_y;
	else
		text_i->wallx = s->player->pos_x + ray->perpwalldist
			* ray->raydir_x;
	text_i->wallx -= floor(text_i->wallx);
	text_i->x = (int)(text_i->wallx * (double)text_i->w);
	if (ray->side == 0 && ray->raydir_x > 0)
		text_i->x = text_i->w - text_i->x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		text_i->x = text_i->w - text_i->x - 1;
}

void	ft_management_texture(t_storage *s, t_ray *ray, int x)
{
	t_text_info		text_i;

	ft_init_value(s, &text_i, ray);
	if (ray->side == 1)
		ft_drw_wl_txr_sn(s, s->texture, &text_i, x);
	else
		ft_drw_wl_txr_ew(s, s->texture, &text_i, x);
}
