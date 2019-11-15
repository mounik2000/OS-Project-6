#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char* argv[]) {
	int i;
	int start = uptime();
	for(i = 0; i < 10000; i++) {
		counter_set(counter_get() + 1);
	}
	int end = uptime();
	printf(1, "Time - %d ticks\n", end - start);
	exit();
}
