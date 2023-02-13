/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:34:11 by afindo          #+#    #+#             */
/*   Updated: 2022/03/03 14:53:51 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../utils/get_next_line.h"
# include "../minilibx/mlx.h"

/* SO_LONG STRUCT */
typedef struct s_solong
{
	char	**map;
	void	*mlx;
	void	*window;
	void	*image;
	void	*draw_bckg;
	void	*draw_wall;
	void	*draw_exit;
	void	*draw_ally;
	void	*draw_coll;
	void	*draw_win;
	void	*draw_lose;
	void	*draw_enemy;
	int		stopgame;
	int		moves;
	int		img_w;
	int		img_h;
	int		ally_x;
	int		ally_y;
	int		enemy_x;
	int		enemy_y;
	int		loopanim;
	int		loopcoll;
	int		animate;
	int		collanim;
	int		map_wall;
	int		map_exit;
	int		map_coll;
	int		map_ally;
	int		map_w;
	int		map_h;
}				t_solong;
/* UTILS */
char	**ft_split(char const *s, char c);
int		ft_strchr(const char *s, int c);
int		ft_print(char *string, ...);
char	*ft_itoa(int n);
/* MAP CHECK */
char	**ft_mapread(char *pattern);
int		ft_check_exit(t_solong *sl);
int		ft_check_coll(t_solong *sl);
int		ft_mapchecker(t_solong *sl);
int		ft_check_shape(char **map);
int		ft_check_pos(t_solong *sl);
int		ft_check_wall(char **map);
int		ft_check_char(char **map);
/* DRAW MAPS AND DRAW OBJECT */
void	ft_imgtowin(t_solong *sl, void *image, int x, int y);
void	ft_allyimg(t_solong *sl, void *img, int x, int y);
void	ft_change_ally_img(int key, t_solong *sl);
void	ft_exitimg(t_solong *sl, int x, int y);
void	ft_window_size(t_solong *sl);
void	ft_gamebegin(t_solong *sl);
void	ft_draw_bckg(t_solong *sl);
void	ft_draw_wall(t_solong *sl);
void	ft_draw_ally(t_solong *sl);
void	ft_draw_coll(t_solong *sl);
void	ft_draw_exit(t_solong *sl);
void	ft_draw_init(t_solong *sl);
int		ft_map_updt(t_solong *sl);
/* PLAYER ACTIONS */
void	ft_player_w(t_solong *sl);
void	ft_player_a(t_solong *sl);
void	ft_player_s(t_solong *sl);
void	ft_player_d(t_solong *sl);
/* GAMEPLAY */
int		ft_in_game_events(int keycode, t_solong *sl);
void	ft_lets_play(t_solong *sl);
void	ft_lose_game(t_solong *sl);
void	ft_win_game(t_solong *sl);
/* QUIT / ERROR HANDLING */
int		ft_quit_game(t_solong *sl);
void	ft_clean_map(char **map);
/* BONUS */
void	ft_enemyimg(t_solong *sl, void *img, int x, int y);
int		ft_change_enemy_img(t_solong *sl);
void	ft_draw_enemy(t_solong *sl);
void	ft_draw_moves(t_solong *sl);

#endif
