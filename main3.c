/*
** main3.c for emacs in /home/kevin.ferchaud/PSU_2016_navy
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Thu Feb  2 20:09:09 2017 ferchaud kevin
** Last update Thu Feb  2 20:09:58 2017 ferchaud kevin
*/

#include "my.h"

char                    **newmapatk(char **map, char *coord)
{
  int                   cpt;
  int                   cpt2;

  cpt = -1;
  cpt2 = -1;
  while (map[0][++cpt] != coord[0]);
  while (map[++cpt2][0] != coord[1]);
  if (map[cpt2][cpt] == '.')
    map[cpt2][cpt] = 'o';
  if ((map[cpt2][cpt] != 'o') && (map[cpt2][cpt] != '.'))
    map[cpt2][cpt] = 'x';
  return (map);
}

char                    **ennemymap(char **enemy, int touch, char *coord)
{
  int                   cpt;
  int                   cpt2;

  cpt = -1;
  cpt2 = -1;
  while (enemy[0][++cpt] != coord[0]);
  while (enemy[++cpt2][0] != coord[1]);
  if (touch == 0)
    enemy[cpt2][cpt] = 'o';
  else
    enemy[cpt2][cpt] = 'x';
  return (enemy);
}

void                    readmap(char **map, char **emap)
{
  int                   cpt;

  cpt = -1;
  my_putstr("my positions:\n");
  while (map[++cpt] != '\0')
    my_putstr(map[cpt]);
  my_putstr("enemy's positions:\n");
  cpt = -1;
  while (emap[++cpt] != '\0')
    my_putstr(emap[cpt]);
}

char                    **replacemap(char **map, char *pos)
{
  int                   cpt;
  int                   cpt2;
  int                   cpt3;
  int                   cpt4;

  cpt3 = 0;
  while (cpt3 <= 24)
    {
      cpt = -1;
      cpt2 = -1;
      cpt4 = -1;
      while (map[0][++cpt] != pos[2 + cpt3]);
      while (map[++cpt2][0] != pos[3 + cpt3]);
      if (pos[2 + cpt3] != pos[5 + cpt3])
	{
	  cpt -=2;
	  while ((pos[2 + cpt3] + ++cpt4) != (pos[5 + cpt3]) + 1)
	    map[cpt2][cpt+=2] = pos[cpt3];
	}
      else
	while ((pos[3 + cpt3] + ++cpt4) != (pos[6 + cpt3]) + 1)
	  map[cpt2++][cpt] = pos[cpt3];
      cpt3 += 8;
    }
  return (map);
}
