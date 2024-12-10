#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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

	for (int test = 0; test < TESTS; test++){

		begin = clock();
		for (int i = 0 ; i < LOOP_REP; i++){

			__asm__ (

			"movdqu (%0), %%xmm0 \n"	//movdqu - Wstaw do xmm niewyrównane podwójne słowa (32b)*4
			"movdqu (%1), %%xmm1 \n"	//jako src dajemy wkaźnik na początek tablicy, w której są 4 int.
			"paddd %%xmm1, %%xmm0 \n"	//Dodaj po 4 int parami z rejestru xmm0 i xmm1
			"movdqu %%xmm0, (%2)"		//Wynik wpisz pod adres wskazujący na początek tablicy z wynikami.
			:
			:"r"(ad1), "r"(ad2), "r"(ad3)
			: "xmm0", "xmm1", "memory"
			);
		};
		end = clock();

		durTime = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
		avgDurTime += durTime;
	};
	avgDurTime /= TESTS;
	printf("Sredni czas dodawania dwoch int to: %lf\n",avgDurTime); 
	printf("wyniki: %d %d %d %d\n",l3[0],l3[1],l3[2],l3[3]); //Do sprawdzenia wyników
	
 	/////SUBTRACTION///////
        avgDurTime = 0;
        for (int test = 0; test < TESTS; test++){

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){

                         __asm__ (

                        "movdqu (%0), %%xmm0 \n"
                        "movdqu (%1), %%xmm1 \n"
                        "psubd %%xmm1, %%xmm0 \n"	//Odejmij po 4 int parami. Od xmm0 odejmujemy xmm1
                        "movdqu %%xmm0, (%2)"
                        : 
                        :"r"(ad1), "r"(ad2), "r"(ad3)
                        : "xmm0", "xmm1", "memory"
                        );

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

                         __asm__ (

                        "movdqu (%0), %%xmm0 \n"
                        "movdqu (%1), %%xmm1 \n"
                        "pmulld %%xmm1, %%xmm0 \n"	//Wymnóż po 4 int parami.
                        "movdqu %%xmm0, (%2)"
                        : 
                        :"r"(ad1), "r"(ad2), "r"(ad3)
                        : "xmm0", "xmm1", "memory"
                        );

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
	//Powrót do większych liczb, l2 dalej zostają zmniejszone
	l1[0] = 123674569;
	l1[1] = 67546354;
	l1[2] = 3663436;
	l1[3] = 35664475;
        for (int test = 0; test < TESTS; test++){

                begin = clock();
                for (int i = 0 ; i < LOOP_REP; i++){
                        __asm__ (
			//Dla int nie ma op dzielenia, dlatego musimy zamienić na float i wtedy wykonać dzielenie
       			"movdqu (%0), %%xmm0 \n"
       			"movdqu (%1), %%xmm1 \n"
        		"cvtdq2ps %%xmm0, %%xmm0 \n" // Konwersja liczb całkowitych w xmm0 na zmiennoprzecinkowe
			"cvtdq2ps %%xmm1, %%xmm1 \n"
			//"movups %%xmm0, (%2)\n"	//wstawianie dla float
			"divps %%xmm1, %%xmm0 \n"	//dzielenie float 
        		"cvttps2dq %%xmm0, %%xmm0 \n" // Konwersja zmiennoprzecinkowych na liczby całkowite (z obcięciem). Round down
			"movdqu %%xmm0, (%2)"
        		:
        		: "r" (ad1), "r" (ad2), "r" (ad3)
        		: "xmm0", "xmm1", "memory"
    			);
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
