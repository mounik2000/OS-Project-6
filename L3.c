#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf(1, "L3: missing operand\nExpected integer after L3\n");
		exit();
	}
	set_wait_bound(atoi(argv[1]));
	int total_time = 0;
	int total_yields = 0;
	int j;
	for(j = 0; j < 100; j++) {
		counter_init();
		int start = uptime();
		int d = fork();
		int i;
		my_futex_lock();
		for(i = 0;i<10000;i++){
			counter_set(counter_get() + 1);
		}
		my_futex_unlock();
		
		if(d == 0) 
			exit();
		
		wait();
		int end = uptime();
		total_time += end - start;
		total_yields += get_num_yields();
	}
	printf(1, "Average Total Time is %d.%d ticks\n", total_time / 100, total_time % 100);
	printf(1, "The average number of times we yield is %d.%d\n", total_yields / 100, total_yields % 100);
	exit();
}
