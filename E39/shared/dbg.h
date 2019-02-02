#ifndef _dbg_h
#define _dbg_h

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
	#define debug(M, ...)
	#define check_mem(A)
	#define sentinel(M, ...)
#else
	#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
	#define check_mem(A) check((A), "Out of memory.")
	#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); }
#endif

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, (!errno ? "None" : strerror(errno)), ##__VA_ARGS__)
#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, (!errno ? "None" : strerror(errno)), ##__VA_ARGS__)
#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define finalize() { errno = 0; goto error; }
#define check(A, M, ...) if (!(A)) { log_err(M, ##__VA_ARGS__); finalize() }
#define check_debug(A, M, ...) if (!(A)) { debug(M, ##__VA_ARGS__); finalize(); }

#endif