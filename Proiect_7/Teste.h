#pragma once
#include "Service.h"
class Teste {

private:
	//Functie de test a clasei de carti
	void Test_clasa_carte();

	//Funcite de test a repository-ului
	void Test_repo(Service& service);

	//Functie de testare a service-ului
	void Test_service(Service& service);
public:
	//Functie ce apeleaza toate celelalte functii de test
	void Testeaza_tot(Service& service);


};