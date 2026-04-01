#pragma once
class Validare {

private:

/*
	Functie ce returneaza anul curent
	pre: -
	post: returneaza un int ce reprezinta anul in care traim
*/
int get_current_year();


public:

/*
	Functie de validare a unui id
	pre: id - type int
	post: functia returneaza 0 daca id-ul corespunde, -10 daca este negativ
*/
int validare_id(int id);

/*
	Functie de validare a unui an
	pre: an - type int
	post: functia returneaza 0 daca anul corespunde, -10 daca este negativ, -20 daca trece de anul curent
*/
int validare_an(int an);

};