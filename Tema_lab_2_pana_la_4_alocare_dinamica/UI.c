#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "Service.h"
#include <ctype.h>
#include "lista_produse.h"

int obtinere_id()
/*
	Functie ce permite obtinerea unui id de la utilizator dupa specificatii.
	preconditii: -
	returneaza: id-ul introdus de utilizator intr-un numar natural nenul.
*/
{
	
	while (1)
	{
		printf("Va rog sa introduceti id-ul ca un numar natural:");
		char id[21], ok = 0;
		scanf_s("%s", id, 21);

		for (int i =0 ; id[i] != '\0'; i++)
			if(id[i] != '\0')
			if (isdigit(id[i]))
				continue;
			else
			{
				
				printf("Va rog sa introduceti o valoare valida!\n");
				ok = 1;
				break ;
			}

			if(ok == 0)
			{
				int int_id = atoi(id);
				if (int_id == 0)
					printf("Va rog sa introduceti o valoare naturala nenula!\n");
				else
				{
				return int_id;

				}

			}

	}


}

float obtinere_pret()
/*
	Functie ce permite obtinerea unui pret float de la utilizator dupa specificatii.
	preconditii: -
	returneaza: pretul introdus de utilizator intr-un numar real pozitiv.
*/
{
	while (1)
	{
		printf("Va rog sa introduceti pretul ca un numar real pozitiv:");
		char pret[21], ok = 0;
		scanf_s("%s", pret, 21);
				
		for(int i =1 ; pret[i] != '\0'; i++)
			if(pret[i] != '\0')
				if (isdigit(pret[i]))
				{
					continue;
				}
				else
				{
					if (pret[i] == '.' && ok == 0)
						ok++;
					else
					{
						if (pret[i] == '.' && ok == 1)
						{
							printf("Va rog sa adaugati o valoare valida!\n");
							ok++;
							break;
						}
						else
						{
							ok = 2;
							printf("Va rog sa adaugati o valoare valida!\n");
							break;
						}

					}
						
						
				}
				
		if (ok != 2)
		{
			float float_pret = atof(pret);
			if(float_pret == 0)
				printf("Va rog sa transmiteti o valoare rationala nenula!");
			else
				return float_pret;
		}
				




	}
}

int obtinere_cantitate()
{
/*
	Functie ce primeste de la tastatura o cantitate.
	preconditii: -
	returneaza: o cantitate naturala si nenula.
*/
	while (1)
	{
		printf("Va rog sa introduceti cantitatea ca un numar natural nenul:");
		char cantitate[21], ok =0;
		scanf_s("%s", cantitate, 21);



		for (int i = 0; cantitate[i] != '\0'; i++)
			if (cantitate[i] != '\0')
			if (isdigit(cantitate[i]))
				continue;
			else
			{
				printf("Va rog sa introduceti o valoare valida!\n");
				ok = 1;
				break;
			}

		if (ok == 0)
		{
			int int_cantitate = atoi(cantitate);
			if (int_cantitate == 0)
				printf("Va rog sa introduceti o cantitate naturala nenula!\n");
			else
			{
					return int_cantitate;
			}

		}

		
	}
}

/*
	Functie ce afiseaza pe ecran valorile unui vector
	pre: adresa unui struct de tip vector_element
	post: pe ecran se vor afisa toate valorile produselor din vector sub un anumit format
*/
void afiseaza_vector(vector_elemente* vector)
{
	for (int i = 1; i <= lungime_vector(vector); i++)
	{
		produs p = returneaza_element(vector, i);
		printf("ID: %d, TIP: %s, PRODUCATOR: %s, MODEL: %s, PRET: %.2f, CANTITATE: %d\n", p.id, p.tip, p.producator, p.model, p.pret, p.cantitate);
	}
		
}

/*
	Functie ce obtine o optiune de la utilizator
	pre: -
	post: returneaza o optiune sub o valoare int
*/

int obtinere_optiune()
{
	
		while (1)
		{
			printf("Optiune:");
			char optiune[21], ok = 0;
			scanf_s("%s", optiune, 21);

			for (int i = 0; optiune[i] != '\0'; i++)
				if (optiune[i] != '\0')
					if (isdigit(optiune[i]))
						continue;
					else
					{

						printf("Va rog sa introduceti o valoare valida!\n");
						ok = 1;
						break;
					}

			if (ok == 0)
			{
				int int_optiune = atoi(optiune);
				if (int_optiune == 0)
					printf("Va rog sa introduceti o valoare naturala nenula!\n");
				else
				{
					return int_optiune;

				}

			}

		}
}

int user_interface(vector_elemente* vector)
/*
	User interface.
	pre: o adresa catre un struct de tipul vector_elemente
	post: interactiunea cu utilizatorul
*/
{
	vector_elemente copie_v = creaza_vector_gol();//folosit la filtrari 
	while (1)
	{
		printf("1.Adaugare produs\n2.Actualizare produs\n3.Stergere produs\n4.Vizualizare produse din stoc ordonate dupa pret si cantitate\n5.Vizualizare lista de produse filtrate dupa un criteriu\n6.Vizualizare lista\n7.Exit\n");
		int optiune = obtinere_optiune();
		switch (optiune)
		{
		case 1:
		{
			//Adaugare produs
			int id = 0;
			id = obtinere_id();

			char tip[21];
			printf("Va rog sa introduceti tipul produsului in cel mult 20 de caractere:");
			scanf_s("%s", tip, 21);

			char producator[21];
			printf("Va rog sa introduceti producatorul produsului in cel mult 20 de caractere:");
			scanf_s("%s", producator, 21);

			char model[21];
			printf("Va rog sa introduceti modelul produsului in cel mult 20 de caractere:");
			scanf_s("%s", model, 21);
			float pret = obtinere_pret();

			int cantitate = obtinere_cantitate();

			switch (adaugare_produs(vector, id, tip, producator, model, pret, cantitate))
			{

				case 0:
					printf("Produs adaugat cu succes!\n");
				break;

				case 1:
					printf("Id-ul introdus se repeta! Cantitatea a fost adaugata la produsul deja existent!\n");
				break;
				
				case 2:
					printf("Id-ul este un numar negativ sau 0! Va rog sa reincercati!\n");
				break;

				case 3:
					printf("Pretul este un numar negativ sau 0! Va rog sa reincercati!\n");
				break;

				case 4: 
					printf("Cantitatea este un numar negativ sau 0! Va rog sa reincercati!\n");
				break;

				case 5:
					printf("Id-ul se repeta insa datele incorporate nu sunt aceleasi! Va rog sa reincercati!\n");
				break;

				case 6:
					printf("Au fost introduce 100 de produse! Momentan nu avem cinstea unui vector dinamic! Va rog mai taiati din ele inainte de a mai adauga!\n");
				break;

			}
			break;
		}


		case 2:
		{
			int optiune_2 = 1;
			while (optiune_2 != 0)
			{
				printf("1.Modificare pret\n2.Modificare cantitate\n3.Inapoi\n");
				optiune_2 = obtinere_optiune();
				switch (optiune_2)
				{
				case 1:
				{	//modificare pret
					int id = obtinere_id();
					float pret = obtinere_pret();
					switch (modificare_pret(vector, id, pret))
					{
						case 1:
							printf("Id ul nu exista in baza de date!\n");
						break;
						
						case 2:
							printf("Pretul este ori negativ ori zero! Va rog sa reincercati!\n");
						break;

						case 0:
						break;
					}		

					break;
				}

				case 2:
				{
					//modificare cantitate
					int id = obtinere_id();
					int cantitate = obtinere_cantitate();
					switch (modificare_cantitate(vector,id, cantitate))
					{
						case 1:
							printf("Id ul nu exista in baza de date!\n");
						break;

						case 2:
							printf("Cantitatea este ori negativ ori zero! Va rog sa reincercati!\n");
						break;

						case 0:
						break;

					}
						
					break;
				}
				case 3:
					optiune_2 = 0;
					break;
				}

			}
			break;
		}


		case 3:
		{
			int id = obtinere_id();
			if (stergere_produs(vector,id) == 1)
				printf("Produsul nu a existat!\n");
			else
			{
				if(stergere_produs(vector, id) == 2)
					printf("Id-ul este negativ sau zero!Va rog sa incercati cu un id strict pozitiv!\n");
			}
		}
		break;

		case 4:
		{
			
			switch (vizualizare_produse_stoc_ordonate(vector, &copie_v))
			{
				case 1:
					printf("Nu exista nici un produs in stoc!\n");
				break;

				case 0:
					//Avem in copie_v vectorul ce trebuie afisat
					afiseaza_vector(&copie_v);
				break;

			}
		}


		break;

		case 5:
		{	//Vizualizare lista de produse ordonate dupa un criteriu
			int optiune_3 = 1;
			while (optiune_3 != 0)
			{
				printf("1.Filtrare produse cu pretul mai mic sau egal decat un pret dat.\n2.Filtrare dupa un producator.\n3.Filtrare produse cu cantitatea strict mai mare decat o cantitate data.\n4.Inapoi\n");
				optiune_3 = obtinere_optiune();
				switch (optiune_3)
				{
				case 1:
				{
					float pret = obtinere_pret();
					switch (filtrare_produse_pret(vector, &copie_v, pret))
					{
						case 1:
							printf("Nu exista nici un element in lista!\n");
						break;

						case 2:
							printf("Pretul dat este negativ sau zero! Va rog sa reincercati cu unul strict pozitiv!\n");
						break;

						case 0:
							afiseaza_vector(&copie_v);
						break;

						case 3:
							printf("Nu exista nici un produs cu un asa pret!\n");
							break;

					}
					
				}
				break;
				case 2:
				{
					char producator[20];

					printf("Va rog sa introduceti producatorul in cel mult 20 de caractere:");
					scanf_s("%s", producator, 20);

					switch(filtrare_produse_producator(vector,&copie_v,producator))
					{
					case 1:
						printf("Nu exista nici un produs in lista!\n");
						break;

					case 0:
						afiseaza_vector(&copie_v);
						break;

					case 3:
						printf("Nu exista nici un produs cu un asa producator!\n");
						break;

					}

					
				}
				break;
				case 3:
				{
					int cantitate = obtinere_cantitate();
				
					switch(filtrare_produse_cantitate(vector, &copie_v,cantitate))
					{
					case 1:
						printf("Nu exista nici un produs in lista!\n");
						break;

					case 2:
						printf("Cantitatea data este una negativa sau zero! Va rog sa reincercati cu o cantitate strict pozitiva!\n");
						break;

					case 3:
						printf("Nu exista nici un produs cu o asa cantitate!\n");
						break;

					case 0:
						afiseaza_vector(&copie_v);
						break;

					}
					
					

				}
					break;

				case 4:
					optiune_3 = 0;
					break;
				}

			}
		}




		break;
		case 6:
			if(lungime_vector(vector) == 0)
				printf("Nu exista nici un element in lista!");
			else
				afiseaza_vector(vector);
			break;
		case 7:
			printf("O zi fainaaa! :DD");
			distruge_vector(&copie_v);
			return 0;
		default:
		{
			printf("Optiune invalida! Va rog sa selectati una dintre optiuni!\n");

			while (getchar() == EOF)
			{
				//golim buffer-ul de intrare(daca este cazul)
				optiune = -1;
			}
		}
		}
	}
	
	
}