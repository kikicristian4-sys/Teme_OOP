#include "Teste.h"
#include "Service.h"
#include "Carte.h"
#include "Repository.h"
#include <iostream>
#include <assert.h>
#include "Errors.h"

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

	try{service.repo.cautare_carte_specifica("Amsterdam", "Big Man", "Documentary", 1999);
		assert(false);
		}
	catch (ValidationError& err)
	{
		assert(err.get_Message().compare(" ") != 0);
		assert(true);
		}
	

	try {
		service.repo.modificare_an_aparitie(10, 2000);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}
	
	try {
		service.repo.modificare_autor(10, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}
	
	try {
		service.repo.modificare_titlu(10, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	try {
		service.repo.modificare_gen(10, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	try {
		service.repo.sterge_carte(2);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}



	Carte carte1{ 1,"Amsterdam", "Big Man", "Documentary", 1999 };
	
	
	assert(service.repo.adauga_carte(carte1) == 0);
	try {
		service.repo.sterge_carte(2);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}
	

	Carte carte2{ 10,"Am", "Man", "Doc", 1910 };
	assert(service.repo.adauga_carte(carte2) == 0);
	
	Carte carte3{ 10,"A", "Mn", "Dc", 1910 };
	Carte carte4{ 9, "Am", "Man", "Doc", 1910};
	
	try {
		service.repo.adauga_carte(carte3);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	try {
		service.repo.adauga_carte(carte4);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}



	assert(service.repo.modificare_an_aparitie(10,2000) == 0);
	
	try {
		service.repo.modificare_an_aparitie(20, 2000);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	assert(service.repo.modificare_autor(10, "Mos_Martin") == 0);
	
	try {
		service.repo.modificare_autor(20, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	assert(service.repo.modificare_titlu(10, "Mos_Martin") == 0);
	
	try {
		service.repo.modificare_titlu(20, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	assert(service.repo.modificare_gen(10, "Mos_Martin") == 0);
	
	try {
		service.repo.modificare_gen(20, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}





	assert (service.repo.cautare_carte_specifica("Amsterdam", "Big Man", "Documentary", 1999) == 1);


	assert (service.repo.cautare_carte_specifica("Mos_Martin", "Mos_Martin", "Mos_Martin", 2000) == 10);

	assert(service.repo.cautare_carte_specifica("Amsterdam", "Big Man", "Documentry", 1999) == 0);

	
	try {
		service.repo.sterge_carte(2);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	assert(service.repo.sterge_carte(10) == 0);
	assert(service.repo.sterge_carte(1) == 0);
}

void Teste::Test_service(Service& service)
{
	try {
		service.sortare_dupa_titlu();
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.sortare_dupa_autor();
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	try {
		service.sortare_an_si_gen();
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.filtrare_dupa_titlu("A");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.filtrare_dupa_an_aparitie(1900);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	try {
		service.cautare_carte_specifica_service("Amsterdam", "Big Man", "Documentary", 1999);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.modificare_an_aparitie_service(10, 2000);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.modificare_autor_service(10, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.modificare_titlu_service(10, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.modificare_gen_service(10, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.sterge_carte_service(2);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	
	try {
		service.adauga_carte_service(-1, "A", "Big Man", "Documentary", 1999);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	
	try {
		service.adauga_carte_service(1, "A", "Big Man", "Documentary", -1999);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.adauga_carte_service(1, "A", "Big Man", "Documentary", 6000);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	assert(service.adauga_carte_service(1, "A", "Big Man", "Documentary", 1999) == 0);
	
	try {
		service.adauga_carte_service(2, "A", "Big Man", "Documentary", 1999);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	assert(service.adauga_carte_service(10, "Am", "Man", "Doc", 1910) == 0);
	assert(service.adauga_carte_service(26, "A", "M", "Dar", 1910) == 0);

	
	try {
		service.adauga_carte_service(10, "A", "Mos_Martin", "Dc", 1910);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}




	assert(service.modificare_an_aparitie_service(10, 2000) == 0);
	
	try {
		service.modificare_an_aparitie_service(10, -2000);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	try {
		service.modificare_an_aparitie_service(-10, 2000);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.modificare_an_aparitie_service(20, 2000);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	assert(service.modificare_an_aparitie_service(10, 1910) == 0);

	assert(service.modificare_autor_service(10, "Mos_Martin") == 0);
	
	try {
		service.modificare_autor_service(-10, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.modificare_autor_service(20, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	assert(service.modificare_titlu_service(10, "Mos_Martin") == 0);
	
	try {
		service.modificare_titlu_service(-10, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.modificare_titlu_service(20, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	assert(service.modificare_gen_service(10, "Mos_Martin") == 0);
	
	try {
		service.modificare_gen_service(-10, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.modificare_gen_service(20, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}



	//Incepe testarea filtrarilor si sortarilor

	assert(service.filtrare_dupa_an_aparitie(1900) == 1);
	assert(service.filtrare_dupa_an_aparitie(1999) == 0);

	for (int i = 0; i < service.repo_copie.lungime; i++)
	{
		Carte c = service.repo_copie.lista[i];
		
		assert(c.get_id() == 1);
		assert(c.get_titlu().compare("A") == 0);
		assert(c.get_autor().compare("Big Man") == 0);
		assert(c.get_gen().compare("Documentary") == 0);
		assert(c.get_anul_aparitiei() == 1999);
	}

	assert(service.filtrare_dupa_titlu("B") == 1);
	assert(service.filtrare_dupa_titlu("A") == 0);
	for (int i = 0; i < service.repo_copie.lungime; i++)
	{
		Carte c = service.repo_copie.lista[i];
		assert(c.get_id() == 1 || c.get_id() == 26);
	}


	//Teste sortari: 
	int nr = 0;
	assert(service.sortare_an_si_gen() == 0);

	nr = 0;
	for (int i = 0; i < service.repo_copie.lungime; i++)
	{
		Carte c = service.repo_copie.lista[i];
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

	for (int i = 0; i < service.repo_copie.lungime; i++)
	{
		Carte c = service.repo_copie.lista[i];
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

	for (int i = 0; i < service.repo_copie.lungime; i++)
	{
		Carte c = service.repo_copie.lista[i];
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

	assert (service.cautare_carte_specifica_service("A", "Big Man", "Documentary", 1999) == 1);

	
	try {
		service.cautare_carte_specifica_service("A", "Big Man", "Documentary", -1999);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	assert(service.cautare_carte_specifica_service("Mos_Martin", "Mos_Martin", "Mos_Martin", 1910) == 10 );

	assert(service.cautare_carte_specifica_service("Amsterdam", "Big Man", "Documentary", 1999) == 0);

	try {
		service.sterge_carte_service(-2);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	
	try {
		service.sterge_carte_service(2);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

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