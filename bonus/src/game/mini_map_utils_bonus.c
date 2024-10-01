/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:22:14 by vgodart           #+#    #+#             */
/*   Updated: 2024/10/01 14:22:16 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	process_map_cell(t_vars *vars, int x, int y)
{
	int32_t	color;

	color = -1;
	if (vars->map[x][y] == '1' || vars->map[x][y] == ' ')
		color = ft_pixel(255, 51, 51, 1000);
	else if (vars->map[x][y] == '0' || vars->map[x][y] == 'N'
			|| vars->map[x][y] == 'S' || vars->map[x][y] == 'E'
			|| vars->map[x][y] == 'W')
		color = ft_pixel(255, 255, 255, 0);
	if (color != -1)
		display_map(vars, color, x, y);
}
