#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void deko_sukurimas (elementas *pradzia, elementas *pabaiga)
{	
	*pradzia = NULL;
	*pabaiga = NULL;
}
int ar_dekas_tuscias (elementas pradzia)
{
	if (pradzia != NULL)
		return 0;
	else
		return 1;
}
int ar_dekas_pilnas ()
{
	elementas elem = (elementas)malloc(sizeof(elementas));
	if (elem == NULL)
		return 1;
	else 
	{
		free(elem);
		return 0;
	}
}
int salinti_is_galo (elementas *pradzia, elementas *pabaiga)
{
		
	elementas elem, end;
	end = *pabaiga;
	if (*pradzia != end) // jei pradzia nelygi galui (tokiu atveju yra vienas elementas, arba dekas tuscias)
	{
		elem = end -> atgal;
		elem -> kitas = NULL;
		free (end);
		*pabaiga = elem;
		return 0;
	}
	else 
	{
		if (*pradzia == end && *pradzia != NULL) // jei pradzia lygi galui, bet dekas netuscias
		{
			free (end);
			*pradzia = NULL;
			*pabaiga = NULL;
			return 0;
		}
		else
			return 1;			
	}
}
int prideti_is_galo (elementas *pradzia, elementas *pabaiga, Type sim)
{
	elementas elem, end;
	elem = (elementas) malloc (sizeof(elementas));
	if (elem != NULL)
	{
		if (*pabaiga != NULL) // jei dekas netuscias
		{
			end = *pabaiga;
			end -> kitas = elem;
			elem -> data = sim;
			elem -> atgal = end;
			elem -> kitas = NULL;
			*pabaiga = elem;
		}
		else // jei dekas tuscias
		{
			elem -> data = sim;
			elem -> atgal = NULL;
			elem -> kitas = NULL;
			*pabaiga = elem;
			*pradzia = elem;
		}
		return 0;
	}
	else
		return 1;
}
int salinti_is_priekio (elementas *pradzia, elementas *pabaiga)
{	
	elementas elem, start;
	start = *pradzia;	
	if (*pradzia != *pabaiga)
	{
		elem = start -> kitas;
		elem -> atgal = NULL;
		free (start);
		*pradzia = elem;
		return 0;
	}
	else
	{	
		if (*pradzia == *pabaiga && *pradzia != NULL)
		{
			free (start);
			*pradzia = NULL;
			*pabaiga = NULL;
			return 0;
		}
		else
			return 1;
	}

}
int prideti_is_priekio (elementas *pradzia, elementas *pabaiga, Type sim)
{
	elementas elem, start;
	elem = (elementas) malloc (sizeof(elementas));
	if (elem != NULL)
	{
		if (*pabaiga != NULL)
		{
			start = *pradzia;
			elem -> data = sim; 
			elem -> atgal = NULL;	
			elem -> kitas = start;
			start -> atgal = elem;
			*pradzia = elem;
		}
		else
		{
			elem -> data = sim; 
			elem -> atgal = NULL;	
			elem -> kitas = NULL;
			*pabaiga = elem;
			*pradzia = elem;
		} 
		return 0;
	}	
	else
		return 1;
}
int elementu_kiekis (elementas pradzia)
{
	elementas elem;	
	int kiek = 0;	
	elem = pradzia;
 	while  (elem != NULL) 
	{
	 	kiek++;
	 	elem = elem -> kitas;
 	}
	return kiek;
}
void spausdinimas (elementas pradzia)
{
	elementas elem;
 	elem = pradzia;
 	while  (elem != NULL) 
	{
 		printf  ("%d ", elem -> data);
 		elem = elem -> kitas;
 	}
}
void deko_salinimas (elementas *pradzia, elementas *pabaiga)
{
	elementas elem, elemk;		
	elem = *pradzia;
 	while  (elem != NULL) 
	{
			elemk = elem -> kitas;
			free (elem);
			elem = elemk;
 	}
	*pradzia = NULL;
	*pabaiga = NULL;
}
