#pragma once
#include "Service.h"
class UI
{
	friend class Teste;
private:
	//Functie ce afiseaza continutul dintr-o harta
	void afisare_harta(std::unordered_map <std::string, Carte_dto> harta, int test = 0);
	//Functie ce afiseaza continutul din cos
	void afisare_cos(const Service& service);
	//Functie ce afiseaza lista din repo
	void afisare_lista(Service& service);

	//Functie ce afiseaza lista copie din service
	void afisare_copie_lista(const Service& service);

	//Functie ce elibereaza buffer-ul din input
	//pre: -
	//post: elibereaza buffer-ul din input
	void elibereaza_buffer();

	//Functie ce transmite un int dat de un utilizator
	//pre: -
	//post: returneazaint-ul dat prin tastatura
	int get_int();

	/*
	Functie ce returneaza un id ce este la dorinta utilizatorului si este din lista_copie
	pre:service - type Service&
	post: va returna un id valid de tip int
	*/
	int get_id_din_lista(Service& service);

public:

	void meniu_utilizator(Service& service);



};