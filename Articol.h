#pragma once
#include "Carte.h"
#include<ctime>
class Articol : public Carte
{
private:
	char* barcode;
	bool doar_referinta;
	char* data_imprumut;
	char* data_scadenta;
	double pret;
	char* format;
	char* status;
	char* data_achizitie;
	char* data_publicare;
	char* sectiune;
	int nr_raft;
	int nr_rand;
public:
	Articol();
	Articol(char*, char*, char*, char*, char*, char*, int, char*, bool, char*, char*, double, char*, char*, char*, char*, char*, int, int);
	Articol(const Articol&);
	~Articol();
	void init(char*, bool, char*, char*, double, char*, char*, char*, char*, char*, int, int);
	bool disponibilitate();
	void detalii();
	void print_art();
	void locatie();
	void inchiriat(char*, char*);
	bool outdated();
	char* get_barcode();
	void updatefile_a(char*);
	void change_disp();
	//Articol& operator=(const Articol&);
};

