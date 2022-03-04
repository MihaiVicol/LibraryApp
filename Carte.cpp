#include "Carte.h"

void Carte::init(char* ISBN, char* t, char* a, char* to, char* e, char* l, int pag)
{
	if (ISBN != nullptr)
	{
		this->ISBN = new char[strlen(ISBN) + 1];
		strcpy(this->ISBN, ISBN);
	}
	else
		this->ISBN = nullptr;
	if (t != nullptr)
	{
		this->titlu = new char[strlen(t) + 1];
		strcpy(this->titlu, t);
	}
	else
		this->titlu = nullptr;
	if (a != nullptr)
	{
		this->autor = new char[strlen(a) + 1];
		strcpy(this->autor, a);
	}
	else
		this->autor = nullptr;
	if (to != nullptr)
	{
		this->topic = new char[strlen(to) + 1];
		strcpy(this->topic, to);
	}
	else
		this->topic = nullptr;
	if (e != nullptr)
	{
		this->editor = new char[strlen(e) + 1];
		strcpy(this->editor, e);
	}
	else
		this->editor = nullptr;
	if (l != nullptr)
	{
		this->limba = new char[strlen(l) + 1];
		strcpy(this->limba, l);
	}
	else
		this->limba = nullptr;
	this->nr_pag = pag;
}

void Carte::info()
{
	cout << "Titlu: " << this->titlu;
	cout << "   Autor: " << this->autor;
	cout << "   Topic: " << this->topic;
	cout << "   Editura: " << this->editor;
	cout << "   In limba:" << this->limba;
	cout << "   Pagini:" << this->nr_pag;
	cout << endl;
}

char* Carte::get_title()
{

	return this->titlu;
}

void Carte::update_file(char* f)
{
	ofstream out(f, ofstream::app);
	out << this->ISBN << "," << this->titlu << "," << this->autor << "," << this->topic << "," << this->editor << "," << this->limba << "," << this->nr_pag << ",";
}

Carte::Carte()
{
	this->autor = this->editor = this->ISBN = this->topic = this->titlu = this->limba = nullptr;
	this->nr_pag = 0;
}

Carte::Carte(char* ISBN, char* t, char* a, char* to, char* e, char* l, int pag)
{
	this->init(ISBN, t, a, to, e, l, pag);
}

Carte::Carte(const Carte& a)
{
	this->init(a.ISBN, a.titlu, a.autor, a.topic, a.editor, a.limba, a.nr_pag);
}

Carte::~Carte()
{
	if (this->autor != nullptr)
		delete[] this->autor;
	if (this->editor != nullptr)
		delete[] this->editor;
	if(this->ISBN != nullptr)
		delete[] this->ISBN;
	if (this->topic != nullptr)
		delete[] this->topic;
	if(this->limba != nullptr)
		delete[] this->limba;
	if (this->titlu != nullptr)
		delete[] this->titlu;

}
