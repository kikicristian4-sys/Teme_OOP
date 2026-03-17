/*
Header al service-ului.
*/
#include "Produse.h"
#include "lista_produse.h"


/*
	Functie de adaugare a unui produs.
	Parametrii: id - id-ul produsului trebuie sa fie un numar natural, tip - tipul produsului, producator - producatorul produsului,
	model - modelul produsului, pret - pretul produsului (pret > 0),
	cantitate - cantitatea produsului.
	Returneaza: 0 daca produsul a fost adaugat cu succes, 1 daca id-ul produsului se repeta.
*/
int adaugare_produs(vector_elemente* vector, int id, char tip[], char producator[], char model[], float pret, int cantitate);

/*
	Functie ce permite modificarea pretului unui produs dat prin id.
	preconditii: id-ul trebuie sa fie un numar natural, pretul trebuie sa fie un numar real pozitiv.
	returneaza: 0 daca pretul a fost modificat cu succes, 1 daca id-ul nu exista in lista de produse.
*/
int modificare_pret(vector_elemente* vector, int id, float pret);

/*
	Functie ce permite modificarea cantitatii unui produs dat prin id.
	preconditii: id-ul trebuie sa fie un numar natural, cantitatea trebuie sa fie un numar natural.
	returneaza: 0 daca cantitatea a fost modificat cu succes, 1 daca id-ul nu exista in lista de produse.
*/
int modificare_cantitate(vector_elemente* vector, int id, int cantitate);


/*
	Functie din Service ce sterge un produs dat prin id.
	pre: o adresa catre un struct de tipul vector_elemente unde este vectorul de elemente, un id de tip int
	post: functia returneaza 1 daca id-ul nu exista in baza de date, 0 altfel
*/
int stergere_produs(vector_elemente* vector, int id);

/*
	Functie ce permite vizualizarea produselor din stoc intr-un mod ordonat dupa pret si cantitate.
	preconditii: un pointer catre un struct de tip vectro_elemente unde sunt valorile,un pointer catre un struct de tip vector_elemente unde vor fi puse rezultatele
	returneaza: un pointer prin parametru catre struct de tip produs ce contine toate produsele din stoc, ordonate dupa pret si cantitate.

*/
int vizualizare_produse_stoc_ordonate(vector_elemente* vector, vector_elemente* copie_v);


/*
	Functie ce returneaza produsele filtrate dupa pret.
	preconditii: un pointer catre un struct de tip vector_elemente unde sunt elemente, un pointer catre un struct de tip vector_elemente unde vor fi puse rezultatele,pretul trebuie sa fie un numar real pozitiv.
	returneaza: un pointer prin parametru catre struct de tip vector_elemente ce contine toate produsele din
	stoc cu pretul mai mic sau egal decat un pret dat
*/
int filtrare_produse_pret(vector_elemente* vector, vector_elemente* copie_v, float pret);

/*
	Functie ce returneaza produsele filtrate dupa producator.
	preconditii: un pointer catre un struct de tip vector_elemente unde sunt elemente,un pointer catre un struct de tip un pointer catre un struct de tip vector_elemente unde vor fi puse rezultatele
	returneaza: un pointer prin parametru catre struct de tip vector_elemente ce contine toate produsele din
	stoc cu producatorul egal cu cel dat
*/
int filtrare_produse_producator(vector_elemente* vector, vector_elemente* copie_v, char producator[]);

/*
Functie ce returneaza produsele filtrate care au cantitatea strict mai mare decat un numar dat.
preconditii: un pointer catre un struct de tip vector_elemente unde sunt elemente,un pointer catre un struct de tip vector_elemente unde vor fi puse rezultatele, un int > 0
returneaza: un pointer prin parametru catre struct de tip vector_elemente ce contine toate produsele din
stoc cu cantitatea egala sau mai mare decat cea data
*/
int filtrare_produse_cantitate(vector_elemente* vector, vector_elemente* copie_v, int cantitate);
