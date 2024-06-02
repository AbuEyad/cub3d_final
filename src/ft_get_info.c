/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:06:16 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 18:54:24 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_get_texture_path_north_south(char *s, t_info *info_map)
{
	int	i;

	i = 2;
	while (s[i] == ' ')
		i++;
	if (s[0] == 'N')
	{
		if (info_map->north_t[0] != '\0')
			return (ft_mgt_error(11, s));
		ft_strcpy(info_map->north_t, &s[i]);
	}
	else if (s[0] == 'S' && s[1] == 'O')
	{
		if (info_map->south_t[0] != '\0')
			return (ft_mgt_error(11, s));
		ft_strcpy(info_map->south_t, &s[i]);
	}
	info_map->info_count++;
	return (1);
}

static int	is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_convert_rgb_to_integer(char *s)
{
	int		i;
	int		nb[4];
	char	**tab;

	i = 0;
	tab = ft_split(&s[1], ',');
	while (tab[i] && !is_digit(tab[i]))
		i++;
	if (i != 3)
		return (ft_mgt_error(4, s));
	i = 0;
	while (i < 3)
	{
		if ((tab[i] == NULL) || !ft_check_space_rgb(tab, i))
			return (ft_mgt_error(4, s));
		else if (ft_strchr(tab[i], '.') != NULL)
			return (ft_mgt_error(12, s));
		else
		{
			nb[i] = ft_atoi(tab[i]);
			i++;
		}
	}
	ft_free_tab(tab);
	return (ft_verif_rgb_is_valid(nb, i));
}

int	ft_get_color(char *s, t_info *info_map)
{
	if (s[0] == 'F' && info_map->colorf == 0)
		info_map->colorf = ft_convert_rgb_to_integer(s);
	else if (s[0] == 'C' && info_map->colorc == 0)
		info_map->colorc = ft_convert_rgb_to_integer(s);
	else
	{
		ft_putstr("Error: Duplicate color floor or ceil :");
		return (ft_mgt_error(9, s));
	}
	info_map->info_count++;
	return (1);
}

int	ft_get_info_map(char *s, t_info *info_map)
{
	if ((s[0] == 'N' && s[1] == 'O') || (s[0] == 'S' && s[1] == 'O'))
	{
		if ((ft_get_texture_path_north_south(s, info_map)) == 0)
			return (0);
	}
	else if ((s[0] == 'W' && s[1] == 'E') || (s[0] == 'E' && s[1] == 'A'))
	{
		if ((ft_get_texture_path_west_east_s(s, info_map)) == 0)
			return (0);
	}
	else if (s[0] == 'F' || s[0] == 'C')
	{
		if ((ft_get_color(s, info_map)) == 0)
			return (0);
	}
	else if (s[0] == '\n' || s[0] == '\0')
		return (1);
	else
		return (ft_mgt_error(3, s));
	return (1);
}
