#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "lista_produse.h"




/*
Se creeaza o lista goala
pre:
post: returneaza adresa unei lista goale de tip vector_elemente
*/
vector_elemente creaza_vector_gol()
{
	vector_elemente lista;
	lista.lungime = 0;
	lista.capacitate = 1;
	lista.elemente = malloc(sizeof(element) * lista.capacitate);
	return lista;
}


/*
Se distruge o lista de tip vector_elemente data
pre:o lista vector_elemente
post: lungimea acesteia devine 0, capacitatea 0 si se dealoca memoria de pe heap
*/

 int distruge_vector(vector_elemente* v)
{
	
	for (int i = 1; i <= v->lungime; i++)
	{
		distruge_produs(&v -> elemente[i]);
	}
	v->lungime = 0;
	v -> capacitate = 0;

	free(v -> elemente);
	return 0;
}

/*
	Functie ce verifica daca avem destul spatiu
	pre: o adresa catre un vector_elemente v
	post: 1 daca nu exista suficient spatiu, 0 daca exista

*/
 int destul_spatiu(vector_elemente* v)
 {
	if(v -> lungime < (v -> capacitate) - 1)//Incepem de la 1, nu de la 0
		return 0;
	return 1;

}

/*
	Functie ce aloca mai mult spatiu in HEAP
	pre: o adresa catre un vector_elemente v
	post: se aloca dublul spatiului deja alocat in HEAP
*/
 void aloca_spatiu(vector_elemente* v)
 {
	element* nou;
	
	int capacitate_noua = (v -> capacitate) * 2;

	nou = malloc( capacitate_noua * sizeof(element));

	
	if (nou != NULL)
	{

		for (int i = 1; i <= v->lungime; i++)
			nou[i] = v->elemente[i];

		free(v->elemente);

		v->elemente = nou;
		v->capacitate = capacitate_noua;
	}
	

 }


/*
	Functie ce adauga un produs in vector-ul de produse
	pre:o adresa catre un vector_elemente v, un produs p
	post: produsul p este adaugat in vectorul de elemente
*/
void adaugare_element(vector_elemente* v, element el)
{
	
	if (destul_spatiu(v))
	{
		aloca_spatiu(v);
	}

	v -> lungime ++;
	v -> elemente[ v -> lungime] = el; 
	
}

/*
	Functie ce cauta un element dupa id si transmite indicele unde a fost gasit
	pre: un vector de tip vector_elemente, un id sub forma de int
	post: functia returneaza indicele unde a fost gasit id-ul sau 0 in cazul in care nu a fost gasit
*/
int pozitie_element(vector_elemente* vector, int id)
{
	
	for (int i = 1; i <= vector->lungime; i++)
	{
		if (id_produs(&vector->elemente[i]) == id)
			return i;
	}
	return 0;
}

/*
	Functie ce primeste pozitia din vector a unui produs si returneaza adresa struct-ului produs
	pre: un vector_elemente v, o pozitie de tip int
	post: adresa produsului de pe pozitia ceruta
	Testare: Testat in Test_filtrare_produse_cantitate(vector_elemente* vector)
*/
element returneaza_element(vector_elemente* v, int pozitie)
{
	return v -> elemente[pozitie];
}



/*
	Functie ce returneaza lungimea vectorului de produse de pana acum
	pre: un vector_elemente v
	post: returneaza lungimea vectorului de elemente specificat
*/
int lungime_vector(vector_elemente* v)
{
	return v -> lungime;
}


/*
	Functie ce verifica exista unui id in lista de produse.
	pre: un vector_elemente vector, un id sub forma de int
	post: returneaza 1 daca a fost gasit, 0 in caz contrar
*/
int existenta_id(vector_elemente* vector, int id)
{
	
	if (pozitie_element(vector, id) != 0)
		return 1;
	return 0;
}


/*
	Functie ce verifica daca un produs este exact la fel din toate punctele de vedere ca altul
	pre: un vector de tip vector_elemente, un produs de tip produs
	post: 0 daca nu exista alt produs exact la fel, 1 altfel
*/
int exact_acelasi(vector_elemente* vector, element* produs)
{
			int i = pozitie_element(vector, id_produs(produs));
			
			if(pret_produs(&vector->elemente[i]) == pret_produs(produs))
			{
			
				if (strcmp(producator_produs(&vector->elemente[i]), producator_produs(produs)) == 0)
				{
					
					if (strcmp(tip_produs(&vector->elemente[i]), tip_produs(produs)) == 0)
					{
						
						if(strcmp(model_produs(&vector->elemente[i]) , model_produs(produs)) == 0)
							return 1;
						else
							return 0;
					}
					
						return 0;
				}
				
					return 0;
			}
			return 0;

		

	
}

/*
	Functie ce adauga la cantitatea unui produs
	pre: un vector de tip vector_elemente, un produs de tip produs
	post: cantitatea din produsul p va fi adaugat la produsul cu acelasi id din lista
*/
void adaugare_cantitate(vector_elemente* vector, produs* p)
{
	int indice = pozitie_element(vector, id_produs(p));
	plus_la_cantitate(&vector -> elemente[indice], cantitate_produs(p));

}

/*
	Functie din lista_produse  ce schimba pretul produsului transmis ca argument cu pretul transmis
	pre: adresa unui tip struct produs, un pret sub forma de float
	post: pretul produsului se schimba cu numarul dat
*/
void schimba_pret(vector_elemente* vector, int id,float pret)
{
	int index = pozitie_element(vector,id);
	updatare_pret(&vector -> elemente[index], pret);
}

/*
	Functie din lista_produse ce schimba cantitatea produsului transmis ca argument cu cantitatea transmisa
	pre: adresa unui tip struct produs, o cantitate sub forma de int
	post: cantitatea produsului se schimba cu numarul dat
*/
void schimba_cantitatea(vector_elemente* vector, int id,int cantitate)
{
	int index = pozitie_element(vector, id);
	updatare_cantitate(&vector->elemente[index], cantitate);
}

/*
	Functie ce copiaza un vector struct de tipul vector elemente din al doilea argument in primul
	pre: o adresa catre un struct de tip vector_elemente unde se doreste copierea vectorului, o adresa catre un struct de tip vector_elemente de unde se copiaza
	post:primul vector transmis ca argument va deveni o copie fidela al celui de-al doilea vector
*/
void copiere_vector(vector_elemente* copie_v, vector_elemente* vector )
{
	copie_v -> capacitate = vector -> capacitate;
	copie_v -> lungime = vector -> lungime;
	copie_v -> elemente = malloc( copie_v -> capacitate * sizeof(element));
	
	for (int i = 1; i <= vector->lungime; i++)
	{
		copie_v -> elemente[i] = vector -> elemente[i];
	}

}
/*
	Functie ce copiaza capacitatea unui vector struct de tipul vector elemente din al doilea argument in primul si aloca memoria necesara
	pre: o adresa catre un struct de tip vector_elemente unde se doreste copierea vectorului, o adresa catre un struct de tip vector_elemente de unde se copiaza
	post:primul vector transmis ca argument va deveni contine aceeasi capacitate ca vectorul din al doilea argument
*/

void copiere_capacitate_vector(vector_elemente* copie_v, vector_elemente* vector)
{
	copie_v->capacitate = vector->capacitate;
	copie_v->elemente = malloc(copie_v->capacitate * sizeof(element));
}


/*
	Functie din lista_produse ce sterge un element din lista
	pre: adresa unui vector de tip vector_element, un id te tip ind
	post: produsul cu id-ul transmis o sa fie sters din lista
*/
void stergere_element(vector_elemente* vector, int id)
{
	int index = pozitie_element(vector, id);
	distruge_produs(&vector -> elemente[index]);

	for (int i = index; i < vector->lungime; i++)
	{
		vector -> elemente[i] = vector -> elemente[i+1];
	}
	vector -> lungime--;
}