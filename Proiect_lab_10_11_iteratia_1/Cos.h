#pragma once
#include "Carte.h"
#include <vector>

using std::vector;

class Cos {
	friend class UI;
	friend class Service;
	friend class Teste;
	private:

	vector <Carte> lista;
	public:

	
	/*
	Functie ce goleste cosul de cumparaturi
	pre: -
	post: cosul utilizatorului va fi golit
	*/
	void goleste_cos() noexcept;

	/*
	* Functie ce adauga o carte in cos
	* pre: referinta catre o carte
	* post: cartea va fi adaugata in cos
	*/
	void adauga_carte_in_cos(const Carte& c);

	/*
		Functie ce exporta lista intr-un fisier cu numele dat prin parametru
		pre: nume - type string
		post: se va crea fisierul cu numele dat prin parametru si se va introduce cosul de cumparaturi in el
	*/
	void Export (string nume);  
};
