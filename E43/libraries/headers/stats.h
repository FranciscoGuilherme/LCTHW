#ifndef _stats_h
#define _stats_h

typedef struct Stats
{
	double sum;
	double sumsq;
	double min;
	double max;
	unsigned long n;
} Stats;

Stats *Stats_recreate(double sum, double sumsq, unsigned long n, double min, double max);
Stats *Stats_create();

double Stats_mean(Stats *st);
double Stats_stddev(Stats *st);
void Stats_sample(Stats *st, double s);
void Stats_dump(Stats *st);

#endif