/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:42:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/30 16:07:49 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define SIZE 4

static int		check_victory(int **grid)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < SIZE)
	{
		while (y < SIZE)
		{
			if (grid[i][y] == WIN_VALUE)
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

static int		check_adj(int **grid)
{
	int		i;
	int		y;

	i = 0;
    y = 0;
    while (i < SIZE)
    {
        y = 0;
		while (y < SIZE)
		{
            if (i > 0)
            {
				if (grid[i -1][y] == grid[i][y])
					return (0);
			}
			if (i < SIZE - 1)
            {
				if (grid[i +1][y] == grid[i][y])
					return (0);
			}
			if (y < SIZE - 1)
            {
				if (grid[i][y + 1] == grid[i][y])
					return (0);
			}
			if (y > 0)
            {
                if (grid[i][y - 1] == grid[i][y])
                    return (0);
            }
            y++;
        }
        i++;
    }
	return (1);
}

static int		check_lose(int **grid)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			if (grid[i][y] == 0)
				return (0);
			y++;
		}
		i++;
	}
	return check_adj(grid);
}

int		check_end(int **grid)
{
	return (check_victory(grid) || check_lose(grid));
}
