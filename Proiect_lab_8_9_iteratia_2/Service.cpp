#include "Service.h"
#include "Errors.h"
#include <iostream>
#include <algorithm>


std::unordered_map <std::string, Carte_dto> Service::frecventa_autor()
{
	vector <Carte> lista = repo.citire_din_fisier();


	std::unordered_map <std::string, Carte_dto> harta;
	for (const Carte& c : lista)
	{
		Carte_dto DTO (c.get_autor());
		if(harta.find(c.get_autor()) != harta.end())
			harta.at(c.get_autor()).crestere_frecventa();
		else
		{
			harta.insert({c.get_autor(), DTO});
		}
	}
	
	
	return harta;
}

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
	vector <Carte> lista = repo.citire_din_fisier();

	if (n < 0)
		throw ValidationError("N este un numar negativ sau egal cu 0!\n");

	if (n > lista.size())
		throw ValidationError("N este mai mare decat numarul de elemente din lista!\n");
	
		

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
	vector <Carte> lista = repo.citire_din_fisier();


	this->lista_copie.clear();
	int nr_carti = 0;
	const Carte* carte = nullptr;
	for (const Carte& c : lista)
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
	vector <Carte> lista = repo.citire_din_fisier();


	if (id < 0)
		throw ValidationError("ID-ul este un numar negativ!\n");

	for (const Carte& c : lista)
	{
		if (c.get_id() == id)
		{
			cos.adauga_carte_in_cos(c);
			return;
		}
	}
}

void Service::adauga_carte_service(int id, string titlu, string autor, string gen, int an_aparitie)
{
	validator.validare_id(id);
	validator.validare_an(an_aparitie);
	Carte carte1(id, titlu, autor, gen, an_aparitie);

	
	this->repo.adauga_carte(carte1);
	undoActions.push_back(new UndoAdauga{carte1, repo});
}

int Service::sterge_carte_service(int id)
{
	validator.validare_id(id);
	Carte copie_carte;

	copie_carte = this->repo.sterge_carte(id);
	undoActions.push_back(new UndoStergere{copie_carte, repo});
	return 0;
}

int Service::modificare_titlu_service(int id, string titlu)
{
	validator.validare_id(id);
	Carte carte;
	 carte = this->repo.modificare_titlu(id, titlu);
	 undoActions.push_back(new UndoModificare(carte,repo));
	return 0;
}

int Service::modificare_autor_service(int id, string autor)
{
	validator.validare_id(id);
	Carte carte;
	carte = this->repo.modificare_autor(id, autor);
	undoActions.push_back(new UndoModificare(carte, repo));
	return 0;
}

int Service::modificare_gen_service(int id, string gen)
{
	validator.validare_id(id);
	Carte carte;
	carte = this->repo.modificare_gen(id, gen);
	undoActions.push_back(new UndoModificare(carte, repo));
	return 0;
}

int Service::modificare_an_aparitie_service(int id, int an_nou)
{
	validator.validare_id(id);
	validator.validare_an(an_nou);
	Carte carte;
	carte = this->repo.modificare_an_aparitie(id, an_nou);
	undoActions.push_back(new UndoModificare(carte, repo));
	return 0;
}

int Service::cautare_carte_specifica_service(string ti, string au, string g, int an)
{
	validator.validare_an(an);
	return this->repo.cautare_carte_specifica(ti, au, g, an);
}

int Service::filtrare_dupa_titlu(string titlu)
{
	vector <Carte> lista = repo.citire_din_fisier();

	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");
	this->lista_copie.clear();
	int rez = 1;
	for (const Carte& c : lista)
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
	vector <Carte> lista = repo.citire_din_fisier();


	validator.validare_an(an_aparitie);
	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");

	this->lista_copie.clear();
	int rez = 1;
	for (const Carte& c : lista)
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
	vector <Carte> lista = repo.citire_din_fisier();


	for (const Carte& c : lista)
	{
		this->lista_copie.push_back(c);
	}

}

int Service::sortare_dupa_titlu()
{	
	vector <Carte> lista = repo.citire_din_fisier();

	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");

	this->lista_copie.clear();

	copie_vector_principat_in_vector_copie();


	std::sort(lista_copie.begin(), lista_copie.end(), [](const Carte &x, const Carte &y)
	{return x.get_titlu().compare(y.get_titlu()) < 0;});
	/*
	 for (int i = 0; i < this->lista_copie.size(); i++)
	{
		for (int j = i + 1; j < this->lista_copie.size(); j++)
			if (this->lista_copie.at(i).get_titlu().compare(this->lista_copie.at(j).get_titlu()) > 0)
			{
				std::swap(lista_copie.at(i), lista_copie.at(j));
			}
	}
	*/
	

	return 0;
}


int Service::sortare_dupa_autor()
{
	vector <Carte> lista = repo.citire_din_fisier();


	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");

	this->lista_copie.clear();

	copie_vector_principat_in_vector_copie();

	std::sort(lista_copie.begin(), lista_copie.end(), [](const Carte& x, const Carte& y)
		{return x.get_autor().compare(y.get_autor()) < 0;});

		/*
		for (int i = 0; i < this->lista_copie.size(); i++)
		{
		for (int j = i + 1; j < this->lista_copie.size(); j++)
			if (this->lista_copie.at(i).get_autor().compare(this->lista_copie.at(j).get_autor()) > 0)
			{
				std::swap(lista_copie.at(i), lista_copie.at(j));
			}
		}
		*/
	

	return 0;
}

int Service::sortare_an_si_gen()
{
	vector <Carte> lista = repo.citire_din_fisier();

	if (lista.size() == 0)
		throw ValidationError("Lista este goala!\n");


	this->lista_copie.clear();

	copie_vector_principat_in_vector_copie();
	
	std::sort(lista_copie.begin(), lista_copie.end(), [](const Carte& x, const Carte& y)
		{if(x.get_anul_aparitiei() == y.get_anul_aparitiei())
			return x.get_gen().compare(y.get_gen()) < 0;
		else
			return x.get_anul_aparitiei() < y.get_anul_aparitiei();
			});
	
	/*
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
	
	*/
	

	return 0;

}

void Service::undo() {
	if (undoActions.empty()) {
		throw ValidationError{ "Nu mai exista operatii" };
	}
	ActiuneUndo* act = undoActions.back();
	act->doUndo(); 
	undoActions.pop_back();
	delete act;
}