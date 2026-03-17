#include <stdio.h>


#pragma once
/*
	Struct-ul produsului
*/
typedef struct
{
	int id;
	char tip[21];
	char producator[21];
	char model[21];
	float pret;
	int cantitate;
}produs;

/*
	Functie ce creeaza un produs
	pre: id-int, cantitate-int, model-char, producator-char, tip-char
	post: returneaza adresa catre un struct de tip produs ce pointeaza
*/
produs creaza_produs(int id, int cantitate, float pret, const char* model, const char* producator, const char* tip);

/*
	Dealocam memoria din structura produs;
	pre: adresa structurii
	post: id = -1 pentru a nu putea fi incurcat cu un produs inca valabil
*/
void distruge_produs(produs* p);

/*
	Functie ce returneaza id ul unui produs
	pre: un produs
	post: id-ul sau
*/
int id_produs(produs* p);

/*
	Functie ce returneaza cantitatea unui produs
	pre: un produs
	post: cantitatea produsului
*/
int cantitate_produs(produs* p);

/*
	Functie ce returneaza pretul unui produs
	pre: un produs
	post: pretul produsului
*/
float pret_produs(produs* p);

/*
	Functie ce returneaza tip-ul unui produs
	pre: un produs
	post: adresa tipului din memorie
*/

char* tip_produs(produs* p);

/*
*	Functie ce returneaza producatorul unui produs
  pre: un produs
  post: adresa producatorului din memorie
*/
char* producator_produs(produs* p);

/*
	Functie ce returneaza modelul unui produs
	pre: un produs
	post: adresa modelului din memorie
*/
char* model_produs(produs* p);

/*
	Functie ce aduna cantitatea transmisa prin argument la produs
	pre: adresa unui tip struct produs, o cantitate sub forma de int
	post: cantitatea produsului creste cu numarul dat
*/
void plus_la_cantitate(produs* p, int cantitate);

/*
	Functie ce schimba cantitatea produsului transmis ca argument cu cantitatea transmisa
	pre: adresa unui tip struct produs, o cantitate sub forma de int
	post: cantitatea produsului se schimba cu numarul dat
*/
void updatare_cantitate(produs* p, int cantitate);


/*
	Functie ce schimba pretul produsului transmis ca argument cu pretul transmis
	pre: adresa unui tip struct produs, un pret sub forma de float
	post: pretul produsului se schimba cu numarul dat
*/
void updatare_pret(produs* p, float pret);

 

