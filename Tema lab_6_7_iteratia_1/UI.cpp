#include "UI.h"
#include "Carte.h"
#include <iostream>

using std::cout;using std::endl;using std::cin;


void UI::afisare_lista(Service& service)
{
	for (Carte& c : service.repo.lista)
	{
	cout<<"ID: "<<c.get_id()<<" titlul: "<<c.get_titlu()<<" autorul: "<<c.get_autor()<<" gen: "<<c.get_gen()<<" anul aparitiei: "<<c.get_anul_aparitiei()<<endl;
	}
}

void UI::afisare_copie_lista(Service& service)
{
	for (Carte& c : service.lista_copie)
	{
		cout << "ID: " << c.get_id() << " titlul: " << c.get_titlu() << " autorul: " << c.get_autor() << " gen: " << c.get_gen() << " anul aparitiei: " << c.get_anul_aparitiei() << endl;
	}
}

void UI::meniu_utilizator(Service& service)
{
	int optiune = 1;
	while (optiune != 0)
	{
		cout<<"1.Adaugare carte\n2.Stergere carte dupa id.\n3.Afisare lista.\n4.Modificare carte.\n5.Cautare carte.\n6.Filtrare carte.\n7.Sortare carti.\n8.Exit\nOptiune:";
		cin>>optiune;
		switch (optiune) {

		case 1:
		{
			string titlu, autor, gen;
			int id, anul_scrierii;

			cout << "Id ul cartii: ";
			cin >> id;
			cout << "Titlul cartii: ";
			cin >> titlu;
			cout << "Autorul cartii: ";
			cin >> autor;
			cout << "Genul cartii: ";
			cin >> gen;
			cout << "Anul aparitiei: ";
			cin >> anul_scrierii;
			if(service.adauga_carte_service(id,titlu,autor,gen,anul_scrierii) == 1)
				cout<<"Id-ul deja exista.\n";
			break;
		}
		case 2:
		{
			int id;
			cout << "Id ul cartii pe care il vreti sters: ";
			cin >> id;
			if(service.sterge_carte_service(id) == 1)
				cout<<"Nu exista cartea cautata in lista\n";
			else
			if(service.sterge_carte_service(id) == 2)
				cout<<"Lista este goala";
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
				switch (optiune_1)
				{
					case 1:
					{
					int id;
					string titlu;
					cout<<"Id-ul cartii: ";
					cin >> id;
					cout<<"Noul titlu al cartii: ";
					cin>>titlu;
					if(service.modificare_titlu_service(id,titlu) == 1)
						cout<<"Nu exista id-ul in lista\n";
					else 
						if(service.modificare_titlu_service(id, titlu) == 2)
							cout<<"Lista este goala\n";
					break;
					}
					case 2:
					{
						int id;
						string autor;
						cout << "Id-ul cartii: ";
						cin >> id;
						cout << "Noul autor al cartii: ";
						cin >> autor;
						if(service.modificare_autor_service(id,autor) == 1)
							cout << "Nu exista id-ul in lista\n";
						else
							if(service.modificare_autor_service(id, autor) == 2)
								cout << "Lista este goala\n";
					break;
					}
					case 3:
					{
						int id;
						string gen;
						cout << "Id-ul cartii: ";
						cin >> id;
						cout << "Noul gen al cartii: ";
						cin >> gen;
						if(service.modificare_gen_service(id,gen) ==1)
							cout << "Nu exista id-ul in lista\n";
						else
							if(service.modificare_gen_service(id, gen) == 2)
								cout << "Lista este goala\n";
					break;
					}
					case 4:
					{
						int id,an_nou;
						cout << "Id-ul cartii: ";
						cin >> id;
						cout << "Noul an de aparitie al cartii: ";
						cin >> an_nou;
						if(service.modificare_an_aparitie_service(id, an_nou) == 1)
							cout << "Nu exista id-ul in lista\n";
						else
							if(service.modificare_an_aparitie_service(id, an_nou) == 2)
								cout << "Lista este goala\n";
					break;
					}
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
			cin >> anul_scrierii;

			int id = service.cautare_carte_specifica_service(titlu,autor,gen,anul_scrierii);
			if(id == 0)
				cout<<"Nu exista nici o carte ce sa aiba aceasta combinatie de elemente.\n";
			else
			{
				if(id == -1)
					cout<<"Lista este goala.\n";
				else
					cout << "ID: " << id << " titlul: " <<titlu << " autorul: " << autor << " gen: " << gen << " anul aparitiei: " << anul_scrierii << endl;
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
						cin>> an;
						int posib = service.filtrare_dupa_an_aparitie(an);
						if(posib == 1)
							cout<<"Nu s-au gasit asemenea carti.\n";
						else
						{
							if( posib == 2)
								cout<<"Nu exista carti in lista.\n";
							else
								afisare_copie_lista(service);
						}
						
						break;
					}
					case 2:
					{
						string titlu;
						cout << "Titlul cartii dupa care doriti sa filtrati: ";
						cin >> titlu;
						int posib = service.filtrare_dupa_titlu(titlu);
						if (posib == 1)
							cout << "Nu s-au gasit asemenea carti.\n";
						else
						{
							if (posib == 2)
								cout << "Nu exista carti in lista.\n";
							else
								afisare_copie_lista(service);
						}
						break;
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
						if(service.sortare_dupa_titlu() == 1 )
							cout<<"Nu exista nimic de sortat!\n";
						else
						afisare_copie_lista(service);
						break;
					}
					case 2:
					{
						if(service.sortare_dupa_autor() == 1)
							cout<<"Nu exista nimic de sortat!\n";
						else
						afisare_copie_lista(service);
						break;
					}
					case 3:
					{
						if(service.sortare_an_si_gen() == 1)
							cout<<"Nu exita nimic de sortat!\n";
						else
						afisare_copie_lista(service);
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