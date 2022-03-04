#include "Articol.h"

void Articol::init(char* c, bool ref, char* di, char* ds, double p, char* f, char* s, char* da, char* dp, char* sec, int raft, int rand)
{
	if (c != nullptr)
	{
		this->barcode = new char[strlen(c) + 1];
		strcpy(this->barcode, c);
	}
	else
		this->barcode = nullptr;
	this->doar_referinta = ref;
	if (di != nullptr)
	{
		this->data_imprumut = new char[strlen(di) + 1];
		strcpy(this->data_imprumut, di);
	}
	else
		this->data_imprumut = nullptr;
	if (ds != nullptr)
	{
		this->data_scadenta = new char[strlen(ds) + 1];
		strcpy(this->data_scadenta, ds);
	}
	else
		this->data_scadenta = nullptr;
	this->pret = p;
	if (f != nullptr)
	{
		this->format = new char[strlen(f) + 1];
		strcpy(this->format, f);
	}
	else
		this->format = nullptr;
	if (s != nullptr)
	{
		this->status = new char[strlen(s) + 1];
		strcpy(this->status, s);
	}
	else
		this->status = nullptr;
	if (da != nullptr)
	{
		this->data_achizitie = new char[strlen(da) + 1];
		strcpy(this->data_achizitie, da);
	}
	else
		this->data_achizitie = nullptr;
	if (dp != nullptr)
	{
		this->data_publicare = new char[strlen(dp) + 1];
		strcpy(this->data_publicare, dp);
	}
	else
		this->data_publicare = nullptr;
	if (sec != nullptr)
	{
		this->sectiune = new char[strlen(sec) + 1];
		strcpy(this->sectiune, sec);
	}
	else
		this->sectiune = nullptr;
	this->nr_raft = raft;
	this->nr_rand = rand;

}

bool Articol::disponibilitate()
{
	if (this->doar_referinta == true)
		return false;
	else if (strcmp(this->status, "inchiriat") == 0)
		return false;
	else if (strcmp(this->status, "pierdut") == 0)
		return false;
	else
		return true;
}

void Articol::detalii()
{
	cout << "Articol:" << endl;
	info();
}

void Articol::print_art()
{
	cout << "Articol:" << endl;
	cout << "   Barcode: " << this->barcode;
	cout << "   Data imprumut: " << this->data_imprumut << endl;
	cout << "   Data scadenta: " << this->data_scadenta << endl;
	cout << "   Pret: " << this->pret << endl;
	cout << "   Format: " << this->format << endl;
	cout << "   Data achizitie: " << this->data_achizitie << endl;
	cout << "   Data publicare: " << this->data_publicare << endl;
}

void Articol::locatie()
{
	cout << "Articolul se afla la sectiunea " << this->sectiune << ", pe raftul " << this->nr_raft << " si randul " << this->nr_rand<<endl;
}

void Articol::inchiriat(char* di, char* ds)
{
	if (this->data_imprumut != nullptr)
		delete[] this->data_imprumut;
	if (this->data_scadenta != nullptr)
		delete[] this->data_scadenta;
	this->data_imprumut = new char[strlen(di) + 1];
	strcpy(this->data_imprumut, di);
	this->data_scadenta = new char[strlen(ds) + 1];
	strcpy(this->data_scadenta, ds);
	if (this->status != nullptr)
		delete[] this->status;
	this->status = new char[10];
	strcpy(this->status, "inchiriat");
}

bool Articol::outdated()
{
	char* tmp;
	tmp = strtok(this->data_scadenta, "-");
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int zic = atoi(tmp);
	tmp = strtok(nullptr, "-");
	int lc = atoi(tmp);
	tmp = strtok(nullptr, "-");
	int anc = atoi(tmp);
	int an = 1900 + ltm->tm_year,luna= 1 + ltm->tm_mon;
	if (anc > an)
		return false;
	else if (anc == an && lc > luna)
		return false;
	else if (anc == an && lc == luna && zic > ltm->tm_mday)
		return false;
	else return true;
}

char* Articol::get_barcode()
{
	return this->barcode;
}

void Articol::updatefile_a(char* f)
{
	ofstream out(f,ofstream::app);
	this->update_file(f);
	out << this->barcode << "," << this->doar_referinta << "," << this->data_imprumut << "," << this->data_scadenta << "," << this->pret << "," << this->format << "," << this->status << "," << this->data_achizitie << "," << this->data_publicare << "," << this->sectiune << "," << this->nr_raft << "," << this->nr_rand << '\n';
}

void Articol::change_disp()
{
	this->status = new char[11];
	strcpy(this->status, "disponibil");
}

/*Articol& Articol::operator =(const Articol& art)
{
	if (this == &art)
		return *this;
	if (art.barcode != nullptr)
	{
		if (this->barcode != nullptr)
			delete[] this->barcode;
		this->barcode = new char[strlen(art.barcode) + 1];
		strcpy(this->barcode, art.barcode);
	}
	else
		this->barcode = nullptr;
	if (art.data_achizitie != nullptr)
	{
		if (this->data_achizitie != nullptr)
			delete[] this->data_achizitie;
		this->data_achizitie = new char[strlen(art.data_achizitie) + 1];
		strcpy(this->data_achizitie, art.data_achizitie);
	}
	else
		this->data_achizitie = nullptr;
	if (art.data_imprumut != nullptr)
	{
		if (this->data_imprumut != nullptr)
			delete[] this->data_imprumut;
		this->data_imprumut = new char[strlen(art.data_imprumut) + 1];
		strcpy(this->data_imprumut, art.data_imprumut);
	}
	else
		this->data_imprumut = nullptr;
	if (art.data_publicare != nullptr)
	{
		if (this->data_publicare != nullptr)
			delete[] this->data_publicare;
		this->data_publicare = new char[strlen(art.data_publicare) + 1];
		strcpy(this->data_publicare, art.data_publicare);
	}
	else
		this->data_publicare = nullptr;
	if (art.data_scadenta != nullptr)
	{
		if (this->data_scadenta != nullptr)
			delete[] this->data_scadenta;
		this->data_scadenta = new char[strlen(art.data_scadenta) + 1];
		strcpy(this->data_scadenta, art.data_scadenta);
	}
	else
		this->data_scadenta = nullptr;
	if (art.format != nullptr)
	{
		if (this->format != nullptr)
			delete[] this->format;
		this->format = new char[strlen(art.format) + 1];
		strcpy(this->format, art.format);
	}
	else
		this->format = nullptr;
	if (art.status != nullptr)
	{
		if (this->status != nullptr)
			delete[] this->status;
		this->status = new char[strlen(art.status) + 1];
		strcpy(this->status, art.status);
	}
	else
		this->status = nullptr;
	if (art.sectiune != nullptr)
	{
		if (this->sectiune != nullptr)
			delete[] this->sectiune;
		this->sectiune = new char[strlen(art.sectiune) + 1];
		strcpy(this->sectiune, art.sectiune);
	}
	else
		this->sectiune = nullptr;
	this->doar_referinta = art.doar_referinta;
	this->pret = art.pret;
	this->nr_raft = art.nr_raft;
	this->nr_rand = art.nr_rand;
	Carte::Carte(art);
	return *this;
}
*/
Articol::Articol():Carte()
{
	this->barcode = this->data_achizitie = this->data_imprumut = this->data_publicare = this->data_scadenta = this->format = this->status = this->sectiune = nullptr;
	this->nr_raft = this->nr_rand = -1;
	this->pret = 0;
	this->doar_referinta = false;
}
Articol::Articol(char* ISBN, char* titlu, char* autor, char* topic, char* editor, char* limba, int nr_pag, char* c, bool ref, char* di, char* ds, double p, char* f, char* s, char* da, char* dp, char* sec, int raft, int rand): Carte(ISBN,titlu,autor,topic,editor,limba,nr_pag)
{
	this->init(c, ref, di, ds, p, f, s, da, dp, sec, raft, rand);
}

Articol::Articol(const Articol& a) : Carte(a)
{
	this->init(a.barcode, a.doar_referinta, a.data_imprumut, a.data_scadenta, a.pret, a.format, a.status, a.data_achizitie, a.data_publicare, a.sectiune, a.nr_raft, a.nr_rand);
}

Articol::~Articol()
{
	if (this->barcode != nullptr)
		delete[] this->barcode;
	if (this->format != nullptr)
		delete[] this->format;
	if (this->status != nullptr)
		delete[] this->status;
	if (this->sectiune != nullptr)
		delete[] this->sectiune;
	if (this->data_achizitie != nullptr)
		delete[] this->data_achizitie;
	if (this->data_imprumut != nullptr)
		delete[] this->data_imprumut;
	if (this->data_publicare != nullptr)
		delete[] this->data_publicare;
	if (this->data_scadenta != nullptr)
		delete[] this->data_scadenta;
}
