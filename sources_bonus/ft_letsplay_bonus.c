/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letsplay_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:52:50 by afindo          #+#    #+#             */
/*   Updated: 2022/03/02 17:17:29 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_in_game_events(int keycode, t_solong *sl)
{
	if (keycode == 13)
	{
		sl->ally_y -= 1;
		ft_player_w(sl);
	}
	else if (keycode == 1)
	{
		sl->ally_y += 1;
		ft_player_s(sl);
	}
	else if (keycode == 0)
	{
		sl->ally_x -= 1;
		ft_player_a(sl);
	}
	else if (keycode == 2)
	{
		sl->ally_x += 1;
		ft_player_d(sl);
	}
	return (0);
}

int	ft_check_key(int keycode, t_solong *sl)
{
	if (keycode == 53 || keycode == 12)
		ft_quit_game(sl);
	else if (!sl->stopgame)
		ft_in_game_events(keycode, sl);
	return (0);
}

void	ft_lets_play(t_solong *sl)
{
	mlx_hook(sl->window, 2, 1L << 0, ft_check_key, sl);
	mlx_hook(sl->window, 17, 1L << 17, ft_quit_game, sl);
	mlx_hook(sl->window, 9, 1L << 21, ft_map_updt, sl);
	mlx_loop_hook(sl->mlx, ft_change_enemy_img, sl);
}
