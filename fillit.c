/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:35:05 by elfetoua          #+#    #+#             */
/*   Updated: 2019/07/05 14:45:03 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage(void)
{
	write(1, "usage: ./fillit target_file\n", 28);
}

void	print(char ***str, int num_tit)
{
	int	i;
	char	**map;
	titro	*mine;

	i = 0;
	mine = stock(str, num_tit);
	map = backtracking(mine, num_tit);
	while (map[i] != NULL)
	{
		ft_putendl(map[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		num_tit;
	char	***str;

	if (argc != 2)
		usage();
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (verification(argv[1]) == 1)
		{
			if ((num_tit = count_titris(argv[1])) > 0)
			{
				str = save(argv[1], num_tit);
				if (cnx_per_bloc(str, num_tit) == 1)
					print(str, num_tit);
				else
					write(1, "error\n", 6);
			}
			else
				write(1, "error\n", 6);
		}
		else
			write(1, "error\n", 6);
	}
	return (0);
}
