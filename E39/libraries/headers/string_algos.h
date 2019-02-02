#ifndef _string_algos_h
#define _string_algos_h

#include "bstrlib.h"
#include "darray.h"

typedef struct StringScanner
{
	bstring in;
	ssize_t hlen;
	ssize_t nlen;
	size_t skip_chars[UCHAR_MAX + 1];
	const unsigned char *haystack;
	const unsigned char *needle;
} StringScanner;

int String_find(bstring in, bstring what);
int StringScanner_scan(StringScanner *scan, bstring tofind);
void StringScanner_destroy(StringScanner *scan);
StringScanner *StringScanner_create(bstring in);

#endif