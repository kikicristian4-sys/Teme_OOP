#pragma once
#include <stdio.h>
#include "Produse.h"

typedef produs element;

typedef struct
{
	element elemente[101];
	int lungime;
} vector_elemente;


/*
	Functie ce primeste pozitia din vector a unui produs si returneaza adresa struct-ului produs
	pre: un vector_elemente v, o pozitie de tip int
	post: adresa produsului de pe pozitia ceruta
*/
element returneaza_element(vector_elemente* v, int pozitie);

/*
	Functie ce copiaza un vector struct de tipul vector elemente din al doilea argument in primul
	pre: o adresa catre un struct de tip vector_elemente unde se doreste copierea vectorului, o adresa catre un struct de tip vector_elemente de unde se copiaza
	post:primul vector transmis ca argument va deveni o copie fidela al celui de-al doilea vector
*/
void copiere_vector(vector_elemente* copie_v, vector_elemente* vector);

/*
Se creeaza o lista goala
pre:
post: returneaza adresa unei lista goale de tip vector_elemente
*/
vector_elemente creaza_vector_gol();

/*
Se distruge o lista de tip vector_elemente data
pre:o lista vector_elemente
post: lungimea acesteia devine 0 (nu este alocat nimic pe HEAP)
*/

int distruge_vector(vector_elemente* v);


/*
	Functie ce returneaza lungimea vectorului de produse de pana acum
	pre: un vector_elemente v
	post: returneaza lungimea vectorului de elemente specificat
*/
int lungime_vector(vector_elemente* v);


/*
	Functie ce adauga un produs in vector-ul de produse
	pre: un vector_elemente v, un produs p
	post: produsul p este adaugat in vectorul de elemente
*/
void adaugare_element(vector_elemente* v, element el);

/*
	Functie ce verifica exista unui id in lista de produse.
	pre: un vector_elemente vector, un id sub forma de int
	post: returneaza 1 daca a fost gasit, 0 in caz contrar
*/
int existenta_id(vector_elemente* vector, int id);

/*
	Functie ce verifica daca un produs este exact la fel din toate punctele de vedere ca altul
	pre: un vector de tip vector_elemente, un produs de tip produs
	post: 0 daca nu exista alt produs exact la fel, 1 altfel
*/
int exact_acelasi(vector_elemente* vector, element* produs);

/*
	Functie ce adauga la cantitatea unui produs
	pre: un vector de tip vector_elemente, un produs de tip produs
	post: cantitatea din produsul p va fi adaugat la produsul cu acelasi id din lista
*/
void adaugare_cantitate(vector_elemente* vector, produs* p);

/*
	Functie din lista_produse  ce schimba pretul produsului transmis ca argument cu pretul transmis
	pre: adresa unui tip struct produs, un pret sub forma de float
	post: pretul produsului se schimba cu numarul dat
*/
void schimba_pret(vector_elemente* vector, int id, float pret);

/*
	Functie din lista_produse ce schimba cantitatea produsului transmis ca argument cu cantitatea transmisa
	pre: adresa unui tip struct produs, o cantitate sub forma de int
	post: cantitatea produsului se schimba cu numarul dat
*/
void schimba_cantitatea(vector_elemente* vector, int id, int cantitate);

/*
	Functie din lista_produse ce sterge un element din lista
	pre: adresa unui vector de tip vector_element, un id te tip ind
	post: produsul cu id-ul transmis o sa fie sters din lista
*/
void stergere_element(vector_elemente* vector, int id);