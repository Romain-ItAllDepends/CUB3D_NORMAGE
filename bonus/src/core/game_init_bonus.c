/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 02:54:38 by vgodart           #+#    #+#             */
/*   Updated: 2024/09/28 10:27:33 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	initialize_window(t_vars *vars)
{
	vars->window = mlx_init(WIDTH, HEIGHT, "CUB3D", 0);
	if (!vars->window)
	{
		ft_putstr_fd("Error\nAn error occurred while opening the window!\n", 2);
		ft_free_vars(vars);
	}
}

void	resize_images(t_vars *vars)
{
	vars->images->north = mlx_texture_to_image(vars->window,
			vars->textures->north);
	vars->images->south = mlx_texture_to_image(vars->window,
			vars->textures->south);
	vars->images->east = mlx_texture_to_image(vars->window,
			vars->textures->east);
	vars->images->west = mlx_texture_to_image(vars->window,
			vars->textures->west);
	if (!vars->images->north || !vars->images->south || !vars->images->east
		|| !vars->images->west)
		texture_error(vars);
	if (mlx_resize_image(vars->images->north, TEXWIDTH, TEXHEIGHT) == 0)
		resize_error(vars);
	if (mlx_resize_image(vars->images->south, TEXWIDTH, TEXHEIGHT) == 0)
		resize_error(vars);
	if (mlx_resize_image(vars->images->east, TEXWIDTH, TEXHEIGHT) == 0)
		resize_error(vars);
	if (mlx_resize_image(vars->images->west, TEXWIDTH, TEXHEIGHT) == 0)
		resize_error(vars);
	vars->images->screen = mlx_new_image(vars->window, WIDTH, HEIGHT);
	if (!vars->images->screen)
		screen_error(vars);
}

static void	weapons_setup(t_vars *vars)
{
	vars->textures->weapon1 = mlx_load_png("./bonus/textures/ak47.png");
	if (!vars->textures->weapon1)
		texture_error(vars);
	vars->images->weapon1 = mlx_texture_to_image(vars->window,
			vars->textures->weapon1);
	if (!vars->images->weapon1)
		texture_error(vars);
	vars->textures->weapon2 = mlx_load_png("./bonus/textures/cut.png");
	if (!vars->textures->weapon2)
		texture_error(vars);
	vars->images->weapon2 = mlx_texture_to_image(vars->window,
			vars->textures->weapon2);
	if (!vars->images->weapon2)
		texture_error(vars);
	if (mlx_resize_image(vars->images->weapon1, 700, 450) == 0)
		resize_error(vars);
	if (mlx_resize_image(vars->images->weapon2, 1150, 600) == 0)
		resize_error(vars);
}

void	setup_textures(t_vars *vars)
{
	vars->textures->north = mlx_load_png(vars->north);
	if (!vars->textures->north)
		texture_error(vars);
	vars->textures->south = mlx_load_png(vars->south);
	if (!vars->textures->south)
		texture_error(vars);
	vars->textures->east = mlx_load_png(vars->east);
	if (!vars->textures->east)
		texture_error(vars);
	vars->textures->west = mlx_load_png(vars->west);
	if (!vars->textures->west)
		texture_error(vars);
	vars->textures->crosshair = mlx_load_png("./bonus/textures/crosshair.png");
	if (!vars->textures->crosshair)
		texture_error(vars);
	vars->images->crosshair = mlx_texture_to_image(vars->window,
			vars->textures->crosshair);
	if (!vars->images->crosshair)
		texture_error(vars);
	weapons_setup(vars);
	resize_images(vars);
}
