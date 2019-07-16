/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:26:56 by hiantrin          #+#    #+#             */
/*   Updated: 2019/07/05 23:19:16 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**test1(char **map, char **str, int s_i, int s_j)
{
	int a;
	int b;
	int i;
	int j;

	a = 0;
	b = -1;
	while (cherche_count(map, str) < 4)
	{
		if (cherche_count(map, str) == 0)
		{
			b++;
			i = s_i;
			j = s_j;
			if (cherche(map, &a, &b) == 0)
				return (map);
			map[a][b] = str[i][j];
		}
		fonc(str, &i, &j);
		if (map[a + (i - s_i)] && (map[a + (i - s_i)][b + (j - s_j)] == '.'))
			map[a + (i - s_i)][b + (j - s_j)] = str[i][j];
		else
			map = clean(map, str[s_i][s_j]);
	}
	return (map);
}

int		fonc(char **str, int *i, int *j)
{
	(*j)++;
	while (str[*i] != NULL)
	{
		while (str[*i][*j] != '\0')
		{
			if (str[*i][*j] >= 'A' && str[*i][*j] <= 'Z')
				return (0);
			(*j)++;
		}
		(*i)++;
		*j = 0;
	}
	return (0);
}

char	**clean(char **map, char a)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == a)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		cherche(char **map, int *a, int *b)
{
	while (map[*a][*b] != '.')
	{
		if (map[*a][*b] == '\0')
		{
			(*a)++;
			*b = 0;
		}
		if (map[*a] == NULL)
			return (0);
		if (map[*a][*b] != '.')
			(*b)++;
		else
			break ;
	}
	return (1);
}
