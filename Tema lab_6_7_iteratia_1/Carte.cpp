#include "Carte.h"
#include <string>


int Carte::get_id() const {
	return this->id;
}

string Carte::get_titlu() const{
	return this->titlu;
}

string Carte::get_autor() const {
	return this -> autor;
}

string Carte::get_gen() const {
	return this -> gen;
}

int Carte::get_anul_aparitiei() const {
	return this -> anul_aparitiei;
}

void Carte::modifica_titlu(string titlu_nou) {
	this -> titlu = titlu_nou;
}

void Carte::modifica_autor(string autor_nou) {
	this -> autor = autor_nou;
}
void Carte::modifica_gen(string gen_nou) {
	this -> gen = gen_nou;
}

void Carte::modifica_an_aparitie(int an_nou) {
	this -> anul_aparitiei = an_nou;
}
