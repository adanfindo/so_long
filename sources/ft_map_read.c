/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:53:38 by afindo          #+#    #+#             */
/*   Updated: 2022/03/03 14:46:42 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_mapread(char *pattern)
{
	int		fd;
	char	*line;
	char	**map;
	char	*tempmap;
	char	*temp;

	fd = open(pattern, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tempmap = malloc(sizeof(char) * 1);
	tempmap[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = tempmap;
		tempmap = ft_strjoin(temp, line);
		free(line);
		free(temp);
	}
	map = ft_split(tempmap, '\n');
	free(tempmap);
	close(fd);
	return (map);
}

int	ft_check_char(char **map)
{
	int	i;
	int	j;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && \
				map[i][j] != 'P' && map[i][j] != 'E' && \
				map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_mapchecker(t_solong *sl)
{
	if (ft_check_coll(sl) && ft_check_exit(sl) && ft_check_shape(sl->map) \
		&& ft_check_pos(sl) && ft_check_wall(sl->map) \
		&& ft_check_char(sl->map))
		return (1);
	return (0);
}
