#include "CarteGUI.h"
#include <unordered_map>

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
		if (val_intreaga(id.toStdString()) && titlu != "" && autor != "" && gen != "" && val_intreaga(an.toStdString()))
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

void CarteGUI::initializeaza_GUI()
{


	QFormLayout* Lyform = new QFormLayout;
	QVBoxLayout* Lydrept = new QVBoxLayout{};
	QHBoxLayout* LyMain = new QHBoxLayout{};
	setLayout(LyMain);


	//Se adauga lista
	LyMain->addWidget(lst);

	//Text:
	Lyform->addRow("Id: ", id_line);
	Lyform->addRow("Titlu: ", titlu_line);
	Lyform->addRow("Autor: ", autor_line);
	Lyform->addRow("Gen: ", gen_line);
	Lyform->addRow("An", an_line);


	//Butoane
	QHBoxLayout* LyButtons = new QHBoxLayout{};

	LyButtons->addWidget(Add_button);
	LyButtons->addWidget(Delete_button);
	LyButtons->addWidget(Modify_button);
	LyButtons->addWidget(Undo_button);
	LyButtons->addWidget(Exit_button);



	Lydrept->addLayout(Lyform);
	Lydrept->addLayout(LyButtons);

	

	LyMain->addLayout(Lydrept);
	
	Buton_dinamic -> setLayout(LyBtnD);
	LyMain -> addWidget(Buton_dinamic);
}

void CarteGUI::adauga_butoane(Service& service) {
	vector <Carte> lista = service.repo.citire_din_fisier();
	for (const Carte& c : lista)
	{
		auto buton = new QPushButton(QString::fromStdString(c.get_titlu()));
		LyBtnD -> addWidget(buton);
		std::string autor = c.get_autor();

		QObject::connect(buton, &QPushButton::clicked, [&service,autor]() {
			
			std::unordered_map <std::string, Carte_dto> harta = service.frecventa_autor();
			QMessageBox::information(nullptr,"Info",QString::fromStdString(std::to_string(harta.at(autor).get_frecventa())));

			});
	}
}
