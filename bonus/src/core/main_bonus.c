/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:23:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 10:27:45 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static void	mouse_recorder(void *param)
{
	t_vars	*vars;
	double	rotspeed;
	int		x;
	int		y;

	x = 0;
	y = 0;
	vars = (t_vars *)param;
	rotspeed = ROT_SPEED * 40;
	mlx_get_mouse_pos(vars->window, &x, &y);
	if (x != WIDTH / 2)
	{
		update_raycast(vars, x, rotspeed);
		mlx_set_mouse_pos(vars->window, WIDTH / 2, HEIGHT / 2);
	}
}

static void	key_recorder(void *param)
{
	t_vars	*vars;

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

static void	initialize_cursor_and_images(t_vars *vars)
{
	vars->cursor = mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR);
	if (!vars->cursor)
	{
		ft_putstr_fd("Error\nAn error occurred while creating the cursor!\n",
			2);
		ft_free_vars(vars);
	}
	mlx_set_cursor_mode(vars->window, MLX_MOUSE_HIDDEN);
	mlx_image_to_window(vars->window, vars->images->crosshair, WIDTH / 2 + 10,
		HEIGHT / 2 + 10);
	mlx_image_to_window(vars->window, vars->images->weapon1, 700, 700);
	mlx_image_to_window(vars->window, vars->images->weapon2, 250, 450);
	mlx_image_to_window(vars->window, vars->images->mini_map, 20, 20);
	mlx_set_instance_depth(vars->images->mini_map->instances, (int32_t)5);
	mlx_set_instance_depth(vars->images->crosshair->instances, (int32_t)6);
	mlx_set_instance_depth(vars->images->weapon1->instances, (int32_t)4);
	mlx_set_instance_depth(vars->images->weapon2->instances, (int32_t)4);
	vars->images->weapon2->instances->enabled = false;
	if (mlx_resize_image(vars->images->crosshair, 20, 20) == 0)
	{
		ft_putstr_fd("Error\nAn error occured while resizing cusor!\n", 2);
		ft_free_vars(vars);
	}
}

static void	setup_hooks(t_vars *vars)
{
	initialize_cursor_and_images(vars);
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
