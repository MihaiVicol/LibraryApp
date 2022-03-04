#pragma once
#include <string>
#include<iostream>
#include<fstream>
using namespace std;
class Carte
{
private:
	char* ISBN;
	char* titlu;
	char* autor;
	char* topic;
	char* editor;
	char* limba;
	int nr_pag;
public:
	Carte();
	Carte(char*, char*, char*, char*, char*, char*, int);
	Carte(const Carte&);
	~Carte();
	void init(char*, char*, char*, char*, char*, char*, int);
	void info();
	char* get_title();
	void update_file(char*);
};

