/*
** get_next_line.c for  in /home/lehuun_m/delivery/CPE_2016_getnextline
**
** Made by Maxime Le Huu Nho
** Login   <lehuun_m@epitech.net>
**
** Started on  Wed Jan 11 15:56:38 2017 Maxime Le Huu Nho
** Last update Sun Feb  5 18:08:49 2017 Maxime Le Huu Nho
*/

#include "my.h"

int     my_strlena(char *str)
{
  int   i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

char    *strcatamoi(char *s1, char *s2)
{
  char  *res;
  int   i;
  int   j;

  i = 0;
  j = 0;
  if ((res = malloc((my_strlena(s1) + my_strlena(s2) + 1)
		    * sizeof(char))) == NULL)
    return (NULL);
  while (s1 != NULL && s1[i] != '\0')
    {
      res[i] = s1[i];
      i++;
    }
  while (s2 != NULL && s2[j] != '\0')
    {
      res[i + j] = s2[j];
      j++;
    }
  res[i + j] = '\0';
  return (res);
}

int		check_char(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	return (0);
      i++;
    }
  return (1);
}

char             *monstrtol(char *str, char **endptr)
{
  char		*res;
  int           i;

  i = 0;
  if ((res = malloc((my_strlena(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  res[i] = '\0';
	  i++;
	  *endptr = &str[i];
	  return (res);
	}
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  *endptr = NULL;
  return (res);
}

char		*get_next_line(const int fd)
{
  static char	*str;
  char		buffer[READ_SIZE + 1];
  int		len;

  len = 1;
  if (str != NULL)
    if (check_char(str) != 1)
      return (monstrtol(str, &str));
  while (len)
    {
      if ((len = read(fd, buffer, READ_SIZE)) <= 0)
	return (NULL);
      buffer[len] = '\0';
      len = check_char(buffer);
      if ((str = strcatamoi(str, buffer)) == NULL)
	return (NULL);
    }
  return (monstrtol(str, &str));
}
