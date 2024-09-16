/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:06:40 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/16 11:27:41 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_vars(t_vars *vars, int error)
{
	// free raycast / images
	if (error == 0)
	{
		// if (vars->map)
		// 	ft_free(vars->map);
		// if (vars->textures)
		// 	free(vars->textures);
		// if (vars->north)
		// 	free(vars->north);
		// if (vars->south)
		// 	free(vars->south);
		// if (vars->east)
		// 	free(vars->east);
		// if (vars->west)
		// 	free(vars->west);
	}
	if (error == 1)
	{
		// if (vars->map)
		// 	ft_free(vars->map);
		// if (vars->textures)
		// 	free(vars->textures);
		// if (vars->north)
		// 	free(vars->north);
		// if (vars->south)
		// 	free(vars->south);
		// if (vars->east)
		// 	free(vars->east);
		// if (vars->west)
		// 	free(vars->west);
		// if (vars->window)
		// 	free(vars->window);
	}
	if (error == 2)
	{
		// if (vars->map)
		// 	ft_free(vars->map);
		// if (vars->textures)
		// 	free(vars->textures);
		// if (vars->north)
		// 	free(vars->north);
		// if (vars->south)
		// 	free(vars->south);
		// if (vars->east)
		// 	free(vars->east);
		// if (vars->west)
		// 	free(vars->west);
		// if (vars->window)
		// 	free(vars->window);
		// if (vars->mini_map)
		// 	free(vars->mini_map);
	}
	if (error == 3)
	{
		// if (vars->map)
		// 	ft_free(vars->map);
		// if (vars->textures)
		// 	free(vars->textures);
		// if (vars->north)
		// 	free(vars->north);
		// if (vars->south)
		// 	free(vars->south);
		// if (vars->east)
		// 	free(vars->east);
		// if (vars->west)
		// 	free(vars->west);
		// if (vars->window)
		// 	free(vars->window);
		// if (vars->mini_map)
		// 	free(vars->mini_map);
		// if (vars->textures->tmp_player_on_map)
		// 	free(vars->textures->tmp_player_on_map);
	}
	if (error == 4)
	{
		// if (vars->map)
		// 	ft_free(vars->map);
		// if (vars->textures)
		// 	free(vars->textures);
		// if (vars->north)
		// 	free(vars->north);
		// if (vars->south)
		// 	free(vars->south);
		// if (vars->east)
		// 	free(vars->east);
		// if (vars->west)
		// 	free(vars->west);
		// if (vars->window)
		// 	free(vars->window);
		// if (vars->mini_map)
		// 	free(vars->mini_map);
		// if (vars->textures->tmp_player_on_map)
		// 	free(vars->textures->tmp_player_on_map);
		// if (vars->player_on_map)
		// 	free(vars->player_on_map);
	}
	if (error == 5)
	{
		// if (vars->map)
		// 	ft_free(vars->map);
		// if (vars->textures)
		// 	free(vars->textures);
		// if (vars->north)
		// 	free(vars->north);
		// if (vars->south)
		// 	free(vars->south);
		// if (vars->east)
		// 	free(vars->east);
		// if (vars->west)
		// 	free(vars->west);
		// if (vars->window)
		// 	free(vars->window);
		// if (vars->mini_map)
		// 	free(vars->mini_map);
		// if (vars->textures->tmp_player_on_map)
		// 	free(vars->textures->tmp_player_on_map);
		// if (vars->player_on_map)
		// 	free(vars->player_on_map);
		// if (vars->tmp)
		// 	free(vars->tmp);
	}
	if (error == 6)
	{
		// if (vars->map)
		// 	ft_free(vars->map);
		// if (vars->textures)
		// 	free(vars->textures);
		// if (vars->north)
		// 	free(vars->north);
		// if (vars->south)
		// 	free(vars->south);
		// if (vars->east)
		// 	free(vars->east);
		// if (vars->west)
		// 	free(vars->west);
		// if (vars->window)
		// 	free(vars->window);
		// if (vars->mini_map)
		// 	free(vars->mini_map);
		// if (vars->textures->tmp_player_on_map)
		// 	free(vars->textures->tmp_player_on_map);
		// if (vars->player_on_map)
		// 	free(vars->player_on_map);
		// if (vars->tmp)
		// 	free(vars->tmp);
		// if (vars->cursor)
		// 	free(vars->cursor);
	}
	if (vars)
	{
		if (vars && vars->map)
			ft_free(vars->map);
		if (vars && vars->north)
			free(vars->north);
		if (vars && vars->south)
			free(vars->south);
		if (vars && vars->east)
			free(vars->east);
		if (vars && vars->west)
			free(vars->west);
		if (vars && vars->images && vars->images->screen)
			free(vars->images->screen);
		if (vars && vars->images && vars->images->crosshair)
			free(vars->images->crosshair);
		if (vars && vars->images && vars->images->mini_map)
			free(vars->images->mini_map);
		if (vars && vars->images && vars->images->north)
			free(vars->images->north);
		if (vars && vars->images && vars->images->south)
			free(vars->images->south);
		if (vars && vars->images && vars->images->east)
			free(vars->images->east);
		if (vars && vars->images && vars->images->west)
			free(vars->images->west);
		if (vars && vars->textures && vars->textures->crosshair)
			free(vars->textures->crosshair);
		if (vars && vars->textures && vars->textures->north)
			free(vars->textures->north);
		if (vars && vars->textures && vars->textures->south)
			free(vars->textures->south);
		if (vars && vars->textures && vars->textures->east)
			free(vars->textures->east);
		if (vars && vars->textures && vars->textures->west)
			free(vars->textures->west);
		if (vars && vars->images)
			free(vars->images);
		if (vars && vars->textures)
			free(vars->textures);
		if (vars && vars->raycast)
			free(vars->raycast);
		free(vars);
		vars = NULL;
	}
}
