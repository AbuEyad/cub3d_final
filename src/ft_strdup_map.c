/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:02:12 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/07 16:43:38 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strdup_map(char *s)
{
	int		i;
	int		n;
	char	*dest;

	i = 0;
	n = 0;
	while (s[i])
	{
		n++;
		i++;
	}
	dest = (char *)malloc(sizeof(char) * n + 1);
	if (!dest)
		return (NULL);
	i = -1;
	n = 0;
	while (s[++i])
	{
		if (s[i] == ' ')
			dest[n++] = '1';
		else
			dest[n++] = s[i];
	}
	dest[n] = '\0';
	return (free(s), dest);
}
