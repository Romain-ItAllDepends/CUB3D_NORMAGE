/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:37:57 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 10:30:22 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static int	ft_strlen1(char const *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;

	if (!s2)
		return (0);
	tab = ft_calloc((1 + ft_strlen1(s1) + ft_strlen1(s2)), sizeof(char));
	i = 0;
	j = 0;
	if (tab == 0)
		return (0);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		j++;
		i++;
	}
	return (tab);
}

char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2 && s2[j++])
		tab[i + j - 1] = s2[j - 1];
	tab[i + j - 1] = '\0';
	if (s1)
		free(s1);
	s1 = NULL;
	return (tab);
}
