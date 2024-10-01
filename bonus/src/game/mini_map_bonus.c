/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:28:53 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 10:29:28 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	mini_map(mlx_key_data_t key, void *param)
{
	t_vars	*vars;

	vars = param;
	if (key.key == MLX_KEY_M && key.action == MLX_PRESS)
		vars->images->mini_map->enabled = !vars->images->mini_map->enabled;
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	display_map(t_vars *vars, int32_t color, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 4)
	{
		j = 0;
		while (j++ <= 4)
			mlx_put_pixel(vars->images->mini_map, y * 4 + i, x * 4 + j, color);
		i++;
	}
}

void	player_on_mini_map(t_vars *vars)
{
	int	player_x;
	int	player_y;

	player_x = (int)(vars->raycast->posx * 4);
	player_y = (int)(vars->raycast->posy * 4);
	mlx_put_pixel(vars->images->mini_map, player_y, player_x, ft_pixel(80, 255,
			50, 1000));
}

void	build_mini_map(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			process_map_cell(vars, x, y);
			y++;
		}
		x++;
	}
	player_on_mini_map(vars);
}
