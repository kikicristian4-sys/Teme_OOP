#pragma once
#include "Carte.h"
#include "Repository.h"


class ActiuneUndo {
	public: 
	virtual void doUndo() = 0;

	virtual ~ActiuneUndo(){};

};

class UndoAdauga : public ActiuneUndo {
	private:
	Carte carte_adaugata;
	Repository& repo;

	public:
		UndoAdauga(const Carte& carte, Repository& repo): carte_adaugata{carte}, repo{repo}{};
		void doUndo() override {
		repo.sterge_carte(carte_adaugata.get_id());
		}

	
};

class UndoStergere : public ActiuneUndo {

	private:
	Carte carte_stearsa;
	Repository& repo;
	public:
	UndoStergere(const Carte& carte, Repository repo): carte_stearsa{carte},repo{repo}{};
	void doUndo() override {
		repo.adauga_carte(carte_stearsa);
	}

};

class UndoModificare : public ActiuneUndo {

private:
Carte carte_inaintea_modificarii;
Repository& repo;
public:
UndoModificare(const Carte& carte, Repository& repo): repo{repo},carte_inaintea_modificarii{carte}{};
void doUndo() override {
	repo.modificare_an_aparitie( carte_inaintea_modificarii.get_id(), carte_inaintea_modificarii.get_anul_aparitiei());
	repo.modificare_titlu(carte_inaintea_modificarii.get_id(), carte_inaintea_modificarii.get_titlu());
	repo.modificare_autor(carte_inaintea_modificarii.get_id(), carte_inaintea_modificarii.get_autor());
	repo.modificare_gen(carte_inaintea_modificarii.get_id(), carte_inaintea_modificarii.get_gen());
	}
};