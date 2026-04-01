#pragma once
#include "Repository.h"
#include "Validare.h"

class Service {

private:

//validatorul 
Validare validator;

/*
	Functie ce copiaza vectorul principal din repo, in vectorul copie din service
	pre: -
	post: lista_copie primeste datele din lista (din repo)
*/
void copie_vector_principat_in_vector_copie();

public:

Repository repo;
vector <Carte> lista_copie;

/*
	Functia de adaugare carte din service
	pre: id - type int, titlu - type string, autor - type string, gen - type string, an_aparitie - type int
	post: se returneaza 0 daca totul a fost okay, 1 daca exista id-ul in lista, -10 daca id-ul dat este negativ, -30 daca anul dat este negativ, -40 daca anul dat este mai mare decat anul curent
*/
int adauga_carte_service(int id, string titlu, string autor, string gen, int an_aparitie);

/*
	Functia de stergere carte din service
	pre: id - type int
	post:returneaza 0 daca totul este ok, 1 daca id-ul nu exista, 2 daca lista este goala, -10 daca id-ul este negativ
*/
int sterge_carte_service(int id);

/*
		Functie ce modifica titlul unei carti date prin id din service
		pre: id - type int pozitiv, titlu - type string
		post: returneaza 0 daca schimbul s-a facut cu succes, 1 daca nu exista cartea cu id-ul specificat, 2 daca lista este goala
	*/
int modificare_titlu_service(int id, string titlu);

/*
		Functie ce modifica autorul unei carti date prin id din service
		pre: id - type int pozitiv, autor - type string
		post: returneaza 0 daca schimbul s-a facut cu succes, 1 daca nu exista cartea cu id-ul specificat, 2 daca lista este goala
	*/
int modificare_autor_service(int id, string autor);

/*
		Functie ce modifica genul unei carti date prin id din service
		pre: id - type int pozitiv, gen - type string
		post: returneaza 0 daca schimbul s-a facut cu succes, 1 daca nu exista cartea cu id-ul specificat, 2 daca lista este goala
	*/
int modificare_gen_service(int id, string gen);

/*
	Functie ce modifica titlul unei carti date prin id din service
	pre: id - type int pozitiv, an_nou - type int pozitiv
	post: returneaza 0 daca schimbul s-a facut cu succes, 1 daca nu exista cartea cu id-ul specificat, 2 daca lista este goala, -30 daca anul dat este negativ, -40 daca anul dat este mai mare decat anul prezent
*/
int modificare_an_aparitie_service(int id, int an_nou);

/*
		Functie ce cauta o carte dupa setul acesteia de date din service
		pre: id - type int pozitiv
		post: returneaza id-ul cartii cu specificatiile fixe, altfe id-ul 0 daca nu a fost gasit, -1 daca nu este nimic in lista, -30 daca anul dat este negativ, -40 daca anul dat este mai mare decat anul prezent
*/
int cautare_carte_specifica_service(string ti, string au, string g, int an);


/*
	Functie de filtrare dupa titlu
	pre: titlu - type string
	post: in lista_copie sunt puse rezultatele filtrarii, se returneaza 0 daca s-a filtrat cu succes si au fost gasite carti dupa specificatie, 1 daca nu s-au gasit asemenea carti, 2 daca nu exista carti in lista
*/
int filtrare_dupa_titlu(string titlu);

/*
	Functie de filtrare dupa anul aparitiei unei carti
	pre: an_aparitie - type int
	post: in lista_copie sunt puse rezultatele filtrarii, se returneaza 0 daca s-a filtrat cu succes si au fost gasite carti dupa specificatie, 1 daca nu s-au gasit asemenea carti, 2 daca nu exista carti in lista, -30 daca anul dat este negativ, -40 daca anul dat este mai mare decat anul prezent
*/
int filtrare_dupa_an_aparitie(int an_aparitie);


/*
	Functie de sortare dupa titlu
	pre: -
	post: in lista_copie sunt puse rezultatul sortat, functia returneaza 0 daca totul s-a sortat, 1 daca nu exista nimic de sortat
*/
int sortare_dupa_titlu();

/*
	Functie de sortare dupa autor
	pre: -
	post: in lista_copie sunt puse rezultatul sortat, functia returneaza 0 daca totul s-a sortat, 1 daca nu exista nimic de sortat
*/
int sortare_dupa_autor();

/*
	Functie de sortare dupa an + gen 
	pre: -
	post: in lista_copie sunt puse rezultatul sortat, functia returneaza 0 daca totul s-a sortat, 1 daca nu exista nimic de sortat
*/
int sortare_an_si_gen();

};