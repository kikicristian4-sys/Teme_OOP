#include "Teste.h"
#define _CRTDBG_MAP_ALLOC
#include "Service.h"
#include "UI.h"
#include <crtdbg.h>



int main()
{

	{
		Service service;
		Teste Tests;
		//UI ui;
		Tests.Testeaza_tot(service);
		//ui.meniu_utilizator(service);

	}
	if (_CrtDumpMemoryLeaks() == 1)
		printf("Exista memory leaks!!");
	else
		printf("Nu exista memory leak-uri, YAAAY :D");
}