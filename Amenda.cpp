#include "Amenda.h"

Amenda::Amenda(int nr, double c, bool b)
{
	this->nr = nr;
	this->cost = c;
	this->status = b;
}

Amenda::Amenda(const Amenda& a)
{
	this->cost = a.cost;
	this->nr = a.nr;
	this->status = a.status;
}

void Amenda::adauga(double co)
{
	if (this->nr == 0)
		this->nr = 1;
	else if (this->verifica())
		this->cost = this->cost + co;
	else {
		this->nr = this->nr + 1;
		this->cost = this->cost + co;
	}
	this->status = true;
}

void Amenda::Plateste(double cos)
{
	this->cost = this->cost - cos;
	if(this->cost==0)
	this->status = false;
}

void Amenda::detalii()
{
	
	cout <<"Cost: "<< this->cost;
}

bool Amenda::verifica()
{
	
	if (this->status)
		return true;
	else
		return false;
}

void Amenda::update(char* f)
{
	ofstream out(f, ofstream::app);
	out << this->nr << "," << this->cost << "," << this->status << ",";
}
