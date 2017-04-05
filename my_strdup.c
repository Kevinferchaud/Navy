/*
** my_strdup.c for emacs in /home/kevin.ferchaud/CPool_Day08/task01
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Wed Oct 12 18:22:23 2016 ferchaud kevin
** Last update Tue Jan 31 14:54:55 2017 ferchaud kevin
*/

#include "my.h"

char	*my_strdup(char *src)
{
  char	*res;
  int	cpt;

  cpt = 0;
  if ((res = malloc((my_strlen(src) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (src[cpt] != '\0')
    {
      res[cpt] = src[cpt];
      cpt++;
    }
  res[cpt] = '\0';
  return (res);
}
