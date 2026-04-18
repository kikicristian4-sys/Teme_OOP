#include "Repository.h"
#include "Carte.h"
#include "Errors.h"
#include <iostream>


bool Repository::cautare_carte(int id) noexcept {

	for (const Carte& c : lista)
	{
		if (c.get_id() == id)
			return true;
	}


	return false;
}

bool Repository::exact_la_fel_ca_alta_carte(const Carte& c) {

	for (const Carte& carte : lista)
	{
		if (carte.get_anul_aparitiei() == c.get_anul_aparitiei() &&
			carte.get_autor().compare(c.get_autor()) == 0 &&
			carte.get_titlu().compare(c.get_titlu()) == 0 &&
			carte.get_gen().compare(c.get_gen()) == 0
			)
			return true;
	}
	return false;


}

int Repository::adauga_carte(const Carte& c) {

	if (cautare_carte(c.get_id()) == true)
		throw ValidationError("Id-ul exista in lista!\n");

	if (exact_la_fel_ca_alta_carte(c) == true)
		throw ValidationError("Id-ul dat este diferit, insa valorile campurilor sunt exact la fel ca ale altei carti!\n");

	lista.push_back(c);
	return 0;
}

int Repository::sterge_carte(int id) {
	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	vector <Carte>::iterator i = lista.begin();

	for (int j = 0; j < lista.size(); j++)

		if (lista.at(j).get_id() == id)
		{
			lista.erase(i + j);
			break;
		}

	return 0;
}

int Repository::modificare_titlu(int id, string titlu)
{		if(lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	for (int j = 0; j < lista.size(); j++)

		if (lista.at(j).get_id() == id)
		{
			lista.at(j).modifica_titlu(titlu);
			break;
		}

	return 0;

}

int Repository::modificare_autor(int id, string autor)
{
	if(lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	for (int j = 0; j < lista.size(); j++)
		if (lista.at(j).get_id() == id)
		{
			lista.at(j).modifica_autor(autor);
			break;
		}

	return 0;
}

int Repository::modificare_gen(int id, string gen)
{
	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	for (int j = 0; j < lista.size(); j++)
		if (lista.at(j).get_id() == id)
		{
			lista.at(j).modifica_gen(gen);
			break;

		}
	return 0;
}

int Repository::modificare_an_aparitie(int id, int an_nou)
{
	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	for (int j = 0; j < lista.size(); j++)
		if (lista.at(j).get_id() == id)
		{
			lista.at(j).modifica_an_aparitie(an_nou);
			break;
		}
	return 0;
}

int Repository::cautare_carte_specifica(string ti, string au, string g, int an)
{
	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");

	for (const Carte& c : lista)
	{
		if (ti.compare(c.get_titlu()) == 0 && au.compare(c.get_autor()) == 0 && g.compare(c.get_gen()) == 0 && an == c.get_anul_aparitiei())
			return c.get_id();
	}

	return 0;
}