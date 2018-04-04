#pragma once
#include "stdafx.h"
#include "Produkt.h"
#include <time.h>
#include <fstream>
#include <vector>


static const char* NAZWA_PLIKU = "Stan automatu.txt";

class CZestawienie
{
public:
	CZestawienie();
	~CZestawienie();
	string RaportDoOdczytu();
	void PobierzStan(string NameFile = "");
	void ZapiszStan( bool NadpisaniePliku = true );
	void Init(vector<CProdukt*>* vec);

private:
	string UstalNazwePliku();
	vector< CProdukt* >* ListaProduktow;
	vector< CProdukt*> ::iterator it;
};

