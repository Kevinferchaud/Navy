/*
** main2.c for emacs in /home/kevin.ferchaud/PSU_2016_navy
**
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
**
** Started on  Thu Feb  2 20:06:50 2017 ferchaud kevin
** Last update Sun Feb  5 18:17:12 2017 Maxime Le Huu Nho
*/

#include "my.h"

char                    *strcapamoi(char *str)
{
  int                   i;

  if (str == NULL)
    return (NULL);
  i = 0;
  str = my_strdup(str);
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] -= 32;
      i++;
    }
  return (str);
}

int                     checkfinish(char **map)
{
  int                   cpt;
  int                   cpt2;
  int                   x;

  cpt = -1;
  cpt2 = 0;
  x = 0;
  while (map[cpt2] != '\0')
    {
      if (map[cpt2][++cpt] == 'x')
	x++;
      if (map[cpt2][cpt] == '\n')
	{
	  cpt2++;
	  cpt = -1;
	}
    }
  if (x == 14)
    return (1);
  return (0);
}

char                    *checkvalueattack(char *coord)
{
  char                  stock;

  if (coord[0] >= '1' && coord[0] <= '8')
    if (coord[1] >= 'A' && coord[1] <= 'H')
      {
	stock = coord[1];
	coord[1] = coord[0];
	coord[0] = stock;
      }
  return (coord);
}

int                     checkvalidattack(char *coord)
{
  if (coord == NULL)
    return (2);
  if (my_strlen(coord) != 2)
    {
      write(1, "wrong position\n", my_strlen("wrong position\n"));
      return (0);
    }
  if (((coord[0] >= 'A' && coord[0] <= 'H') &&
       (coord[1] >= '1' && coord[1] <= '8')) ||
      ((coord[1] >= 'A' && coord[1] <= 'H') &&
       (coord[0] >= '1' && coord[0] <= '8')))
    return (1);
  else
    {
      write(1, "wrong position\n", my_strlen("wrong position\n"));
      return (0);
    }
}

int                     attacknavy(char **map, char *coord)
{
  int                   cpt;
  int                   cpt2;

  cpt = -1;
  cpt2 = -1;
  while (map[0][++cpt] != coord[0]);
  while (map[++cpt2][0] != coord[1]);
  if (map[cpt2][cpt] >= '2' && map[cpt2][cpt] <= '5')
    return (1);
  else
    return (0);
}
