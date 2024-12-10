#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TESTS 100
#define LOOP_REP 20000000
int main(){
	
	clock_t begin, end;		//cpu ticks
	double durTime, avgDurTime = 0 ;//duration time in ms
	int intValue0, intValue1, intResult;
	float floatValue0, floatValue1, floatResult;
	srand(time(NULL));

	//Addition
	for (int test = 0; test < TESTS; test ++){
		intValue0 = rand()/ 1000;
		intValue1 = rand()/ 1000;

		begin = clock();
		for (int i = 0 ; i < LOOP_REP ; i++){

			intResult = intValue0 + intValue1;
		};
		end = clock();
	
		durTime =(double) (end - begin) / CLOCKS_PER_SEC * 1000; // in milliseconds
		avgDurTime += durTime;
	};
	avgDurTime /= 100;
	printf("Sredni czas dodawania dla int to: %lf\n",avgDurTime);

	//Subtraction
	avgDurTime = 0;
	for (int test = 0; test < TESTS; test ++){
                intValue0 = rand()/ 1000;
                intValue1 = rand()/ 1000;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP ; i++){

                        intResult = intValue0 - intValue1;
                };
                end = clock();

                durTime =(double) (end - begin) / CLOCKS_PER_SEC * 1000; // in milliseconds 
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas odejmowania dla int to: %lf\n",avgDurTime);

	//Multiplication
	avgDurTime = 0;
	for (int test = 0; test < TESTS; test ++){
                intValue0 = rand()/1000;
                intValue1 = rand()/1000;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP ; i++){

                        intResult = intValue0 * intValue1;
                };
                end = clock();

                durTime =(double) (end - begin) / CLOCKS_PER_SEC * 1000; // in milliseconds 
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas mnozenia dla int to: %lf\n",avgDurTime);


	//Division
	avgDurTime = 0;
	for (int test = 0; test < TESTS; test ++){
                intValue0 = rand()/1000;
                intValue1 = rand()/1000;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP ; i++){

                        intResult = intValue0 / intValue1;
                };
                end = clock();

                durTime =(double) (end - begin) / CLOCKS_PER_SEC * 1000; // in milliseconds 
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas dzielenia dla int to: %lf\n",avgDurTime);
	printf("\n");

	//////////////// FLOAT //////////////////
	float a = 100.0; 	//Max range of the random float
	//Addition
	avgDurTime = 0;
        for (int test = 0; test < TESTS; test ++){
                floatValue0 = ((float)rand()/(float)(RAND_MAX)) * a;
                floatValue1 = ((float)rand()/(float)(RAND_MAX)) * a;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP ; i++){

                        floatResult = floatValue0 + floatValue1;
                };
                end = clock();

                durTime =(double) (end - begin) / CLOCKS_PER_SEC * 1000; // in milliseconds 
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas dodawania dla float to: %lf\n",avgDurTime);
	
	//Subtraction
        avgDurTime = 0;
        for (int test = 0; test < TESTS; test ++){
                floatValue0 = ((float)rand()/(float)(RAND_MAX)) * a;
                floatValue1 = ((float)rand()/(float)(RAND_MAX)) * a;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP ; i++){

                        floatResult = floatValue0 - floatValue1;
                };
                end = clock();

                durTime =(double) (end - begin) / CLOCKS_PER_SEC * 1000; // in milliseconds 
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas odejmowania dla float to: %lf\n",avgDurTime);
	
	//Multiplication
        avgDurTime = 0;
        for (int test = 0; test < TESTS; test ++){
                floatValue0 = ((float)rand()/(float)(RAND_MAX)) * a;
                floatValue1 = ((float)rand()/(float)(RAND_MAX)) * a;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP ; i++){

                        floatResult = floatValue0 * floatValue1;
                };
                end = clock();

                durTime =(double) (end - begin) / CLOCKS_PER_SEC * 1000; // in milliseconds 
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas mnozenia dla float to: %lf\n",avgDurTime);

	//Division
        avgDurTime = 0;
        for (int test = 0; test < TESTS; test ++){
                floatValue0 = ((float)rand()/(float)(RAND_MAX)) * a;
                floatValue1 = ((float)rand()/(float)(RAND_MAX)) * a;

                begin = clock();
                for (int i = 0 ; i < LOOP_REP ; i++){

                        floatResult = floatValue0 / floatValue1;
                };
                end = clock();

                durTime =(double) (end - begin) / CLOCKS_PER_SEC * 1000; // in milliseconds 
                avgDurTime += durTime;
        };
        avgDurTime /= 100;
        printf("Sredni czas dzielenia dla float to: %lf\n",avgDurTime);


	return 0;
}
