#include "Cos.h"
#include <fstream>

void Cos::adauga_carte_in_cos(const Carte& c)
{
	lista.push_back(c);
}

void Cos::goleste_cos() noexcept
{
	lista.clear();
}

void Cos::Export(string nume)
{
	std::ofstream fout(nume);
	for (const Carte& c : lista)
	{
		fout<<c.get_id()<<',' << c.get_titlu() << ',' << c.get_autor() << ',' << c.get_gen() << ',' << c.get_anul_aparitiei()<<std::endl;
	}
	fout.close();
}