/*
** main6.c for emacs in /home/kevin.ferchaud/PSU_2016_navy
**
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
**
** Started on  Thu Feb  2 20:13:01 2017 ferchaud kevin
** Last update Wed Feb 15 10:29:02 2017 Maxime Le Huu Nho
*/

#include "my.h"

void                    wait_answer()
{
  struct sigaction      act;

  gpid = -1;
  act.sa_sigaction = &attack_hdl;
  act.sa_flags = SA_SIGINFO;
  sigaction(10, &act, NULL);
  sigaction(12, &act, NULL);
  while (gpid == -1);
}

char                    make_char()
{
  static char           c;

  if (gpid == 0)
    c = (c << 1) + 0;
  else
    if (gpid == 1)
      c = (c << 1) + 1;
  return (c);
}

char                    *recup_message()
{
  char                  *res;
  int                   cpt;
  int                   i;

  cpt = 0;
  i = 0;
  res = malloc(3 * sizeof(char));
  while (cpt != 16)
    {
      if (gpid == 0 || gpid == 1)
	{
	  res[i] = make_char();
	  cpt++;
	  if (cpt == 8)
	    i++;
	}
      gpid = -1;
      usleep(10000);
    }
  res[2] = '\0';
  return (res);
}

char                    *wait_attack()
{
  struct sigaction      func;
  char                  *res;

  my_putstr("waiting for enemy's attack...\n");
  func.sa_sigaction = &attack_hdl;
  func.sa_flags = SA_SIGINFO;
  sigaction(10, &func, NULL);
  sigaction(12, &func, NULL);
  res = recup_message();
  return (res);
}

char                    **play_turn(pid_t epid, char **emap)
{
  char                  *s;
  char                  *save;
  int			i;

  my_putstr("attack: ");
  s = strcapamoi(get_next_line(0));
  while ((i = checkvalidattack(s)) != 1)
    {
      if (i != 2)
	my_putstr("attack: ");
      s = strcapamoi(get_next_line(0));
    }
  s = checkvalueattack(s);
  my_printf("%s: ", s);
  save = s;
  s = strcatamoi(make_zero(do_binary2(s[0])),
		 make_zero(do_binary2(s[1])));
  send_attack(epid, s);
  wait_answer();
  if (gpid == 0)
    my_putstr("missed\n\n");
  else
    my_putstr("hit\n\n");
  return (ennemymap(emap, gpid, save));
}
