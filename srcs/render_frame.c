/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_frame.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:49:46 by nvan-der      #+#    #+#                 */
/*   Updated: 2021/05/12 09:54:29 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "../includes/cub3d.h"

/*
**		Constantly checks, calculates and draws the game.
*/

int	frame_loop(t_data *mlx)
{
	int		x;
	t_image	*cur_img;

	if (mlx->active_img)
		cur_img = &mlx->img1;
	else
		cur_img = &mlx->img2;
	draw_floors(mlx, cur_img);
	x = 0;
	while (x < mlx->map.res.x)
	{
		calculate_variables(mlx, x);
		calculate_texture(mlx);
		draw_wall_texture(mlx, x, cur_img);
		x++;
	}
	sprite_engine(mlx, cur_img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, cur_img->img, 0, 0);
	mlx->active_img = !mlx->active_img;
	move_player(mlx);
	return (0);
}

/*
**		Renders one frame for the screenshot.
*/

void	screenshot_frame_loop(t_data *mlx)
{
	int		x;

	draw_floors(mlx, &mlx->img1);
	x = 0;
	while (x < mlx->map.res.x)
	{
		calculate_variables(mlx, x);
		calculate_texture(mlx);
		draw_wall_texture(mlx, x, &mlx->img1);
		x++;
	}
	sprite_engine(mlx, &mlx->img1);
}
