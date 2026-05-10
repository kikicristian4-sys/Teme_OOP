#include "validare.h"
#include "chrono"
#include "Errors.h"

int Validare::validare_id(int id)
{
	if (id < 0)
		throw ValidationError("Id_ul dat este negativ!\n");
	return 0;
}

int Validare::validare_an(int an)
{
	if (an < 0)
		throw ValidationError("Anul dat este negativ!\n");
	
	return 0;
}