#include "Biblioteca.h"

Biblioteca::Biblioteca(char* n, int nr, int nr_pers)
{
	if (n != nullptr)
	{
		this->nume = new char[strlen(n) + 1];
		strcpy(this->nume, n);
	}
	else
		this->nume = nullptr;
	this->nr_cr_carti = 0;
	this->arti = new Articol* [nr*2];
	this->nr_cr_pers = 0;
	this->pers = new Persoana* [nr_pers*2];

}

void Biblioteca::add_art( Articol& art)
{
	this->arti[this->nr_cr_carti++] = new Articol(art);
}

void Biblioteca::add_pers(Persoana& p)
{
	this->pers[this->nr_cr_pers++] = new Persoana(p);
}

Articol& Biblioteca::search_add_art(char* ar)
{
	for (int i = 0; i < this->nr_cr_carti; i++)
		if (strcmp(this->arti[i]->get_barcode(), ar) == 0)
		{
			this->pers[this->nr_cr_pers-1]->add_ar(*this->arti[i]);
			break;
		}
	return *new Articol();
}

void Biblioteca::afis_art()
{
	for (int i = 0; i < this->nr_cr_carti; i++)
		this->arti[i]->detalii();
}

void Biblioteca::afis_pers()
{
	for (int i = 0; i < this->nr_cr_pers; i++)
	{
		this->pers[i]->print();
		cout << "\nCartile imprumutate: ";
		this->pers[i]->afis_carti_imprum();
		cout << "\nAmenzi:";
		this->pers[i]->detalii();
		cout << "\n";
	}
}

bool Biblioteca::este_art(char* tit)
{
	for (int i = 0; i < this->nr_cr_carti; i++)
		if (strcmp(tit, this->arti[i]->get_title()) == 0)
			if (this->arti[i]->disponibilitate())
				return true;
	return false;
}

bool Biblioteca::este_pers(char* cnp)
{
	for (int i = 0; i < this->nr_cr_pers; i++)
		if (strcmp(cnp, this->pers[i]->get_cnp()) == 0)
			return true;
	return false;
}

void Biblioteca::take_book(char* np, char* ca)
{
	int k = 0;
	for (int i = 0; i < this->nr_cr_pers; i++)
		if (strcmp(np, this->pers[i]->get_cnp()) == 0)
		{
			this->pers[i]->checkout(ca);
			break;
		}
}

bool Biblioteca::imprumuta(char* cnp, char* ar)
{
	for(int i=0;i<this->nr_cr_pers;i++)
		if(strcmp(cnp,this->pers[i]->get_cnp())==0)
			if (this->pers[i]->verifica_imprumut())
				for(int j=0;j<this->nr_cr_carti;j++)
					if (strcmp(ar, this->arti[i]->get_title()) == 0)
						if(this->arti[i]->disponibilitate())
						{
							this->pers[i]->add_ar(*this->arti[j]);
							cout << "Introduceti datele pentru imprumut in format zz-ll-aaaa: \n";
							char s[14];
							char *di, *ds;
							cin >> s;
							di = new char[strlen(s)+1];
							strcpy(di, s);
							cin >> s;
							ds = new char[strlen(s) + 1];
							strcpy(ds, s);
							this->arti[j]->inchiriat(di, ds);
							this->arti[j]->locatie();
							return true;
						}
	return false;
}

void Biblioteca::amenzi()
{
	for (int i = 0; i < this->nr_cr_pers; i++)
		this->pers[i]->genereaza_amenda();
}

void Biblioteca::search_afis(char* titlu)
{
	for (int i = 0; i < this->nr_cr_carti; i++)
		if (strcmp(titlu, this->arti[i]->get_title()) == 0)
		{
			this->arti[i]->info();
			break;
		}
}

void Biblioteca::afiseaza_amenzi_nr_imprumut(char* cnp)
{
	for(int i=0;i<this->nr_cr_pers;i++)
		if (strcmp(cnp, this->pers[i]->get_cnp()) == 0)
		{
			this->pers[i]->detalii();
			cout << "\nnr carti imprumutate: " << this->pers[i]->nr_imprumut() << "\n";
			break;
		}
}

void Biblioteca::plateste(char* cnp, double c)
{
	for (int i = 0; i < this->nr_cr_pers; i++)
		if (strcmp(cnp, this->pers[i]->get_cnp()) == 0)
		{
			this->pers[i]->Plateste(c);
			break;
		}
}

void Biblioteca::update_all(char* f1, char* f2)
{
	ofstream out(f1, ofstream::app);
	out << this->nume << "," << this->nr_cr_carti << "," << this->nr_cr_pers << '\n';
	out.close();
	for (int i = 0; i < this->nr_cr_carti; i++)
	{
		this->arti[i]->updatefile_a(f1);
		delete this->arti[i];
	}
	for (int i = 0; i < this->nr_cr_pers; i++)
	{
		this->pers[i]->update_p(f2);
		delete this->pers[i];
	}
}

Biblioteca::~Biblioteca()
{
	if (this->nume != nullptr)
		delete[] nume;
}
