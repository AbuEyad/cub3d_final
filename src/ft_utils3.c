/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:01:12 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 18:05:00 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	upper_one(char **map, int i, int j)
{
	if (i == 0)
		return (0);
	while (i >= 0)
	{
		if (map[i][j] == '1')
			return (1);
		i--;
	}
	return (0);
}

int	lower_one(char **map, int i, int j)
{
	while (map[i])
	{
		if (map[i][j] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	open_zero(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				if (!upper_one(map, i, j) || !lower_one(map, i, j))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
