#include "stdafx.h"
#include "Zestawienie.h"


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
	string NameFile;
	return NameFile;
}
void CZestawienie::PobierzStan(vector<CProdukt*>* vec, string NameFile /* = ""*/)
{
	ifstream Odczyt;
//	NameFile.empty() ? Odczyt.open(NAZWA_PLIKU) : Odczyt.open( NameFile );


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