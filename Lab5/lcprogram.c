#include <stdio.h>
#include <time.h>
#define TESTS 100
#define LOOP_REP 2500000
int main(){

        int l1 = 123674569;
        int l2 = 14664674;
        int l3 = 0;
        clock_t begin, end;
        double durTime, avgDurTime = 0;
        /////ADDITION////
        for (int test = 0; test < TESTS; test++){

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){
                        
			for (int j = 0; j < 4; j++){
				l3 = l1 + l2;
			};
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= TESTS;
        printf("Sredni czas dodawania dwoch int to: %lf\n",avgDurTime); 
        printf("wyniki: %d \n", l3);
	
	/////SUBTRACTION/////
	avgDurTime = 0;
        for (int test = 0; test < TESTS; test++){

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                        for (int j = 0; j < 4; j++){
                                l3 = l1 - l2;
                        };
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= TESTS;
        printf("Sredni czas odejmowania dwoch int to: %lf\n",avgDurTime); 
        printf("wyniki: %d \n", l3);

	/////MULTIPLICATION/////
	avgDurTime = 0;
	l1 /= 1000;
	l2 /= 1000; //Zmniejszenie liczb, aby wynik nie przekroczył zakresu int
        for (int test = 0; test < TESTS; test++){

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                        for (int j = 0; j < 4; j++){
                                l3 = l1 * l2;
                        };
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= TESTS;
        printf("Sredni czas mnozenia dwoch int to: %lf\n",avgDurTime); 
        printf("wyniki: %d \n", l3);

	/////DIVISION/////
	avgDurTime = 0;
	l1 = 123674569; //Przywracamy większą wartość pierwszej liczby. Druga dalej zmniejszona
        for (int test = 0; test < TESTS; test++){

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                        for (int j = 0; j < 4; j++){
                                l3 = l1 / l2;
                        };
                };
                end = clock();

                durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
                avgDurTime += durTime;
        };
        avgDurTime /= TESTS;
        printf("Sredni czas dzielenia dwoch int to: %lf\n",avgDurTime); 
        printf("wyniki: %d \n", l3);

	return 0;
}

