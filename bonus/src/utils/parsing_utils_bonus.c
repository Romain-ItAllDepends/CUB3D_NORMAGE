/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:55:11 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 10:30:28 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

char	*copy(char *s)
{
	int		i;
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

int	len_db_char(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	invert_skip_space(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str && i > 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	return (i);
}

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

int	start_map(char **file)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file && file[i])
	{
		if (file[i][skip_space(file[i])] != '\n' && count < 6)
			count++;
		if (count == 6 && file[i][skip_space(file[i])] == '1')
			return (i);
		i++;
	}
	ft_free(file);
	return (-1);
}
