/*
** main5.c for emacs in /home/kevin.ferchaud/PSU_2016_navy
**
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
**
** Started on  Thu Feb  2 20:11:41 2017 ferchaud kevin
** Last update Wed Feb 15 10:34:43 2017 Maxime Le Huu Nho
*/

#include "my.h"

char                    *do_binary2(unsigned int a)
{
  char                  *hexa;
  char                  *stock;
  int                   cpt;

  cpt = 0;
  if ((stock = malloc((my_intlenunsign(a) + 1) *
		      sizeof(char))) == NULL)
    return (NULL);
  if (a == 0)
    return (my_strdup("0"));
  hexa = my_strdup("01");
  while (a > 0)
    {
      stock[cpt++] = hexa[a % 2];
      a /= 2;
    }
  stock[cpt] = '\0';
  my_revstr(stock);
  return (stock);
}

int             my_getnbr(char *str)
{
  int           res;
  int           i;

  i = 0;
  res = 0;
  while (str[i])
    {
      res = res * 10 + (str[i] - '0');
      i++;
    }
  return (res);
}

void                    send_attack(pid_t pid, char *s)
{
  int                   i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '0')
	kill(pid, 10);
      else
	kill(pid, 12);
      usleep(1000);
      i++;
    }
}

int	                play_2(pid_t epid, char **amap, char **emap, pid_t apid)
{
  int                   i;

  i = 0;
  if (kill(epid, 10) == -1)
    return (84);
  wait_ad();
  my_putstr("successfully connected\n\n");
  readmap(amap, emap);
  while (i == 0)
    {
      amap = wait_turn(epid, amap);
      if (checkfinish(amap) == 1)
	i = 2;
      else
	{
	  emap = play_turn(epid, emap);
	  if (checkfinish(emap) == 1)
	    i = 1;
	  else
	    readmap(amap, emap);
	}
    }
  return (aff_end(amap, emap, i));
}
