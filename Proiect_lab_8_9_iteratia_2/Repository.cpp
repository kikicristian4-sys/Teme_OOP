#include "Repository.h"
#include "Carte.h"
#include "Errors.h"
#include <iostream>
#include <sstream>

void Repository::updatare_fisier(vector<Carte> l)
{
	std::ofstream fout(fisier);
	for (const Carte& c : l)
	{
		fout << c.get_id() << "," << c.get_titlu() << "," << c.get_autor() << "," << c.get_gen() << "," << c.get_anul_aparitiei() << std::endl;
	}
}

vector <Carte> Repository::citire_din_fisier()
{
	std::ifstream fin(fisier);
	vector <Carte> lista;
	string s;
	while (std::getline(fin, s))
	{
		string titlu, autor, gen;
		int id, anul_aparitiei;

		std::istringstream stream(s);
		std::string parte;


		getline(stream, parte, ',');
		id = atoi(parte.c_str());
		getline(stream, parte, ',');
		titlu = parte;
		getline(stream, parte, ',');
		autor = parte;
		getline(stream, parte, ',');
		gen = parte;
		getline(stream, parte, ',');
		anul_aparitiei = atoi(parte.c_str());

		Carte c = Carte(id, titlu, autor, gen, anul_aparitiei);

		lista.push_back(c);


	}
	return lista;
}

bool Repository::cautare_carte(int id) noexcept {


	vector <Carte> lista = citire_din_fisier();


	for (const Carte& c : lista)
	{
		if (c.get_id() == id)
			return true;
	}


	return false;
}

bool Repository::exact_la_fel_ca_alta_carte(const Carte& c) {

	vector <Carte> lista = citire_din_fisier();

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

	vector <Carte> lista = citire_din_fisier();

	if (cautare_carte(c.get_id()) == true)
		throw ValidationError("Id-ul exista in lista!\n");

	if (exact_la_fel_ca_alta_carte(c) == true)
		throw ValidationError("Id-ul dat este diferit, insa valorile campurilor sunt exact la fel ca ale altei carti!\n");

	lista.push_back(c);
	updatare_fisier(lista);
	return 0;
}

Carte Repository::sterge_carte(int id) {
	vector <Carte> lista = citire_din_fisier();

	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	vector <Carte>::iterator i = lista.begin();
	Carte carte_copie;
	for (int j = 0; j < lista.size(); j++)

		if (lista.at(j).get_id() == id)
		{
			carte_copie = lista.at(j);
			lista.erase(i + j);
			break;
		}
	updatare_fisier(lista);
	return carte_copie;
}

Carte Repository::modificare_titlu(int id, string titlu)
{
	vector <Carte> lista = citire_din_fisier();

	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");
	Carte carte_copie;
	for (Carte& c : lista)
		if (c.get_id() == id)
		{
			carte_copie = c;
			c.modifica_titlu(titlu);
			break;
		}

	updatare_fisier(lista);
	return carte_copie;

}

Carte Repository::modificare_autor(int id, string autor)
{
	vector <Carte> lista = citire_din_fisier();

	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	Carte carte_copie;
	for (Carte& c : lista)
		if (c.get_id() == id)
		{
			carte_copie = c;
			c.modifica_autor(autor);
			break;
		}

	updatare_fisier(lista);
	return carte_copie;
}

Carte Repository::modificare_gen(int id, string gen)
{
	vector <Carte> lista = citire_din_fisier();

	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	Carte carte_copie;
	for (Carte& c : lista)
		if (c.get_id() == id)
		{
			carte_copie = c;
			c.modifica_gen(gen);
			break;
		}

	updatare_fisier(lista);
	return carte_copie;

}

Carte Repository::modificare_an_aparitie(int id, int an_nou)
{
	vector <Carte> lista = citire_din_fisier();

	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	if (cautare_carte(id) == false)
		throw ValidationError("Id-ul nu exista in lista!\n");

	Carte carte_copie;
	for (Carte& c : lista)
		if (c.get_id() == id)
		{
			carte_copie = c;
			c.modifica_an_aparitie(an_nou);
			break;
		}

	updatare_fisier(lista);
	return carte_copie;
}

int Repository::cautare_carte_specifica(string ti, string au, string g, int an)
{
	vector <Carte> lista = citire_din_fisier();

	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");

	for (const Carte& c : lista)
	{
		if (ti.compare(c.get_titlu()) == 0 && au.compare(c.get_autor()) == 0 && g.compare(c.get_gen()) == 0 && an == c.get_anul_aparitiei())
			return c.get_id();
	}

	return 0;
}