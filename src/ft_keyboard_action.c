/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:06:41 by habu-zua          #+#    #+#             */
/*   Updated: 2024/05/31 16:34:11 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_keyrelease(int keycode, t_move *move)
{
	if (keycode == 53)
		move->esc = 0;
	else if (keycode == 13)
		move->foward = 0;
	else if (keycode == 1)
		move->retreat = 0;
	else if (keycode == 0)
		move->left = 0;
	else if (keycode == 2)
		move->right = 0;
	else if (keycode == 123)
		move->turn_left = 0;
	else if (keycode == 124)
		move->turn_right = 0;
	else if (keycode == 257)
		move->sprint = 0;
	return (0);
}

int	ft_keypress(int keycode, t_move *move)
{
	if (keycode == 53)
		move->esc = 1;
	else if (keycode == 13)
		move->foward = 1;
	else if (keycode == 1)
		move->retreat = 1;
	else if (keycode == 0)
		move->left = 1;
	else if (keycode == 2)
		move->right = 1;
	else if (keycode == 123)
		move->turn_left = 1;
	else if (keycode == 124)
		move->turn_right = 1;
	else if (keycode == 257)
		move->sprint = 1;
	else if (keycode == 18)
		move->texture = 1;
	else if (keycode == 19)
		move->texture = 0;
	return (0);
}
