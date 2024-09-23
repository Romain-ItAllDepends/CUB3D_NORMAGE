/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:23:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/23 12:04:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	mouse_recorder(void *param)
{
	t_vars		*vars;
	int			x;
	int			y;
	double		rotSpeed;
	double oldDirX;
	double oldPlaneX;
	double angle;

	vars = (t_vars *)param;
	mlx_get_mouse_pos(vars->window, &x, &y); // y is unused
	rotSpeed = ROT_SPEED * 40; // sensi de la souris
	if (x != WIDTH / 2) // Vérifie si la souris n'est pas au centre de l'écran (en largeur). Si c'est le cas, la caméra doit être tournée.
	{
		oldDirX = vars->raycast->dirx;
		oldPlaneX = vars->raycast->planex;
		angle = (WIDTH / 2 - x) * rotSpeed / WIDTH; // Calcule l'angle de rotation en fonction de la distance entre la position actuelle de la souris et le centre de l'écran. Le signe de l'angle est inversé pour corriger la direction de la rotation. normalement c'est bon mais si tu veux la souris dans lautre sens c'est x - WIDTH / 2
		vars->raycast->dirx = vars->raycast->dirx * cos(angle) - vars->raycast->diry * sin(angle);
		vars->raycast->diry = oldDirX * sin(angle) + vars->raycast->diry * cos(angle);
		vars->raycast->planex = vars->raycast->planex * cos(angle) - vars->raycast->planey * sin(angle);
		vars->raycast->planey = oldPlaneX * sin(angle) + vars->raycast->planey * cos(angle);
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
		vars->images->weapon2->instances->enabled = 0;
		vars->images->weapon1->instances->enabled = 1;
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_2))
	{
		vars->images->weapon2->instances->enabled = 1;
		vars->images->weapon1->instances->enabled = 0;
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
	paint_on_screen(vars);
	mlx_image_to_window(vars->window, vars->images->weapon1, 700, 700);
	mlx_image_to_window(vars->window, vars->images->weapon2, 250, 450);
	vars->images->weapon2->enabled = 0;
	mlx_image_to_window(vars->window, vars->images->mini_map, 20, 20);
	vars->cursor = mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR);
	if (!vars->cursor)
	{
		ft_putstr_fd(
			"Error\nAn error occurred while creating the cursor!\n", 2);
		ft_free_vars(vars);
		exit(1);
	}
	mlx_set_cursor_mode(vars->window, MLX_MOUSE_HIDDEN);
	mlx_image_to_window(vars->window, vars->images->crosshair,
		WIDTH / 2 + 10, HEIGHT / 2 + 10);
	if (mlx_resize_image(vars->images->crosshair, 20, 20) == 0)
	{
		ft_free_vars(vars);
		ft_putstr_fd("Error\nAn error occured while resizing cusor!\n", 2);
		exit(1);
	}
	mlx_set_mouse_pos(vars->window, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor(vars->window, vars->cursor);
	mlx_cursor_hook(vars->window, (void *)mouse_recorder, vars);
	mlx_loop_hook(vars->window, (void *)key_recorder, vars);
	mlx_key_hook(vars->window, (void *)mini_map, vars);
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
