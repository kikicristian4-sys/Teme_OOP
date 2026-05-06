#pragma once
#include "Teste.h"
#include "CarteGUI.h"
#include "Lab_10_11_iteratia_1.h"
#include <QtWidgets/QApplication>


int main(int argc, char * argv[])
{

	 
		QApplication app(argc, argv);

		Service service_test("Storage_test.txt");
		Teste Tests;
		Tests.Testeaza_tot(service_test);
		          
		Service service_oficial("Storage.txt");
		CarteGUI ui(service_oficial);
		
		ui.show();

		return app.exec();
	
	
}