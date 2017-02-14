/*
** my.h for my in /home/jossel_a/rendu/sudoki-bi/include/
**
** Made by arthur josselin
** Login   <jossel_a@epitech.eu>
**
** Started on  Sun Feb 28 22:04:11 2016 arthur josselin
** Last update Sun Feb 28 22:04:15 2016 arthur josselin
*/

#ifndef MY_H_
# define MY_H_

void    show(int **grid);
int     **alloc_int(int **tab);
char    *set_grille(char *grille);
int     **set_int_tab(int **tab, char *grille);
int     checkligne(int k, int **grid, int i);
int     checkcolumn(int k, int **grid, int j);
int     checkbloc(int k, int **grid, int i, int j);
int     isright(int **grid, int position);

#endif /* !MY_H_ */
