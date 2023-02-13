/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:04:12 by afindo          #+#    #+#             */
/*   Updated: 2022/03/02 17:25:56 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw_moves(t_solong *sl)
{
	char	*str;

	str = ft_itoa(sl->moves);
	mlx_string_put(sl->mlx, sl->window, 25, 20, 0x00FFFFFF, "Moves: ");
	mlx_string_put(sl->mlx, sl->window, 85, 20, 0x00FFFFFF, str);
	free(str);
}

int	ft_change_enemy_img(t_solong *sl)
{
	if (sl->stopgame)
		return (0);
	if (sl->loopanim++ < 1000)
		return (0);
	sl->loopanim = 0;
	if (sl->animate == 1)
		sl->draw_enemy = mlx_xpm_file_to_image
			(sl->mlx, "./Images/Enemy1.xpm", &sl->img_w, &sl->img_h);
	else if (sl->animate == 2)
		sl->draw_enemy = mlx_xpm_file_to_image
			(sl->mlx, "./Images/Enemy2.xpm", &sl->img_w, &sl->img_h);
	else if (sl->animate == 3)
		sl->draw_enemy = mlx_xpm_file_to_image
			(sl->mlx, "./Images/Enemy3.xpm", &sl->img_w, &sl->img_h);
	else if (sl->animate == 4)
	{
		sl->draw_enemy = mlx_xpm_file_to_image
			(sl->mlx, "./Images/Enemy4.xpm", &sl->img_w, &sl->img_h);
		sl->animate = 0;
	}
	ft_map_updt(sl);
	sl->animate++;
	return (0);
}

void	ft_enemyimg(t_solong *sl, void *img, int x, int y)
{
	sl->enemy_x = x;
	sl->enemy_y = y;
	ft_imgtowin(sl, img, x, y);
}

void	ft_draw_enemy(t_solong *sl)
{
	int		i;
	int		j;
	char	*path;

	path = "./Images/Enemy1.xpm";
	sl->draw_enemy = mlx_xpm_file_to_image(sl->mlx, path,
			&sl->img_w, &sl->img_h);
	i = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			if (sl->map[i][j] == 'N')
			{
				mlx_put_image_to_window(sl->mlx, sl->window, sl->draw_enemy, \
						j * 48, i * 48);
				sl->enemy_x = j;
				sl->enemy_y = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_lose_game(t_solong *sl)
{
	ft_window_size(sl);
	mlx_clear_window(sl->mlx, sl->window);
	sl->map[sl->ally_y][sl->ally_x - 1] = '0';
	sl->moves++;
	sl->stopgame = 1;
	sl->draw_lose = mlx_xpm_file_to_image(sl->mlx, "./Images/lose.xpm", \
		&sl->img_w, &sl->img_h);
	sl->map_w = sl->map_w / 2 - 90;
	sl->map_h = sl->map_h / 2 - 60;
	mlx_put_image_to_window(sl->mlx, sl->window, sl->draw_lose, \
		sl->map_w, sl->map_h);
}
