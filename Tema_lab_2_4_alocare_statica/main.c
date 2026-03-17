#include <stdio.h>
#include "UI.h"
#include "Service.h"
#include "Tests.h"
#include "lista_produse.h"

int main()
{
	vector_elemente vector = creaza_vector_gol();

	Test_all(&vector);
	
	user_interface(&vector);

	return 0;


}