/*
** error.c for emacs in /home/kevin.ferchaud/PSU_2016_navy
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Wed Feb  1 18:17:36 2017 ferchaud kevin
** Last update Thu Feb  2 20:53:26 2017 ferchaud kevin
*/

#include "my.h"

char			*remp_res(char *save, int cpt)
{
  char			*res;

  res = malloc(sizeof(char) * 3);
  res[0] = save[cpt];
  res[1] = save[cpt + 1];
  res[2] = '\0';
  return (res);
}
int			check_save(char *save)
{
  int			cpt;
  int			cpt2;
  char			*res;
  int			j;

  cpt = 0;
  while (save[cpt] != '\0')
    {
      cpt2 = 0;
      j = 0;
      res = remp_res(save, cpt);
      while (save[cpt2] != '\0')
	{
	  if (save[cpt2] == res[0] &&
	      save[cpt2 + 1] == res[1])
	    {
	      j++;
	      if (j == 2)
		return (0);
	    }
	  cpt2 += 2;
	}
      cpt +=2;
    }
  return (1);
}

char			*concat_save1(char *map, int cpt, char *save, int i)
{
  char			*new;
  new = malloc(sizeof(char) * 3);
  while ((map[3 + i] + cpt) != map[6 + i] + 1)
    {
      new[0] = map[2 + i];
      new[1] = map[3 + i] + cpt;
      new[2] = '\0';
      save = strcatamoi(save, new);
      cpt++;
    }
  return (save);
}

char			*concat_save2(char *map, int cpt, char *save, int i)
{
  char			*new;
  new = malloc(sizeof(char) * 3);
  while ((map[3 + i] + cpt) != map[6 + i] + 1)
    {
      new[0] = map[2 + i];
      new[1] = map[3 + i] + cpt;
      new[2] = '\0';
      save = strcatamoi(save, new);
      cpt++;
    }
  return (save);
}

int			test_correct(char *map)
{
  char		        *save;
  int			cpt;
  int			i;

  i = 0;
  save = "";
  while (i <= 24)
    {
      cpt = 0;
      if (map[2 + i] == map[5 + i])
	save = concat_save1(map, cpt, save, i);
      else
	save = concat_save1(map, cpt, save, i);
      i += 8;
    }
  if (check_save(save) == 0)
    return (0);
  return (1);
}
