#include "Teste.h"
#include "Service.h"
#include "Carte.h"
#include "Repository.h"
#include <iostream>
#include <assert.h>
#include "Errors.h"
#include <fstream>
#include <string>
#include "UI.h"

void Teste::Test_clasa_carte()
{
	Carte carte1{ 1,"Amsterdam", "Big Man", "Documentary", 1999 };

	assert(carte1.get_id() == 1);
	assert(carte1.get_anul_aparitiei() == 1999);
	assert(carte1.get_autor() == "Big Man");
	assert(carte1.get_gen() == "Documentary");
	assert(carte1.get_titlu() == "Amsterdam");

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

void Teste::Test_Undo(Service& service)
{
	try {
	service.undo();
	assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	assert(service.adauga_carte_service(1, "A", "Big Man", "Documentary", 1999) == 0);
	service.undo();

	try {
		service.sterge_carte_service(23);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}
	assert(service.adauga_carte_service(1, "A", "Big Man", "Documentary", 1999) == 0);

	assert(service.modificare_titlu_service(1, "Abraham") == 0);
	assert(service.modificare_autor_service(1, "Abraham") == 0);
	assert(service.modificare_gen_service(1, "Abraham") == 0);
	assert(service.modificare_an_aparitie_service(1, 2000) == 0);

	assert(service.cautare_carte_specifica_service("Abraham", "Abraham", "Abraham", 2000) == 1);
	service.undo();
	assert(service.cautare_carte_specifica_service("Abraham", "Abraham", "Abraham",1999) == 1);
	service.undo();
	assert(service.cautare_carte_specifica_service("Abraham", "Abraham", "Documentary", 1999) == 1);
	service.undo();
	assert(service.cautare_carte_specifica_service("Abraham", "Big Man", "Documentary", 1999) == 1);
	service.undo();
	assert(service.cautare_carte_specifica_service("A", "Big Man", "Documentary", 1999) == 1);

	service.sterge_carte_service(1);

	try {
		service.cautare_carte_specifica_service("A", "Big Man", "Documentary", 1999);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	service.undo();
	assert(service.cautare_carte_specifica_service("A", "Big Man", "Documentary", 1999) == 1);

	service.sterge_carte_service(1);

}


void Teste::Test_repo(Service& service) {

	try {
		service.repo.cautare_carte_specifica("Amsterdam", "Big Man", "Documentary", 1999);
		assert(false);
	}
	catch (const ValidationError& err)
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
	Carte carte4{ 9, "Am", "Man", "Doc", 1910 };

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



	service.repo.modificare_an_aparitie(10, 2000);

	try {
		service.repo.modificare_an_aparitie(20, 2000);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	service.repo.modificare_autor(10, "Mos_Martin");

	try {
		service.repo.modificare_autor(20, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	service.repo.modificare_titlu(10, "Mos_Martin");

	try {
		service.repo.modificare_titlu(20, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	service.repo.modificare_gen(10, "Mos_Martin");

	try {
		service.repo.modificare_gen(20, "Mos_Martin");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}





	assert(service.repo.cautare_carte_specifica("Amsterdam", "Big Man", "Documentary", 1999) == 1);


	assert(service.repo.cautare_carte_specifica("Mos_Martin", "Mos_Martin", "Mos_Martin", 2000) == 10);

	assert(service.repo.cautare_carte_specifica("Amsterdam", "Big Man", "Documentry", 1999) == 0);


	try {
		service.repo.sterge_carte(2);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	service.repo.sterge_carte(10);
	service.repo.sterge_carte(1);
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

	for (const Carte& c : service.lista_copie)
	{

		assert(c.get_id() == 1);
		assert(c.get_titlu().compare("A") == 0);
		assert(c.get_autor().compare("Big Man") == 0);
		assert(c.get_gen().compare("Documentary") == 0);
		assert(c.get_anul_aparitiei() == 1999);
	}

	assert(service.filtrare_dupa_titlu("B") == 1);
	assert(service.filtrare_dupa_titlu("A") == 0);
	for (const Carte& c : service.lista_copie)
	{
		assert(c.get_id() == 1 || c.get_id() == 26);
	}


	//Teste sortari: 
	int nr = 0;
	assert(service.sortare_an_si_gen() == 0);

	nr = 0;
	for (const Carte& c : service.lista_copie)
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
			assert(c.get_id() == 26);
			nr++;
		}


	}

	nr = 0;
	assert(service.sortare_dupa_autor() == 0);

	for (const Carte& c : service.lista_copie)
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

	for (const Carte& c : service.lista_copie)
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


	//Testare frecventa

	service.adauga_carte_service(12, "A", "Mos_Martin", "Documentary", 1925);

	std::unordered_map <std::string, Carte_dto> harta;
	

	harta = service.frecventa_autor();
	assert(harta.at("Mos_Martin").get_frecventa() == 2);
	assert(harta.at("Big Man").get_frecventa() == 1);
	UI ui;
	ui.afisare_harta(harta,1);

	service.sterge_carte_service(12);
	//Final testare frecventa
	assert(service.cautare_carte_specifica_service("A", "Big Man", "Documentary", 1999) == 1);


	try {
		service.cautare_carte_specifica_service("A", "Big Man", "Documentary", -1999);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}

	assert(service.cautare_carte_specifica_service("Mos_Martin", "Mos_Martin", "Mos_Martin", 1910) == 10);

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

void Teste::Test_cos()
{

	//Testare adaugare
	Cos cos;
	Carte carte1{ 1,"Amsterdam", "Big Man", "Documentary", 1999 };
	Carte carte2{ 23,"Am", "Big", "Doc", 199 };
	cos.adauga_carte_in_cos(carte1);
	assert(cos.lista.size() == 1);
	cos.adauga_carte_in_cos(carte2);
	assert(cos.lista.size() == 2);


	//Testare export lista
	cos.Export("Ionel");

	std::ifstream fin("Ionel");

	std::string s;
	getline(fin, s);
	assert(s.compare("1,Amsterdam,Big Man,Documentary,1999") == 0);
	getline(fin, s);
	assert(s.compare("23,Am,Big,Doc,199") == 0);
	fin.close();

	//Testare golire lista
	cos.goleste_cos();
	assert(cos.lista.size() == 0);

}

void Teste::Test_cos_din_service(Service& service)
{

	assert(service.adauga_carte_service(1, "A", "Big Man", "Documentary", 1999) == 0);
	assert(service.adauga_carte_service(23, "A", "Bian", "Dmentary", 1999) == 0);
	assert(service.adauga_carte_service(76, "B", "Bg Man", "Documtary", 1999) == 0);

	//Testare generare cos

	try {
		service.genereaza_cos(-4);
		assert(false);
	}
	catch (ValidationError&)
	{

		assert(true);
	}

	try {
		service.genereaza_cos(4);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}




	service.genereaza_cos(2);
	assert(service.cos.lista.size() == 2);

	//Test pentru golire cos
	service.goleste_cos_service();
	assert(service.cos.lista.size() == 0);

	//Test pentru adaugare carti


	try {
		service.adauga_carte_in_cos("Ial");
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	assert(service.adauga_carte_in_cos("B") == 0);
	assert(service.adauga_carte_in_cos("A") == 1);

	for (const Carte& c : service.lista_copie)
	{
		assert(c.get_id() == 1 || c.get_id() == 23);
	}

	try {
		service.adauga_carte_in_cos_dupa_id(-1);
		assert(false);
	}
	catch (ValidationError&)
	{
		assert(true);
	}


	service.adauga_carte_in_cos_dupa_id(23);
	assert(service.cos.lista.size() == 2);
	assert(service.cos.lista.at(0).get_id() == 76);
	assert(service.cos.lista.at(1).get_id() == 23);


	//Testarea exportului in fisier din service
	service.export_cos_in_fisier_service("Ionder");
	std::ifstream fin("Ionder");

	string linie;
	getline(fin, linie);

	assert(linie.compare("76,B,Bg Man,Documtary,1999") == 0);
	getline(fin, linie);
	assert(linie.compare("23,A,Bian,Dmentary,1999") == 0);

	service.sterge_carte_service(1);
	service.sterge_carte_service(23);
	service.sterge_carte_service(76);


}

void Teste::Testeaza_tot(Service& service)
{
	
	Teste::Test_clasa_carte();
	Teste::Test_Undo(service);
	Teste::Test_repo(service);
	Teste::Test_service(service);
	Teste::Test_cos();
	Teste::Test_cos_din_service(service);
}