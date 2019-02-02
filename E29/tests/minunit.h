#undef NDEBUG

#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include <stdlib.h>
#include "../shared/dbg.h"

#define mu_suite_start() char *message = NULL
#define mu_assert(test, message) if (!(test)) { log_err(message); return message; }
#define mu_run_test(test) debug("%s", #test); tests_run++; if ((message = test())) return message;

int tests_run;

#endif