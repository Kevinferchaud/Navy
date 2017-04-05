/*
** error2.c for emacs in /home/kevin.ferchaud/PSU_2016_navy
**
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
**
** Started on  Thu Feb  2 19:57:51 2017 ferchaud kevin
** Last update Sun Feb  5 18:21:30 2017 Maxime Le Huu Nho
*/

#include "my.h"

char                    *stringmap(char *pos)
{
  char                  buf[2];
  char                  *buff;
  int                   cpt;
  char                  **map;
  int                   fd;

  cpt = 0;
  if ((fd = open(pos, O_RDONLY)) == -1)
    return (NULL);
  while (read(fd, buf, 1) != 0)
    cpt++;
  buff = malloc(sizeof(char) * (cpt + 1));
  close(fd);
  fd = open(pos, O_RDONLY);
  read(fd, buff, cpt);
  buff[cpt] = '\0';
  close(fd);
  buff = strcapamoi(buff);
  buff = inversmap(buff);
  buff = test_val(buff);
  return (buff);
}

int                     is_a_map(char *map)
{
  int                   cpt;
  int                   nbrn;
  int                   nbrpt;
  char                  *newmap;

  nbrn = 0;
  nbrpt = 0;
  cpt = -1;
  if ((newmap = stringmap(map)) == NULL)
    return (0);
  if (my_strlen(newmap) != 32)
    return (0);
  while (newmap[++cpt] != '\0')
    {
      if (newmap[cpt] == '\n')
	nbrn++;
      if (newmap[cpt] == ':')
	nbrpt++;
    }
  if (nbrn != 4 && nbrpt != 8)
    return (0);
  if (test_coord(newmap) == 0 || test_correct(newmap) == 0)
    return (0);
  return (1);
}

int                     test_coord(char *map)
{
  char                  str[3];
  char                  str2[3];
  int                   cpt;
  int                   cpt2;

  cpt = 0;
  cpt2 = -1;
  if (testval(map) == 0)
    return (0);
  while (++cpt2 < 4)
    {
      str[0] = map[2 + cpt];
      str[1] = map[3 + cpt];
      str[2] = '\0';
      if (checkvalidattack(str) == 0)
	return (0);
      str2[0] = map[5 + cpt];
      str2[1] = map[6 + cpt];
      str2[2] = '\0';
      if (checkvalidattack(str2) == 0 ||
	  testlongmap(map[cpt], str, str2) == 0)
	return (0);
      cpt += 8;
    }
  return (1);
}

int                     testval(char *map)
{
  if (map[0] < '2' || map[0] > '5')
    return (0);
  if (map[8] < '2' || map[8] > '5')
    return (0);
  if (map[16] < '2' || map[16] > '5')
    return (0);
  if (map[24] < '2' || map[24] > '5')
    return (0);
  if (map[0] == map[8] ||
            map[16] == map[24] ||
            map[0] == map[24] ||
      map[8] == map[16])
    return (0);
  if (((map[0] + map[8] + map[16] + map[24]) - ('0' * 4)) != 14)
    return (0);
  return (1);
}

int                     testlongmap(char map, char str[3], char str2[3])
{
  if (str[0])
    if (((map - '0') == ((str2[0] - '0') - (str[0] - '0') + 1) &&
	 ((str2[1] - '0') - (str[1] - '0')) == 0)||
	(((map - '0') == ((str2[1] - '0') - (str[1] - '0') + 1)) &&
	 ((str2[0] - '0') - (str[0] - '0')) == 0))
      return (1);
    else
      return (0);
}
