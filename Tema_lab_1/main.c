#include <stdio.h>

float P2[2];
float P1[2];
float L1[3];
float P3[2];
float P4[2];
float L2[3];
float x, y;

/*
	11. Determina intersectia a doua segmente plane (date prin coordonatele
    lor carteziene).
*/


void ec_dreaptei(float* A, float* B, float* C, float P1[], float P2[])//facem un pointer care pointeaza catre adresa
{	/*
		-Functie ce returneaza valorile de A, B si C dintr-o formula Ax + By = C
		-Argumente: se introduc 3 adrese pentru valorile A, B si C din formula si doi vectori ce contin valorile x si y a 
		fiecarui punct in parte
		-Return: In primele 3 argumente vor fi asezate valorile respective (A, B si C)
    */

	//Voi folosi formula (y1 - y2)x + (x2 - x1)y = (y1x2 - x1y2) pentru a afla elementele

	*A = P1[1] - P2[1];
	*B = P2[0] - P1[0];
	*C = P1[1]*P2[0] - P1[0] * P2[1];
	
}

int punct_intersectie(float L1[],float  L2[], float* x, float* y )
{
	/*
		-Functie ce gaseste punctul de intersectie a doua drepte (daca acesta exista)
		-Primeste doi vectori ce au fiecare cate 3 valori A B si C in L[0], L[1] respectiv L[2] si adresele unde vor fi depozitate 
		valorile x si y
		-Returneaza prin valoare coordonatele intersectiei (x,y)
	*/

	float D = L1[0] * L2[1] - L1[1] * L2[0]; //determinantul 
	
	if (D == 0)
		return 1;

	*x = (L1[2] * L2[1] - L1[1] * L2[2]) / D ;// x = Dx/D
	*y = (L1[0] * L2[2] - L1[2] * L2[0]) / D ;// y = Dy/D

	return 0;

}

int este_intersectie(float P1[], float P2[], float P3[], float P4[], float x, float y)
{
	/*
		Functie ce afla daca un punct de intersectie se afla pe ambele segmente date prim coordonatele celor 4 puncte
		Argumente: 4 vectori ce contin coordonatele celor 4 puncte si coordonatele punctului de intersectie
		Return: 1 daca se intersecteaza, 0 daca nu
	*/

	//Mai intai sa verificam toate posibilitatile ca punctul sa se afle pe segmentul format din P1 si P2
	int ok = 0;//Pentru a verifica daca punctul se afla pe segment 

	if ((x == P1[0] && y == P1[1]) || (x == P2[0] && y == P2[1]))
		ok = 1; 
	else
		{
			if (x < P1[0] && x > P2[0] || x > P1[0] && x < P2[0])
				ok = 1;
			else
			{
				if (y < P1[1] && y > P2[1] || y > P1[1] && y < P2[1])
					ok = 1;
				else
					return 0;

			}

		}

	
	//Acum sa verificam toate posibilitatile ca punctul sa se afle pe segmentul format din P3 si P4

	if ((x == P3[0] && y == P3[1]) || (x == P4[0] && y == P4[1]))
		return 1;
	else
	{
		if (x < P3[0] && x > P4[0] || x > P3[0] && x < P4[0])
			return 1;
		else
		{
			if (y < P3[1] && y > P4[1] || y > P3[1] && y < P4[1])
				return 1;
			else
				return 0;

		}
			
	}



}

void UI()
{
	/*
		UI-ul aplicatiei
		nu are argumente
		rezulta doar pe ecran
	*/
	while (1)
	{
		printf("Va rog sa alegeti optiunea:\n1.Aflati daca exista intersectia dintre 2 segmente si determinati-o\n2.Exit\n");
		int optiune;
		

		if (scanf_s("%d", &optiune) != 1)
		{
			while (getchar() == EOF)
			{
				optiune = -1;
			}
			printf("Va rog sa scrieti o valuare corecta!\n");
			
		}

		if (optiune == 1)
		{
			/*
				Pentru a rezolva problema, mai intai avem nevoie sa descoperim care este punctul de intersectie cu adevarat.
				Pentru asta vom aplica metoda Cramer ce ne spune ca daca avem un sistem de ecuatii 
				A1x + B1y = C1
				A2x + B2y = C2 /care sunt dreptele liniilor 
				rezultatul acestora (daca exista unul) va fi dat de x = Dx/D si y = Dy/D

			*/
			//Trebuie mai intai sa luam primele 2 puncte ale unei drepte
			
			printf("Va rog sa introduceti coordonatele primului punct al primei drepte sub formatul x y:");
			scanf_s("%f %f",&P1[0],&P1[1]);

			printf("Va rog sa introduceti coordonatele celui de al doilea punct primei drepte sub formatul x y:");
			
			scanf_s("%f %f", &P2[0], &P2[1]);

			//Avem prima dreapta, hai sa ii facem si ecuatia (Ax + Bx + C = 0)

		    ec_dreaptei(&L1[0], &L1[1], &L1[2], P1, P2);//transmitem adresa

			//Acum urmeaza cele 2 puncte pentru urmatoarea dreapta

			printf("Va rog sa introduceti coordonatele primului punct al urmatoarei drepte sub formatul x y:");
			scanf_s("%f %f", &P3[0], &P3[1]);

			printf("Va rog sa introduceti coordonatele celui de al doilea punct urmatoarei drepte sub formatul x y:");

			scanf_s("%f %f", &P4[0], &P4[1]);

			//Avem a doua dreapta, hai sa ii facem si ecuatia (Ax + Bx + C = 0)

			ec_dreaptei(&L2[0], &L2[1], &L2[2], P3, P4);//transmitem adresa


			//Acum avem cele doua drepte si este timpul sa gasim punctul in care se intersecteaza(daca se intersecteaza)
			if (punct_intersectie(L1, L2, &x, &y) == 1)
			{
				//Mai exista si cazul in care segmentele se intersecteaza intr o infinitate de puncte, insa si cazul in care 
				//se intersecteaza intr un singur punct, acela fiind unul dintre capete, iar dupa aceea se confunda, determinantul
				//devenind 0.
				//Inainte de a verifica acest lucru insa, trebuie sa ne asiguram ca nu cumva segmentele in sine sa se confunde.
				// spre exemplu (x1 = 1 y1 = 1) [x2 = 2 y2 = 2] (x3 = 1 y3 = 1) [x4 = 2 y4 = 2].

				if((P1[0] == P3[0] && P1[1] == P3[1] && P2[0] == P4[0] && P2[1] == P4[1])  || (P1[0] == P4[0] && P1[1] == P4[1] && P2[0] == P3[0] && P2[1] == P3[1]))
				{
					printf("Segmentele se confunda!\n");
					continue;
				}
				if((P1[0] == P3[0]) && (P1[1] == P3[1]))
					printf("Segmentele se intersecteaza intr-un singur punct, si anume x = %f si y = %f.\n", P1[0], P1[1]);
				else if ((P1[0] == P4[0]) && (P1[1] == P4[1]))
					printf("Segmentele se intersecteaza intr-un singur punct, si anume x = %f si y = %f.\n", P1[0], P1[1]);
				else if ((P2[0] == P3[0]) && (P2[1] == P3[1]))
					printf("Segmentele se intersecteaza intr-un singur punct, si anume x = %f si y = %f.\n", P2[0], P2[1]);
				else if ((P2[0] == P4[0]) && (P2[1] == P4[1]))
					printf("Segmentele se intersecteaza intr-un singur punct, si anume x = %f si y = %f.\n", P2[0], P2[1]);
				else
				printf("Segmentele ori nu se intersecteaza, ori se intersecteaza intr-o infinitate de puncte!\n");

				continue;
		    }
		   
			   
			//Acum urmeaza sa vedem daca segmentele se intersecteaza prin compararea coordonatelor!
			//In aceasta intersectie trebuie sa ne asiguram ca punctul se afla pe ambele segmente
			//adica sa fie intre cele 2 puncte ale fiecarei drepte

			if (este_intersectie(P1,P2,P3,P4,x,y) == 1)
				printf("Segmentele se intersecteaza, coordonatele intersectiei fiind x = %f si y = %f.\n",x,y);
			else
				printf("Segmentele nu se intersecteaza!\n");
		}
		else
		{
			if (optiune == 2)
				break;
			else
				printf("Va rog sa alegeti una dintre optiuni!\n");
		}


	}

}



int main()
{

	UI();
	return 0;
}