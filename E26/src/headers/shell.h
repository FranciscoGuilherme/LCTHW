#ifndef _shell_h
#define _shell_h

#define MAX_COMMANDS_ARGS 100

#include <apr_thread_proc.h>

typedef struct Shell
{
	const char *dir;
	const char *exe;
	const char *args[MAX_COMMANDS_ARGS];

	apr_procattr_t *attr;
	apr_proc_t proc;
	apr_exit_why_e exit_why;

	int exit_code;
} Shell;

int Shell_run(apr_pool_t *p, Shell *cmd);
int Shell_exec(Shell cmd, ...);

extern Shell CLEANUP_SH;
extern Shell GIT_SH;
extern Shell TAR_SH;
extern Shell CURL_SH;
extern Shell CONFIGURE_SH;
extern Shell MAKE_SH;
extern Shell INSTALL_SH;

#endif