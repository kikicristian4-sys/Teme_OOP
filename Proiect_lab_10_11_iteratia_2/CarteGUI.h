#pragma once
#include <Service.h>
#include <Errors.h>
#include "Lab_10_11_iteratia_1.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <qstring.h>
#include <qlineedit.h>
#include <string>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qgridlayout.h>
#include <qboxlayout.h>
#include <qstackedlayout.h>
#include <qformlayout.h>
#include <vector>
#include <qdebug.h>
#include <qmessagebox.h>
#include <sstream>

using std::vector, std::string;


//Fereastra pentru rezolvarea adaugarii in cos
class rez_Cos : public QDialog
{
	public:
		rez_Cos(Service& service, int& id) {
		Init_rez();
		Add_Data_lscop(service);
		Init_Connect(service,id);
	}
	private:

	QListWidget* lst = new QListWidget;
	QLineEdit* linie = new QLineEdit;
	QPushButton* Back_button = new QPushButton("Back");
	QPushButton* Add_button = new QPushButton("Add");



	//Initializarea ferestrii 
	void Init_rez();
	//Adauga date din vectorul copie din service
	void Add_Data_lscop(Service& service);
	//Initializarea conexiunilor
	void Init_Connect(Service& service,int& id);
};


//Fereastra butonului de cos
class Cos_UI : public QDialog {
public:
Cos_UI(Service& service){
	Init_CosGUI();
	Add_Data(service);
	Init_Connect(service);
};
private:
QListWidget* lst = new QListWidget;
QLabel* L_introduce = new QLabel("Introduce:");
QLineEdit* intr_linie = new QLineEdit;
QPushButton* Add_button = new QPushButton("Adauga carte cu acest titlu in cos.");
QPushButton* Golire_button = new QPushButton("Goleste cos");
QPushButton* Gen_button = new QPushButton("Genereaza cos");
QPushButton* Exp_button = new QPushButton("Export cos");
QPushButton* Back_button = new QPushButton("Back");

//Initierea ferestrei pentru cos
void Init_CosGUI();
//Adaugare de date in lista
void Add_Data(Service& service);
//Initializarea conexiunilor
void Init_Connect(Service& service);

};









//Fereastra butonului de stergere
class Sterge_UI : public QDialog {

	public:
		Sterge_UI(int& id) {
	    Init_fer_stergere();
		Init_connect( id);
		};
	
		
	private:
		QPushButton* Del = new QPushButton("Sterge");
		QPushButton* Back = new QPushButton("Inchide");
		QLineEdit* linie = new QLineEdit();
		


		//Functie de initiere a conexiunilor dintre sloturi si semnale
		//id este valoare ce este introdusa de utilizator si returnata 
		void Init_connect(int& id);

		//Initierea window-ului pentru fereastra de stergere
		void Init_fer_stergere();

};




//Fereastra principala
class CarteGUI : public QWidget {

public :
	CarteGUI(Service& s) {
		initializeaza_GUI();
		adauga_date(s);
		init_connect(s);
		adauga_butoane(s);
	}

private:
	QListWidget* lst = new QListWidget;
	
	QPushButton* Add_button = new QPushButton{ "Adauga carte" };
	QPushButton* Delete_button = new QPushButton{ "Sterge carte" };
	QPushButton* Modify_button = new QPushButton{ "Modifica carte" };
	QPushButton* Undo_button = new QPushButton{ "Undo" };
	QPushButton* Exit_button = new QPushButton{"&Exit"};
	QPushButton* Filtrare_titlu_button = new QPushButton{ "Filtrare dupa titlu" };
	QPushButton* Filtrare_an_aparitie_button = new QPushButton{ "Filtrare dupa an aparitie" };
	QPushButton* Sortare_titlu_button = new QPushButton{ "Sortare dupa titlu" };
	QPushButton* Sortare_autor_button = new QPushButton{ "Sortare dupa autor" };
	QPushButton* Sortare_an_si_gen_button = new QPushButton{ "Sortare dupa an si gen" };
	QPushButton* Afisare_lista_button= new QPushButton{ "Afisare lista" };
	QPushButton* Cautare_in_lista_button = new QPushButton{ "Cautare carte specifica" };
	QPushButton* Cos_button = new QPushButton{ "Cos" };

	QLineEdit* titlu_filtline = new QLineEdit;
	QLineEdit* an_filtline = new QLineEdit;
	QLineEdit* id_line = new QLineEdit;
	QLineEdit* titlu_line = new QLineEdit;
	QLineEdit* autor_line = new QLineEdit;
	QLineEdit* gen_line = new QLineEdit;
	QLineEdit* an_line = new QLineEdit;
	QWidget* Buton_dinamic = new QWidget;
	QVBoxLayout* LyBtnD = new QVBoxLayout;
	vector<QPushButton*> butoane;


	//O functie ce preia un string si verifica daca valoarea ei poate fi adusa la un numar intreg
	bool val_intreaga(string id);

	//Initializarea conexiunilor de tip semnal si slot
	void init_connect(Service& service);

	//Functie ce adauga datele in lista ce este afisata in fereastra
	void adauga_date(Service& service);
	
	//Functie  ce adauga datele din vecotrul copie(cel in care se fac filtrari si sortari) in lista ce este afisata in fereastra
	void adauga_date_din_vcopie(Service& service);

	//Initierea ferestrei principale
	void initializeaza_GUI();

	//Functionalitatea de adaugare a butoanelor dinamice
	void adauga_butoane(Service& service);  

	//Functionalitatea de stergere a butoanelor dinamice
	void sterge_butoane();
};