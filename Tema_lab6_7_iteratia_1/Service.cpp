#include "Service.h"
#include <iostream>

int Service::adauga_carte_service(int id, string titlu, string autor, string gen, int an_aparitie)
{
	if (validator.validare_id(id) !=0)
		return validator.validare_id(id);
	if(validator.validare_an(an_aparitie) != 0)
		return validator.validare_an(an_aparitie);
	Carte carte1(id, titlu, autor, gen, an_aparitie);
	return this->repo.adauga_carte(carte1);
}

int Service::sterge_carte_service(int id)
{
	if (validator.validare_id(id) != 0)
		return validator.validare_id(id);
	return this->repo.sterge_carte(id);
}

int Service::modificare_titlu_service(int id, string titlu)
{
	if (validator.validare_id(id) != 0)
		return validator.validare_id(id);
	return this-> repo.modificare_titlu(id,titlu);
}

int Service::modificare_autor_service(int id, string autor)
{
	if (validator.validare_id(id) != 0)
		return validator.validare_id(id);
	return this->repo.modificare_autor(id, autor);
}

int Service::modificare_gen_service(int id, string gen)
{
	if (validator.validare_id(id) != 0)
		return validator.validare_id(id);
	return this->repo.modificare_gen(id, gen);
}

int Service::modificare_an_aparitie_service(int id, int an_nou)
{
	if (validator.validare_id(id) != 0)
		return validator.validare_id(id);
	if (validator.validare_an(an_nou) != 0)
		return validator.validare_an(an_nou);
	return this->repo.modificare_an_aparitie(id,an_nou);
}

int Service::cautare_carte_specifica_service(string ti, string au, string g, int an)
{
	if (validator.validare_an(an) != 0)
		return validator.validare_an(an);
	return this->repo.cautare_carte_specifica(ti,au,g,an);
}

int Service::filtrare_dupa_titlu(string titlu)
{
	if(this->repo.lista.size() == 0)
		return 2;
	this->lista_copie.clear();
	int rez = 1;
	for (const Carte& c : this->repo.lista)
		{
		if (c.get_titlu().compare(titlu) == 0)
		{
			this->lista_copie.push_back(c);
			rez = 0;
		}
				
	}
	return rez;
}


int Service::filtrare_dupa_an_aparitie(int an_aparitie)
{
	if (validator.validare_an(an_aparitie) != 0)
		return validator.validare_an(an_aparitie);
	if (this->repo.lista.size() == 0)
		return 2;

	this->lista_copie.clear();
	int rez = 1;
	for (const Carte& c : this->repo.lista)
	{
		if (c.get_anul_aparitiei() == an_aparitie)
		{
			this->lista_copie.push_back(c);
			rez = 0;
		}

	}
	return rez;
}

void Service::copie_vector_principat_in_vector_copie() {
	for (const Carte& c : this->repo.lista)
	{
		this->lista_copie.push_back(c);
	}

}


int Service::sortare_dupa_titlu()
{
	if(this->repo.lista.size() == 0)
		return 1;

	this -> lista_copie.clear();

	copie_vector_principat_in_vector_copie();

	for (int i = 0; i < this->lista_copie.size(); i++)
	{
		for(int j = i+1; j < this -> lista_copie.size(); j ++)
			if (this->lista_copie.at(i).get_titlu().compare(this->lista_copie.at(j).get_titlu()) > 0)
			{
				std::swap(lista_copie.at(i), lista_copie.at(j));
			}
	}

	return 0;
}


int Service::sortare_dupa_autor()
{
	if (this->repo.lista.size() == 0)
		return 1;

	this->lista_copie.clear();

	copie_vector_principat_in_vector_copie();

	for (int i = 0; i < this->lista_copie.size(); i++)
	{
		for (int j = i+1; j < this->lista_copie.size(); j++)
			if (this->lista_copie.at(i).get_autor().compare(this->lista_copie.at(j).get_autor()) > 0)
			{
				std::swap(lista_copie.at(i), lista_copie.at(j));
			}
	}

	return 0;
}

int Service::sortare_an_si_gen()
{
	if (this->repo.lista.size() == 0)
		return 1;


	this->lista_copie.clear();

	copie_vector_principat_in_vector_copie();

	for (int i = 0; i < this->lista_copie.size(); i++)
	{
		for (int j = i+1; j < this->lista_copie.size(); j++)
			if (this->lista_copie.at(i).get_anul_aparitiei() > this->lista_copie.at(j).get_anul_aparitiei())
			{
				std::swap(lista_copie.at(i), lista_copie.at(j));
			}
			else
			{
				if (this->lista_copie.at(i).get_anul_aparitiei() == this->lista_copie.at(j).get_anul_aparitiei())
					if (this->lista_copie.at(i).get_gen().compare(this->lista_copie.at(j).get_gen()) > 0)
					{
						std::swap(lista_copie.at(i), lista_copie.at(j));
					}
			}
			
	}

	return 0;

}