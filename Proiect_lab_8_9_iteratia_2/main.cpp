#include "Teste.h"
#define _CRTDBG_MAP_ALLOC
#include "Service.h"
#include "UI.h"
#include <crtdbg.h>



int main()
{

	{
		Service service_test("Storage_test.txt");
		Teste Tests;
		UI ui;
		Tests.Testeaza_tot(service_test);
		Service service_oficial("Storage.txt");
		ui.meniu_utilizator(service_oficial);

	}
	if (_CrtDumpMemoryLeaks() == 1)
		printf("Exista memory leaks!!");
	else
		printf("Nu exista memory leak-uri, YAAAY :D");
}