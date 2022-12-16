/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:45:20 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/16 14:53:24 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game *g)
{
	g->down = mlx_xpm_file_to_image(g->mlx, "images/down.xpm",
			&g->width, &g->height);
	g->down2 = mlx_xpm_file_to_image(g->mlx, "images/down2.xpm",
			&g->width, &g->height);
	g->up = mlx_xpm_file_to_image(g->mlx, "images/up.xpm",
			&g->width, &g->height);
	g->up2 = mlx_xpm_file_to_image(g->mlx, "images/up2.xpm",
			&g->width, &g->height);
	g->left = mlx_xpm_file_to_image(g->mlx, "images/left.xpm",
			&g->width, &g->height);
	g->left2 = mlx_xpm_file_to_image(g->mlx, "images/left2.xpm",
			&g->width, &g->height);
	g->right = mlx_xpm_file_to_image(g->mlx, "images/right.xpm",
			&g->width, &g->height);
	g->right2 = mlx_xpm_file_to_image(g->mlx, "images/right2.xpm",
			&g->width, &g->height);
	g->wall = mlx_xpm_file_to_image(g->mlx, "images/wall.xpm",
			&g->width, &g->height);
	g->key = mlx_xpm_file_to_image(g->mlx, "images/key.xpm",
			&g->width, &g->height);
	g->way = mlx_xpm_file_to_image(g->mlx, "images/way.xpm",
			&g->width, &g->height);
	g->exit = mlx_xpm_file_to_image(g->mlx, "images/exit.xpm",
			&g->width, &g->height);
	g->pl = g->down;
}

void	init_game(t_game *g, char **str)
{
	t_lst_bp	*start;

	start = find_start(str);
	g->i = 0;
	g->nb_img = 0;
	g->str = str;
	g->width = ft_strlen(g->str[0]) * 50;
	while (g->str[g->i])
		g->i++;
	g->height = g->i * 50;
	g->i = start->i;
	g->j = start->j;
	ft_lst_bp_clear(&start);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->width, g->height, "so_long");
	g->amount_key = amount_collectibles(str);
	g->amount_move = 0;
}

void	put_background(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (g->str[j])
	{
		i = 0;
		while (g->str[j][i])
		{
			if (is_in(g->str[j][i], "0PEC"))
				mlx_put_image_to_window(g->mlx, g->win, g->way, i * 50, j * 50);
			if (g->str[j][i] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->wall,
					i * 50, j * 50);
			if (g->str[j][i] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->key, i * 50, j * 50);
			if (g->str[j][i] == 'E' && g->amount_key == 0)
				mlx_put_image_to_window(g->mlx, g->win, g->exit,
					i * 50, j * 50);
			i++;
		}
		j++;
	}
	return ;
}

void	good_img_pl(int keycode, t_game *g)
{
	if (keycode == K_LEFT)
	{
		g->pl = g->left;
		g->pl2 = g->left2;
	}
	if (keycode == K_RIGHT)
	{
		g->pl = g->right;
		g->pl2 = g->right2;
	}
	if (keycode == K_UP)
	{
		g->pl = g->up;
		g->pl2 = g->up2;
	}
	if (keycode == K_DOWN)
	{
		g->pl = g->down;
		g->pl2 = g->down2;
	}
}
