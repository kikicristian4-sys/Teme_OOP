#pragma once
#include "Repository.h"
#include "Validare.h"
#include "Cos.h"
#include <algorithm>
#include <random> // std::default_random_engine
#include <chrono> // std::chrono::system_clock
#include <unordered_map>
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
	Cos cos;


	/*
	Functie ce returneaza un dictionar cu frecvente si autori
	pre: -
	post: se returneaza dictionarul
	*/
	std::unordered_map <std::string, Carte_dto> frecventa_autor();

	void goleste_cos_service() noexcept;
	/*
		Functie ce genereaza un cos
		pre: n - type int strict pozitiv
		post: Se vor adauga n carti aleatorii in cos, se genereaza exceptie daca n este mai mare decat numarul de carti din lista
	*/
	void genereaza_cos(int n);

	/*
	Functie ce adauga o carte cu un anumit titlu in cos
	pre: titlu - type string
	post: returneaza 0 daca a fost gasita o singura carte si a fost adaugata in cos, 1 daca au fost gasite mai multe carti si trebuie aleasa una lista cartilor cu acelasi titlu fiind pusa in vectorul copie, exceptie in cazul in care nu a fost gasita nici o carte
	*/
	int adauga_carte_in_cos(string titlu);

	/*
	Functie ce exporta continutul din cos intr-un fisier cu numele dat de utilizator
	pre: nume - type string
	post: Cartile din cos vor fi exportate intr-un fisier cu numele dat
	*/
	void export_cos_in_fisier_service(string nume);

	/*
	Functie ce adauga o carte cu un anumit id in cos
	pre: id - type int strict pozitiv
	post: cartea cu id-ul specificat va fi adaugat in cos
	*/
	void adauga_carte_in_cos_dupa_id(int id);

	/*
	Functia de adaugare carte din service
	pre: id - type int, titlu - type string, autor - type string, gen - type string, an_aparitie - type int
	post: se returneaza 0 daca totul a fost okay, exceptie in orice alt caz
	*/
	int adauga_carte_service(int id, string titlu, string autor, string gen, int an_aparitie);

	/*
		Functia de stergere carte din service
		pre: id - type int
		post:returneaza 0 daca totul este ok, exceptie in orice alt caz
	*/
	int sterge_carte_service(int id);

	/*
			Functie ce modifica titlul unei carti date prin id din service
			pre: id - type int pozitiv, titlu - type string
			post: returneaza 0 daca schimbul s-a facut cu succes, exceptie in orice alt caz
		*/
	int modificare_titlu_service(int id, string titlu);

	/*
			Functie ce modifica autorul unei carti date prin id din service
			pre: id - type int pozitiv, autor - type string
			post: returneaza 0 daca schimbul s-a facut cu succes, exceptie in orice alt caz
		*/
	int modificare_autor_service(int id, string autor);

	/*
			Functie ce modifica genul unei carti date prin id din service
			pre: id - type int pozitiv, gen - type string
			post: returneaza 0 daca schimbul s-a facut cu succes, exceptie in orice alt caz
		*/
	int modificare_gen_service(int id, string gen);

	/*
		Functie ce modifica titlul unei carti date prin id din service
		pre: id - type int pozitiv, an_nou - type int pozitiv
		post: returneaza 0 daca schimbul s-a facut cu succes, exceptie in orice alt caz
	*/
	int modificare_an_aparitie_service(int id, int an_nou);

	/*
			Functie ce cauta o carte dupa setul acesteia de date din service
			pre: id - type int pozitiv
			post: returneaza id-ul cartii cu specificatiile fixe, altfe id-ul 0 daca nu a fost gasit, exceptie in orice alt caz
	*/
	int cautare_carte_specifica_service(string ti, string au, string g, int an);


	/*
		Functie de filtrare dupa titlu
		pre: titlu - type string
		post: in lista_copie sunt puse rezultatele filtrarii, se returneaza 0 daca s-a filtrat cu succes si au fost gasite carti dupa specificatie, exceptie in orice alt caz
	*/
	int filtrare_dupa_titlu(string titlu);

	/*
		Functie de filtrare dupa anul aparitiei unei carti
		pre: an_aparitie - type int
		post: in lista_copie sunt puse rezultatele filtrarii, se returneaza 0 daca s-a filtrat cu succes si au fost gasite carti dupa specificatie, exceptie in orice alt caz
	*/
	int filtrare_dupa_an_aparitie(int an_aparitie);


	/*
		Functie de sortare dupa titlu
		pre: -
		post: in lista_copie sunt puse rezultatul sortat, functia returneaza 0 daca totul s-a sortat,  exceptie in orice alt caz
	*/
	int sortare_dupa_titlu();

	/*
		Functie de sortare dupa autor
		pre: -
		post: in lista_copie sunt puse rezultatul sortat, functia returneaza 0 daca totul s-a sortat, exceptie in orice alt caz
	*/
	int sortare_dupa_autor();

	/*
		Functie de sortare dupa an + gen
		pre: -
		post: in lista_copie sunt puse rezultatul sortat, functia returneaza 0 daca totul s-a sortat,  exceptie in orice alt caz
	*/
	int sortare_an_si_gen();

};