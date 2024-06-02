/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:05:36 by habu-zua          #+#    #+#             */
/*   Updated: 2024/05/31 16:34:11 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_drw_wl_txr_sn(t_storage *s, t_texture *txr,
t_text_info *t_i, int x)
{
	if (s->ray->raydir_y >= 0)
	{
		while (t_i->dr_st < t_i->dr_en)
		{
			t_i->y = abs((((t_i->dr_st * 256 - s->info->ry
								* 128 + t_i->lh * 128) * 64) / t_i->lh) / 256);
			ft_memcpy(s->mlx->data_img + 4 * s->info->rx * t_i->dr_st
				+ x * 4, &txr[1].img[t_i->y % 64 * txr[1].size_line
				+ t_i->x % 64 * txr[1].bpixel / 8], sizeof(int));
			t_i->dr_st++;
		}
	}
	else
	{
		while (t_i->dr_st < t_i->dr_en)
		{
			t_i->y = abs((((t_i->dr_st * 256 - s->info->ry * 128
								+ t_i->lh * 128) * 64) / t_i->lh) / 256);
			ft_memcpy(s->mlx->data_img + 4 * s->info->rx * t_i->dr_st + x
				* 4, &txr[0].img[t_i->y % 64 * txr[0].size_line
				+ t_i->x % 64 * txr[0].bpixel / 8], sizeof(int));
			t_i->dr_st++;
		}
	}
}

void	ft_drw_wl_txr_ew(t_storage *s, t_texture *txr,
t_text_info *text_i, int x)
{
	if (s->ray->raydir_x >= 0)
	{
		while (text_i->dr_st < text_i->dr_en)
		{
			text_i->y = abs((((text_i->dr_st * 256 - s->info->ry * 128
								+ text_i->lh * 128) * 64) / text_i->lh) / 256);
			ft_memcpy(s->mlx->data_img + 4 * s->info->rx * text_i->dr_st
				+ x * 4, &txr[3].img[text_i->y % 64 * txr[3].size_line
				+ text_i->x % 64 * txr[3].bpixel / 8], sizeof(int));
			text_i->dr_st++;
		}
	}
	else
	{
		while (text_i->dr_st < text_i->dr_en)
		{
			text_i->y = abs((((text_i->dr_st * 256 - s->info->ry * 128
								+ text_i->lh * 128) * 64) / text_i->lh) / 256);
			ft_memcpy(s->mlx->data_img + 4 * s->info->rx * text_i->dr_st
				+ x * 4, &txr[2].img[text_i->y % 64 * txr[2].size_line
				+ text_i->x % 64 * txr[2].bpixel / 8], sizeof(int));
			text_i->dr_st++;
		}
	}
}
