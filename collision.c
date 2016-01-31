/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:23:22 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/30 19:08:07 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ncurses.h>

#define SIZE 4

static void	collision_right(int **grid)
{
	int		i;
	int		y;

	i = 0;
	while (i < SIZE)
	{
		y = SIZE - 1;
		while (y > 0)
		{
			if (grid[i][y] == grid[i][y -1])
			{
			   grid[i][y] = grid[i][y] + grid[i][y - 1];
			   grid[i][y-1] = 0;
			}
			y--;
		}
		i++;
	}
}

static void	collision_left(int **grid)
{
	int		i;
	int		y;

	i = 0;
	while (i < SIZE)
	{
		y = 0;
		while (y < SIZE - 1)
		{
			if (grid[i][y] == grid[i][y + 1])
			{
				grid[i][y] = grid[i][y] + grid[i][y + 1];
				grid[i][y + 1] = 0;
			}
			y++;
		}
		i++;
	}
}

static void collision_up(int **grid)
{
	int		i;
	int		y;

	y = 0;
	while (y < SIZE)
	{
		i =  0;
		while (i < SIZE -1)
		{
			if (grid[i][y] == grid[i + 1][y])
			{
				grid[i][y] = grid[i][y] + grid[i + 1][y];
				grid[i +1][y] = 0;
			}
			i++;
		}
		y++;
	}
}

static void collision_down(int **grid)
{
	int		i;
	int		y;

	y = 0;
	while (y < SIZE)
	{
		i = SIZE - 1;
		while (i > 0)
		{
			if (grid[i][y] == grid[i - 1][y])
			{
				grid[i][y] = grid[i][y] + grid[i - 1][y];
				grid[i -1][y] = 0;
			}
			i--;
		}
		y++;
	}
}

void	collision(int **grid, int direction)
{
	if (direction == KEY_RIGHT)
		collision_right(grid);
	else if (direction == KEY_LEFT)
		collision_left(grid);
	else if (direction == KEY_UP)
		collision_up(grid);
	else if (direction == KEY_DOWN)
		collision_down(grid);
}
