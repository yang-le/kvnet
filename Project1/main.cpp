#include <cstdio>
#include "stastic.h"
#include "random.h"
#include "util.h"

int main(int argc, char **argv)
{
	#define DATA_SIZE 4096
	#define HIST_SIZE 20
	
	printf("generate %d numbers\n", DATA_SIZE);
	float data[DATA_SIZE];
	normal_kv(KV("data", data, "size", DATA_SIZE));
	

	float _hist[HIST_SIZE];
	hist(data, DATA_SIZE, _hist, HIST_SIZE);

	printf("min is %f, max is %f, avg is %f, var is %f\n",
		min(data, DATA_SIZE), max(data, DATA_SIZE), avg(data, DATA_SIZE), var(data, DATA_SIZE));

	puts("distribution");
	plot_kv(KV("data", _hist, "num", HIST_SIZE, "scale", .1));
	return 0;
}
