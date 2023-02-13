/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:03:49 by afindo          #+#    #+#             */
/*   Updated: 2022/03/03 14:49:33 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_shape(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != '\0')
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_wall(char **map)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if ((map[0][j] != '1') || (map[i - 1][j] != '1'))
			return (0);
		j++;
	}
	i = 1;
	size = ft_strlen(map[i]);
	while (map[i] != '\0')
	{
		if ((map[i][0] != '1') || (map[i][size - 1]) != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_exit(t_solong *sl)
{
	int	i;
	int	j;

	i = 1;
	if (!sl->map)
		return (0);
	while (sl->map[i] != '\0')
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			if (sl->map[i][j] == 'E')
				sl->map_exit++;
			j++;
		}
		i++;
	}
	if (sl->map_exit < 1)
		return (0);
	return (1);
}

int	ft_check_coll(t_solong *sl)
{
	int	i;
	int	j;

	i = 1;
	if (!sl->map)
		return (0);
	while (sl->map[i] != '\0')
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			if (sl->map[i][j] == 'C')
				sl->map_coll++;
			j++;
		}
		i++;
	}
	if (sl->map_coll < 1)
		return (0);
	return (1);
}

int	ft_check_pos(t_solong *sl)
{
	int	i;
	int	j;

	i = 1;
	if (!sl->map)
		return (0);
	while (sl->map[i] != '\0')
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			if (sl->map[i][j] == 'P')
				sl->map_ally++;
			j++;
		}
		i++;
	}
	if (sl->map_ally != 1)
		return (0);
	return (1);
}
