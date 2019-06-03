/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adsIlgas_h.h"

int main(int argc, char *argv[])
{
    ilgasSveikas * skaicius1 = NULL;
    ilgasSveikas * skaicius2 = NULL;
    ilgasSveikas * skaicius3 = NULL;
    ilgasSveikas * skaicius4 = NULL;

    char *skaicius;
    int inicijuotas = 0;

    // ciklas
    for (int i = 0; i < 20000000; i++) {
 	inicijuoti(&skaicius1, "121245645");
	salinimasSkaiciaus(&skaicius1);
    }

    do {
       	printf("Iveskite 1-aji skaciu:");
       	ivedimas(&skaicius);

	inicijuotas = inicijuoti(&skaicius1, skaicius);

	if (inicijuotas == 0)
	    printf("Ivyko klaida. Neteisingas skaicius.\n");
    } while (inicijuotas == 0);
    inicijuotas = 0;
    do {
       	printf("Iveskite 2-aji skaciu:");
        ivedimas(&skaicius);
	
   	inicijuotas = inicijuoti(&skaicius2, skaicius);

	if (inicijuotas == 0)
	    printf("Ivyko klaida. Neteisingas skaicius.\n");
    } while (inicijuotas == 0);

    // Tikrina dalyba
    printf("\nDalyba:");

    if (dalyba(skaicius1, skaicius2, &skaicius3, &skaicius4) == 1) {
        printf("\nDalybos rezultatas:");
        spausdintiSkaiciu(skaicius3);
        printf("Dalybos liekana:");
        spausdintiSkaiciu(skaicius4); 
    } else {
    	printf("Dalyba is nulio negalima.");
    }

    // Tikrina sandauga
    printf("\nSandauga:");

    if (sandauga(skaicius1, skaicius2, &skaicius3) == 1) {
        printf("\nSandaugos rezultatas:");
        spausdintiSkaiciu(skaicius3);  
    }

    // Tikrina sudeti
    printf("\nSudetis:");

    if (sudetis(skaicius1, skaicius2, &skaicius3) == 1) {
	    printf("\nSudeties rezultatas:");
        spausdintiSkaiciu(skaicius3);
    }

    // Tikrina atimti
    printf("\nAtimtis:");

    if (atimti(skaicius1, skaicius2, &skaicius3) == 1) {
        printf("\nAtimties rezultatas:");
        spausdintiSkaiciu(skaicius3);
    }

    // Palygina skaicius
    printf("Palyginimas:\n");

    if (arLygus(skaicius1, skaicius2) == 1) {
        printf("Skaiciai lygus.\n");
    }
    
    if (arMaziau(skaicius1, skaicius2) == 1) {
        printf("Pirmas skaicius mazesnis.\n");
    }
    
    if (arDaugiau(skaicius1, skaicius2) == 1) {
        printf("Pirmas skaicius didesnis.\n");
    }

    return 0;
}
*/