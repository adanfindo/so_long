/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:34:04 by afindo          #+#    #+#             */
/*   Updated: 2022/02/23 17:38:06 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_bckg(t_solong *sl)
{
	int		i;
	int		j;
	char	*path;

	path = "./Images/free.xpm";
	i = 0;
	sl->draw_bckg = mlx_xpm_file_to_image(sl->mlx, path,
			&sl->img_w, &sl->img_h);
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			if (sl->map[i][j] == '0')
				mlx_put_image_to_window(sl->mlx, sl->window, sl->draw_bckg, \
						j * 48, i * 48);
			j++;
		}
		i++;
	}
}

void	ft_draw_wall(t_solong *sl)
{
	int		i;
	int		j;
	char	*path;

	path = "./Images/wall.xpm";
	i = 0;
	sl->draw_wall = mlx_xpm_file_to_image(sl->mlx, path,
			&sl->img_w, &sl->img_h);
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			if (sl->map[i][j] == '1')
				mlx_put_image_to_window(sl->mlx, sl->window, sl->draw_wall, \
						j * 48, i * 48);
			j++;
		}
		i++;
	}
}

void	ft_draw_ally(t_solong *sl)
{
	int		i;
	int		j;
	char	*path;

	path = "./Images/ally.xpm";
	sl->draw_ally = mlx_xpm_file_to_image(sl->mlx, path,
			&sl->img_w, &sl->img_h);
	i = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			if (sl->map[i][j] == 'P')
			{
				mlx_put_image_to_window(sl->mlx, sl->window, sl->draw_ally, \
						j * 48, i * 48);
				sl->ally_x = j;
				sl->ally_y = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_draw_coll(t_solong *sl)
{
	int		i;
	int		j;
	char	*path;

	path = "./Images/collect.xpm";
	sl->draw_coll = mlx_xpm_file_to_image(sl->mlx, path,
			&sl->img_w, &sl->img_h);
	i = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			if (sl->map[i][j] == 'C')
				mlx_put_image_to_window(sl->mlx, sl->window, sl->draw_coll, \
						j * 48, i * 48);
			j++;
		}
		i++;
	}
}

void	ft_draw_exit(t_solong *sl)
{
	int		i;
	int		j;
	char	*path;

	path = "./Images/closed.xpm";
	sl->draw_exit = mlx_xpm_file_to_image(sl->mlx, path,
			&sl->img_w, &sl->img_h);
	i = 0;
	while (sl->map[i])
	{
		j = 0;
		while (sl->map[i][j] != '\0')
		{
			if (sl->map[i][j] == 'E')
				mlx_put_image_to_window(sl->mlx, sl->window, sl->draw_exit, \
						j * 48, i * 48);
			j++;
		}
		i++;
	}
}
