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

	//Functie de testare a constructorilor si a assigner-ilor
	void Test_cpy_create_move_asign();
public:
	//Functie ce apeleaza toate celelalte functii de test
	void Testeaza_tot(Service& service);


};