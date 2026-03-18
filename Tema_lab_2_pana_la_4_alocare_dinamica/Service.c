#include <stdio.h>
#include <string.h>
#include "Service.h"
#include "lista_produse.h"
#include "Produse.h"
#include "Validator.h"

/*
	Functie de adaugare a unui produs.
	Parametrii: id - id-ul produsului trebuie sa fie un numar natural, tip - tipul produsului, producator - producatorul produsului,
	model - modelul produsului, pret - pretul produsului (pret > 0),
	cantitate - cantitatea produsului.
	Returneaza: 0 daca produsul a fost adaugat cu succes, 1 daca id-ul produsului se repeta.
*/
int adaugare_produs(vector_elemente* vector,int id, const char* tip, const char* producator, const char*  model, float pret, int cantitate)
{
	
	if (validare_criterii_produs(id, pret, cantitate) != 0)
		return validare_criterii_produs(id, pret, cantitate);

	
	if (existenta_id(vector,id))
	{
		
		produs p = creaza_produs(id, cantitate, pret ,model, producator, tip);
		
		if (exact_acelasi(vector, &p) == 1)
		{
			
			adaugare_cantitate(vector, &p);
			
			distruge_produs(&p);
			
			return 1;
		}
		distruge_produs(&p);
		return 5;
		
	}
	produs p = creaza_produs(id, cantitate,pret, model, producator, tip);

	adaugare_element(vector, p);
	
	return 0;
}


/*
	Functie ce permite modificarea pretului unui produs dat prin id.
	preconditii: id-ul trebuie sa fie un numar natural, pretul trebuie sa fie un numar real pozitiv.
	returneaza: 0 daca pretul a fost modificat cu succes, 1 daca id-ul nu exista in lista de produse.
*/
int modificare_pret(vector_elemente* vector, int id, float pret)

{
	if (existenta_id(vector, id) == 0)
		return 1;

	if(validare_pret(pret) == 1)
		return 2;

	schimba_pret(vector, id, pret);

	return 0;
}


/*
	Functie ce permite modificarea cantitatii unui produs dat prin id.
	preconditii: id-ul trebuie sa fie un numar natural, cantitatea trebuie sa fie un numar natural.
	returneaza: 0 daca cantitatea a fost modificat cu succes, 1 daca id-ul nu exista in lista de produse.
*/
int modificare_cantitate(vector_elemente* vector, int id, int cantitate)

{
	if (existenta_id(vector, id) == 0)
		return 1;

	if (validare_cantitate(cantitate) == 1)
		return 2;

	schimba_cantitatea(vector, id, cantitate);
	

	return 0;
}


/*
	Functie din Service ce sterge un produs dat prin id.
	pre: o adresa catre un struct de tipul vector_elemente unde este vectorul de elemente, un id de tip int
	post: functia returneaza 1 daca id-ul nu exista in baza de date, 0 altfel
*/
int stergere_produs(vector_elemente* vector, int id)
{
	if(validare_id(id) == 1)
		return 2;

	if (existenta_id(vector, id) == 0)
		return 1;

	stergere_element(vector, id);
	
	return 0;
}

/*
	Functie ce ordoneaza un vector de tip struct dupa pret si cantitate.
		preconditii: vector trebuie sa fie adresa unui vector de tip struct vector_elemente.
		returneaza: vectorul transmis prin adresa, ordonat dupa pret si cantitate.
*/
void ordonare_dupa_pret_cantitate(vector_elemente* vector)
{
	int nr_produse = lungime_vector(vector);

	for (int i = 1; i <= nr_produse - 1; i++)
	{
		for (int j = i + 1; j <= nr_produse; j++)
		{

			if (pret_produs(&vector -> elemente[i]) > pret_produs(&vector->elemente[j]))// stoc[i] -> pret == *stoc[i].pret
			{
				produs aux = vector->elemente[i];
				vector->elemente[i] = vector->elemente[j];
			    vector->elemente[j] = aux;
			}
			else if (pret_produs(&vector->elemente[i]) == pret_produs(&vector->elemente[j]))
			{
				if (cantitate_produs(&vector->elemente[i]) > cantitate_produs(&vector->elemente[j]))
				{
					produs aux = vector->elemente[i];
					vector->elemente[i] = vector->elemente[j];
					vector->elemente[j] = aux;
				}
			}
		}
	}
}


/*
	Functie ce permite vizualizarea produselor din stoc intr-un mod ordonat dupa pret si cantitate.
	preconditii: un pointer catre un struct de tip vectro_elemente unde sunt valorile,un pointer catre un struct de tip vector_elemente unde vor fi puse rezultatele
	returneaza: un pointer prin parametru catre struct de tip produs ce contine toate produsele din stoc, ordonate dupa pret si cantitate.

*/
int vizualizare_produse_stoc_ordonate(vector_elemente* vector, vector_elemente* copie_v)

{
	
	if(lungime_vector(vector) == 0)
		return 1;
	
	copiere_vector(copie_v, vector);

	ordonare_dupa_pret_cantitate(copie_v);

	return 0;

}

/*
	Functie ce returneaza produsele filtrate dupa pret.
	preconditii: un pointer catre un struct de tip vector_elemente unde sunt elemente, un pointer catre un struct de tip vector_elemente unde vor fi puse rezultatele,pretul trebuie sa fie un numar real pozitiv.
	returneaza: un pointer prin parametru catre struct de tip vector_elemente ce contine toate produsele din
	stoc cu pretul mai mic sau egal decat un pret dat
*/
int filtrare_produse_pret(vector_elemente* vector,vector_elemente* copie_v, float pret)
{
	if(validare_pret(pret) == 1)
		return 2;

	if (lungime_vector(vector) == 0)
		return 1;

	copiere_capacitate_vector(copie_v, vector);

	int nr_gasite = 0;

	for (int i = 1; i <= lungime_vector(vector); i++)
	{
		if (pret_produs(&vector -> elemente[i]) <= pret)
		{
			nr_gasite++;
			produs p = creaza_produs(id_produs(&vector->elemente[i]), cantitate_produs(&vector->elemente[i]), pret_produs(&vector->elemente[i]), model_produs(&vector->elemente[i]), producator_produs(&vector->elemente[i]), tip_produs(&vector->elemente[i]));
			copie_v->elemente[nr_gasite] = p;
		}

	}

	copie_v -> lungime = nr_gasite;

	if(nr_gasite == 0)
		return 3;

	return 0;
}


/*
	Functie ce returneaza produsele filtrate dupa producator.
	preconditii: un pointer catre un struct de tip vector_elemente unde sunt elemente,un pointer catre un struct de tip un pointer catre un struct de tip vector_elemente unde vor fi puse rezultatele
	returneaza: un pointer prin parametru catre struct de tip vector_elemente ce contine toate produsele din
	stoc cu producatorul egal cu cel dat
*/
int filtrare_produse_producator(vector_elemente* vector, vector_elemente* copie_v,char producator[])
{

	if (lungime_vector(vector) == 0)
		return 1;

	int nr_gasite = 0;
	
	copiere_capacitate_vector(copie_v, vector);

	for (int i = 1; i <= lungime_vector(vector); i++)
	{
		if (strcmp(producator_produs(&vector -> elemente[i]),producator) == 0)
		{
			nr_gasite++;
			produs p = creaza_produs(id_produs(&vector->elemente[i]), cantitate_produs(&vector->elemente[i]), pret_produs(&vector->elemente[i]), model_produs(&vector->elemente[i]), producator_produs(&vector->elemente[i]), tip_produs(&vector->elemente[i]));
			copie_v->elemente[nr_gasite] = p;
		}

	}

	copie_v->lungime = nr_gasite;

	if (nr_gasite == 0)
		return 3;

	return 0;
}



/*
Functie ce returneaza produsele filtrate care au cantitatea strict mai mare decat un numar dat.
preconditii: un pointer catre un struct de tip vector_elemente unde sunt elemente,un pointer catre un struct de tip vector_elemente unde vor fi puse rezultatele, un int > 0
returneaza: un pointer prin parametru catre struct de tip vector_elemente ce contine toate produsele din
stoc cu cantitatea egala sau mai mare decat cea data
*/
int filtrare_produse_cantitate(vector_elemente* vector, vector_elemente* copie_v, int cantitate)
{	
	if (validare_cantitate(cantitate) == 1)
		return 2;

	if (lungime_vector(vector) == 0)
		return 1;

	copiere_capacitate_vector(copie_v, vector);

		int nr_gasite = 0;


		for (int i = 1; i <= lungime_vector(vector); i++)
		{
			if (cantitate_produs(&vector->elemente[i]) > cantitate)
			{
				nr_gasite++;
				produs p = creaza_produs(id_produs(&vector->elemente[i]), cantitate_produs(&vector->elemente[i]), pret_produs(&vector->elemente[i]), model_produs(&vector->elemente[i]), producator_produs(&vector->elemente[i]), tip_produs(&vector->elemente[i]));
				copie_v->elemente[nr_gasite] = p;
			}

		}

		copie_v->lungime = nr_gasite;
		if(nr_gasite == 0)
			return 3;

		return 0;

}





