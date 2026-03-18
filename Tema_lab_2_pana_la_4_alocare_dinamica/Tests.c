#include <stdio.h>
#include "UI.h"
#include "Service.h"
#include <assert.h>
#include "Produse.h"
#include "lista_produse.h"


void Test_creaza_vector_gol()
{
	vector_elemente exemplu = creaza_vector_gol();
	assert (exemplu.lungime == 0 );
	assert(distruge_vector(&exemplu) == 0);


}
void Test_vizualizare_produse_stoc_zero(vector_elemente* vector)
{
	vector_elemente copie_v;
	assert(vizualizare_produse_stoc_ordonate(vector,&copie_v) == 1);

}

void Test_filtrare_produse_pret_zero(vector_elemente* vector)
{	
	vector_elemente copie_v;
	assert(filtrare_produse_pret(vector,&copie_v, 102.5) == 1);


}

void Test_filtrare_produse_producator_zero(vector_elemente* vector)
{
	
	vector_elemente copie_v;
	assert(filtrare_produse_producator(vector, &copie_v, "Dan\0") == 1);


}

void Test_filtrare_produse_cantitate_zero(vector_elemente* vector)
{
	vector_elemente copie_v;
	assert(filtrare_produse_cantitate(vector, &copie_v, 20) == 1);

}

void Test_adaugare_produs(vector_elemente* vector)
/*
	Functie de test pentru adaugarea unui produs.
*/
{	
	
	assert(adaugare_produs(vector, 101, "Armaghedon\0", "Dan\0", "Hercule\0", 102.5, 20) == 0);
	assert(adaugare_produs(vector, 102, "Armaghedon\0", "Dan\0", "Hercule\0", 102.5, 22) == 0);
	assert(adaugare_produs(vector, 102, "Armaghedo\0", "Dan\0", "Hercule\0", 102.5, 22) == 5);
	assert(adaugare_produs(vector, 102, "Armaghedon\0", "Dar\0", "Hercule\0", 102.5, 22) == 5);
	assert(adaugare_produs(vector, 102, "Armaghedon\0", "Dan\0", "Hercula\0", 102.5, 22) == 5);
	assert(adaugare_produs(vector, 102, "Armaghedon\0", "Dan\0", "Hercule\0", 102, 22) == 5);
	assert(adaugare_produs(vector,103, "Armaghedon\0", "Dn\0", "Hercule\0", 10, 20) == 0);
	assert(adaugare_produs(vector,102, "Armaghedon\0", "Dan\0", "Hercule\0", 102.5, 20) == 1);
	assert(adaugare_produs(vector, 102, "Armaghedon\0", "Dan\0", "Hercule\0", -102.5, 20) == 3);
	assert(adaugare_produs(vector, -102, "Armaghedon\0", "Dan\0", "Hercule\0", 102.5, 20) == 2);
	assert(adaugare_produs(vector, 102, "Armaghedon\0", "Dan\0", "Hercule\0", 102.5, -20) == 4);
}

void Test_distrugere_vector_cu_elemente()
{
	vector_elemente exemplu = creaza_vector_gol();
	assert(adaugare_produs(&exemplu, 101, "Armaghedon\0", "Dan\0", "Hercule\0", 102.5, 20) == 0);
	assert(adaugare_produs(&exemplu, 102, "Armdon\0", "Da\0", "Hecule\0", 102.5, 20) == 0);
	assert(exemplu.lungime == 2);
	assert(exemplu.capacitate == 4);

	assert(distruge_vector(&exemplu) == 0);


}

void Test_vizualizare_produse_stoc(vector_elemente* vector)
{
	vector_elemente copie_v = creaza_vector_gol();
	vizualizare_produse_stoc_ordonate(vector, &copie_v);
	
	assert(id_produs(&copie_v.elemente[2]) == 101);
	assert(pret_produs(&copie_v.elemente[2]) == 102.5);
	assert(cantitate_produs(&copie_v.elemente[2]) == 20);
	assert(id_produs(&copie_v.elemente[1]) == 103);
	assert(pret_produs(&copie_v.elemente[1]) == 10);
	assert(cantitate_produs(&copie_v.elemente[1]) == 20);
	assert(id_produs(&copie_v.elemente[3]) == 102);
	assert(pret_produs(&copie_v.elemente[3]) == 102.5);
	assert(cantitate_produs(&copie_v.elemente[3]) == 42);//Este declarat ca 22, insa id-ul 102 se repeta la adaugare,
	//deci prin urmare este adaugat la cantitate

	distruge_vector(&copie_v);

}

void Test_filtrare_produse_pret(vector_elemente* vector)
{

	vector_elemente copie_v = creaza_vector_gol();
	assert(filtrare_produse_pret(vector, &copie_v, -100) == 2);
	filtrare_produse_pret(vector,&copie_v,100);


	assert(id_produs(&copie_v.elemente[1]) == 103);
	assert(pret_produs(&copie_v.elemente[1]) == 10);
	assert(cantitate_produs(&copie_v.elemente[1]) == 20);

	assert(filtrare_produse_pret(vector, &copie_v, 1) == 3);

	filtrare_produse_pret(vector,&copie_v, 9);
	assert(copie_v.lungime == 0);

	
	filtrare_produse_pret(vector, &copie_v, 102.5);
	assert(id_produs(&copie_v.elemente[1]) == 101);
	assert(pret_produs(&copie_v.elemente[1]) == 102.5);
	assert(cantitate_produs(&copie_v.elemente[1]) == 20);
	assert(id_produs(&copie_v.elemente[2]) == 102);
	assert(pret_produs(&copie_v.elemente[2]) == 102.5);
	assert(cantitate_produs(&copie_v.elemente[2]) == 42);
	assert(id_produs(&copie_v.elemente[3]) == 103);
	assert(pret_produs(&copie_v.elemente[3]) == 10);
	assert(cantitate_produs(&copie_v.elemente[3]) == 20);


	distruge_vector(&copie_v);

}

void Test_filtrare_produse_producator(vector_elemente* vector)
{
	vector_elemente copie_v = creaza_vector_gol();
	filtrare_produse_producator(vector, &copie_v, "Dan\0");
	assert(id_produs(&copie_v.elemente[1]) == 101);
	assert(pret_produs(&copie_v.elemente[1]) == 102.5);
	assert(cantitate_produs(&copie_v.elemente[1]) == 20);
	assert(id_produs(&copie_v.elemente[2]) == 102);
	assert(pret_produs(&copie_v.elemente[2]) == 102.5);
	assert(cantitate_produs(&copie_v.elemente[2]) == 42);

	assert(filtrare_produse_producator(vector, &copie_v, "D") == 3);

	
	filtrare_produse_producator(vector, &copie_v, "Dn\0");
	assert(id_produs(&copie_v.elemente[1]) == 103);
	assert(pret_produs(&copie_v.elemente[1]) == 10);
	assert(cantitate_produs(&copie_v.elemente[1]) == 20);

	distruge_vector(&copie_v);

}

void Test_filtrare_produse_cantitate(vector_elemente* vector)
{

	vector_elemente copie_v = creaza_vector_gol();
	assert(filtrare_produse_cantitate(vector, &copie_v, -19) == 2);
	filtrare_produse_cantitate(vector, &copie_v, 19);

	assert(id_produs(&copie_v.elemente[1]) == 101);
	assert(pret_produs(&copie_v.elemente[1]) == 102.5);
	assert(cantitate_produs(&copie_v.elemente[1]) == 20);

	produs p = returneaza_element(&copie_v, 1);
	assert(p.id = 101);


	assert(id_produs(&copie_v.elemente[2]) == 102);
	assert(pret_produs(&copie_v.elemente[2]) == 102.5);
	assert(cantitate_produs(&copie_v.elemente[2]) == 42);
	assert(id_produs(&copie_v.elemente[3]) == 103);
	assert(pret_produs(&copie_v.elemente[3]) == 10);
	assert(cantitate_produs(&copie_v.elemente[3]) == 20);

	assert(filtrare_produse_cantitate(vector, &copie_v, 43) == 3);
	
	filtrare_produse_cantitate(vector, &copie_v, 43);
	assert(copie_v.lungime == 0);

	
	filtrare_produse_cantitate(vector, &copie_v, 22);
	
	assert(id_produs(&copie_v.elemente[1]) == 102);
	assert(pret_produs(&copie_v.elemente[1]) == 102.5);
	assert(cantitate_produs(&copie_v.elemente[1]) == 42);
	
	distruge_vector(&copie_v);

}


void Test_actualizare_produs(vector_elemente* vector)
{
	
	assert(modificare_pret(vector,101, 190.2) == 0);
	assert(modificare_pret(vector,105, 190.2) == 1);
	assert(modificare_pret(vector, 101, -190.2) == 2);
	assert(modificare_cantitate(vector,101, 190) == 0);
	assert(modificare_cantitate(vector,105, 190) == 1);
	assert(modificare_cantitate(vector, 101, -190) == 2);

}



void Test_stergere_produs(vector_elemente* vector)
{
	
	assert(stergere_produs(vector,101) == 0);
	assert(stergere_produs(vector,-101) == 2);
	assert(stergere_produs(vector,102) == 0);
	assert(stergere_produs(vector,103) == 0);
	assert(stergere_produs(vector,105) == 1);
	
}



void Test_all(vector_elemente* vector)
/*
	Functie ce apeleaza toate functiile de test.
*/
{
	Test_creaza_vector_gol();
	Test_vizualizare_produse_stoc_zero(vector);
	Test_filtrare_produse_pret_zero(vector);
	Test_filtrare_produse_producator_zero(vector);
	Test_filtrare_produse_cantitate_zero(vector);
	
	Test_adaugare_produs(vector);

	Test_distrugere_vector_cu_elemente();
	Test_vizualizare_produse_stoc(vector);
	Test_filtrare_produse_pret(vector);
	Test_filtrare_produse_producator(vector);
	Test_filtrare_produse_cantitate(vector);
	Test_actualizare_produs(vector);
	Test_stergere_produs(vector);

	Test_adaugare_produs(vector);
	
	
	

	
}


