#pragma once
#include "Service.h"
class Teste {

private:
	//Functie de test a clasei Undo
	void Test_Undo(Service& service);
	//Functie de test a clasei de carti
	void Test_clasa_carte();

	//Funcite de test a repository-ului
	void Test_repo(Service& service);

	//Functie de testare a service-ului
	void Test_service(Service& service);

	//Functie de testare a constructorilor si a assigner-ilor
	void Test_cpy_create_move_asign();
	//Functie ce testeaza un cos
	void Test_cos();
	//Functie ce testeaza functiile din service ce au legatura cu Cos-ul
	void Test_cos_din_service(Service& service);
public:
	//Functie ce apeleaza toate celelalte functii de test
	void Testeaza_tot(Service& service);


};