/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:23:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/24 09:31:18 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	mouse_recorder(void *param)
{
	t_vars		*vars;
	int			x;
	int			y;
	double		rotspeed;
	double		olddirx;
	double		oldplanex;
	double		angle;

	vars = (t_vars *)param;
	mlx_get_mouse_pos(vars->window, &x, &y);
	rotspeed = ROT_SPEED * 40;
	if (x != WIDTH / 2)
	{
		olddirx = vars->raycast->dirx;
		oldplanex = vars->raycast->planex;
		angle = (WIDTH / 2 - x) * rotspeed / WIDTH;
		vars->raycast->dirx = vars->raycast->dirx
			* cos(angle) - vars->raycast->diry * sin(angle);
		vars->raycast->diry = olddirx * sin(angle)
			+ vars->raycast->diry * cos(angle);
		vars->raycast->planex = vars->raycast->planex * cos(angle)
			- vars->raycast->planey * sin(angle);
		vars->raycast->planey = oldplanex * sin(angle)
			+ vars->raycast->planey * cos(angle);
		mlx_set_mouse_pos(vars->window, WIDTH / 2, HEIGHT / 2);
	}
}

static void	key_recorder(void *param)
{
	t_vars		*vars;

	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->window, MLX_KEY_ESCAPE))
		ft_free_vars(vars);
	if (mlx_is_key_down(vars->window, MLX_KEY_1))
	{
		vars->images->weapon2->instances->enabled = false;
		vars->images->weapon1->instances->enabled = true;
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_2))
	{
		vars->images->weapon2->instances->enabled = true;
		vars->images->weapon1->instances->enabled = false;
	}
	if (mlx_is_mouse_down(vars->window, MLX_MOUSE_BUTTON_LEFT))
		vars->is_shooting = 1;
	else
		vars->is_shooting = 0;
	ft_shoot(vars);
	forward_and_back(vars, MOVE_SPEED);
	right_and_left(vars, MOVE_SPEED);
	rotate_camera(vars, ROT_SPEED);
	build_mini_map(vars);
	paint_on_screen(vars);
}

static void	mini_map(mlx_key_data_t key, void *param)
{
	t_vars	*vars;

	vars = param;
	if (key.key == MLX_KEY_M && key.action == MLX_PRESS)
		vars->images->mini_map->enabled = !vars->images->mini_map->enabled;
}

static void	setup_hooks(t_vars *vars)
{
	mlx_image_to_window(vars->window, vars->images->mini_map, 20, 20);
	vars->cursor = mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR);
	if (!vars->cursor)
	{
		ft_putstr_fd(
			"Error\nAn error occurred while creating the cursor!\n", 2);
		ft_free_vars(vars);
	}
	mlx_set_cursor_mode(vars->window, MLX_MOUSE_HIDDEN);
	mlx_image_to_window(vars->window, vars->images->crosshair,
		WIDTH / 2 + 10, HEIGHT / 2 + 10);
	mlx_image_to_window(vars->window, vars->images->weapon1, 700, 700);
	mlx_image_to_window(vars->window, vars->images->weapon2, 250, 450);
	mlx_set_instance_depth(vars->images->crosshair->instances, (int32_t)5);
	mlx_set_instance_depth(vars->images->weapon1->instances, (int32_t)4);
	mlx_set_instance_depth(vars->images->weapon2->instances, (int32_t)4);
	vars->images->weapon2->instances->enabled = false;
	if (mlx_resize_image(vars->images->crosshair, 20, 20) == 0)
	{
		ft_putstr_fd("Error\nAn error occured while resizing cusor!\n", 2);
		ft_free_vars(vars);
	}
	mlx_set_mouse_pos(vars->window, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor(vars->window, vars->cursor);
	mlx_cursor_hook(vars->window, (void *)mouse_recorder, vars);
	mlx_loop_hook(vars->window, (void *)key_recorder, vars);
	mlx_key_hook(vars->window, (void *)mini_map, vars);
	paint_on_screen(vars);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	vars = NULL;
	if (ac != 2)
		nb_arg_error();
	parse_file(av[1]);
	initialize_vars(&vars, av[1]);
	initialize_window(vars);
	setup_textures(vars);
	initialize_mini_map(vars);
	build_mini_map(vars);
	setup_hooks(vars);
	mlx_loop(vars->window);
	mlx_close_window(vars->window);
	mlx_terminate(vars->window);
	vars->window = NULL;
	ft_free_vars(vars);
	return (0);
}
