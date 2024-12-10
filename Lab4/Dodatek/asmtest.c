#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){

        int intValue0, intValue1, intResult;
        clock_t begin, end;
        double durTime, avgDurTime = 0;
        srand(time(NULL));

        for (int test = 0; test < 100; test++){
                //intValue0 = rand();
                //intValue1 = rand();
        	intValue0 = 346436576;
        	intValue1 = 1743564381;
                begin = clock();
                for (int i = 0 ; i < 10000000; i++){

                        __asm__ volatile(

                        "movl %2, %%edx \n"
                        "addl %1, %%edx \n"
                        "movl %%edx, %0 "
                        : "=g"(intResult) //tylko zapis
                        :"g"(intValue0), "g"(intValue1)
                        : "edx"
                        );
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
		avgDurTime += durTime;
	};
	avgDurTime /= 100;
        printf("Sredni czas dodawania dwoch int to: %lf\n",avgDurTime);

	return 0;
}
