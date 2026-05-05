#pragma once
#include "Carte.h"
#include <vector>
#include <fstream>

using std::vector;

class Repository
{
	friend class Service;
	friend class UI;
private:
	string fisier;
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

	//constructor 
	Repository(string fisier) : fisier{ fisier } {};

	Repository(const Repository& alt) : fisier{ alt.fisier } {};

	Repository(Repository&&) = default;

	Repository& operator = (const Repository&) = default;//Cu copiere la assignement

	Repository& operator = (Repository&&) = default;

	Repository(Repository&) noexcept = default;

	//deconstructor
	Repository() {};

	/*
		Functie ce scrie in fisier valorile prezente in lista l
		pre: l - type vector <Carte>
		post: toate valorile din l vor fi adaugate in fisier
		*/
	void updatare_fisier(vector<Carte> l);

	/*
	Functie ce citeste din fisier
	pre: -
	post: returneaza un vector <Carte> unde sunt trecute valorile din fisier
	*/
	vector <Carte> citire_din_fisier();

	/*
		Functie ce adauga o carte in lista
		pre: c - o carte transmisa prin referinta
		post: returneaza 0 daca cartea c a fost adaugata in lista de carti, arunca exceptie: daca id-ul deja exista

	*/
	int adauga_carte(const Carte& c);


	/*
		Functie ce sterge o carte data printr-un id
		pre: id - type int pozitiv
		post: returneaza 0 daca cartea cu id-ul specificat a fost stearsa, arunca exceptie daca nu exista in lista, daca lista este goala
	*/
	Carte sterge_carte(int id);


	/*
		Functie ce modifica titlul unei carti date prin id
		pre: id - type int pozitiv, titlu - type string
		post: returneaza 0 daca schimbul s-a facut cu succes, arunca exceptie daca nu exista cartea cu id-ul specificat, daca lista este goala
	*/
	Carte modificare_titlu(int id, string titlu);

	/*
		Functie ce modifica autorul unei carti date prin id
		pre: id - type int pozitiv, autor - type string
		post: returneaza 0 daca schimbul s-a facut cu succes, arunca exceptie daca nu exista cartea cu id-ul specificat, daca lista este goala
	*/
	Carte modificare_autor(int id, string autor);

	/*
		Functie ce modifica genul unei carti date prin id
		pre: id - type int pozitiv, gen - type string
		post: returneaza 0 daca schimbul s-a facut cu succes,arunca exceptie daca nu exista cartea cu id-ul specificat, daca lista este goala
	*/
	Carte modificare_gen(int id, string gen);

	/*
		Functie ce modifica titlul unei carti date prin id
		pre: id - type int pozitiv, an_nou - type int pozitiv
		post: returneaza 0 daca schimbul s-a facut cu succes, arunca exceptie daca nu exista cartea cu id-ul specificat, daca lista este goala
	*/
	Carte modificare_an_aparitie(int id, int an_nou);

	/*
		Functie ce cauta o carte dupa setul acesteia de date
		pre: id - type int pozitiv
		post: returneaza id-ul cartii cu specificatiile fixe, altfe id-ul 0 daca nu a fost gasit, arunca exceptie daca nu este nimic in lista
	*/
	int cautare_carte_specifica(string ti, string au, string g, int an);


};