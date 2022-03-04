#pragma once
#include "Amenda.h"
#include "Articol.h"
#include <cstring>
class Persoana:public Amenda
{
private:
	char* nume;
	char* telefon;
	char* email;
	char* adresa;
	char* cnp;
	int nr_carti;
	Articol** art;
public:
	Persoana(char*, char*, char*, char*, char*, int, double, bool);
	Persoana(const Persoana&);
	bool verifica_imprumut();
	int nr_imprumut();
	void add_ar(Articol&);
	//Persoana& operator =(Persoana&);
	void print();
	char* get_cnp();
	void checkout(char*);
	void afis_carti_imprum();
	void genereaza_amenda();
	void update_p(char*);
	~Persoana();

};

