/*
** main.c for sudoku in /home/capon_p/sudoki/
**
** Made by pierre capon
** Login   <jossel_a@epitech.eu>
**
** Started on  Sat Feb 27 10:24:21 2016 pierre capon
** Last update Mon Feb 29 00:04:37 2016 pierre capon
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int     checkligne(int k, int **grid, int i)
{
  int   j;

  j = 0;
  while (j < 9)
    {
      if (grid[i][j] == k)
	return (0);
      j++;
    }
  return (1);
}

int     checkcolumn(int k, int **grid, int j)
{
  int   i;

  i = 0;
  while (i < 9)
    {
      if (grid[i][j] == k)
	return (0);
      i++;
    }
  return (1);
}

int     checkbloc(int k, int **grid, int i, int j)
{
  int   ibis;
  int   jbis;

  ibis = i - (i % 3);
  jbis = j - (j % 3);
  i= ibis;
  while (i < ibis +3)
    {
      j = jbis;
      while (j < jbis + 3)
	{
	  if (grid[i][j] == k)
	    return (0);
	  j++;
	}
      i++;
    }
  return (1);
}

int     isright(int **grid, int position)
{
  int   i;
  int   j;
  int   k;

  if (position == 9*9)
    return (1);
  k = 1;
  i = position / 9;
  j = position % 9;
  if (grid[i][j] != 0)
    return isright(grid, position+1);
  while (k <= 9)
    {
      if (checkligne(k, grid, i) && checkcolumn(k, grid, j)
	  && checkbloc(k, grid, i, j))
	{
	  grid[i][j] = k;
	  if (isright(grid, position+1))
	    return (1);
	}
      k++;
    }
  grid[i][j] = 0;
  return (0);
}

int	main()
{
  int	count;
  char	*grille;
  int	**tab;

  count = 0;
  while ((grille = set_grille(grille)) != NULL)
    {
      if (count != 0)
	printf("####################\n");
      tab = set_int_tab(tab, grille);
      isright(tab, 0);
      show(tab);
      count++;
    }
  return (0);
}
