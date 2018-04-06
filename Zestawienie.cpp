#include "stdafx.h"
#include "Zestawienie.h"
#include "Napoj.h"
#include "Woda.h"
#include "Baton.h"
#include "Produkt.h"

CZestawienie::CZestawienie()
{
}
CZestawienie::~CZestawienie()
{
}
void CZestawienie::Init(vector<CProdukt*>* vec)
{
	ListaProduktow = vec;
}
string CZestawienie::RaportDoOdczytu()
{
	vector< string > NamesFiles;
	WIN32_FIND_DATA file;
	HANDLE search_handle = FindFirstFile("*.txt", &file);
	int iWybor = 0;
	if (search_handle)
	{
		int iLicznik = 1;
		do
		{
			std::wcout<<iLicznik<<". "<< file.cFileName << std::endl;
			NamesFiles.push_back(file.cFileName);
			iLicznik++;
		} while (FindNextFile(search_handle, &file));
		FindClose(search_handle);
	}
	cout << "Wybierz plik: ";
	cin >> iWybor;
	if (!cin)
	{
		throw new exception;
	}
	return NamesFiles[iWybor - 1];
}
void CZestawienie::PobierzStan( string NameFile /* = ""*/)
{
	ListaProduktow->clear();
	bool CosZnaleziono = false;
	ifstream Odczyt;
	NameFile.empty() ? Odczyt.open(NAZWA_PLIKU) : Odczyt.open(NameFile);
	regex rBaton("Baton: (.+), Cena: (.+), Smak: (.+)");
	regex rWoda("Woda: (.+), Cena: (.+), Gazowana: (.+)");
	regex rNapoj("Napoj: (.+), Cena: (.+), Pojemnosc: (.+)");
	string linia;

	while (getline(Odczyt, linia))
	{
		CosZnaleziono = false;

		smatch wynik;
		if (regex_search(linia, wynik, rBaton))
		{
			ListaProduktow->push_back(new CBaton);
			it = ListaProduktow->end() - 1;
			(*it)->UstalSpecyficzneDane(&(wynik[3].str()));
			CosZnaleziono = true;
		}
		else if (regex_search(linia, wynik, rWoda))
		{
			ListaProduktow->push_back(new CWoda);
			it = ListaProduktow->end() - 1;
			(*it)->UstalSpecyficzneDane(&(wynik[3].str()));
			CosZnaleziono = true;
		}
		else if (regex_search(linia, wynik, rNapoj))
		{
			ListaProduktow->push_back(new CNapoj);
			it = ListaProduktow->end() - 1;
			(*it)->UstalSpecyficzneDane((int*)atoi(wynik[3].str().c_str()));
			CosZnaleziono = true;
		}
		if (CosZnaleziono)
		{
			(*it)->UstalCene(atoi(wynik[2].str().c_str()));
			(*it)->UstalNazwe(wynik[1].str());
		}

	}


	Odczyt.close();
}
void CZestawienie::ZapiszStan(bool NadpisaniePliku /*= true*/)
{
	string NazwaPliku;
	if ( NadpisaniePliku )
	{
		NazwaPliku = NAZWA_PLIKU;
	}
	else
	{
		NazwaPliku = UstalNazwePliku();
	}
	ofstream zapis;
	zapis.open(NazwaPliku);
	vector < CProdukt* > ::iterator it;
	it = ListaProduktow->begin();
	if (it == ListaProduktow->end())
	{
		zapis << "W automacie nie ma ¿adnego produktu.\n";
	}
	else
	{
		int LacznaKwota = 0;
		int SumaProduktow = 0;
		while (it != ListaProduktow->end())
		{
			zapis << ((*it)->DaneOProdukcie().c_str());
			SumaProduktow++;
			LacznaKwota += (*it)->PobierzCene();
			it++;
		}
		zapis << "W automacie jest: " << SumaProduktow << " przedmiotow\n";
		zapis << "Saldo w automacie na dzien sporzadzenia raportu to: " << LacznaKwota << ".\n";
	}

	zapis.close();
}
string CZestawienie::UstalNazwePliku()
{
	time_t t_Data;
	tm tm_DataCzas;
	time(&t_Data);
	localtime_s(&tm_DataCzas, &t_Data );

	string Nazwa;
	Nazwa = to_string( tm_DataCzas.tm_mday ) 
		+ "-" + to_string( tm_DataCzas.tm_mon )
		+ "-" + to_string( tm_DataCzas.tm_hour )
		+ "-" + to_string( tm_DataCzas.tm_min ) 
		+ "-" + to_string( tm_DataCzas.tm_sec )
		+ ".txt";

	return Nazwa;
}