#include  <stdio.h>
#include <omp.h>


int count = 0;

void counter(int id) {
	if (count <= 100) {
		count++;
		printf("count: %d, pid: %d\n", count,id);
	}
}


int main(void) {
#pragma omp parallel num_threads(100)
	{
//#pragma omp critical
		counter(omp_get_thread_num());
	}
	
	count = 0;
	printf("count reset\n");

#pragma omp parallel for num_threads(2)
	for (int i = 0; i < 100; i++) {
//#pragma omp critical
		counter(omp_get_thread_num());
	}
}

