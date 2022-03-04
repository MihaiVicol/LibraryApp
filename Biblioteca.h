#pragma once
#include "Articol.h"
#include "Persoana.h"
#include<iostream>
#include<cstring>
class Biblioteca
{
private:
	char* nume;
	int nr_cr_carti;
	int nr_cr_pers;
	Articol** arti;
	Persoana** pers;
public:
	Biblioteca(char*, int, int);
	void add_art( Articol&);
	void add_pers(Persoana&);
	Articol& search_add_art(char*);
	void afis_art();
	void afis_pers();
	bool este_art(char*);
	bool este_pers(char*);
	void take_book(char*,char*);
	bool imprumuta(char*,char*);
	void amenzi();
	void search_afis(char*);
	void afiseaza_amenzi_nr_imprumut(char*);
	void plateste(char*, double);
	void update_all(char*, char*);
	~Biblioteca();
};

