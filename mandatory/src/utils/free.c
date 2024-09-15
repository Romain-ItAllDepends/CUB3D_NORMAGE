/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:06:40 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/15 09:25:40 by rgobet           ###   ########.fr       */
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
		if (vars->map)
			ft_free(vars->map);
		if (vars->textures)
			free(vars->textures);
		if (vars->north)
			free(vars->north);
		if (vars->south)
			free(vars->south);
		if (vars->east)
			free(vars->east);
		if (vars->west)
			free(vars->west);
	}
	if (error == 1)
	{
		if (vars->map)
			ft_free(vars->map);
		if (vars->textures)
			free(vars->textures);
		if (vars->north)
			free(vars->north);
		if (vars->south)
			free(vars->south);
		if (vars->east)
			free(vars->east);
		if (vars->west)
			free(vars->west);
		// if (vars->window)
		// 	free(vars->window);
	}
	if (error == 2)
	{
		if (vars->map)
			ft_free(vars->map);
		if (vars->textures)
			free(vars->textures);
		if (vars->north)
			free(vars->north);
		if (vars->south)
			free(vars->south);
		if (vars->east)
			free(vars->east);
		if (vars->west)
			free(vars->west);
		// if (vars->window)
		// 	free(vars->window);
		// if (vars->mini_map)
		// 	free(vars->mini_map);
	}
	if (error == 3)
	{
		if (vars->map)
			ft_free(vars->map);
		if (vars->textures)
			free(vars->textures);
		if (vars->north)
			free(vars->north);
		if (vars->south)
			free(vars->south);
		if (vars->east)
			free(vars->east);
		if (vars->west)
			free(vars->west);
		// if (vars->window)
		// 	free(vars->window);
		// if (vars->mini_map)
		// 	free(vars->mini_map);
		// if (vars->textures->tmp_player_on_map)
		// 	free(vars->textures->tmp_player_on_map);
	}
	if (error == 4)
	{
		if (vars->map)
			ft_free(vars->map);
		if (vars->textures)
			free(vars->textures);
		if (vars->north)
			free(vars->north);
		if (vars->south)
			free(vars->south);
		if (vars->east)
			free(vars->east);
		if (vars->west)
			free(vars->west);
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
		if (vars->map)
			ft_free(vars->map);
		if (vars->textures)
			free(vars->textures);
		if (vars->north)
			free(vars->north);
		if (vars->south)
			free(vars->south);
		if (vars->east)
			free(vars->east);
		if (vars->west)
			free(vars->west);
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
		if (vars->map)
			ft_free(vars->map);
		if (vars->textures)
			free(vars->textures);
		if (vars->north)
			free(vars->north);
		if (vars->south)
			free(vars->south);
		if (vars->east)
			free(vars->east);
		if (vars->west)
			free(vars->west);
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
		free(vars);
		vars = NULL;
	}
}
