#include <stdio.h>
#include <time.h>
#include <sys/sysinfo.h>

int main(){

	double a = 2.566543212;
	double b = 5.129395093;
	double c = 0;
	long int loops = 999999;
	double before = clock();
	for(int i = 0; i < loops; i++){
		c = a + b;
	}
	double after = clock();
	double result = loops/((after-before)/CLOCKS_PER_SEC)/(1000*1000)  * get_nprocs_conf();
	printf("GFlops: %lf\n",result );
	return 0;
}
