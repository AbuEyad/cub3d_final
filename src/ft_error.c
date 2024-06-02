/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:05:45 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 18:02:18 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_information_start(int error)
{
	if (error == -1)
		ft_putstr("Error\n: The programme cannot run without file [*.cub]\n");
	else if (error == 0)
		ft_putstr("Error\n: To much argument, the programme can run only with");
	else if (error == 1)
	{
		ft_putstr("Error\n: Extension of files no correct, put map in format");
		ft_putstr(" [*.cub]\n");
	}
	else if (error == 2)
		ft_putstr("Error\n: open(*.cub) failed\n");
}

void	ft_information_error(int error, char *s)
{
	if (error == 3)
	{
		ft_put2str("Error\n: information no correct [", s);
		ft_putstr("]\n");
	}
	else if (error == 4)
	{
		ft_put2str("Error\n: color for floor or ceil not correct [", s);
		ft_putstr("]\nExemple : F 220,100,0\n");
	}
	else if (error == 10)
		ft_putstr("Error\n: Mutiple resolution, put only one resolution\n");
	else if (error == 11)
	{
		ft_put2str("Error\n: Duplicate texture [", s);
		ft_putstr("]\n");
	}
	else if (error == 12)
	{
		ft_put2str("Error\n: Numbers Must be Integers[", s);
		ft_putstr("]\n");
	}
}

void	ft_map_error(int error)
{
	if (error == 5)
		ft_putstr("Error\n: Map isn't surrounded by a wall\n");
	else if (error == 6)
	{
		ft_putstr("Error\n: Character in the map no valid, ");
		ft_putstr("put only [0,1,2,N,S,E,W]\n");
	}
	else if (error == 7)
		ft_putstr("Error\n: Multiple player positions\n");
	else if (error == 8)
		ft_putstr("Error\n: No player positions\n");
	else if (error == 9)
		ft_putstr("Error\n: Empty line in the map\n");
}

int	ft_mgt_error(int error, char *s)
{
	if (error >= -2 && error <= 2)
		ft_information_start(error);
	if (error == 3 || error == 4 || error == 10 || error == 11 || error == 12)
		ft_information_error(error, s);
	if (error >= 5 && error <= 8)
		ft_map_error(error);
	if (error == 9)
		ft_putstr(s);
	if (error == 4 || error == 12)
		return (-1);
	return (0);
}
