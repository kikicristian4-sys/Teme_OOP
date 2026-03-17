#include <stdio.h>
#include "UI.h"
#include "Service.h"
#include "Tests.h"
#include "lista_produse.h"
#include <crtdbg.h>

int main()
{
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	vector_elemente vector = creaza_vector_gol();

	Test_all(&vector);
	
	user_interface(&vector);

	return 0;
}