/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:01:08 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 18:03:24 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_verif_rgb_is_valid(int nb[4], int n)
{
	if (nb[0] > 255 || nb[1] > 255 || nb[2] > 255)
		return (-2);
	else if (nb[0] < 0 || nb[1] < 0 || nb[2] < 0)
		return (-2);
	else
		nb[n] = 65536 * nb[0] + 256 * nb[1] + nb[2];
	return (nb[n]);
}

int	ft_get_texture_path_west_east_s(char *s, t_info *info_map)
{
	int	i;

	i = 2;
	while (s[i] == ' ')
		i++;
	if (s[0] == 'W')
	{
		if (info_map->west_t[0] != '\0')
			return (ft_mgt_error(11, s));
		ft_strcpy(info_map->west_t, &s[i]);
	}
	else if (s[0] == 'E')
	{
		if (info_map->east_t[0] != '\0')
			return (ft_mgt_error(11, s));
		ft_strcpy(info_map->east_t, &s[i]);
	}
	info_map->info_count++;
	return (1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_check_space_rgb(char **tab, int i)
{
	int	n;
	int	valid;

	n = 0;
	valid = 0;
	while (tab[i][n])
	{
		if (tab[i][n] != ' ')
			valid = 1;
		n++;
	}
	if (valid == 0)
		return (0);
	return (1);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
}
