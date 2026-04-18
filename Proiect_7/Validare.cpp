#include "validare.h"
#include "chrono"
#include "Errors.h"

int Validare::validare_id(int id) 
{
	if(id < 0 )
		throw ValidationError("Id_ul dat este negativ!\n");
	return 0;
}

int Validare::get_current_year() noexcept {
	using namespace std::chrono;
	return static_cast<int>(
		year_month_day{ time_point_cast<days>(system_clock::now()) }.year());
}

int Validare::validare_an(int an) 
{
	if(an < 0)
		throw ValidationError("Anul dat este negativ!\n");
	if(an > get_current_year())
		throw ValidationError("Anul dat este mai mare decat anul curent!\n");
	return 0;
}