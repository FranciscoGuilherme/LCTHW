#ifndef _E25_h
#define _E25_h

#define MAX_DATA 100

int read_string(char **out_string, int max_buffer);
int read_int(int *out_int);
int read_scan(const char *fmt, ...);

#endif