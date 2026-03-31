#pragma once
#include "Service.h"
class UI
{
	private:
	//Functie ce afiseaza lista din repo
	void afisare_lista(Service& service);
	
	//Functie ce afiseaza lista copie din service
	void afisare_copie_lista(Service& service);
	public:

	void meniu_utilizator(Service& service);



};