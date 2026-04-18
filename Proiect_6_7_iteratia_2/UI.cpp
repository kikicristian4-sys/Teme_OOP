#include "UI.h"
#include "Carte.h"
#include <iostream>
#include <limits>
#include "Errors.h"

using std::cout;using std::endl;using std::cin;


void UI::afisare_lista(Service& service)
{
	for (int i = 0; i < service.repo.lungime; i++)
	{
		Carte c = service.repo.lista[i];
	cout<<"ID: "<<c.get_id()<<" titlul: "<<c.get_titlu()<<" autorul: "<<c.get_autor()<<" gen: "<<c.get_gen()<<" anul aparitiei: "<<c.get_anul_aparitiei()<<endl;
	}
}

void UI::afisare_copie_lista(Service& service)
{
	for (int i = 0; i < service.repo_copie.lungime; i++)
	{
		Carte c = service.repo_copie.lista[i];
		cout << "ID: " << c.get_id() << " titlul: " << c.get_titlu() << " autorul: " << c.get_autor() << " gen: " << c.get_gen() << " anul aparitiei: " << c.get_anul_aparitiei() << endl;
	}
}

void UI::elibereaza_buffer()
{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int UI::get_int()
{
	string optiune;
	while (true)
	{
		cin>>optiune;

		int ok = 0;
		for (int i = 0; i < optiune.length(); i++)
		{
			if (isdigit(optiune.at(i)) == 0 && optiune.at(i) != '-')
			{
				cout << "Valoarea introdusa nu este de tip intreg, va rog reincercati!" << endl << "Valoare: ";
				elibereaza_buffer();
				ok = 1;
				break;
			}
		}
		if (ok == 0)
		{
			int const optiune_int = atoi(optiune.c_str());
			return optiune_int;
		}
		
		
	}
}

void UI::meniu_utilizator(Service& service)
{
	int optiune = 1;
	while (optiune != 0)
	{
		cout<<"1.Adaugare carte\n2.Stergere carte dupa id.\n3.Afisare lista.\n4.Modificare carte.\n5.Cautare carte.\n6.Filtrare carte.\n7.Sortare carti.\n8.Exit\nOptiune:";
		optiune = get_int();
		elibereaza_buffer();
		switch (optiune) {

		case 1:
		{
			string titlu, autor, gen;
			int id = 0, anul_scrierii = 0;

			cout << "Id ul cartii: ";
			id = get_int();
			elibereaza_buffer();
			cout << "Titlul cartii: ";
			cin >> titlu;
			cout << "Autorul cartii: ";
			cin >> autor;
			cout << "Genul cartii: ";
			cin >> gen;
			cout << "Anul aparitiei: ";
			anul_scrierii = get_int();
			elibereaza_buffer();

			try {
				service.adauga_carte_service(id, titlu, autor, gen, anul_scrierii);
			}
			catch (ValidationError& err) {
				cout << err.get_Message()<<endl;
				}	
			break;
		}
		case 2:
		{
			int id;
			cout << "Id ul cartii pe care il vreti sters: ";
			id = get_int();
			elibereaza_buffer();
			try {
				service.sterge_carte_service(id);

			}
			catch (ValidationError& err) {
				cout<< err.get_Message()<<endl;
			}
			
			break;
		}
			
		case 3:
		{
			afisare_lista(service);
			break;
		}
		case 4:
		{
			int optiune_1 = 1;
			while (optiune_1 != 0)
			{
				cout<<"1.Modificare titlu.\n2.Modificare autor.\n3.Modificare gen.\n4.Modificare an aparitie.\n5.Inapoi\nOptiune: ";
				cin>>optiune_1;
				elibereaza_buffer();
				switch (optiune_1)
				{
					case 1:
					{
					int id;
					string titlu;
					cout<<"Id-ul cartii: ";
					id = get_int();
					elibereaza_buffer();
					cout<<"Noul titlu al cartii: ";
					cin>>titlu;
					try {
						service.modificare_titlu_service(id, titlu);
					}
					catch (ValidationError& err) {
						cout << err.get_Message()<<endl;
					}
					
					break;
					
					}
					case 2:
					{
						int id;
						string autor;
						cout << "Id-ul cartii: ";
						id = get_int();
						elibereaza_buffer();
						cout << "Noul autor al cartii: ";
						cin >> autor;
						try {
							service.modificare_autor_service(id, autor);
						}
						catch (ValidationError& err) {
							cout << err.get_Message() << endl;
						}
						break;
					}
					case 3:
					{
						int id;
						string gen;
						cout << "Id-ul cartii: ";
						id = get_int();
						elibereaza_buffer();
						cout << "Noul gen al cartii: ";
						cin >> gen;
						try {
							service.modificare_gen_service(id, gen);
						}
						catch (ValidationError& err) {
							cout << err.get_Message() << endl;
							}
						break;
					}
					case 4:
					{
						int id = 0,an_nou = 0;
						cout << "Id-ul cartii: ";
						id = get_int();
						cout << "Noul an de aparitie al cartii: ";
						an_nou = get_int();
						try{
							service.modificare_an_aparitie_service(id, an_nou);
						}
						catch (ValidationError& err) {
							cout << err.get_Message() << endl;
							}	
						}
					break;
					case 5:
					{
					optiune_1 = 0;
					break;

					default:
						cout << "Va rog sa alegeti una din optiunile prezentate!!!!" << endl;
					}
				}
			}
			break;
		}
		case 5:
		{
			string titlu, autor, gen;
			int anul_scrierii;
			cout << "Titlul cartii cautate: ";
			cin >> titlu;
			cout << "Autorul cartii cautate: ";
			cin >> autor;
			cout << "Genul cartii cautate: ";
			cin >> gen;
			cout << "Anul aparitiei cautate: ";
			anul_scrierii = get_int();

			try{
			int const id = service.cautare_carte_specifica_service(titlu,autor,gen,anul_scrierii);
			cout << "ID: " << id << " titlul: " << titlu << " autorul: " << autor << " gen: " << gen << " anul aparitiei: " << anul_scrierii << endl;

			}
			catch (ValidationError& err) {
				cout << err.get_Message() << endl;
				}
			break;
		}
		case 6:
		{
			int optiune_2 = 1;
			while (optiune_2 != 0)
			{
				cout<<"Filtrare dupa:\n1.Anul aparitiei.\n2.Titlul cartii.\n3.back\nOptiune:";
				cin>>optiune_2;
				switch (optiune_2)
				{
					case 1:
					{
					int an;
						cout<<"Anul dupa care doriti sa filtrati: ";
						an = get_int();
						
						try{
							service.filtrare_dupa_an_aparitie(an);
						}
						catch (ValidationError& err) {
							cout << err.get_Message() << endl;
							}
						break;
					}
					case 2:
					{
						string titlu;
						cout << "Titlul cartii dupa care doriti sa filtrati: ";
						cin >> titlu;
						try {
						service.filtrare_dupa_titlu(titlu);
						afisare_copie_lista(service);
						}
						catch (ValidationError& err) {
							cout << err.get_Message() << endl;
							}
					}
					case 3:
					{
						optiune_2 = 0;
						break;
					}
					default:
						cout << "Va rog sa alegeti una din optiunile prezentate!!!!" << endl;
				}
			}
			break;
		}
		case 7:
		{
			int optiune_3 = 1;
			while (optiune_3 != 0)
			{
				cout<<"1.Sortare dupa titlu.\n2.Sortare dupa autor.\n3.Sortare dupa anul aparitiei + gen.\n4.Inapoi\nOptiune:";
				cin >> optiune_3;
				switch (optiune_3)
				{
					case 1:
					{
					try{
						service.sortare_dupa_titlu();
						afisare_copie_lista(service);
					}
					catch (ValidationError& err) {
						cout << err.get_Message() << endl;}
						break;
					}
					case 2:
					{
						try{
							service.sortare_dupa_autor();
							afisare_copie_lista(service);
						}
						catch (ValidationError& err) {
							cout << err.get_Message() << endl;}
						break;
					}
					case 3:
					{
						try{
							service.sortare_an_si_gen();
							afisare_copie_lista(service);
						}
						catch (ValidationError& err) {
							cout << err.get_Message() << endl;}
						break;
					}
					case 4:
					{
						optiune_3 = 0;
						break;
					}
					default:
					cout<< "Va rog sa alegeti una din optiunile prezentate!!!!" << endl;
				}
			}
			break;
		}
		case 8:
			cout<<"O zi buna! :DD"<<endl;
			optiune = 0;
			break;
		default:
			cout<<"Va rog sa alegeti una din optiunile prezentate!!!!"<<endl;
		}
	}
}