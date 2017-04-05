/*
** my.h for  in /home/lehuun_m/delivery/PSU_2016_navy/include
**
** Made by Maxime Le Huu Nho
** Login   <lehuun_m@epitech.net>
**
** Started on  Mon Jan 30 17:04:44 2017 Maxime Le Huu Nho
** Last update Sun Feb  5 17:45:33 2017 Maxime Le Huu Nho
*/

#ifndef MY_H
# define MY_H

#ifndef READ_SIZE
# define READ_SIZE (10)
#endif /* !READ_SIZE */

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

int	gpid;
int	my_strlen(char *);
char	*get_next_line(const int);
void	my_putstr(char *);
void	my_printf(const char *, ...);
void    do_int(int a);
void    do_long(long a);
void    do_float(float a);
void    do_char(char a);
void    do_string(char *a);
void    do_point(int a);
void    do_short(short a);
int     do_hexd(int a);
int     do_binary(unsigned a);
void    do_prints(char *a);
int     do_modulo();
int	my_getnbr(char *);
char	*my_strdup(char *);
void	my_putchar(char);
int	my_intlenunsign(unsigned int);
char	*my_revstr(char *);
char	*strcatamoi(char *, char *);
int	testlongmap(char map, char str[3], char str2[3]);
char	**play_turn(pid_t epid, char **emap);
char    *wait_attack();
char    *recup_message();
char    make_char();
void    wait_answer();
char    **wait_turn(pid_t epid, char **amap);
int	aff_end(char **amap, char **emap, int val);
char    *do_binary2(unsigned int a);
int	my_getnbr(char *str);
void    send_attack(pid_t pid, char *s);
int	play_2(pid_t epid, char **amap, char **emap, pid_t apid);
char    **replacemap(char **map, char *pos);
char    **createmap();
char    **stockmap(char *pos);
char    *make_zero(char *str);
char    **newmapatk(char **map, char *coord);
char    **ennemymap(char **enemy, int touch, char *coord);
void    readmap(char **map, char **emap);
char    *strcapamoi(char *str);
int     checkfinish(char **map);
char    *checkvalueattack(char *coord);
int     checkvalidattack(char *coord);
int     attacknavy(char **map, char *coord);
int	play_1(char **amap, char **emap, pid_t apid);
void    conexion_hdl(int sig, siginfo_t *info, void *text);
void    attack_hdl(int sig, siginfo_t *info, void *text);
void    wait_ad();
int     my_error(int ac, char **av, int i);
char    *inversmap(char *map);
char    *test_val(char *map);
int     check_save(char *save);
int     test_correct(char *map);
char    *stringmap(char *pos);
int     is_a_map(char *map);
int     test_coord(char *map);
int     testval(char *map);
int     testlongmap(char map, char str[3], char str2[3]);

#endif /* !MY_H */
