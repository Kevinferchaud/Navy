/*
** main4.c for emacs in /home/kevin.ferchaud/PSU_2016_navy
**
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
**
** Started on  Thu Feb  2 20:10:21 2017 ferchaud kevin
** Last update Sun Feb  5 18:22:53 2017 Maxime Le Huu Nho
*/

#include "my.h"

char                    **createmap()
{
  char                  **map;

  map = malloc(sizeof(char *) * 11);
  map[0] = my_strdup(" |A B C D E F G H\n");
  map[1] = my_strdup("-+---------------\n");
  map[2] = my_strdup("1|. . . . . . . .\n");
  map[3] = my_strdup("2|. . . . . . . .\n");
  map[4] = my_strdup("3|. . . . . . . .\n");
  map[5] = my_strdup("4|. . . . . . . .\n");
  map[6] = my_strdup("5|. . . . . . . .\n");
  map[7] = my_strdup("6|. . . . . . . .\n");
  map[8] = my_strdup("7|. . . . . . . .\n");
  map[9] = my_strdup("8|. . . . . . . .\n\n");
  map[10] = NULL;
  return (map);
}

char                    **stockmap(char *pos)
{
  char                  buf[2];
  char                  *buff;
  int                   cpt;
  char                  **map;
  int                   fd;

  cpt = 0;
  fd = open(pos, O_RDONLY);
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
  map = createmap();
  map = replacemap(map, buff);
  return (map);
}

char                    *make_zero(char *str)
{
  int                   i;
  int                   j;
  char                  *res;

  i= my_strlen(str);
  if (i == 8)
    return (str);
  j = 8 - i;
  res = malloc((j + 1) * sizeof(char));
  i = 0;
  while (i < j)
    res[i++] = '0';
  res[j] = '\0';
  str = strcatamoi(res, str);
  return (str);
}
