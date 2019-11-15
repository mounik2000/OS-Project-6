#include "types.h"
#include "stat.h"
#include "user.h"


int main() {
	int total_time = 0;
	int j;
	for(j = 0; j < 10; j++) {
		counter_init();
		int start = uptime();
		int d = fork();
		int i;
		for(i = 0;i<10000;i++){
			counter_set(counter_get() + 1);
		}
		if(d == 0) 
			exit();
		wait();
		int end = uptime();
		total_time += end - start;
		printf(1, "%d - %d ticks\n", counter_get(), end - start);
	}
	exit();
}
