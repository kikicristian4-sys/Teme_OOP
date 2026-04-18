#include "Repository.h"
#include "Carte.h"
#include <iostream>
#include "Errors.h"

bool Repository::cautare_carte(int id) noexcept {

	for (int i = 0; i < lungime; i ++)
	{
		Carte c = lista[i];
		if (c.get_id() == id)
			return true;
	}

	
	return false;
}

bool Repository::exact_la_fel_ca_alta_carte(const Carte& c){
	
	for (int i = 0; i < lungime; i++)
	{
		Carte carte = lista[i];
		if(carte.get_anul_aparitiei() == c.get_anul_aparitiei() && 
		carte.get_autor().compare(c.get_autor()) == 0 && 
			carte.get_titlu().compare(c.get_titlu()) == 0 &&
			carte.get_gen().compare(c.get_gen()) == 0
		)
		return true;
	}
	return false;


}

void Repository::redimensionare()
{		
	capacitate = capacitate * 2;

	Carte* vector_nou = new Carte[capacitate];

	for(int i = 0; i < lungime; i ++)
		vector_nou[i] = lista[i];

	delete [] lista;

	lista = vector_nou;
}

int Repository::adauga_carte(const Carte& c) {
	
	if (cautare_carte(c.get_id()) == true)
		throw ValidationError("Id-ul exista in lista!\n");

	if(exact_la_fel_ca_alta_carte(c) == true)
		throw ValidationError ("Id-ul dat este diferit, insa valorile campurilor sunt exact la fel ca ale altei carti!\n");

	if(lungime == capacitate)
		redimensionare();

	lista[lungime] = c;
	lungime++;
	return 0;
}

void Repository::clear() {
	lungime = 0;
}

int Repository::sterge_carte(int id) {
	if (lungime == 0)
		throw ValidationError ("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError ("Id-ul nu exista in lista!\n");

	for (int j = 0; j < lungime; j++)
	
		if (lista[j].get_id() == id)
		{
			lungime--;
			for (int i = j; i < lungime; i++)
				lista[i] = lista[i + 1];
			break;
		}
			
		
			
	return 0;
}

int Repository::modificare_titlu(int id, string titlu)
{
	if (lungime == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	for (int j = 0; j < lungime; j++)
	
		if (lista[j].get_id() == id)
		{
			lista[j].modifica_titlu(titlu);
			break;
		}
			
	return 0;
	
}

int Repository::modificare_autor(int id, string autor)
{
	if (lungime == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	for (int j = 0; j < lungime; j++)
		if (lista[j].get_id() == id)
		{
			lista[j].modifica_autor(autor);
			break;
		}
			
	return 0;
}

int Repository::modificare_gen(int id, string gen)
{
	if (lungime == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	for (int j = 0; j < lungime; j++)
		if (lista[j].get_id() == id)
		{
			lista[j].modifica_gen(gen);
			break;

		}
	return 0;
}

int Repository::modificare_an_aparitie(int id, int an_nou)
{
	if (lungime == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	for (int j = 0; j < lungime; j++)
		if (lista[j].get_id() == id)
		{
			lista[j].modifica_an_aparitie(an_nou);
			break;
		}
	return 0;
}

int Repository::cautare_carte_specifica(string ti, string au, string g, int an)
{
	if (lungime == 0)
		throw ValidationError("Lista este goala!\n");
	
	
	for (int i = 0; i < lungime; i++)
	{
		Carte c = lista[i];
		if(ti.compare(c.get_titlu()) == 0 && au.compare(c.get_autor()) == 0 && g.compare(c.get_gen()) == 0 && an == c.get_anul_aparitiei())
			return c.get_id();
	}

	return 0;
}

