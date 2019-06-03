//Austeja Putnaite

/*#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
	elementas pradzia, pabaiga;
	Type sim;
	char symbol;
	int ar;
	int v = 0;
	printf ("1 - sukurti deka. \n");
	printf ("2 - ar dekas tuscias? \n");
	printf ("3 - ar dekas pilnas? \n");
	printf ("4 - elemento salinimas is galo. \n");
	printf ("5 - elemento pridejimas is galo. \n");
	printf ("6 - elemento salinimas is priekio. \n");
	printf ("7 - elemento pridejimas is priekio. \n");
	printf ("8 - isvedamas deko elementu kiekis. \n");
	printf ("9 - deko isspausdinimas. \n");
	printf ("10 - istrinti deko elementus. \n");
	printf ("11 - pakartoti pasirinkimus. \n");	
	printf ("12 - baigti darba. \n");
	while (v != 12)
	{
		printf ("Pasirinkite norima komanda: ");		
		scanf ("%d", &v);
		switch(v)
		{	
				case 1: 
					deko_sukurimas(&pradzia, &pabaiga);
					printf ("Dekas sukurtas. \n");
					break;
				case 2:
					ar = ar_dekas_tuscias (pradzia);
					if (ar == 1)
						printf ("Dekas tuscias. \n");
					else
						printf ("Dekas netuscias. \n");					
					break;
				case 3:
					ar = ar_dekas_pilnas ();
					if (ar == 1)
						printf ("Dekas pilnas. \n");
					else
						printf ("Dekas nepilnas. \n");					
					break;
				case 4:	
					ar = salinti_is_galo (&pradzia, &pabaiga);
					if (ar == 1)
						printf ("Elemento pasalinti negalima, nes dekas tuscias. \n");
					break;
				case 5: 
					printf ("Iveskite skaiciu, kuri norite ideti: \n");
					scanf("%d", &sim);
					ar = prideti_is_galo (&pradzia, &pabaiga, sim);
					if (ar == 1)
						printf ("pasalnti negalima, nes dekas pilnas. \n");
					break;
				case 6:
					ar = salinti_is_priekio (&pradzia, &pabaiga);
					if (ar == 1)
						printf ("Elemento pasalinti negalima, nes dekas tuscias. \n");
					break;
				case 7: 
					printf ("Iveskite skaiciu, kuri norite ideti: \n");
					scanf("%d", &sim);
					ar = prideti_is_priekio (&pradzia, &pabaiga, sim);
					if (ar == 1)
						printf ("pasalnti negalima, nes dekas pilnas. \n");
					break;
				case 8:
					sim = elementu_kiekis (pradzia);
					printf ("Elementu kiekis sarase: %d \n", sim);
					
					break;
				case 9: 
					printf ("Spausdinamas gautasis sarasas:\n");					
					spausdinimas (pradzia);
					printf ("\n");
					break;	
				case 10:	
					deko_salinimas (&pradzia, &pabaiga);
					break;	
				case 11:	
					printf ("1 - sukurti deka. \n");
					printf ("2 - ar dekas tuscias? \n");
					printf ("3 - ar dekas pilnas? \n");
					printf ("4 - elemento salinimas is galo. \n");
					printf ("5 - elemento pridejimas is galo. \n");
					printf ("6 - elemento salinimas is priekio. \n");
					printf ("7 - elemento pridejimas is priekio. \n");
					printf ("8 - isvedamas deko elementu kiekis. \n");
					printf ("9 - deko isspausdinimas. \n");
					printf ("10 - istrinti deko elementus. \n");
					printf ("11 - pakartoti pasirinkimus. \n");	
	printf ("12 - baigti darba. \n");
					break;
				
				case 12:
					printf ("Programa baige darba. \n");
					break;
				default:
					printf("Neteisingas proceduros numeris. \n");
					break;
		}
	}
	return 0;
}

*/