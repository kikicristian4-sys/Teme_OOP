#pragma once
#include <string>

using std::string;


class Carte {

private:
	int id;
	string titlu;
	string autor;
	string gen;
	int anul_aparitiei;


public:
	//Constructor implicit
	Carte() = default;

	/*
		Functie de construire a unei carti
		pre: id_ul - int titlu - string, autor - string, gen - string, an - int
		post: se creaza cartea
	*/
	Carte(int id_ul, string ti, string au, string g, int an) :id{id_ul}, titlu{ ti }, autor{ au }, gen{ g }, anul_aparitiei{ an }{};

	//Constructorul de copiere
	Carte(const Carte& alt) : id{alt.id}, titlu{ alt.titlu}, autor{alt.autor}, gen{alt.gen}, anul_aparitiei{alt.anul_aparitiei}{};

	/*
		Functie ce returneaza titlul unei carti
		pre: -
		post: se returneaza titlul cartii
	*/
	string get_titlu() const;


	/*
		Functie ce returneaza id-ul unei carti
		pre: 
		post: se returneaza id-ul cartii
	*/
	int get_id() const;

	/*
	Functie ce returneaza autorul unei carti
	pre: -
	post: se returneaza autorul cartii
	*/
	string get_autor() const;

	/*
	Functie ce returneaza genul unei carti
	pre:-
	post: se returneaza genul cartii
	*/
	
	string get_gen() const;


	/*
	Functie ce returneaza anul aparitiei unei carti
	pre: -
	post: se returneaza anul aparitiei cartii
	*/
	int get_anul_aparitiei() const;	

	/*
		Functie de modificare a titlului unei carti
		pre: titlu_nou - type string
		post: in carte se modifica valoarea initiala cu valoarea noua din argument
	*/
	void modifica_titlu(const string titlu_nou);

	/*
		Functie de modificare a autorului unei carti
		pre: autor_nou - type string
		post: in carte se modifica valoarea initiala cu valoarea noua din argument
	*/
	void modifica_autor(const string autor_nou);

	/*
		Functie de modificare a genului unei carti
		pre: gen_nou - type string
		post: in carte se modifica valoarea initiala cu valoarea noua din argument
	*/
	void modifica_gen(const string gen_nou);

	/*
		Functie de modificare a anului de aparitie a unei carti
		pre: an_nou - type  int
		post: in carte se modifica valoarea initiala cu valoarea noua din argument
	*/
	void modifica_an_aparitie(const int an_nou);


};