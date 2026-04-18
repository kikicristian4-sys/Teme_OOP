#pragma once
#include "Service.h"
class UI
{
private:
	//Functie ce afiseaza lista din repo
	void afisare_lista(const Service& service);

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

public:

	void meniu_utilizator(Service& service);



};