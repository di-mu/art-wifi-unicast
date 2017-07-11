#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char python_call[256];

unsigned long ms_timer(u_char cmd) {
	static struct timespec times[2];
	unsigned long time_ms = 0;
	clock_gettime(CLOCK_MONOTONIC_RAW, times + cmd);
	if(cmd) time_ms = (times[1].tv_sec - times[0].tv_sec) * 1000
					+ (times[1].tv_nsec - times[0].tv_nsec) / 1000000;
	return time_ms;
}

int main(int argn, char* argv[]) {
	int i; unsigned long t;
	if (argn!=2) {printf("usage: %s <number of runs>", argv[0]); exit(0);}
	srand(time(NULL));
	for (i=atoi(argv[1]); i>0; i--) {
		sprintf(python_call, "python online_opt_mod_test.py %d %d %d %d %d %d %d",
			rand()%22, rand()%9, rand()%101, rand()%101, (rand()%901) + 100, (rand()%100) + 750, (rand()%50)+200);
		//printf("%s => ", python_call+30); fflush(stdout);
		ms_timer(0);
		system(python_call);
		t = ms_timer(1);
		printf("In C: %lu ms\n", t); fflush(stdout);
	}
	return(0);
}
