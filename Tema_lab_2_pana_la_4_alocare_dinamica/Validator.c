
/*
	Functie de validare a 3 criterii
	pre: un id de tip int, un pret de tip float, o cantitate de tip int
	post: 2 daca id-ul este negativ sau 0, 3 daca pretul este negativ sau 0, 4 daca cantitatea este negativa sau 0, 0 daca totul este okay
*/
int validare_criterii_produs(int id, float pret, int cantitate)
{
	if( id <= 0)
		return 2;
	if(pret <= 0)
		return 3;
	if(cantitate <= 0)
		return 4;
	return 0;
}


/*
	Functie ce valideaza un pret
	pre: pretul ca valoare float
	post: functia returneaza 1 daca pretul este negativ sau zero, 0 daca este okay!
*/
int validare_pret(float pret)
{
	if (pret <= 0)
		return 1;
	return 0;
}

/*
	Functie ce valideaza un id
	pre: id-ul ca valoare int
	post: functia returneaza 1 daca id-ul este negativa sau zero, 0 daca este okay!
*/
int validare_id(int id)
{
	if(id <= 0)
		return 1;
	return 0;
}

/*
	Functie ce valideaza o cantitate
	pre: cantitatea ca valoare int
	post: functia returneaza 1 daca cantitatea este negativa sau zero, 0 daca este okay!
*/
int validare_cantitate(int cantitate)
{
	if (cantitate <= 0)
		return 1;
	return 0;
}
