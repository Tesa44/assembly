#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){

        clock_t begin, end;             //cpu ticks
        double durTime, avgDurTime = 0 ;//duration time in ms
        int intValue0, intValue1, intResult;
        srand(time(NULL));

	for (int test = 0; test < 100;test ++){
		//intValue0 = rand();
		//intValue1 = rand();
       		intValue0 = 343609937;
        	intValue1 = 1725330624;
                begin = clock();
                for (int i = 0 ; i < 10000000 ; i++){

                        intResult = intValue0 + intValue1;
                };
                end = clock();

                durTime =(double) (end - begin) / CLOCKS_PER_SEC * 1000; // in milliseconds
		avgDurTime += durTime;
      	};
	avgDurTime /= 100;
        printf("Sredni czas dodawania bez asm dla int to: %lf \n",avgDurTime);

	return 0;
}
