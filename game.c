/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:27:12 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/16 15:19:14 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int keycode, t_game *g)
{
	g->nb_img -= (keycode == K_LEFT || keycode == K_UP);
	g->nb_img += (keycode == K_RIGHT || keycode == K_DOWN);
	if (keycode == K_LEFT || keycode == K_UP
		|| keycode == K_RIGHT || keycode == K_DOWN)
	{
		if (g->str[g->i - (keycode == K_UP) + (keycode == K_DOWN)][g->j
			- (keycode == K_LEFT) + (keycode == K_RIGHT)] != '1')
		{
			(g->j) = (g->j) - (keycode == K_LEFT) + (keycode == K_RIGHT);
			(g->i) = (g->i) - (keycode == K_UP) + (keycode == K_DOWN);
			g->amount_move++;
			ft_printf("%d\n", g->amount_move);
		}
	}
	good_img_pl(keycode, g);
	if (g->nb_img % 2 == 0)
		mlx_put_image_to_window(g->mlx, g->win, g->pl, g->j * 50, g->i * 50);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->pl2, g->j * 50, g->i * 50);
}

int	key_handle(int keycode, t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	put_background(g);
	move(keycode, g);
	if (g->str[g->i][g->j] == 'C')
	{
		g->str[g->i][g->j] = '0';
		g->amount_key--;
		if (g->amount_key == 0)
		{
			put_background(g);
			mlx_put_image_to_window(g->mlx, g->win,
				g->pl, g->j * 50, g->i * 50);
		}
	}
	if (keycode == K_ESCAPE
		|| (g->amount_key == 0 && g->str[g->i][g->j] == 'E'))
	{
		mlx_destroy_window(g->mlx, g->win);
		free_array(g->str, 1);
		exit(0);
	}
	ft_printf("--%d--\n", keycode);
	return (0);
}

int	close_window(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	free_array(g->str, 1);
	exit(0);
}

int	game(char **str)
{
	t_game	g;

	init_game(&g, str);
	init_img(&g);
	mlx_do_sync(g.mlx);
	put_background(&g);
	mlx_put_image_to_window(g.mlx, g.win, g.pl, g.j * 50, g.i * 50);
	mlx_hook(g.win, 2, (1L << 0), key_handle, &g);
	mlx_hook(g.win, 17, 0, close_window, &g);
	mlx_loop(g.mlx);
	return (0);
}
