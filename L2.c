#include "types.h"
#include "stat.h"
#include "user.h"


int main() {
	int total_time = 0;
	int j;
	for(j = 0; j < 100; j++) {
		counter_init();
		int start = uptime();
		int d = fork();
		int i;
		my_spin_lock();
		for(i = 0;i<10000;i++){
			counter_set(counter_get() + 1);
		}
		my_spin_unlock();
		if(d == 0) 
			exit();
		
		wait();
		int end = uptime();
		total_time += end - start;
	}
	printf(1, "Average Total Time is %d.%d ticks\n", total_time / 100, total_time % 100);
	exit();
}
