#include "validare.h"
#include "chrono"

int Validare::validare_id(int id)
{
	if(id < 0 )
		return -10;
	return 0;
}

int Validare::get_current_year() {
	using namespace std::chrono;
	return static_cast<int>(
		year_month_day{ time_point_cast<days>(system_clock::now()) }.year());
}

int Validare::validare_an(int an)
{
	if(an < 0)
		return -30;
	if(an > get_current_year())
		return -40;
	return 0;
}