/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:35:41 by elfetoua          #+#    #+#             */
/*   Updated: 2019/07/12 13:17:38 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>

typedef struct  m_point
{
    int x;
    int y;
}               posi;

typedef struct  s_point
{
    char	c;
    posi	*titris;
}               titro;

int		verification(char *file);
int		cnx_per_bloc(char ***str, int num_tit);
void	usage(void);
int		check(char **str);
int		dashes_per_bloc(char *file);
int		count_titris(char *file);
char	**titris(int fd);
char	***save(char *file, int num_tit);
char	***alpha_titris(char ***str, int num_tit);
void	print(char ***str, int num_tit);
int		verifi(int fd);
int		cnx_count(char **str, int i, int j, char c);
titro   *stock(char ***str, int num_tit);
titro   *remplir_mine(char ***str, int num_tit, titro *mine);
posi	*remplir_titris(char **str, posi *titris);
char	character(char **str);
int		next_position(char **str, int *i, int *j);
char    **backtracking(titro *mine, int num_tit);
char    **solve(titro *mine, int num_tit, char **map);
char	**rem_map(titro	mine, char **map);
int		if_can_put(posi	*titris, char **map, int a, int b);
char	**put_tit(titro mine, char **map, int a, int b);
char	**ft_map(int num);
int		cherche_count(char **map, char c);
char	**clean_titris(char **map, char a);
int		cherche(char **map, int *a, int *b, char c);
char    **final_track(titro *mine, int num_tit, char **map, int j);
char    **move_titris(titro mine, char **map);
char	**move(titro mine, char **map, int a, int b);

#endif
