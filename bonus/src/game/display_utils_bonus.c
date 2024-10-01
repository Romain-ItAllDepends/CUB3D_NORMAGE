/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:46:22 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/02 00:06:13 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int32_t	get_color(int32_t pixel)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;
	int32_t	color;

	r = ((pixel >> 24) & 0xFF);
	g = ((pixel >> 16) & 0xFF);
	b = ((pixel >> 8) & 0xFF);
	a = (pixel & 0xFF);
	color = ((a << 24) | (b << 16) | (g << 8) | r);
	return (color);
}

void	select_textures(t_vars *vars)
{
	if (vars->raycast->side == 0 && vars->raycast->ray_dirx < 0)
	{
		vars->raycast->color = get_color(
				((int32_t *)vars->images->north->pixels)
			[TEXWIDTH * vars->raycast->texy + vars->raycast->texx]);
	}
	else if (vars->raycast->side == 0 && vars->raycast->ray_dirx >= 0)
	{
		vars->raycast->color = get_color(
				((int32_t *)vars->images->south->pixels)
			[TEXWIDTH * vars->raycast->texy + vars->raycast->texx]);
	}
	else if (vars->raycast->side == 1 && vars->raycast->ray_diry < 0)
	{
		vars->raycast->color = get_color(((int32_t *)vars->images->west->pixels)
			[TEXWIDTH * vars->raycast->texy + vars->raycast->texx]);
	}
	else
	{
		vars->raycast->color = get_color(((int32_t *)vars->images->east->pixels)
			[TEXWIDTH * vars->raycast->texy + vars->raycast->texx]);
	}
}

void	put_pixels(t_vars *vars, int x)
{
	int	i;

	i = 0;
	while (i < vars->raycast->draw_start)
	{
		mlx_put_pixel(vars->images->screen, x, i, (vars->ceiling[0] << 24)
			| (vars->ceiling[1] << 16) | (vars->ceiling[2] << 8) | 255);
		i++;
	}
	while (i < vars->raycast->draw_end)
	{
		vars->raycast->texy = (int)vars->raycast->tex_pos & (TEXHEIGHT - 1);
		vars->raycast->tex_pos += vars->raycast->step;
		vars->raycast->color = 0;
		select_textures(vars);
		mlx_put_pixel(vars->images->screen, x, i, vars->raycast->color);
		i++;
	}
	while (i < HEIGHT - 1)
	{
		mlx_put_pixel(vars->images->screen, x, i, (vars->floor[0] << 24)
			| (vars->floor[1] << 16) | (vars->floor[2] << 8) | 255);
		i++;
	}
}

void	texture_coord(t_vars *vars)
{
	if (vars->raycast->side == 0)
	{
		vars->raycast->wallx = vars->raycast->posy
			+ vars->raycast->perp_wall_dist * vars->raycast->ray_diry;
	}
	else
	{
		vars->raycast->wallx = vars->raycast->posx
			+ vars->raycast->perp_wall_dist * vars->raycast->ray_dirx;
	}
	vars->raycast->wallx -= floor((vars->raycast->wallx));
	vars->raycast->texx = (int)(vars->raycast->wallx * (double)TEXWIDTH);
	if (vars->raycast->side == 0 && vars->raycast->ray_dirx > 0)
		vars->raycast->texx = TEXWIDTH - vars->raycast->texx - 1;
	if (vars->raycast->side == 1 && vars->raycast->ray_diry < 0)
		vars->raycast->texx = TEXWIDTH - vars->raycast->texx - 1;
	vars->raycast->step = 1.0 * TEXHEIGHT / vars->raycast->line_height;
	vars->raycast->tex_pos = (vars->raycast->draw_start - HEIGHT / 2
			+ vars->raycast->line_height / 2) * vars->raycast->step;
}

void	wall_start_end(t_vars *vars)
{
	vars->raycast->draw_start = -vars->raycast->line_height / 2 + HEIGHT / 2;
	if (vars->raycast->draw_start < 0)
		vars->raycast->draw_start = 0;
	vars->raycast->draw_end = vars->raycast->line_height / 2 + HEIGHT / 2;
	if (vars->raycast->draw_end >= HEIGHT)
		vars->raycast->draw_end = HEIGHT - 1;
}
