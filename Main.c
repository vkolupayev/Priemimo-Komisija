#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "adsIlgas_h.h"
#include "head.h"

#define EAT_WHITE_SPACE \
while ((c=getc(fp))=='\n'||c==' '|| \
c=='\t'||c=='\r'||c=='\v'||c=='\f') ;

/*char * getSveikasSkaiciusEilute (ilgasSveikas *pradzia)
{
	char** new_array;
	new_array =malloc(sizeof(char*)*60);//ignore casting malloc
	int index = 0;
	
	while(pradzia != NULL)
	{
		*(new_array + index) = pradzia->duom;
		printf("%c", pradzia->duom);
		pradzia = pradzia->priekin;
	}

	return new_array;
	
}*/

void skip_cmt(int z, FILE *fp)
{
int c;
EAT_WHITE_SPACE
if (c==z) {
do {
while ((c=getc(fp))!='\n') ;
EAT_WHITE_SPACE
} while (c==z);
(void)ungetc(c,fp);
}
else
(void)ungetc(c,fp);
}

void priskirti(ilgasSveikas **pradinis, ilgasSveikas *priskiriama) {

    ilgasSveikas *nulis = NULL;
    inicijuoti(&nulis, "0");
    sudetis(nulis, priskiriama, pradinis);
	salinimasSkaiciaus(&nulis);
}

int main()
{

	FILE *file1 = fopen("data.txt", "r");

	int produktyvumasInp1, produktyvumasInp2 , priemimoLaikasInp, stojantys, kuriDarb, testDeck, testIlgas, tikimybe, ran, ar_ateina_zmogus;

	
	//pradiniu duomenu ivedimas	


		skip_cmt('#',file1);
		fscanf(file1, "%d", &produktyvumasInp1);
		skip_cmt('#',file1);
		skip_cmt('#',file1);
		fscanf(file1, "%d", &produktyvumasInp2);
		skip_cmt('#',file1);
		fscanf(file1, "%d", &priemimoLaikasInp);
		skip_cmt('#',file1);
		fscanf(file1, "%d", &stojantys);
		skip_cmt('#',file1);
		fscanf(file1, "%d", &tikimybe);
		skip_cmt('#',file1);
		fscanf(file1, "%d", &ar_ateina_zmogus);
		skip_cmt('#',file1);
		if((produktyvumasInp1 <= priemimoLaikasInp)||
		(produktyvumasInp2 <= priemimoLaikasInp)|| tikimybe>100 || ar_ateina_zmogus>100)
			printf("duomenys ivesti neteisingai, taisykite faila\n");
		

		//printf("Duomenys ivesti teisingai\n");
		//else printf("Klaida ivedant duomenis\n");

	printf("%d %d %d %d %d %d \n", produktyvumasInp1, produktyvumasInp2, priemimoLaikasInp, stojantys, tikimybe, ar_ateina_zmogus);

	//is pradiniu duomenu gaunamas tvarkymas, data reikalinga ilgamSveikam konvertuojama i char* ir tada inicijuojami ilgiSveiki Skaiciai

	int tvarkymasInp1 = produktyvumasInp1 - priemimoLaikasInp; 
	int tvarkymasInp2 = produktyvumasInp2 - priemimoLaikasInp; 

	char * tvarkymasCh1 = malloc(sizeof(char)*5);
	char * tvarkymasCh2 = malloc(sizeof(char)*5);
	char * priemimoLaikasCh = malloc(sizeof(char)*5);

	sprintf(tvarkymasCh1, "%d", tvarkymasInp1);
	sprintf(tvarkymasCh2, "%d", tvarkymasInp2);
	sprintf(priemimoLaikasCh, "%d", priemimoLaikasInp);

	ilgasSveikas * tvarkymas1 = NULL;
	ilgasSveikas * tvarkymas2 = NULL;
	ilgasSveikas * priemimas = NULL;

	inicijuoti(&tvarkymas1, tvarkymasCh1);
	inicijuoti(&tvarkymas2, tvarkymasCh2);
	inicijuoti(&priemimas, priemimoLaikasCh);

	free(tvarkymasCh1);
	free(tvarkymasCh2);
	free(priemimoLaikasCh);
	
	spausdintiSkaiciu(tvarkymas1);
	spausdintiSkaiciu(tvarkymas2);
	spausdintiSkaiciu(priemimas);


	// ADT sukurimas

	elementas pradzia, pabaiga;

	deko_sukurimas (&pradzia, &pabaiga);
    ilgasSveikas * pirmosDarbPriemLaik = NULL;
	ilgasSveikas * antrosDarbPriemLaik = NULL;
	ilgasSveikas * darbTvarkLaik = NULL;
	ilgasSveikas * standartinisDarboDienLaik = NULL;

	inicijuoti(&pirmosDarbPriemLaik, "0");
	inicijuoti(&antrosDarbPriemLaik, "0");
	inicijuoti(&darbTvarkLaik, "0"); 
	inicijuoti(&standartinisDarboDienLaik, "480");

	srand(time(NULL));


	//dokumentu priemimas ir darbuotoju dokumentu priemimo laikas
	//dokumentus priimti gali tik darbo laiku 9-17, visi kiti atlieka
	//jei dokumentus priima iki pat darbo laiko pabaigos, jos vis tiek tures sutvarkyti

	ilgasSveikas * temp = NULL;	

	for(int i=0;i<stojantys;i++)
	{
		if(arMaziau(pirmosDarbPriemLaik, standartinisDarboDienLaik)==1 && arMaziau(antrosDarbPriemLaik, standartinisDarboDienLaik)==1)
		{
			ran = rand()%100;

			if(ar_ateina_zmogus>ran){
		
				//kuriDarb=rand() % 2;
				//ran = ran%100;
				if(tikimybe<ran)
					kuriDarb = 0;
					else kuriDarb = 1;

				if(kuriDarb==0)	
				{
					//decko nauduojimas, i lentyna dedamas dokumentas
					//duomenys dedami i decka - kuri darbuotoja
					testDeck = prideti_is_priekio (&pradzia, &pabaiga, 1);
					if (testDeck == 1)
						printf ("prideti negalima, nes dekas pilnas. \n");
			
					//ilgoSveiko nauduojimas, pridedamas laikas
					testIlgas = sudetis(pirmosDarbPriemLaik, priemimas, &temp);
					if(testIlgas = 0)
						printf("ivyko klaida sudedant ilgus Sveikus skaicius. \n");
					priskirti(&pirmosDarbPriemLaik, temp);

					//printf("pirmos darbuotojos priemimo laikas\n");
					//spausdintiSkaiciu(pirmosDarbPriemLaik);

				}
				else if(kuriDarb==1)
				{

					//decko nauduojimas, i lentyna dedamas dokumentas
					//duomenys dedami i decka - kuri darbuotoja
					testDeck = prideti_is_galo (&pradzia, &pabaiga, 2);
					if (testDeck == 1)
						printf ("prideti negalima, nes dekas pilnas. \n");
		
					//ilgoSveiko nauduojimas, pridedamas laikas
					testIlgas = sudetis(antrosDarbPriemLaik, priemimas, &temp);
					if(testIlgas = 0)
						printf("ivyko klaida sudedant ilgus Sveikus skaicius. \n");
					priskirti(&antrosDarbPriemLaik, temp);
	
					//printf("antros darbuotojos priemimo laikas\n");
					//spausdintiSkaiciu(antrosDarbPriemLaik);

				}
		}		
		}
		else break;
		}
	

	salinimasSkaiciaus(&temp);

	/*char * eilute = getSveikasSkaiciusEilute(pirmosDarbPriemLaik);
	printf("\n%s\n", eilute);
	ilgasSveikas * aaaa = NULL;
	inicijuoti(&aaaa, eilute);
	spausdintiSkaiciu(aaaa);*/

	//Lentynos isspausdinimas
	printf ("Spausdinamas gautasis sarasas:\n");					
	spausdinimas (pradzia);
	printf ("\n");
	printf("%d", elementu_kiekis (pradzia));


	ilgasSveikas * vienetas = NULL;
	inicijuoti(&vienetas, "1");
	ilgasSveikas * nulis = NULL;
	inicijuoti(&nulis, "0");

	ilgasSveikas * dalyba1 = NULL;
	ilgasSveikas * liekana1 = NULL;
	ilgasSveikas * dalyba2 = NULL;
	ilgasSveikas * liekana2 = NULL;	
	
	ilgasSveikas * laikas = NULL;

	//dokumnetu tvarkymas nauduojantis timeriu, ilgu sveiku skaiciumi pridedant po viena
	//kol lentyna tuscia, sutvarko kai  timeris % tvarkymo laikas lygus 0

	while(ar_dekas_tuscias(pradzia) != 1)
	{
		//countdown		
		sudetis(darbTvarkLaik, vienetas, &laikas);
		priskirti(&darbTvarkLaik, laikas);

		//spausdintiSkaiciu(laikas);

		dalyba(darbTvarkLaik, tvarkymas1, &dalyba1, &liekana1);
		dalyba(darbTvarkLaik, tvarkymas2, &dalyba2, &liekana2);

		if(arLygus(nulis, liekana1))
		{
			salinti_is_priekio (&pradzia, &pabaiga);
			//printf("a");
		}

		if(arLygus(nulis, liekana2))
		{
			salinti_is_galo (&pradzia, &pabaiga);
			//printf("b");
		}

		//salinimasSkaiciaus(&dalyba1);
		//salinimasSkaiciaus(&liekana1);		
		//salinimasSkaiciaus(&dalyba2);
		//salinimasSkaiciaus(&liekana2);
		
	}

	salinimasSkaiciaus(&laikas);

	//Patikrinu ar algoritmas suveike, ar deckas tuscias?
	testDeck = ar_dekas_tuscias (pradzia);
		if (testDeck == 1)
			printf ("Dekas tuscias. \n");
			else
				printf ("Dekas netuscias.\n");


	printf("dokumentu tvarkymo laikas\n");
	spausdintiSkaiciu(darbTvarkLaik);


	//lyginu darbuotoju priemimo laikus, nes pradeda tvarkyti tik nuo paskutinio priimto laiko, kad gauti bendra laika
	ilgasSveikas * bendrasDarbLaik = NULL;
	
	if(arLygus(pirmosDarbPriemLaik, antrosDarbPriemLaik)==1 || arDaugiau(pirmosDarbPriemLaik, antrosDarbPriemLaik)==1)
	{
		sudetis(pirmosDarbPriemLaik, darbTvarkLaik, &bendrasDarbLaik);
	}
		else
		{
			sudetis(antrosDarbPriemLaik, darbTvarkLaik, &bendrasDarbLaik);
		}

	printf("visas darbo laikas\n");

	spausdintiSkaiciu(bendrasDarbLaik);

	//lyginu bendra darbuotuoju laika su 9-17 darbo dienos laiku, kad apskaiciuti darbuotoju uzimtuma

	ilgasSveikas * uzimtumas = NULL;
	ilgasSveikas * virsValandziai = NULL;

	if(arLygus(standartinisDarboDienLaik, bendrasDarbLaik)==1 || arDaugiau(bendrasDarbLaik, standartinisDarboDienLaik)==1)
	{
		inicijuoti(&uzimtumas, "100");
		atimti(bendrasDarbLaik, standartinisDarboDienLaik, &virsValandziai);

	}
		else
		{
			ilgasSveikas * simtas = NULL;
			inicijuoti(&simtas, "100");
			ilgasSveikas * taco = NULL;
			ilgasSveikas * kebab = NULL;

			sandauga(simtas, bendrasDarbLaik, &kebab);
			dalyba(kebab, standartinisDarboDienLaik, &uzimtumas, &taco);
			inicijuoti(&virsValandziai , "0");
			salinimasSkaiciaus(&simtas);
			salinimasSkaiciaus(&taco);
			salinimasSkaiciaus(&kebab);
		}

	//rezultatu spausdinimas
	printf("darbuotoju uzimtumas (procentais): \n");
	spausdintiSkaiciu(uzimtumas);
	printf("papildomas darbas:\n");
	spausdintiSkaiciu(virsValandziai);

	//atminties atlaisvinimas, trinimas...
	deko_salinimas(&pradzia, &pabaiga);
	salinimasSkaiciaus(&pirmosDarbPriemLaik);
	salinimasSkaiciaus(&antrosDarbPriemLaik);
	salinimasSkaiciaus(&darbTvarkLaik);
	salinimasSkaiciaus(&standartinisDarboDienLaik);
	salinimasSkaiciaus(&uzimtumas);
	salinimasSkaiciaus(&virsValandziai);
	salinimasSkaiciaus(&bendrasDarbLaik);
	salinimasSkaiciaus(&tvarkymas1);
	salinimasSkaiciaus(&tvarkymas2);
	salinimasSkaiciaus(&priemimas);
	fclose(file1);

	return 0;
}
