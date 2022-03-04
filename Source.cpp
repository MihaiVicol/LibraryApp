#pragma once
#include "carte.h"
#include "Articol.h"
#include "Amenda.h"
#include "Persoana.h"
#include "Biblioteca.h"
#include <iostream>
#include<fstream>
#include <cstring>
#include<stdlib.h>
using namespace std;
ifstream f("file.txt");
ifstream z("file1.txt");
int main()
{
	char s[500];
	bool dr=false;
	int nr_p = 0, nr_c = 0, nr_pag = 0, raft = 0, rand = 0, p1 = 0, k = 0, n_carti, nr_am = 0;
	double pf=0.0;
	f.getline(s, 500);
	char *tmp,*bc,*di,*ds,*fo,*st,*da,*dp,*sec,*IS,*ti,*au,*to,*ed,*li,*nu,*num,*tel,*em,*adr,*cnp,*file_p,*file_a;
	file_p = new char[10];
	strcpy(file_p, "file1.txt");
	file_a = new char[9];
	strcpy(file_a, "file.txt");
	tmp = strtok(s, ",");
	nu = new char[strlen(tmp) + 1];
	strcpy(nu, tmp);
	tmp = strtok(nullptr, ",");
	for (int i = strlen(tmp) - 1; i >= 0; i--)
		nr_c = nr_c * 10 + (tmp[i] - '0');
	tmp = strtok(nullptr, ",");
	for (int i = strlen(tmp) - 1; i >= 0; i--)
		nr_p = nr_p * 10 + (tmp[i] - '0');
	bc = di = ds = fo = st = da = dp = sec = IS = ti = au = to = ed = li = num = tel = adr = cnp = em =  nullptr;
	Biblioteca wr(nu, nr_c, nr_p);
	for (int l = 1; l <= nr_c; l++)
	{
	    nr_pag = 0, raft = 0, rand = 0, p1 = 0, k = 0;
		double kk = 1;
		f.getline(s, 500);
		tmp = strtok(s, ",");
		delete[] IS;
		IS = new char[strlen(tmp) + 1];
		strcpy(IS, tmp);
		tmp = strtok(nullptr, ",");
		delete[] ti;
		ti = new char[strlen(tmp) + 1];
		strcpy(ti, tmp);
		tmp = strtok(nullptr, ",");
		delete[] au;
		au = new char[strlen(tmp) + 1];
		strcpy(au, tmp);
		tmp = strtok(nullptr, ",");
		delete[] to;
		to = new char[strlen(tmp) + 1];
		strcpy(to, tmp);
		tmp = strtok(nullptr, ",");
		delete[] ed;
		ed = new char[strlen(tmp) + 1];
		strcpy(ed, tmp);
		tmp = strtok(nullptr, ",");
		li = new char[strlen(tmp) + 1];
		strcpy(li, tmp);
		tmp = strtok(nullptr, ",");
		for (int i = 0; i <= strlen(tmp) - 1; i++)
			nr_pag = nr_pag * 10 + (tmp[i] - '0');
		tmp = strtok(nullptr, ",");
		delete[] bc;
		bc = new char[strlen(tmp) + 1];
		strcpy(bc, tmp);
		tmp = strtok(nullptr, ",");
		if (strcmp(tmp, "true") == 0)
			dr = true;
		else
			dr = false;
		tmp = strtok(nullptr, ",");
		delete[] di;
		di = new char[strlen(tmp) + 1];
		strcpy(di, tmp);
		tmp = strtok(nullptr, ",");
		delete[] ds;
		ds = new char[strlen(tmp) + 1];
		strcpy(ds, tmp);
		tmp = strtok(nullptr, ",");
		for (int i = 0; i <= strlen(tmp) - 1; i++)
			if (tmp[i] != '.')
				p1 = p1 * 10 + (tmp[i] - '0');
			else
				k = i;
		for (int i = 1; i <= k; i++)
			kk = kk * 10.0;
		pf = p1 / kk;
		tmp = strtok(nullptr, ",");
		delete[] fo;
		fo = new char[strlen(tmp) + 1];
		strcpy(fo, tmp);
		tmp = strtok(nullptr, ",");
		delete[] st;
		st = new char[strlen(tmp) + 1];
		strcpy(st, tmp);
		tmp = strtok(nullptr, ",");
		delete[] da;
		da = new char[strlen(tmp) + 1];
		strcpy(da, tmp);
		tmp = strtok(nullptr, ",");
		delete[] dp;
		dp = new char[strlen(tmp) + 1];
		strcpy(dp, tmp);
		tmp = strtok(nullptr, ",");
		delete[] sec;
		sec = new char[strlen(tmp) + 1];
		strcpy(sec, tmp);
		tmp = strtok(nullptr, ",");
		for (int i = 0; i <= strlen(tmp) - 1; i++)
			raft = raft * 10 + (tmp[i] - '0');
		tmp = strtok(nullptr, ",");
		for (int i = 0; i <= strlen(tmp) - 1; i++)
			rand = rand * 10 + (tmp[i] - '0');
		Articol a(IS, ti, au, to, ed, li, nr_pag, bc, dr, di, ds, pf, fo, st, da, dp, sec, raft, rand);
		wr.add_art(a);
	}
	for (int l = 1; l <= nr_p; l++)
	{
		nr_am = 0, p1 = 0, k = 0;
		double kk = 1;
		z.getline(s, 500);
		tmp = strtok(s, ",");
		num = new char[strlen(tmp) + 1];
		strcpy(num, tmp);
		tmp = strtok(nullptr, ",");
		tel = new char[strlen(tmp) + 1];
		strcpy(tel, tmp);
		tmp = strtok(nullptr, ",");
		em = new char[strlen(tmp) + 1];
		strcpy(em, tmp);
		tmp = strtok(nullptr, ",");
		adr = new char[strlen(tmp) + 1];
		strcpy(adr, tmp);
		tmp = strtok(nullptr, ",");
		cnp = new char[strlen(tmp) + 1];
		strcpy(cnp, tmp);
		tmp = strtok(nullptr, ",");
		for (int i = 0; i <= strlen(tmp) - 1; i++)
			nr_am = nr_am * 10 + (tmp[i] - '0');
		tmp = strtok(nullptr, ",");
		for (int i = 0; i <= strlen(tmp) - 1; i++)
			if (tmp[i] != '.')
				p1 = p1 * 10 + (tmp[i] - '0');
			else
				k = i;
		for (int i = 1; i <= k; i++)
			kk = kk * 10.0;
		pf = p1 / kk;
		tmp = strtok(nullptr, ",");
		if (strcmp(tmp, "true") == 0)
			dr = true;
		else
			dr = false;
		tmp = strtok(nullptr, ",");
		n_carti = tmp[0] - '0';
		Persoana pe(num,tel,em,adr,cnp,nr_am,pf,dr);
		wr.add_pers(pe);
		for (int i = 1; i <= n_carti; i++)
		{
			tmp = strtok(nullptr, ",");
			wr.search_add_art(tmp);
		}
	}
	wr.amenzi();
	int x;
	char* tmpa;
backp:system("cls");
	cout << "Alege optiune:\n"<<"1.Imprumuta o carte\n"<<"2.Cauta amenzi \n"<<"3.Primire carte \n"<<"4.Actualizeaza date si inchide program \n";
	cin >> x;
	switch (x)
	{
	case 1:
		inapoi:system("cls");
		cout << "Introduceti titlul cartii sau 0 pentru a reveni la meniul anterior: ";
		do{
		cin.getline(s, 256);
		while(strlen(s)==0)
			cin.getline(s, 256);
			tmp = new char[strlen(s) + 1];
			strcpy(tmp, s);
			if (tmp[0] == '0')
				goto backp;
			else if (!wr.este_art(tmp))
				cout << "Articol indisponibil, introduceti alt titlu sau 0 pentru a reveni la meniul principal: ";
		} while (!wr.este_art(tmp));
		system("cls");
		wr.search_afis(tmp);
		cout << "Introduceti cnp-ul persoanei, 0 pentru inapoi sau 00 pentru meniul principal: ";
		cin.getline(s, 256);
		while (strlen(s) == 0)
			cin.getline(s, 256);
		tmpa = new char[strlen(tmp) + 1];
		strcpy(tmpa, tmp);
		tmp = new char[strlen(s) + 1];
		strcpy(tmp, s);
		if (tmp[1] == '0' && tmp[0]=='0')
			goto backp;
		else if (tmp[0] == '0')
			goto inapoi;
		else if (wr.este_pers(tmp))
		{
			if (!wr.imprumuta(tmp, tmpa))
			{
				system("cls");
				cout << "Persoana nu poate imprumuta carti: \n"<<"Amenda: \n";
				wr.afiseaza_amenzi_nr_imprumut(tmp);
				cout << "Introduceti 00 pentru a reveni la meniul principal: ";
				cin.getline(s, 256);
				while (strlen(s) == 0)
					cin.getline(s, 256);
				goto backp;
			}
			cout << "Datele au fost actualizate! Apasa 00 pentru a reveni la meniul principal";
			cin.getline(s, 256);
			while (strlen(s) == 0)
				cin.getline(s, 256);
			goto backp;

		}
		else {
			cout << "Persoana neinregistrata: \n";
			nr_am = 0, p1 = 0, k = 0;
			double kk = 1;
			cout << "Introduceti:\n";
			cout << "	Nume: ";
			cin.getline(s, 256);
			while (strlen(s) == 0)
				cin.getline(s, 256);
			num = new char[strlen(s) + 1];
			strcpy(num, s);
			cout << "	Telefon: ";
			cin.getline(s, 256);
			while (strlen(s) == 0)
				cin.getline(s, 256);
			tel = new char[strlen(s) + 1];
			strcpy(tel, s);
			cout << "	Adresa de e-mail: ";
			cin.getline(s, 256);
			while (strlen(s) == 0)
				cin.getline(s, 256);
			em = new char[strlen(s) + 1];
			strcpy(em, s);
			cout << "	Adresa: ";
			cin.getline(s, 256);
			while (strlen(s) == 0)
				cin.getline(s, 256);
			adr = new char[strlen(s) + 1];
			strcpy(adr, s);
			cout << "	CNP: ";
			cin.getline(s, 256);
			while (strlen(s) == 0)
				cin.getline(s, 256);
			cnp = new char[strlen(s) + 1];
			strcpy(cnp, s);
			nr_am = 0;
			pf = 0;
			dr = false;
			Persoana pe(num, tel, em, adr, cnp, nr_am, pf, dr);
			wr.add_pers(pe);
			wr.search_add_art(tmpa);
			system("cls");
			cout << "Datele au fost actualizate! Introduceti 00 pentru a reveni la meniul principal";
			cin.getline(s, 256);
			while (strlen(s) == 0)
				cin.getline(s, 256);
			goto backp;
		}
		break;
	case 2:
		backin:
		system("cls");
		cout << "Introduceti CNP-ul persoanei pentru a verifica amenzile: ";
		cin.getline(s, 256);
		while (strlen(s) == 0)
			cin.getline(s, 256);
		tmp = new char[strlen(s) + 1];
		strcpy(tmp, s);
		tmpa = new char[strlen(tmp) + 1];
		strcpy(tmpa, tmp);
		system("cls");
		cout << "Amenzile persoanei cu CNP-ul: " << tmpa << "\n";
		wr.afiseaza_amenzi_nr_imprumut(tmp);
		cout << "Introduceti 1 pentru plata, 0 pentru inapoi sau 00 pentru meniul principal: ";
		cin.getline(s, 256);
		while (strlen(s) == 0)
			cin.getline(s, 256);
		if (s[0] == '1')
		{
			system("cls");
			cout << "Introduceti suma: ";
			double sum;
			cin >> sum;
			wr.plateste(tmpa, sum);
			system("cls");
			cout << "Suma a fost introdusa! Introduceti 00 pentru a va intoarce la meniul principal: ";
			cin.getline(s, 256);
			while (strlen(s) == 0)
				cin.getline(s, 256);
			goto backp;

		}
		else if (s[0] == '0' && s[1] == '0')
			goto backp;
		else
			goto backin;
		break;
	case 3:
		system("cls");
		cout << "Introduceti CNP-ul peroanei care a adus cartea: ";
		cin.getline(s, 256);
		while (strlen(s) == 0)
			cin.getline(s, 256);
		char *cnpp,*arp;
		cnpp = new char[strlen(s) + 1];
		strcpy(cnpp, s);
		cout << "Introduceti titlul cartii aduse: ";
		cin.getline(s, 256);
		while (strlen(s) == 0)
			cin.getline(s, 256);
		arp = new char[strlen(s) + 1];
		strcpy(arp, s);
		wr.take_book(cnpp, arp);
		system("cls");
		cout << "Cartea a fost actualizata! Introduceti 00 pentru meniul principal \n";
		cin.getline(s, 256);
		while (strlen(s) == 0)
			cin.getline(s, 256);
		goto backp;
		break;
	case 4:
		ofstream f3("file.txt", ofstream::trunc);
		ofstream f4("file1.txt", ofstream::trunc);
		f3.close();
		f4.close();
		wr.update_all(file_a, file_p);
		break;
	}
}