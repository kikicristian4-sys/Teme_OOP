#include "CarteGUI.h"
#include <unordered_map>


void rez_Cos::Add_Data_lscop(Service& service)
{
	for (const Carte& c : service.lista_copie)
	{
		string s = std::to_string(c.get_id()) + "; " + c.get_titlu() + "; " + c.get_autor() + "; " + c.get_gen() + "; " + std::to_string(c.get_anul_aparitiei());
		lst->addItem(QString::fromStdString(s));
	}
}

void rez_Cos::Init_rez()
{
	QVBoxLayout* LyMain = new QVBoxLayout{};
	QHBoxLayout* LyDown = new QHBoxLayout{};
	this ->setLayout(LyMain);
	this -> show();

	LyMain ->addWidget(lst);
	LyMain ->addWidget(linie);

	LyDown ->addWidget(Add_button);
	LyDown->addWidget(Back_button);

	LyMain ->addLayout(LyDown);


}

void rez_Cos::Init_Connect(Service& service, int& id)
{		

	QObject::connect(Add_button, &QPushButton::clicked, [&]() {
		string nr = (linie->text()).toStdString();
		if (nr == "")
		{
			QMessageBox::information(NULL, "Error", "Va rog sa adaugat un numar intreg!");

		}
		else
		{
			int ok = 0;
			for (int i = 0; i < nr.size(); i++)
			{
				if (!isdigit(nr[i]))
				{
					QMessageBox::information(NULL, "Error", "Va rog sa adaugat un numar intreg!");
					ok = 1;
					break;
				}
			}
			if (ok == 0)
			{
				int aux = atoi(nr.c_str());
				for (Carte& c : service.lista_copie)
				{
					if (c.get_id() == aux)
					{
						id = aux;
						this->close();
					}
				}
				if( id == -1)
					QMessageBox::information(NULL, "ERROR", "Va rog sa alegeti una dintre id-urile prezentate!");
			}
		}
		
	});
	
	QObject::connect(Back_button,&QPushButton::clicked, [&](){
		this -> close();
	});
}




void Cos_UI::Init_CosGUI()
{
	QVBoxLayout* LyMain  = new QVBoxLayout{};
	QFormLayout* LyForm = new QFormLayout;
	QHBoxLayout* LyDown = new QHBoxLayout{};
	QFormLayout* LyDinV = new QFormLayout;

	this -> setLayout(LyMain);
	this -> show();

	LyMain -> addWidget(lst);

	LyForm ->addRow(L_introduce,intr_linie);
	LyMain ->addLayout(LyForm);


	LyDinV -> addRow(Add_button,Golire_button);
	LyDinV -> addRow(Gen_button,Exp_button);

	LyDown -> addLayout(LyDinV);
	LyDown -> addWidget (Back_button);

	LyMain ->addLayout(LyDown);
	

}

void Cos_UI::Init_Connect(Service& service)
{
	//Add la cos
	QObject::connect(Add_button,&QPushButton::clicked, [&](){
	
	string titlu = (intr_linie->text()).toStdString();

	try {
		int nr = service.adauga_carte_in_cos(titlu);
		if (nr == 1)
		{
			int id = -1;
			rez_Cos* rez = new rez_Cos(service, id);
			rez ->exec();
			if (id != -1)
			{
				service.adauga_carte_in_cos_dupa_id(id);
				Add_Data(service);
			}
		}
		else
		{
			Add_Data(service);
		}

	}
	catch (ValidationError& err)
	{
		QMessageBox::information(NULL,"ERROR", QString::fromStdString(err.get_Message()));
	}

	});

	//Genereaza carti in cos
	QObject::connect(Gen_button, &QPushButton::clicked, [&]() {
		string nr = (intr_linie->text()).toStdString();
		int ok = 0;
		for (int i = 0; i < nr.size(); i++)
		{
			if (!isdigit(nr[i]))
			{
				QMessageBox::information(NULL, "Error", "Va rog sa adaugat un numar intreg!");
				ok = 1;
				break;
			}
		}
		if (ok == 0)
		{
			try {
				service.genereaza_cos(atoi(nr.c_str()));
				Add_Data(service);
			}
			catch (ValidationError& err) {
				QMessageBox::information(NULL,"ERROR",QString::fromStdString(err.get_Message()));
			}
		}
		});

	//Export cos
	QObject::connect(Exp_button, &QPushButton::clicked, [&]() {
		string nume = (intr_linie -> text()).toStdString();
		service.export_cos_in_fisier_service(nume);
	});

	//Goleste cos
	QObject::connect(Golire_button, &QPushButton::clicked, [&]() {
		 service.cos.lista.clear();
		 lst ->clear();
		 Add_Data(service);
	});

	//Back din cos
	QObject::connect(Back_button,&QPushButton::clicked,[&](){
	this ->close();
	});
}

void Cos_UI::Add_Data(Service& service)
{
	for (Carte& c : service.cos.lista)
	{
		string s = std::to_string(c.get_id()) + "; " + c.get_titlu() + "; " + c.get_autor() + "; " + c.get_gen() + "; " + std::to_string(c.get_anul_aparitiei());
		lst->addItem(QString::fromStdString(s));
	}
}



void Sterge_UI::Init_connect(int& id) {
	QPushButton::connect(Del, &QPushButton::clicked, [&]() {
		string id_aici = (linie->text()).toStdString();
		int ok = 0;
		for (auto i : id_aici)
			if ((!isdigit(i)) && (i == '-' && ok == 1))
			{
				QMessageBox::information(nullptr, "Error", "Valoarea data nu este de tipul intreg!");
				ok = 2;
			}

			else
			{
				if (i == '-')
					ok++;
			}

		if (ok == 0)
		{
			id = atoi(id_aici.c_str());
			this->close();
		}
		});

	QPushButton::connect(Back, &QPushButton::clicked, [&]() {
		this->close();
		});
}


void Sterge_UI::Init_fer_stergere()
{

	QVBoxLayout* LayMain = new QVBoxLayout{};
	this->setLayout(LayMain);
	this->show();

	QHBoxLayout* LayBut = new QHBoxLayout{};

	LayBut->addWidget(Del);
	LayBut->addWidget(Back);

	QLabel* label = new QLabel("Va rog sa introduceti Id-ul cartii pe care vreti sa o stergeti");


	LayMain->addWidget(label);
	LayMain->addWidget(linie);
	LayMain->addLayout(LayBut);
}

bool CarteGUI::val_intreaga(string id)
{
	string id_aici = id;
	int ok = 0;
	for (auto i : id_aici)
		if ((!isdigit(i)) && (i == '-' && ok == 1))
		{

			return false;
		}

		else
		{
			if (i == '-')
				ok++;
		}


	return true;

}

void CarteGUI::init_connect(Service& service)
{

	//Cos
	QObject::connect(Cos_button, &QPushButton::clicked, [&]() {
		Cos_UI* cos = new Cos_UI(service);
		cos -> exec();

	});
	//Cautare carte specifica
	QObject::connect(Cautare_in_lista_button, &QPushButton::clicked, [&]() {
		
		auto titlu = titlu_line->text();
		auto autor = autor_line->text();
		auto gen = gen_line->text();
		auto an = an_line->text();
		if (titlu != "" && autor != "" && gen != "" && an != "" && val_intreaga(an.toStdString()))
		{
			int id = service.cautare_carte_specifica_service(titlu.toStdString(), autor.toStdString(), gen.toStdString(), atoi(an.toStdString().c_str()));
			if(id != 0)
				id_line ->setText(QString::fromStdString(std::to_string(id)));
			else
				QMessageBox::information(nullptr, "Info", "Nu s a gasit o carte cu asa specificatii!");
		}
		else
			QMessageBox::information(nullptr, "Error", "Va rog sa verificati valorile introduse!!");

		
		});

	//Filtrare dupa titlu
	QObject::connect(Filtrare_titlu_button, &QPushButton::clicked, [&]() {
		string titlu = (titlu_filtline ->text()).toStdString();
		if(titlu == "")
			QMessageBox::information(NULL,"Error","Va rog sa introduceti un titlu valid!");
		else
		{
			service.filtrare_dupa_titlu(titlu);
			lst->clear();
			adauga_date_din_vcopie(service);
		}
		
		});

	//Filtrare dupa an
	QObject::connect(Filtrare_an_aparitie_button, &QPushButton::clicked, [&]() {
		string an = (an_filtline->text()).toStdString();
		if (an == "")
			QMessageBox::information(NULL, "Error", "Va rog sa introduceti un an valid!");
		else
		{
			int ok = 0;
			for (int i = 0; i < an.length(); i++)
			{
				if (!isdigit(an[i]))
				{
					QMessageBox::information(NULL, "Error", "Va rog sa introduceti un an intreg!");
					ok = 1;
					break;
				}
					
			}
			if (ok == 0)
			{
				
				service.filtrare_dupa_an_aparitie(atoi(an.c_str()));
				lst->clear();
				adauga_date_din_vcopie(service);
			}
			
		}

		});


	//Sortare dupa titlu
	QObject::connect(Sortare_titlu_button, & QPushButton::clicked, [&]() {
			service.sortare_dupa_titlu();
			lst->clear();
			adauga_date_din_vcopie(service);
	});

	//Sortare dupa autor
	QObject::connect(Sortare_autor_button, &QPushButton::clicked, [&]() {
		service.sortare_dupa_autor();
		lst->clear();
		adauga_date_din_vcopie(service);
		});

	//Sortare dupa an si gen
	QObject::connect(Sortare_an_si_gen_button, &QPushButton::clicked, [&]() {
		service.sortare_an_si_gen();
		lst->clear();
		adauga_date_din_vcopie(service);
		});

	//Afisare lista
	QObject::connect(Afisare_lista_button, &QPushButton::clicked, [&]() {
		lst->clear();
		adauga_date(service);
		});

	//Exit
	QObject::connect(Exit_button, &QPushButton::clicked, [&]() {
		close();
	});

	//Adauga
	QObject::connect(Add_button, &QPushButton::clicked, [&]() {
		auto id = id_line->text();
		auto titlu = titlu_line->text();
		auto autor = autor_line->text();
		auto gen = gen_line->text();
		auto an = an_line->text();
		if (val_intreaga(id.toStdString()) && id != "" && titlu != "" && autor != "" && gen != "" && an != "" && val_intreaga(an.toStdString()))
		{

			try {
				service.adauga_carte_service(atoi((id.toStdString()).c_str()), titlu.toStdString(), autor.toStdString(), gen.toStdString(), atoi((an.toStdString()).c_str()));

				string s = id.toStdString() + "; " + titlu.toStdString() + "; " + autor.toStdString() + "; " + gen.toStdString() + "; " + an.toStdString();
				lst->addItem(QString::fromStdString(s));
			}
			catch (ValidationError& err)
			{
				QMessageBox::information(nullptr, "Eroare!", QString::fromStdString(err.get_Message()));
			}
		}
		else
			QMessageBox::information(nullptr, "Error", "Va rog sa verificati valorile introduse!!");

		adauga_butoane(service);
		});

	//Undo
	QObject::connect(Undo_button, &QPushButton::clicked, [&]() {
		try {
			service.undo();
			lst->clear();
			adauga_date(service);
		}
		catch (ValidationError& err)
		{
			QMessageBox::information(nullptr, "Eroare!", QString::fromStdString(err.get_Message()));
		}
		adauga_butoane(service);
		});

	//Sterge
	QObject::connect(Delete_button, &QPushButton::clicked, [&]() {

		int id = 0;
		Sterge_UI* Sec_Win = new Sterge_UI(id);

		Sec_Win->exec();

		if (id != 0)
		{
			try {
				service.sterge_carte_service(id);
			}
			catch (ValidationError& err)
			{
				QMessageBox::information(nullptr, "Eroare!", QString::fromStdString(err.get_Message()));
			}
		}


		lst->clear();
		adauga_date(service);

		adauga_butoane(service);
		});


	QObject::connect(lst, &QListWidget::itemSelectionChanged, [&]() {

		auto sel = lst->selectedItems();
		if (sel.isEmpty())
		{
			id_line->setText("");
			titlu_line->setText("");
			autor_line->setText("");
			gen_line->setText("");
			an_line->setText("");
		}
		else
		{
			auto selItem = sel.at(0);
			string s = (selItem->text()).toStdString();

			std::istringstream stream(s);

			string parte;

			std::getline(stream, parte, ';');
			id_line->setText(QString::fromStdString(parte));

			std::getline(stream, parte, ';');
			parte.erase(0, 1);
			titlu_line->setText(QString::fromStdString(parte));

			std::getline(stream, parte, ';');
			parte.erase(0, 1);
			autor_line->setText(QString::fromStdString(parte));

			std::getline(stream, parte, ';');
			parte.erase(0, 1);
			gen_line->setText(QString::fromStdString(parte));

			std::getline(stream, parte, ';');
			parte.erase(0, 1);
			an_line->setText(QString::fromStdString(parte));

		}
		});


	QObject::connect(Modify_button, &QPushButton::clicked, [&]() {
		auto id = id_line->text();
		auto titlu = titlu_line->text();
		auto autor = autor_line->text();
		auto gen = gen_line->text();
		auto an = an_line->text();



		if (titlu != "")
		{
			try {
				service.modificare_titlu_service(atoi(((id).toStdString()).c_str()), (titlu).toStdString());

				if (autor != "")
				{
					try {


						service.modificare_autor_service(atoi(((id).toStdString()).c_str()), (autor).toStdString());
					}
					catch (ValidationError& err)
					{
						QMessageBox::information(nullptr, "Eroare!", QString::fromStdString(err.get_Message()));
					}
				}

				if (gen != "")
				{
					try {
						service.modificare_gen_service(atoi(((id).toStdString()).c_str()), (gen).toStdString());
					}
					catch (ValidationError& err)
					{
						QMessageBox::information(nullptr, "Eroare!", QString::fromStdString(err.get_Message()));
					}
				}
				if (an != "")
				{
					try {
						service.modificare_an_aparitie_service(atoi(((id).toStdString()).c_str()), atoi(((id).toStdString()).c_str()));

					}
					catch (ValidationError& err)
					{
						QMessageBox::information(nullptr, "Eroare!", QString::fromStdString(err.get_Message()));
					}
				}
			}
			catch (ValidationError& err)
			{
				QMessageBox::information(nullptr, "Eroare!", QString::fromStdString(err.get_Message()));
			}
		}



		lst->clear();
		adauga_date(service);
		adauga_butoane(service);
		});
}

void CarteGUI::adauga_date(Service& service)
{
	vector <Carte> lista = service.repo.citire_din_fisier();
	for (const Carte& c : lista)
	{
		string s = std::to_string(c.get_id()) + "; " + c.get_titlu() + "; " + c.get_autor() + "; " + c.get_gen() + "; " + std::to_string(c.get_anul_aparitiei());
		lst->addItem(QString::fromStdString(s));
	}
}

void CarteGUI::adauga_date_din_vcopie(Service& service)
{
	for (const Carte& c : service.lista_copie)
	{
		string s = std::to_string(c.get_id()) + "; " + c.get_titlu() + "; " + c.get_autor() + "; " + c.get_gen() + "; " + std::to_string(c.get_anul_aparitiei());
		lst->addItem(QString::fromStdString(s));
	}
}

void CarteGUI::initializeaza_GUI()
{


	QFormLayout* Lyform = new QFormLayout;
	QVBoxLayout* Lydrept = new QVBoxLayout{};
	QHBoxLayout* LyMain = new QHBoxLayout{};
	QVBoxLayout* LyStanga = new QVBoxLayout{};
	QHBoxLayout* LyButoane_filsort1 = new QHBoxLayout{};
	QHBoxLayout* LyButoane_filsort1_2 = new QHBoxLayout{};
	QHBoxLayout* LyButoane_filsort2 = new QHBoxLayout{};

	setLayout(LyMain);


	//Se adauga lista
	LyStanga->addWidget(lst);

	//Butoane filtrari si sortari
	LyButoane_filsort1->addWidget(Filtrare_titlu_button);
	LyButoane_filsort1->addWidget(titlu_filtline);

	LyButoane_filsort1_2->addWidget(Filtrare_an_aparitie_button);
	LyButoane_filsort1_2->addWidget(an_filtline);
	
	
	
	LyButoane_filsort2->addWidget(Sortare_titlu_button);
	LyButoane_filsort2->addWidget(Sortare_autor_button);
	LyButoane_filsort2->addWidget(Sortare_an_si_gen_button);
	LyButoane_filsort2->addWidget(Afisare_lista_button);
	

	LyStanga->addLayout(LyButoane_filsort1);
	LyStanga->addLayout(LyButoane_filsort1_2);
	LyStanga->addLayout(LyButoane_filsort2);
	
	LyMain->addLayout(LyStanga);
	

	//Text:
	Lyform->addRow("Id: ", id_line);
	Lyform->addRow("Titlu: ", titlu_line);
	Lyform->addRow("Autor: ", autor_line);
	Lyform->addRow("Gen: ", gen_line);
	Lyform->addRow("An", an_line);

	Lydrept->addLayout(Lyform);

	//Butoane
	QHBoxLayout* LyButtons = new QHBoxLayout{};

	LyButtons->addWidget(Add_button);
	LyButtons->addWidget(Delete_button);
	LyButtons->addWidget(Modify_button);
	LyButtons->addWidget(Undo_button);
	LyButtons->addWidget(Cautare_in_lista_button);
	LyButtons->addWidget(Cos_button);
	LyButtons->addWidget(Exit_button);
	
	
	Lydrept->addLayout(LyButtons);

	LyMain->addLayout(Lydrept);
	
	//Butoane dinamice
	Buton_dinamic -> setLayout(LyBtnD);
	LyMain -> addWidget(Buton_dinamic);


}

void CarteGUI::adauga_butoane(Service& service) {
	vector <Carte> lista = service.repo.citire_din_fisier();
	std::unordered_map <std::string, int> map;

	sterge_butoane();
	for (const Carte& c : lista)
	{
		
		if(map.count(c.get_titlu()) == 0)
		{
			int a = 1;
			map.insert({c.get_titlu(),a});
			auto buton = new QPushButton(QString::fromStdString(c.get_titlu()));
			LyBtnD->addWidget(buton);
			butoane.push_back(buton);
			std::string autor = c.get_autor();

			QObject::connect(buton, &QPushButton::clicked, [&service, autor]() {

				std::unordered_map <std::string, Carte_dto> harta = service.frecventa_autor();
				QMessageBox::information(nullptr, "Info", QString::fromStdString(std::to_string(harta.at(autor).get_frecventa())));

				});
		}
		
	}
}

void CarteGUI::sterge_butoane() {
	
	for (QPushButton* b : butoane)
	{
		if (b != nullptr)
		{
			LyBtnD->removeWidget(b);
			delete b;

		}
		
	}
	butoane.clear();
	
	
}