#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int o_strcomp(char *str1, char *str2);
size_t o_str_n_comp(char *str1, char *str2, size_t n);
int o_str_length(char *string);
char *o_strcopy(char *dest, char *src);
char *o_strconcat(char *dest, char *src);
int o_putcharac(char carma);
char *o_strchart(const char *string, int carma);
size_t o_strspin(const char *str1, const char *str2);
size_t o_strspun(const char *str1, const char *str2);

char *o_path_find(char **env_scap);
int abpaz(char **parag, char **env_scap);
char *o_cmd(void);
int o_pick(char **parag, char **argv, char **env_scap,
char *p_o_tr, int nerp, int carma);
char *o_toks(char *str, const char *delim);
void o_get_environ(char **env_scap);
char **o_get_toktok(char *p_o_tr);
void o_exit(char **args, char *p_o_tr, int _out_);



#endif