/*
** main7.c for emacs in /home/kevin.ferchaud/PSU_2016_navy
**
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
**
** Started on  Thu Feb  2 20:14:28 2017 ferchaud kevin
** Last update Sun Feb  5 17:45:46 2017 Maxime Le Huu Nho
*/

#include "my.h"

char                    **wait_turn(pid_t epid, char **amap)
{
  char                  *res;

  gpid = -1;
  res = wait_attack();
  my_printf("%s: ", res);
  if (attacknavy(amap, res) == 1)
    {
      my_putstr("hit\n\n");
      kill(epid, 12);
    }
  else
    {
      my_putstr("missed\n\n");
      kill(epid, 10);
    }
  amap = newmapatk(amap, res);
  return (amap);
}

int                    aff_end(char **amap, char **emap, int val)
{
  readmap(amap, emap);
  if (val == 1)
    {
      my_putstr("I won\n");
      return (1);
    }
  else
    my_putstr("Enemy won\n");
  return (0);
}
