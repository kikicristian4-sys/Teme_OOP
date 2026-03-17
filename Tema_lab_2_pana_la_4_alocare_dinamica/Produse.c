#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produse.h"

/*
	Functie ce creeaza un produs
	pre: id-int, cantitate-int, model-char, producator-char, tip-char
	post: returneaza adresa catre un struct de tip produs ce pointeaza
*/
produs creaza_produs(int id, int cantitate,float pret, const char* model, const char* producator, const char* tip)
{
		produs rezolvare;
	rezolvare.cantitate = cantitate;
	rezolvare.id = id;
	rezolvare.pret = pret;

	rsize_t dimensiune = strlen(producator) + 1;
	rezolvare.producator = malloc(dimensiune * sizeof(char));
	strcpy_s(rezolvare.producator, dimensiune, producator);
	

	dimensiune = strlen(model) + 1;
	rezolvare.model = malloc(dimensiune * sizeof(char));
	strcpy_s(rezolvare.model, dimensiune, model);
	

	dimensiune = strlen(tip) + 1;
	rezolvare.tip  = malloc(dimensiune * sizeof(char));
	strcpy_s(rezolvare.tip, dimensiune, tip);
	
	return rezolvare;
}


/*
	Dealocam memoria din structura produs;
	pre: adresa structurii 
	post: id = -1 si cantitate = -1 pentru a nu putea fi incurcat cu un produs inca valabil si toata zona de memorie alocata pe HEAP este eliberata
*/
void distruge_produs(produs* p)
{
	free(p -> model);
	free(p -> producator);
	free(p -> tip);

	p -> model = NULL;
	p -> producator = NULL;
	p -> tip = NULL;	

	p -> id = -1;
	p -> cantitate = -1;

}


/*
	Functie ce returneaza id ul unui produs
	pre: un produs 
	post: id-ul sau
*/
int id_produs(produs* p)
{
	return p -> id;
}

/*
	Functie ce returneaza cantitatea unui produs
	pre: un produs
	post: cantitatea produsului
*/
int cantitate_produs(produs* p)
{
	return p -> cantitate;
}

/*
	Functie ce returneaza pretul unui produs
	pre: un produs
	post: pretul produsului
*/
float pret_produs(produs* p)
{
	return p -> pret;
}

/*
	Functie ce returneaza tip-ul unui produs
	pre: un produs
	post: adresa tipului din memorie
*/

char* tip_produs(produs* p)
{
	return p -> tip;
}

/*
*	Functie ce returneaza producatorul unui produs
  pre: un produs
  post: adresa producatorului din memorie
*/
char* producator_produs(produs* p)
{
	return p -> producator;
}

/*
	Functie ce returneaza modelul unui produs
	pre: un produs
	post: adresa modelului din memorie
*/
char* model_produs(produs* p)
{
	return p -> model;
}


/*
	Functie ce aduna cantitatea transmisa prin argument la produs
	pre: adresa unui tip struct produs, o cantitate sub forma de int
	post: cantitatea produsului creste cu numarul dat
*/
void plus_la_cantitate(produs* p, int cantitate)
{
	p -> cantitate += cantitate;
}


/*
	Functie ce schimba cantitatea produsului transmis ca argument cu cantitatea transmisa
	pre: adresa unui tip struct produs, o cantitate sub forma de int
	post: cantitatea produsului se schimba cu numarul dat
*/
void updatare_cantitate(produs* p, int cantitate)
{
	p -> cantitate = cantitate;
}


/*
	Functie ce schimba pretul produsului transmis ca argument cu pretul transmis
	pre: adresa unui tip struct produs, un pret sub forma de float
	post: pretul produsului se schimba cu numarul dat
*/
void updatare_pret(produs* p, float pret)
{
	p -> pret = pret;
}





