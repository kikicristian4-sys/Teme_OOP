#include "Service.h"
#include <iostream>
#include "Errors.h"

int Service::adauga_carte_service(int id, string titlu, string autor, string gen, int an_aparitie)
{
	validator.validare_id(id);
	validator.validare_an(an_aparitie);
	Carte carte1(id, titlu, autor, gen, an_aparitie);
	return this->repo.adauga_carte(carte1);
}

int Service::sterge_carte_service(int id)
{
	validator.validare_id(id);
	return this->repo.sterge_carte(id);
}

int Service::modificare_titlu_service(int id, string titlu)
{
	validator.validare_id(id);
	return this-> repo.modificare_titlu(id,titlu);
}

int Service::modificare_autor_service(int id, string autor)
{
	validator.validare_id(id);
		
	return this->repo.modificare_autor(id, autor);
}

int Service::modificare_gen_service(int id, string gen)
{
	validator.validare_id(id);
		
	return this->repo.modificare_gen(id, gen);
}

int Service::modificare_an_aparitie_service(int id, int an_nou)
{
	validator.validare_id(id);
	validator.validare_an(an_nou);
	return this->repo.modificare_an_aparitie(id,an_nou);
}

int Service::cautare_carte_specifica_service(string ti, string au, string g, int an)
{
	validator.validare_an(an);
	return this->repo.cautare_carte_specifica(ti,au,g,an);
}

int Service::filtrare_dupa_titlu(string titlu)
{
	if(this->repo.lungime == 0)
		throw ValidationError("Lista este goala!\n");
	this->repo_copie.clear();
	int rez = 1;
	for(int i = 0; i < repo.lungime; i ++)
		{
			Carte c = repo.lista[i];
		if (c.get_titlu().compare(titlu) == 0)
		{
			this->repo_copie.adauga_carte(c);
			rez = 0;
		}
				
	}
	return rez;
}


int Service::filtrare_dupa_an_aparitie(int an_aparitie)
{
	validator.validare_an(an_aparitie);
	if (this->repo.lungime == 0)
		throw ValidationError("Lista este goala!\n");

	this->repo_copie.clear();
	int rez = 1;
	for (int i = 0; i < repo.lungime; i++)
	{
		Carte c = repo.lista[i];
		if (c.get_anul_aparitiei() == an_aparitie)
		{
			this->repo_copie.adauga_carte(c);
			rez = 0;
		}

	}
	return rez;
}

void Service::copie_vector_principat_in_vector_copie() {
	for (int i = 0; i < repo.lungime; i++)
	{
		Carte c = repo.lista[i];
		this->repo_copie.adauga_carte(c);
	}

}


int Service::sortare_dupa_titlu()
{
	if(this->repo.lungime == 0)
		throw ValidationError("Lista este goala!\n");

	this -> repo_copie.clear();

	copie_vector_principat_in_vector_copie();

	for (int i = 0; i < this->repo_copie.lungime; i++)
	{
		for(int j = i+1; j < this -> repo_copie.lungime; j ++)
			if (this->repo_copie.lista[i].get_titlu().compare(this->repo_copie.lista[j].get_titlu()) > 0)
			{
				std::swap(repo_copie.lista[i], repo_copie.lista[j]);
			}
	}

	return 0;
}


int Service::sortare_dupa_autor()
{
	if (this->repo.lungime == 0)
		throw ValidationError("Lista este goala!\n");

	this->repo_copie.clear();

	copie_vector_principat_in_vector_copie();

	for (int i = 0; i < this->repo_copie.lungime; i++)
	{
		for (int j = i+1; j < this->repo_copie.lungime; j++)
			if (this-> repo_copie.lista[i].get_autor().compare(this-> repo_copie.lista[j].get_autor()) > 0)
			{
				std::swap(repo_copie.lista[i], repo_copie.lista[j]);
			}
	}

	return 0;
}

int Service::sortare_an_si_gen()
{
	if (this->repo.lungime == 0)
		throw ValidationError("Lista este goala!\n");


	this->repo_copie.clear();

	copie_vector_principat_in_vector_copie();

	for (int i = 0; i < this->repo_copie.lungime; i++)
	{
		for (int j = i+1; j < this->repo_copie.lungime; j++)
			if (this->repo_copie.lista[i].get_anul_aparitiei() > this->repo_copie.lista[j].get_anul_aparitiei())
			{
				std::swap(repo_copie.lista[i], repo_copie.lista[j]);
			}
			else
			{
				if (this->repo_copie.lista[i].get_anul_aparitiei() == this->repo_copie.lista[j].get_anul_aparitiei())
					if (this->repo_copie.lista[i].get_gen().compare(this->repo_copie.lista[j].get_gen()) > 0)
					{
						std::swap(repo_copie.lista[i], repo_copie.lista[j]);
					}
			}
			
	}

	return 0;

}