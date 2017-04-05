/*
** error3.c for emacs in /home/kevin.ferchaud/PSU_2016_navy
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Thu Feb  2 20:52:38 2017 ferchaud kevin
** Last update Thu Feb  2 20:53:22 2017 ferchaud kevin
*/

#include "my.h"

int                     my_error(int ac, char **av, int i)
{
  if (ac == 1 || (ac == 2 &&
		  (av[1][0] == '-' &&
		                      av[1][1] == 'h' &&
		   av[1][2] == '\0')))
    {
      my_printf("USAGE\n\t");
      my_printf("   ./navy [first_player_pid] navy_positions\n\n");
      my_printf("DESCRIPTION\n");
      my_printf("\t   first_player_pid\tonly for the 2nd player.");
      my_printf(" pid of the first player.\n");
      my_printf("\t   navy_positions\tfile representing");
      my_printf(" the positions of the ships.\n");
      return (1);
    }
  if (is_a_map(av[1 + i]) == 0)
    return (1);
  return (0);
}

char                    *inversmap(char *map)
{
  char                  save;
  int                   i;

  i = 0;
  while (i <= 24)
    {
      if (map[2 + i] >= '1' && map[2 + i] <= '8')
	{
	  save = map[2 + i];
	  map[2 + i] = map[3 + i];
	  map[3 + i] = save;
	}
      if (map[5 + i] >= '1' && map[5 + i] <= '8')
	{
	  save = map[5 + i];
	  map[5 + i] = map[6 + i];
	  map[6 + i] = save;
	}
      i+= 8;
    }
  return (map);
}

char                    *test_val(char *map)
{
  char                  save;
  int                   val;

  val = 0;
  while (val <= 24)
    {
      if (map[2 + val] > map[5 + val])
	{
	  save = map[5 + val];
	  map[5 + val] = map[2 + val];
	  map[2 + val] = save;
	}
      if (map[3 + val] > map[6 + val])
	{
	  save = map[6 + val];
	  map[6 + val] = map[3 + val];
	  map[3 + val] = save;
	}
      val += 8;
    }
  return (map);
}
