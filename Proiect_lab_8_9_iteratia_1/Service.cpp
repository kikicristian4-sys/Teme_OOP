#include "Service.h"
#include "Errors.h"
#include <iostream>

void Service::goleste_cos_service() noexcept
{
	cos.goleste_cos();
}


void Service::export_cos_in_fisier_service(string nume)
{
	cos.Export(nume);
}

void Service::genereaza_cos(int n)
{
	if (n > repo.lista.size())
		throw ValidationError("N este mai mare decat numarul de elemente din lista!\n");
	if (n < 0)
		throw ValidationError("N este un numar negativ!\n");

	copie_vector_principat_in_vector_copie();

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(lista_copie.begin(), lista_copie.end(), std::default_random_engine(static_cast<int>(seed))); //amesteca vectorul 

	int i = 0;
	for (const Carte& c : lista_copie)
	{
		if(i < n)
			cos.adauga_carte_in_cos(c);
		else
			break;
		i++;
	}
}
int Service::adauga_carte_in_cos(string titlu)
{
	this->lista_copie.clear();
	int nr_carti = 0;
	const  Carte* carte = nullptr;
	for (const Carte& c : repo.lista)
	{
		if ((c.get_titlu()).compare(titlu) == 0)
		{
			nr_carti ++;
			this->lista_copie.push_back(c);
			carte = &c;
		}
	}

	if (nr_carti == 1)
	{
		Carte c(carte->get_id(),carte->get_titlu(), carte->get_autor(), carte->get_gen(), carte->get_anul_aparitiei());
		cos.adauga_carte_in_cos(c);
		return 0;
	}
	if(nr_carti == 0)
		throw ValidationError("Nici o carte nu a fost gasita care sa aibe titlul dat!\n");
	return 1;
}

void Service::adauga_carte_in_cos_dupa_id(int id)
{
	if (id < 0)
		throw ValidationError("ID-ul este un numar negativ!\n");

	for (const Carte& c : repo.lista)
	{
		if (c.get_id() == id)
		{
			cos.adauga_carte_in_cos(c);
			return;
		}
	}
}

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
	return this->repo.modificare_titlu(id, titlu);
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
	return this->repo.modificare_an_aparitie(id, an_nou);
}

int Service::cautare_carte_specifica_service(string ti, string au, string g, int an)
{
	validator.validare_an(an);
	return this->repo.cautare_carte_specifica(ti, au, g, an);
}

int Service::filtrare_dupa_titlu(string titlu)
{
	if (this->repo.lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
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
	validator.validare_an(an_aparitie);
	if (this->repo.lista.size() == 0)
		throw ValidationError("Lista este goala!\n");

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
	if (this->repo.lista.size() == 0)
		throw ValidationError("Lista este goala!\n");

	this->lista_copie.clear();

	copie_vector_principat_in_vector_copie();

	for (int i = 0; i < this->lista_copie.size(); i++)
	{
		for (int j = i + 1; j < this->lista_copie.size(); j++)
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
		throw ValidationError("Lista este goala!\n");

	this->lista_copie.clear();

	copie_vector_principat_in_vector_copie();

	for (int i = 0; i < this->lista_copie.size(); i++)
	{
		for (int j = i + 1; j < this->lista_copie.size(); j++)
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
		throw ValidationError("Lista este goala!\n");


	this->lista_copie.clear();

	copie_vector_principat_in_vector_copie();

	for (int i = 0; i < this->lista_copie.size(); i++)
	{
		for (int j = i + 1; j < this->lista_copie.size(); j++)
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