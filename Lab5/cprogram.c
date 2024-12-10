#include <stdio.h>
#include <time.h>
#define TESTS 100
#define LOOP_REP 2500000
int main(){

        int l1[4] = {123674569,67546354,3663436,35664475};
        int l2[4] = {14664674,5678853,8854754,576746};
        int l3[4] = {0,0,0,0};
        int *ad1 = l1;
        int *ad2 = l2;
        int *ad3 = l3;
        clock_t begin, end;
        double durTime, avgDurTime = 0;
	/////ADDITION////
        for (int test = 0; test < TESTS; test++){

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){
			l3[0] = l1[0] + l2[0];
			l3[1] = l1[1] + l2[1];
			l3[2] = l1[2] + l2[2];
			l3[3] = l1[3] + l2[3];
		};
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= TESTS;
        printf("Sredni czas dodawania dwoch int to: %lf\n",avgDurTime); 
	printf("wyniki: %d %d %d %d \n", l3[0],l3[1],l3[2],l3[3]);
	
	/////SUBTRACTION///////
	avgDurTime = 0;
	for (int test = 0; test < TESTS; test++){

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){
                        l3[0] = l1[0] - l2[0];
                        l3[1] = l1[1] - l2[1];
                        l3[2] = l1[2] - l2[2];
                        l3[3] = l1[3] - l2[3];
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };        
        avgDurTime /= TESTS;
        printf("Sredni czas odejmowania dwoch int to: %lf\n",avgDurTime); 
        printf("wyniki: %d %d %d %d\n", l3[0],l3[1],l3[2],l3[3]);

	/////MULTIPLICATION/////
	avgDurTime = 0;
	for (int l = 0; l < 4; l++){
		//Operacja zmniejszenia liczb, zeby wynik mnozenia nie przekraczal zakresu int
		l1[l] /= 1000;
		l2[l] /= 1000;
	};
	for (int test = 0; test < TESTS; test++){

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){
                        l3[0] = l1[0] * l2[0];
                        l3[1] = l1[1] * l2[1];
                        l3[2] = l1[2] * l2[2];
                        l3[3] = l1[3] * l2[3];
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };        
        avgDurTime /= TESTS;
        printf("Sredni czas mnozenia dwoch int to: %lf\n",avgDurTime); 
        printf("wyniki: %d %d %d %d\n", l3[0],l3[1],l3[2],l3[3]);
	
	/////DIVISION/////
	avgDurTime = 0;
        l1[0] = 123674569;
        l1[1] = 67546354;
        l1[2] = 3663436;
        l1[3] = 35664475;
        for (int test = 0; test < TESTS; test++){

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){
                        l3[0] = l1[0] / l2[0];
                        l3[1] = l1[1] / l2[1];
                        l3[2] = l1[2] / l2[2];
                        l3[3] = l1[3] / l2[3];
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };        
        avgDurTime /= TESTS;
        printf("Sredni czas dzielenia dwoch int to: %lf\n",avgDurTime); 
        printf("wyniki: %d %d %d %d\n", l3[0],l3[1],l3[2],l3[3]);

        return 0;
}
