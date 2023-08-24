#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define PROG_NAME "./shell"
#define PROMPT "USER@SHELL:~$ "
#define PROMPT_LEN 14

/** env function */
void _envHandler(char **env, char **av);

/** exit function */
void _exitHandler(int ac, char **av, char *buf);

/** free_memory function */
void _freeAV(char **av);

/** getline functions */
size_t _getline(char **buf);

/** get_tokens functions */
size_t _getTokenLen(char *buf);
char **_getToken(char **av, char *buf);

/** path functions */
char *_getenv(char *var_name, char **envp);
char *_pathConcat(char *cmd, char *tok);
char *_findCMD(char *cmd, char **envp);

/** process function */
int _forkProcess(char **av, char *cmd, char *buf, char **env, int ex);

/** prompt function */
void _prompt(void);

/** strings functions */
int _strlen(char *str);
char *_strcpy(char *dst, char *src);
char *_strcat(char *dst, char *src);
int _strcmp(char *str1, char *str2);
char *_strdup(char *src);

#endif /* MAIN_HEADER */


