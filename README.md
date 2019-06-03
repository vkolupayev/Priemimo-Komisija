Salyga:

Priėmimo komisija (ADT: dekas, ilgas sveikas skaičius). Procesas: priėmimo komisijoje dirba 2
darbuotojos, kurių produktyvumas skirtingas, jos priima stojančiųjų prašymus ir stato į lentyną,
kiekviena iš savo pusės, kai nėra stojančiųjų ir pasibaigus tos dienos priėmimui, jos ima stojančiųjų
prašymus ir juos sutvarko. Tikslas: patyrinėti, kiek laiko reikia skirti prašymų tvarkymui, pasibaigus jų
priėmimui. Pradiniai duomenys: darbuotojų produktyvumas (abi darbuotojos prašymo priėmimui
sugaišta vienodai laiko, bet prašymo sutvarkymui skirtingai laiko), stojančiojo atėjimo tikimybė
(galima realizacija: generuojamas atsitiktinis skaičius ir tikrinama, ar jis tenkina tam tikrą sąlygą),
dokumentų priėmimo laikas. Rezultatai: papildomas darbo laikas, kuris turi būti skiriamas prašymų
tvarkymui, darbuotojų užimtumas (procentais), nes galima situacija, kad pagal pateiktus pradinius
duomenis stojančiųjų intensyvumas toks nedidelis, kad dalį laiko darbuotojos poilsiauja.

Programą paleisti reikia naudoti makefile, jo pavyzdys:
	all: head.o deka.o
		gcc deka.o head.o -o dekas
	head.o: head.c
		gcc -c head.c -o head.o
	deka.o: deka.c 
		gcc -c deka.c -o deka.o
	clean: 
		rm *.o 
