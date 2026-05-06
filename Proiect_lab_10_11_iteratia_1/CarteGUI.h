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
	QLineEdit* id_line = new QLineEdit;
	QLineEdit* titlu_line = new QLineEdit;
	QLineEdit* autor_line = new QLineEdit;
	QLineEdit* gen_line = new QLineEdit;
	QLineEdit* an_line = new QLineEdit;
	QWidget* Buton_dinamic = new QWidget;
	QVBoxLayout* LyBtnD = new QVBoxLayout;

	//O functie ce preia un string si verifica daca valoarea ei poate fi adusa la un numar intreg
	bool val_intreaga(string id);

	//Initializarea conexiunilor de tip semnal si slot
	void init_connect(Service& service);

	//Functie ce adauga datele in lista ce este afisata in fereastra
	void adauga_date(Service& service);

	//Initierea ferestrei principale
	void initializeaza_GUI();

	//Functionalitatea de adaugare a butoanelor dinamice
	void adauga_butoane(Service& service);  
};