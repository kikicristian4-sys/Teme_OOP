#include "Teste.h"
#include "Service.h"
#include "Carte.h"
#include "Repository.h"
#include <iostream>
#include <assert.h>

void Teste::Test_clasa_carte()
{
	Carte carte1{1,"Amsterdam", "Big Man", "Documentary", 1999};

	assert(carte1.get_id() == 1);
	assert(carte1.get_anul_aparitiei() == 1999);
	assert (carte1.get_autor() == "Big Man");
	assert (carte1.get_gen() == "Documentary");
	assert (carte1.get_titlu() == "Amsterdam");

	carte1.modifica_an_aparitie(1991);
	assert(carte1.get_anul_aparitiei() == 1991);

	carte1.modifica_autor("Dan");
	assert(carte1.get_autor() == "Dan");

	carte1.modifica_gen("Alfabet");
	assert(carte1.get_gen() == "Alfabet");

	carte1.modifica_titlu("Abcd");
	assert(carte1.get_titlu() == "Abcd");
	assert(carte1.get_id() == 1);
}

void Teste::Test_repo(Service& service) {

	assert(service.repo.cautare_carte_specifica("Amsterdam", "Big Man", "Documentary", 1999) == -1);
	assert(service.repo.modificare_an_aparitie(10, 2000) == 2);
	assert(service.repo.modificare_autor(10, "Mos_Martin") == 2);
	assert(service.repo.modificare_titlu(10, "Mos_Martin") == 2);
	assert(service.repo.modificare_gen(10, "Mos_Martin") == 2);
	assert(service.repo.sterge_carte(2) == 2);



	Carte carte1{ 1,"Amsterdam", "Big Man", "Documentary", 1999 };
	
	
	assert(service.repo.adauga_carte(carte1) == 0);

	

	Carte carte2{ 10,"Am", "Man", "Doc", 1910 };
	assert(service.repo.adauga_carte(carte2) == 0);

	
	Carte carte3{ 10,"A", "Mn", "Dc", 1910 };
	
	assert(service.repo.adauga_carte(carte3) == 1);



	assert(service.repo.modificare_an_aparitie(10,2000) == 0);
	assert(service.repo.modificare_an_aparitie(20, 2000) == 1);

	assert(service.repo.modificare_autor(10, "Mos_Martin") == 0);
	assert(service.repo.modificare_autor(20, "Mos_Martin") == 1);

	assert(service.repo.modificare_titlu(10, "Mos_Martin") == 0);
	assert(service.repo.modificare_titlu(20, "Mos_Martin") == 1);

	assert(service.repo.modificare_gen(10, "Mos_Martin") == 0);
	assert(service.repo.modificare_gen(20, "Mos_Martin") == 1);




	assert(service.repo.cautare_carte_specifica("Amsterdam", "Big Man", "Documentary", 1999) == 1);
	assert(service.repo.cautare_carte_specifica("Mos_Martin", "Mos_Martin", "Mos_Martin", 2000) == 10);
	assert(service.repo.cautare_carte_specifica("Amsterdam", "Big Man", "Documentry", 1999) == 0);

	assert(service.repo.sterge_carte(2) == 1);
	assert(service.repo.sterge_carte(10) == 0);
	assert(service.repo.sterge_carte(1) == 0);
}

void Teste::Test_service(Service& service)
{
	assert(service.sortare_dupa_titlu() == 1);
	assert(service.sortare_dupa_autor() == 1);
	assert(service.sortare_an_si_gen() == 1);
	assert(service.filtrare_dupa_titlu("A") == 2);
	assert(service.filtrare_dupa_an_aparitie(1900) == 2);
	assert(service.cautare_carte_specifica_service("Amsterdam", "Big Man", "Documentary", 1999) == -1);
	assert(service.modificare_an_aparitie_service(10, 2000) == 2);
	assert(service.modificare_autor_service(10, "Mos_Martin") == 2);
	assert(service.modificare_titlu_service(10, "Mos_Martin") == 2);
	assert(service.modificare_gen_service(10, "Mos_Martin") == 2);
	assert(service.sterge_carte_service(2) == 2);


	assert(service.adauga_carte_service(1, "A", "Big Man", "Documentary", 1999) == 0);

	assert(service.adauga_carte_service(10, "Am", "Man", "Doc", 1910) == 0);
	assert(service.adauga_carte_service(26, "A", "M", "Dar", 1910) == 0);

	assert(service.adauga_carte_service(10, "A", "Mos_Martin", "Dc", 1910) == 1);



	assert(service.modificare_an_aparitie_service(10, 2000) == 0);
	assert(service.modificare_an_aparitie_service(20, 2000) == 1);
	assert(service.modificare_an_aparitie_service(10, 1910) == 0);

	assert(service.modificare_autor_service(10, "Mos_Martin") == 0);
	assert(service.modificare_autor_service(20, "Mos_Martin") == 1);

	assert(service.modificare_titlu_service(10, "Mos_Martin") == 0);
	assert(service.modificare_titlu_service(20, "Mos_Martin") == 1);

	assert(service.modificare_gen_service(10, "Mos_Martin") == 0);
	assert(service.modificare_gen_service(20, "Mos_Martin") == 1);


	//Incepe testarea filtrarilor si sortarilor

	assert(service.filtrare_dupa_an_aparitie(1900) == 1);
	assert(service.filtrare_dupa_an_aparitie(1999) == 0);
	for (Carte& c : service.lista_copie)
	{
		assert(c.get_id() == 1);
		assert(c.get_titlu().compare("A") == 0);
		assert(c.get_autor().compare("Big Man") == 0);
		assert(c.get_gen().compare("Documentary") == 0);
		assert(c.get_anul_aparitiei() == 1999);
	}

	assert(service.filtrare_dupa_titlu("B") == 1);
	assert(service.filtrare_dupa_titlu("A") == 0);
	for (Carte& c : service.lista_copie)
	{
		assert(c.get_id() == 1 || c.get_id() == 26);
	}


	//Teste sortari: 
	int nr;
	assert(service.sortare_an_si_gen() == 0);

	nr = 0;
	for (Carte& c : service.lista_copie)
	{
		if (nr == 2)
			assert(c.get_id() == 1);
		if (nr == 1)
		{
			
			assert(c.get_id() == 10);
			nr++;
		}

		if (nr == 0)
		{
			
		assert(c.get_id() ==26);
		nr++;
		}
		
		
	}

	nr = 0;
	assert(service.sortare_dupa_autor() == 0);

	for (Carte& c : service.lista_copie)
	{
		if (nr == 2)
			assert(c.get_id() == 10);
		if (nr == 1)
		{
			assert(c.get_id() == 26);
			nr++;
		}
		
		if (nr == 0)
		{
			assert(c.get_id() == 1);
			nr++;
		}
		
	}

	nr = 0;
	assert(service.sortare_dupa_titlu() == 0);

	for (Carte& c : service.lista_copie)
	{
		if (nr == 2)
			assert(c.get_id() == 10);
		if (nr == 1)
		{
			assert(c.get_id() == 26);
			nr++;
		}
		
		if (nr == 0)
		{
			assert(c.get_id() == 1);
			nr++;
		}
		
		
	}


	//Final testare filtrari si sortari

	assert(service.cautare_carte_specifica_service("A", "Big Man", "Documentary", 1999) == 1);
	assert(service.cautare_carte_specifica_service("Mos_Martin", "Mos_Martin", "Mos_Martin", 1910) == 10);
	assert(service.cautare_carte_specifica_service("Amsterdam", "Big Man", "Documentary", 1999) == 0);

	assert(service.sterge_carte_service(2) == 1);
	assert(service.sterge_carte_service(10) == 0);
	assert(service.sterge_carte_service(1) == 0);
	assert(service.sterge_carte_service(26) == 0);
}




void Teste::Testeaza_tot(Service& service)
{
	Teste::Test_clasa_carte();
	Teste::Test_repo( service);
	Teste::Test_service(service);

}