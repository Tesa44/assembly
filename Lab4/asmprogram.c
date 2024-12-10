#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TESTS 100
#define LOOP_REP 20000000
int main(){

	int intValue0, intValue1, intResult;
	float floatValue0, floatValue1, floatResult;
	float *addr = &floatResult;
	clock_t begin, end;
	double durTime, avgDurTime = 0;
	srand(time(NULL));

	for (int test = 0; test < TESTS; test++){
		intValue0 = rand()/ 1000;
		intValue1 = rand()/ 1000;

		begin = clock();
		for (int i = 0 ; i < LOOP_REP; i++){

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
	
	//Subrtaction
	avgDurTime = 0;
        for (int test = 0; test < TESTS; test++){
                intValue0 = rand()/ 1000;
                intValue1 = rand()/ 1000;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                        __asm__ volatile(

                        "movl %2, %%edx \n"
                        "subl %1, %%edx \n"
                        "movl %%edx, %0 "
                        : "=g"(intResult) //tylko zapis
                        : "g"(intValue0), "g"(intValue1)
                        : "edx"
                        );
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas odejmowanie dwoch int to: %lf\n",avgDurTime); 
	
	//Multiplication
	avgDurTime = 0;
        for (int test = 0; test < TESTS; test++){
                intValue0 = rand()/1000;
                intValue1 = rand()/1000;
		//printf("%d %d ", intValue0, intValue1);
                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                        __asm__ volatile(

                        "movl %2, %%eax \n"
                        "mull %1 \n"
                        "movl %%eax, %0 "
                        : "=g"(intResult) //tylko zapis
                        : "g"(intValue0), "g"(intValue1)
                        : "eax"
                        );
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas mnozenia dwoch int to: %lf\n",avgDurTime); 
	
	//Division
        avgDurTime = 0;
        for (int test = 0; test < TESTS; test++){
                intValue0 = rand()/1000;
                intValue1 = rand()/1000;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                        __asm__ volatile(

                        "movl $0, %%edx \n"	//rozszerzenie
			"movl %1, %%eax \n"	//dzielna
			//"movl %2, %%ecx \n"	//dzielnik
                        "divl %2 \n"
                        "movl %%eax, %0"
                        : "=g"(intResult) //tylko zapis
                        : "g"(intValue0), "g"(intValue1)
                        : "edx", "eax", "ecx"
                        );
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas mnozenia dwoch int to: %lf\n",avgDurTime); 
	printf("\n");
	///////////// FLOAT ///////////////
	float a = 100.0;
	//Addition
	avgDurTime = 0;
	for (int test = 0; test < TESTS; test ++){
		floatValue0 = ((float)rand()/(float)(RAND_MAX)) * a;
                floatValue1 = ((float)rand()/(float)(RAND_MAX)) * a;

		begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                        __asm__ volatile(

                        "flds %2 \n"
                        "flds %1  \n"
                        "faddp \n"
                        "fstp (%0)"
                       // : "=g"(sumFloat) //tylko zapis
                        :
                        :"r"(addr), "g"(floatValue0), "g"(floatValue1)
                        : "memory"
                        );
                };
                end = clock();
                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
		avgDurTime += durTime;
	};
	avgDurTime /= 100;
    	printf("Sredni czas dodawania float to: %lf\n", avgDurTime);
	
	//Subtraction
        avgDurTime = 0;
        for (int test = 0; test < TESTS; test ++){
                floatValue0 = ((float)rand()/(float)(RAND_MAX)) * a;
                floatValue1 = ((float)rand()/(float)(RAND_MAX)) * a;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                        __asm__ volatile(

                        "flds %2 \n"
                        "flds %1  \n"
                        "fsubp \n"
                        "fstp (%0)"
                       // : "=g"(sumFloat) //tylko zapis
                        :
                        :"r"(addr), "g"(floatValue0), "g"(floatValue1)
                        : "memory"
                        );
                };
                end = clock();
                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas odejmowania float to: %lf\n", avgDurTime);

	//Multiplication
	avgDurTime = 0;
        for (int test = 0; test < TESTS; test ++){
                floatValue0 = ((float)rand()/(float)(RAND_MAX)) * a;
                floatValue1 = ((float)rand()/(float)(RAND_MAX)) * a;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                        __asm__ volatile(

                        "flds %2 \n"
                        "flds %1  \n"
                        "fmulp \n"
                        "fstp (%0)"
                       // : "=g"(sumFloat) //tylko zapis
                        :
                        :"r"(addr), "g"(floatValue0), "g"(floatValue1)
                        : "memory"
                        );
                };
                end = clock();
                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas mnozenia float to: %lf\n", avgDurTime);
	
	//Division
        avgDurTime = 0;
        for (int test = 0; test < TESTS; test ++){
                floatValue0 = ((float)rand()/(float)(RAND_MAX)) * a;
                floatValue1 = ((float)rand()/(float)(RAND_MAX)) * a;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                        __asm__ volatile(

                        "flds %2 \n"
                        "flds %1  \n"
                        "fdivp \n"
                        "fstp (%0)"
                       // : "=g"(sumFloat) //tylko zapis
                        :
                        :"r"(addr), "g"(floatValue0), "g"(floatValue1)
                        : "memory"
                        );
                };
                end = clock();
                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas dzielenia float to: %lf\n", avgDurTime);

	return 0;
}
