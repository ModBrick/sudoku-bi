/*
** set_function.c for setfunction in /home/capon_p/rendu/sudoki-bi/
**
** Made by pierre capon
** Login   <jossel_a@epitech.eu>
**
** Started on  Sun Feb 28 22:10:43 2016 pierre capon
** Last update Sun Feb 28 23:55:37 2016 pierre capon
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

void    show(int **grid)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  printf("|------------------|\n");
  while (i < 9)
    {
      printf("| ");
      while (j < 8)
	{
	  printf("%d ", grid[i][j]);
	  j++;
	}
      printf("%d|", grid[i][j]);
      putchar('\n');
      i++;
      j = 0;
    }
  printf("|------------------|\n");
}

int     **alloc_int(int **tab)
{
  int   j;

  j = 8;
  tab = malloc(sizeof(int *) * 9);
  while (j >= 0)
    {
      tab[j] = malloc(sizeof(int) * 9);
      j--;
    }
  return (tab);
}

char    *set_grille(char *grille)
{
  int   i;

  grille = malloc(sizeof(char) * 4096);
  i = read(0, grille, 231);
  if (i == 0)
    return (NULL);
  if (grille[229] != '|')
    {
      printf("MAP ERROR\n");
      return(NULL);
    }
  return (grille);
}

int     **set_int_tab(int **tab, char *grille)
{
  int   count;
  int   j;
  int   k;
  char  number[1];

  tab = alloc_int(tab);
  count = 23;
  j = 0;
  while (j != 9 && !(k = 0))
    {
      while (k != 9)
	{
	  number[0] = grille[count];
	  if (number[0] == '0' && (count += 2) && !(tab[j][k++] = 0))
	    count += 2;
	  else
	    {
	      tab[j][k++] = atoi(number);
	      count += 2;
	    }
	}
      count += 3;
      j++;
    }
  return (tab);
}
