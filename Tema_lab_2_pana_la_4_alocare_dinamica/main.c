#include <stdio.h>
#include "UI.h"
#define _CRTDBG_MAP_ALLOC
#include "Service.h"
#include "Tests.h"
#include "lista_produse.h"
#include <crtdbg.h>

int main()
{
	vector_elemente vector = creaza_vector_gol();

	Test_all(&vector);
	
	user_interface(&vector);


	distruge_vector(&vector);
	_CrtDumpMemoryLeaks();
	
	return 0;
}