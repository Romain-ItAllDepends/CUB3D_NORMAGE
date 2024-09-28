/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:08:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 10:29:41 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static int	verif_texture(char *str)
{
	static int	north;
	static int	south;
	static int	east;
	static int	west;

	str = &str[skip_space(str)];
	if (str && str[0] && str[1] && str[2]
		&& (str[0] == 'S' && str[1] == 'O')
		&& (str[2] == ' ' || str[2] == '\t'))
		south++;
	if (str && str[0] && str[1] && str[2]
		&& (str[0] == 'N' && str[1] == 'O')
		&& (str[2] == ' ' || str[2] == '\t'))
		north++;
	if (str && str[0] && str[1] && str[2]
		&& (str[0] == 'W' && str[1] == 'E')
		&& (str[2] == ' ' || str[2] == '\t'))
		west++;
	if (str && str[0] && str[1] && str[2]
		&& (str[0] == 'E' && str[1] == 'A')
		&& (str[2] == ' ' || str[2] == '\t'))
		east++;
	if (north == 1 && south == 1 && west == 1 && east == 1)
		return (1);
	return (0);
}

static int	verif_color(char *str)
{
	str = &str[skip_space(str)];
	if (str && str[0] && str[1]
		&& str[0] == 'F'
		&& (str[1] == ' ' || str[1] == '\t'))
		return (1);
	else if (str && str[0] && str[1]
		&& str[0] == 'C'
		&& (str[1] == ' ' || str[1] == '\t'))
		return (2);
	return (0);
}

static void	verif_paramaters(char **file)
{
	int	i;
	int	floor;
	int	ceiling;
	int	textures;

	i = 0;
	floor = 0;
	ceiling = 0;
	textures = 0;
	while (file && file[i])
	{
		if (verif_color(file[i]) == 1)
			floor++;
		else if (verif_color(file[i]) == 2)
			ceiling++;
		else
			textures = verif_texture(file[i]);
		i++;
	}
	if (ceiling != 1 || floor != 1 || textures != 1)
	{
		free(file);
		file = NULL;
	}
}

static void	parse_file_content(int fd)
{
	char	**file;
	char	**map;

	file = get_file(fd);
	close(fd);
	printf(" - Arg check  ✅\n");
	verif_paramaters(file);
	if (!file)
	{
		ft_putstr_fd("Error\nWrong number of parameters! ❌\n", 2);
		exit(1);
	}
	check_data(file);
	printf(" - Data check ✅\n");
	map = get_map(file);
	ft_free(file);
	if (!map)
		exit(1);
	check_map(map);
	printf(" - Map check  ✅\n");
	ft_free(map);
}

void	parse_file(char *file)
{
	int	fd;
	int	pos;

	if (!file)
		empty_arg();
	pos = ft_strcspn(file, ".");
	fd = -1;
	if (pos != 0 && ft_strlen(file) != pos)
	{
		if (file && file[pos] && file[pos + 1] && file[pos + 2] && file[pos + 3]
			&& file[pos + 1] == 'c' && file[pos + 2] == 'u'
			&& file[pos + 3] == 'b' && ft_strlen(file) == pos + 4)
		{
			fd = open(file, O_RDONLY);
			if (fd == -1)
				error_fd();
			else
				parse_file_content(fd);
		}
		else
			error_extention();
	}
	else
		error_extention();
}
