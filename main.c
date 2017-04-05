/*
** navy.c for emacs in /home/kevin.ferchaud
**
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
**
** Started on  Mon Jan 30 14:36:13 2017 ferchaud kevin
** Last update Thu Feb  9 17:08:50 2017 ferchaud kevin
*/

#include "my.h"
int			gpid;

int			play_1(char **amap, char **emap, pid_t apid)
{
  pid_t			epid;
  int			i;

  i = 0;
  my_putstr("waiting for enemy connexion...\n");
  wait_ad();
  epid = gpid;
  my_putstr("enemy connected\n\n");
  kill(epid, 10);
  readmap(amap, emap);
  while (i == 0)
    {
      emap = play_turn(epid, emap);
      if (checkfinish(emap) == 1)
	i = 1;
      else
	{
	  amap = wait_turn(epid, amap);
	  if (checkfinish(amap) == 1)
	    i = 2;
	  else
	    readmap(amap, emap);
	}
    }
  return (aff_end(amap, emap, i));
}

void                    conexion_hdl(int sig, siginfo_t *info, void *text)
{
  gpid = info->si_pid;
}

void                    attack_hdl(int sig, siginfo_t *info, void *text)
{
  if (sig == 10)
    gpid = 0;
  else
    gpid = 1;
}

void                    wait_ad()
{
  struct sigaction      act;

  act.sa_sigaction = &conexion_hdl;
  act.sa_flags = SA_SIGINFO;
  sigaction(10, &act, NULL);
  while (gpid == 0);
}

int			main(int ac, char **av)
{
  gpid = 0;
  if (ac == 2)
    {
      if (my_error(ac, av, 0) == 1)
	return (84);
      my_printf("my_pid: %d\n", getpid());
      return (play_1(stockmap(av[1]), createmap(), getpid()));
    }
  else
    if (ac == 3)
      {
	if (my_error(ac, av, 1) == 1)
	  return (84);
	my_printf("my_pid: %d\n", getpid());
	return (play_2(my_getnbr(av[1]), stockmap(av[2]),
		       createmap(), getpid()));
      }
  return (0);
}
