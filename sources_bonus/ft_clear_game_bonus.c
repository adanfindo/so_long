/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:51:06 by afindo          #+#    #+#             */
/*   Updated: 2022/03/03 15:04:59 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_clean_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_quit_game(t_solong *sl)
{
	ft_clean_map(sl->map);
	mlx_destroy_window(sl->mlx, sl->window);
	exit(0);
	return (0);
}
