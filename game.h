/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:13:08 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/30 19:07:51 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef GAME_H
# define GAME_H

enum e_const
{
	WIN_VALUE = 2048
};

int		check_end(int **grid);
void	move_grid(int **grid, int direction);
void	collision(int **grid, int direction);

#endif
