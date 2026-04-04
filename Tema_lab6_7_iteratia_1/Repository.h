#pragma once
#include "Carte.h"
#include <vector>

using std::vector;

class Repository
{
	friend class Service;
	friend class UI;
	private:

	//Vectorul ce contine lista de carti
	vector <Carte> lista;

	/*
		Functie ce cauta o carte dupa id
		pre: id - type int pozitiv
		post: returneaza true daca exista, false daca nu
	*/
	bool cautare_carte(int id) noexcept;

	/*
		Functie ce cauta o carte dupa toate informatiile inafara de id
		pre: c - type carte
		post: returneaza true daca exista, false daca nu
	*/
	bool exact_la_fel_ca_alta_carte(const Carte& c);

	public:
	/*
		Functie ce adauga o carte in lista
		pre: c - o carte transmisa prin referinta
		post: returneaza 0 daca cartea c a fost adaugata in lista de carti, 1 daca id-ul deja exista
	
	*/
	int adauga_carte(const Carte& c);


	/*
		Functie ce sterge o carte data printr-un id
		pre: id - type int pozitiv
		post: returneaza 0 daca cartea cu id-ul specificat a fost stearsa, 1 daca nu exista in lista, 2 daca lista este goala
	*/
	int sterge_carte(int id);


	/*
		Functie ce modifica titlul unei carti date prin id
		pre: id - type int pozitiv, titlu - type string
		post: returneaza 0 daca schimbul s-a facut cu succes, 1 daca nu exista cartea cu id-ul specificat, 2 daca lista este goala
	*/
	int modificare_titlu(int id, string titlu);

	/*
		Functie ce modifica autorul unei carti date prin id
		pre: id - type int pozitiv, autor - type string
		post: returneaza 0 daca schimbul s-a facut cu succes, 1 daca nu exista cartea cu id-ul specificat, 2 daca lista este goala
	*/
	int modificare_autor(int id, string autor);

	/*
		Functie ce modifica genul unei carti date prin id
		pre: id - type int pozitiv, gen - type string
		post: returneaza 0 daca schimbul s-a facut cu succes, 1 daca nu exista cartea cu id-ul specificat, 2 daca lista este goala
	*/
	int modificare_gen(int id, string gen);

	/*
		Functie ce modifica titlul unei carti date prin id
		pre: id - type int pozitiv, an_nou - type int pozitiv
		post: returneaza 0 daca schimbul s-a facut cu succes, 1 daca nu exista cartea cu id-ul specificat, 2 daca lista este goala
	*/
	int modificare_an_aparitie(int id, int an_nou);

	/*
		Functie ce cauta o carte dupa setul acesteia de date
		pre: id - type int pozitiv
		post: returneaza id-ul cartii cu specificatiile fixe, altfe id-ul 0 daca nu a fost gasit, -1 daca nu este nimic in lista
	*/
	int cautare_carte_specifica(string ti, string au, string g, int an);

	
};