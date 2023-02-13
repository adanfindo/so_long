/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:19:09 by afindo          #+#    #+#             */
/*   Updated: 2022/03/03 15:05:05 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw_all(t_solong *sl)
{
	ft_draw_bckg(sl);
	ft_draw_wall(sl);
	ft_draw_ally(sl);
	ft_draw_coll(sl);
	ft_draw_exit(sl);
	ft_draw_enemy(sl);
}

void	ft_window_size(t_solong *sl)
{
	int	i;

	sl->map_w = ft_strlen(sl->map[0]) * 48;
	i = 0;
	while (sl->map[i] != '\0')
		i++;
	sl->map_h = i * 48;
}

void	ft_gamebegin(t_solong *sl)
{
	sl->mlx = mlx_init();
	ft_window_size(sl);
	sl->window = mlx_new_window(sl->mlx, sl->map_w, sl->map_h, "Terraria");
	sl->moves = 0;
	sl->stopgame = 0;
	sl->loopanim = 0;
	sl->animate = 1;
	ft_draw_all(sl);
}
