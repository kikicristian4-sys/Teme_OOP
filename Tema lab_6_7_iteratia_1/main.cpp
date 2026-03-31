#include "Teste.h"
#include "Service.h"
#include "UI.h"



int main()
{

	Service service;
	Teste Tests;
	UI ui;
	Tests.Testeaza_tot(service);
	ui.meniu_utilizator(service);
}