#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Amenda
{
private:
	int nr;
	double cost;
	bool status;
public:
	Amenda(int, double, bool);
	Amenda(const Amenda&);
	void adauga(double);
	void Plateste(double);
	void detalii();
	bool verifica();
	void update(char*);
};

