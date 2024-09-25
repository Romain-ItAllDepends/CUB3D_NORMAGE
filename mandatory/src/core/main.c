/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:23:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/25 13:55:41 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	key_recorder(void *param)
{
	t_vars		*vars;

	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->window, MLX_KEY_ESCAPE))
		ft_free_vars(vars);
	forward_and_back(vars, MOVE_SPEED);
	right_and_left(vars, MOVE_SPEED);
	rotate_camera(vars, ROT_SPEED);
	paint_on_screen(vars);
}

static void	setup_hooks(t_vars *vars)
{
	vars->cursor = mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR);
	if (!vars->cursor)
	{
		ft_putstr_fd(
			"Error\nAn error occurred while creating the cursor! ❌\n", 2);
		ft_free_vars(vars);
	}
	mlx_set_cursor_mode(vars->window, MLX_MOUSE_HIDDEN);
	mlx_image_to_window(vars->window, vars->images->crosshair,
		WIDTH / 2 + 10, HEIGHT / 2 + 10);
	mlx_set_instance_depth(vars->images->crosshair->instances, (int32_t)5);
	if (mlx_resize_image(vars->images->crosshair, 20, 20) == 0)
	{
		ft_putstr_fd("Error\nAn error occured while resizing cusor! ❌\n", 2);
		ft_free_vars(vars);
	}
	mlx_set_mouse_pos(vars->window, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor(vars->window, vars->cursor);
	mlx_loop_hook(vars->window, (void *)key_recorder, vars);
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
	setup_hooks(vars);
	mlx_loop(vars->window);
	mlx_close_window(vars->window);
	mlx_terminate(vars->window);
	vars->window = NULL;
	ft_free_vars(vars);
	return (0);
}
