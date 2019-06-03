#ifndef HEAD_H
#define HEAD_H

	typedef int Type;
	typedef struct el *elementas;
	struct el{
		Type data;
		struct el *kitas;
		struct el *atgal;
	};

	void deko_sukurimas (elementas *pradzia, elementas *pabaiga);
	int ar_dekas_tuscias (elementas pradzia); 	// return 0; dekas netuscias, return 1; dekas tuscias
	int ar_dekas_pilnas (); 	// return 0; dekas nepilnas, return 1; dekas pilnas
	int salinti_is_galo (elementas *pradzia, elementas *pabaiga);	// return 0; viskas gerai, return 1; pasalnti negalima, nes dekas tuscias
	int prideti_is_galo (elementas *pradzia, elementas *pabaiga, Type sim);	// return 0; viskas gerai, return 1; prideti negalima, nes dekas pilnas
	int salinti_is_priekio (elementas *pradzia, elementas *pabaiga); 	// return 0; viskas gerai, return 1; pasalnti negalima, nes dekas tuscias	
	int prideti_is_priekio (elementas *pradzia, elementas *pabaiga, Type sim);	//return 0; viskas gerai, return 1; prideti negalima, nes dekas pilnas
	int elementu_kiekis (elementas pradzia);
	void spausdinimas (elementas pradzia);
	void deko_salinimas (elementas *pradzia, elementas *pabaiga);

#endif

