/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:57:32 by afindo          #+#    #+#             */
/*   Updated: 2022/03/01 12:25:52 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win_game(t_solong *sl)
{
	ft_window_size(sl);
	sl->draw_win = mlx_xpm_file_to_image(sl->mlx, "./Images/win.xpm", \
		&sl->img_w, &sl->img_h);
	sl->map_w = sl->map_w / 2 - 90;
	sl->map_h = sl->map_h / 2 - 60;
	mlx_put_image_to_window(sl->mlx, sl->window, sl->draw_win, \
		sl->map_w, sl->map_h);
}

void	ft_imgtowin(t_solong *sl, void *img, int x, int y)
{
	mlx_put_image_to_window(sl->mlx, sl->window, img, x * 48, y * 48);
}

void	ft_exitimg(t_solong *sl, int x, int y)
{
	if (sl->map_coll == 0)
	{
		mlx_destroy_image(sl->mlx, sl->draw_exit);
		sl->draw_exit = mlx_xpm_file_to_image(sl->mlx, "./Images/open.xpm",
				&sl->img_w, &sl->img_h);
	}
	ft_imgtowin(sl, sl->draw_exit, x, y);
}

void	ft_allyimg(t_solong *sl, void *img, int x, int y)
{
	sl->ally_x = x;
	sl->ally_y = y;
	ft_imgtowin(sl, img, x, y);
}

int	ft_map_updt(t_solong *sl)
{
	int	y;
	int	x;

	y = 0;
	while (sl->map[y])
	{
		x = 0;
		while (sl->map[y][x])
		{
			if (sl->map[y][x] == '1')
				ft_imgtowin(sl, sl->draw_wall, x, y);
			else if (sl->map[y][x] == '0')
				ft_imgtowin(sl, sl->draw_bckg, x, y);
			else if (sl->map[y][x] == 'P')
				ft_allyimg(sl, sl->draw_ally, x, y);
			else if (sl->map[y][x] == 'C')
				ft_imgtowin(sl, sl->draw_coll, x, y);
			else if (sl->map[y][x] == 'E')
				ft_exitimg(sl, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
