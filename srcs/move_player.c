/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:31:08 by nvan-der      #+#    #+#                 */
/*   Updated: 2021/05/07 08:01:31 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"

/*
**		Calculates when the player is moving forwards or backwards.
*/

void	move_forward_or_backward(t_data *mlx, double dir)
{
	t_vector_d	*player;
	t_vector_d	*move;

	player = &mlx->ray.dir;
	move = &mlx->move.pos;
	if (mlx->map.map[(int)move->y][(int)(move->x + player->x * dir)] == '0')
		move->x += (player->x * dir);
	if (mlx->map.map[(int)(move->y + player->y * dir)][(int)move->x] == '0')
		move->y += (player->y * dir);
}

/*
**		Calculates when the player is strafing.
*/

void	strafe_player(t_data *mlx, double dir)
{
	t_vector_d	*player;
	t_vector_d	*move;

	player = &mlx->ray.plane;
	move = &mlx->move.pos;
	if (mlx->map.map[(int)move->y][(int)(move->x + player->x * dir)] == '0')
		move->x += (player->x * dir);
	if (mlx->map.map[(int)(move->y + player->y * dir)][(int)move->x] == '0')
		move->y += (player->y * dir);
}

/*
**		Calculates when the player is rotating.
*/

void	rotate_player(t_data *mlx, double dir)
{
	double		old_dir_x;
	double		old_plane_x;
	t_vector_d	*player;
	t_vector_d	*plane;

	player = &mlx->ray.dir;
	plane = &mlx->ray.plane;
	old_dir_x = player->x;
	player->x = player->x * cos(dir) - player->y * sin(dir);
	player->y = old_dir_x * sin(dir) + player->y * cos(dir);
	old_plane_x = plane->x;
	plane->x = plane->x * cos(dir) - plane->y * sin(dir);
	plane->y = old_plane_x * sin(dir) + plane->y * cos(dir);
}

/*
**		Checks what direction the player will move to.
*/

void	move_player(t_data *mlx)
{
	mlx->move.rot_speed = 0.04;
	if (mlx->move.shift == 1)
		mlx->move.move_speed = 0.25;
	else
		mlx->move.move_speed = 0.05;
	if (mlx->move.w == 1)
		move_forward_or_backward(mlx, mlx->move.move_speed);
	if (mlx->move.s == 1)
		move_forward_or_backward(mlx, mlx->move.move_speed * -1);
	if (mlx->move.d == 1)
		strafe_player(mlx, mlx->move.move_speed);
	if (mlx->move.a == 1)
		strafe_player(mlx, mlx->move.move_speed * -1);
	if (mlx->move.right == 1)
		rotate_player(mlx, mlx->move.rot_speed);
	if (mlx->move.left == 1)
		rotate_player(mlx, mlx->move.rot_speed * -1);
}
