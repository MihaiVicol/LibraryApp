#include "Persoana.h"

Persoana::Persoana(char* n, char* t, char* e, char* a, char* cnp, int d, double p, bool b):Amenda(d,p,b)
{
	if (n != nullptr)
	{
		this->nume = new char[strlen(n) + 1];
		strcpy(this->nume, n);
	}
	else this->nume = nullptr;
	if (t != nullptr)
	{
		this->telefon = new char[strlen(t) + 1];
		strcpy(this->telefon, t);
	}
	else this->telefon = nullptr;
	if (e != nullptr)
	{
		this->email = new char[strlen(e) + 1];
		strcpy(this->email, e);
	}
	else this->email = nullptr;
	if (a != nullptr)
	{
		this->adresa = new char[strlen(a) + 1];
		strcpy(this->adresa, a);
	}
	else this->adresa = nullptr;
	if (cnp != nullptr)
	{
		this->cnp = new char[strlen(cnp) + 1];
		strcpy(this->cnp, cnp);
	}
	else this->cnp = nullptr;
	this->nr_carti = 0;
	this->art = new Articol* [5];
}

Persoana::Persoana(const Persoana& p):Amenda(p)
{
	if (p.nume != nullptr)
	{
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
	}
	else this->nume = nullptr;
	if (p.telefon != nullptr)
	{
		this->telefon = new char[strlen(p.telefon) + 1];
		strcpy(this->telefon, p.telefon);
	}
	else this->telefon = nullptr;
	if (p.email != nullptr)
	{
		this->email = new char[strlen(p.email) + 1];
		strcpy(this->email, p.email);
	}
	else this->email = nullptr;
	if (p.adresa != nullptr)
	{
		this->adresa = new char[strlen(p.adresa) + 1];
		strcpy(this->adresa, p.adresa);
	}
	else this->adresa = nullptr;
	if (p.cnp != nullptr)
	{
		this->cnp = new char[strlen(p.cnp) + 1];
		strcpy(this->cnp, p.cnp);
	}
	else this->cnp = nullptr;
	this->nr_carti = 0;
	this->art = new Articol * [5];
}

bool Persoana::verifica_imprumut()
{
	if (this->nr_carti > 5)
		return false;
	else if (verifica())
		return false;
	else
		return true;
}

int Persoana::nr_imprumut()
{
	return this->nr_carti;
}

void Persoana::add_ar(Articol& a)
{
	this->art[this->nr_carti] = new Articol(a);
	this->nr_carti = this->nr_carti + 1;
}

/*Persoana& Persoana::operator=(Persoana& p)
{
	if (this == &p)
		return *this;
	if (p.adresa != nullptr)
	{
		if (this->adresa != nullptr)
			delete[] this->adresa;
		this->adresa = new char[strlen(p.adresa) + 1];
		strcpy(this->adresa, p.adresa);
	}
	else
		this->adresa = nullptr;
	if (p.cnp != nullptr)
	{
		if (this->cnp != nullptr)
			delete[] this->cnp;
		this->cnp = new char[strlen(p.cnp) + 1];
		strcpy(this->cnp, p.cnp);
	}
	else
		this->cnp = nullptr;
	if (p.nume != nullptr)
	{
		if (this->nume != nullptr)
			delete[] this->nume;
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
	}
	else
		this->nume = nullptr;
	if (p.email != nullptr)
	{
		if (this->email != nullptr)
			delete[] this->email;
		this->email = new char[strlen(p.email) + 1];
		strcpy(this->email, p.email);
	}
	else
		this->email = nullptr;
	if (p.telefon != nullptr)
	{
		if (this->telefon != nullptr)
			delete[] this->telefon;
		this->telefon = new char[strlen(p.telefon) + 1];
		strcpy(this->telefon, p.telefon);
	}
	else
		this->telefon = nullptr;
	this->nr_carti = p.nr_carti;
	Amenda::Amenda(p);
	for (int i = 0; i < p.nr_carti; i++)
		this->art[i] = p.art[i];
	return *this;
}
*/
void Persoana::print()
{
	cout <<"Nume: "<< this->nume<<endl<<"CNP: "<<this->cnp<<endl<<"E-mail: "<<this->email<<endl<<"Telefon: "<<this->telefon<<endl<<"Adresa: "<<this->adresa<<endl;
}

char* Persoana::get_cnp()
{
	return this->cnp;
}

void Persoana::checkout(char* c)
{
	for (int i = 0; i < this->nr_carti; i++)
		if(this->art[i]!=nullptr)
		if (strcmp(c, this->art[i]->get_title()) == 0)
		{
			this->art[i]->change_disp();
			//delete this->art[i];
			this->art[i] = nullptr;
			break;
		}
}
void Persoana::afis_carti_imprum()
{
	for (int i = 1; i < this->nr_carti; i++)
		if(this->art[i])
			this->art[i]->detalii();
}
void Persoana::genereaza_amenda()
{
	for (int i = 0; i < this->nr_carti; i++)
		if (this->art[i]->outdated())
			this->adauga(1.2);
}
void Persoana::update_p(char* f)
{
	ofstream out(f, ofstream::app);
	out << this->nume << "," << this->telefon << "," << this->email << "," << this->adresa << "," << this->cnp << ",";
	out.close();
	this->update(f);
	ofstream ou(f, ofstream::app);
	ou << this->nr_carti << ",";
	for (int i = 0; i < this->nr_carti; i++)
	{
		ou << this->art[i]->get_barcode();
		if(i!=this->nr_carti-1)
			ou << ",";
	}
	ou << '\n';
}
Persoana::~Persoana()
{
	if (this->nume != nullptr)
		delete[] this->nume;
	if (this->adresa != nullptr)
		delete[] this->adresa;
	if (this->telefon != nullptr)
		delete[] this->telefon;
	if (this->email != nullptr)
		delete[] this->email;
	if (this->cnp != nullptr)
		delete[] this->cnp;
}
