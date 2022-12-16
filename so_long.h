/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:48:10 by ratinax           #+#    #+#             */
/*   Updated: 2022/12/16 12:03:03 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft/libft.h"
# include <errno.h>
# include <string.h>
# include "minilibx/mlx.h"

# define K_DOWN 65364
# define K_UP 65362
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_ESCAPE 65307

typedef struct s_amount
{
	int	exit;
	int	item;
	int	start;
}	t_amount;

typedef struct s_list_breakpoint
{
	int							i;
	int							j;
	struct s_list_breakpoint	*next;
}	t_lst_bp;

typedef struct s_game
{
	char	**str;
	void	*mlx;
	void	*win;
	void	*up;
	void	*up2;
	void	*down;
	void	*down2;
	void	*left;
	void	*left2;
	void	*right;
	void	*right2;
	void	*pl;
	void	*pl2;
	void	*wall;
	void	*key;
	void	*way;
	void	*exit;
	int		i;
	int		j;
	int		width;
	int		height;
	int		nb_img;
	int		amount_key;
	int		amount_move;
}	t_game;

char		**get_input(char *filename);
int			good_input(char **str);
int			is_path(char **str);
/*Test paths*/
int			nb_directions(char **str, int i, int j);
t_lst_bp	*find_start(char **str);
char		**strrdup(char **str);
void		ft_test_moove(char **str, int *i, int *j);
void		go_to_bp(int *i, int *j, t_lst_bp **bp);
int			amount_collectibles(char **str);
/*lists breakpoint*/
t_lst_bp	*ft_lst_bp_new(int i, int j);
t_lst_bp	*ft_lst_bp_last(t_lst_bp *lst);
void		ft_lst_bp_add_back(t_lst_bp **lst, t_lst_bp *new);
void		ft_lst_bp_del_last(t_lst_bp **lst);
void		ft_lst_bp_clear(t_lst_bp **lst);
/*Visual*/
int			game(char **str);
/*Init*/
void		init_img(t_game *g);
void		put_background(t_game *g);
void		init_game(t_game *g, char **str);
void		good_img_pl(int keycode, t_game *g);
#endif
