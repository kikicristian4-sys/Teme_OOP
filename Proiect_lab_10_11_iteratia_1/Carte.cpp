#include "Carte.h"
#include <string>

void Carte_dto::crestere_frecventa() noexcept
{
	frecventa_autor++;
}



int Carte_dto::get_frecventa() noexcept
{
	return frecventa_autor;
}

int Carte::get_id()  const noexcept {
	return this->id;
}



string Carte::get_titlu() const {
	return this->titlu;
}

string Carte::get_autor() const {
	return this->autor;
}

string Carte::get_gen() const {
	return this->gen;
}

int Carte::get_anul_aparitiei() const noexcept {
	return this->anul_aparitiei;
}

void Carte::modifica_titlu(string titlu_nou) {
	this->titlu = titlu_nou;
}

void Carte::modifica_autor(string autor_nou) {
	this->autor = autor_nou;
}
void Carte::modifica_gen(string gen_nou) {
	this->gen = gen_nou;
}

void Carte::modifica_an_aparitie(int an_nou) noexcept {
	this->anul_aparitiei = an_nou;
}