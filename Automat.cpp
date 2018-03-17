#include "stdafx.h"
#include "Automat.h"
#include "Baton.h"

void CAutomat::Init()
{
	bool bKontynuuj = true;
	while (bKontynuuj)
	{
		unsigned wybor = 0;
		cout << "Wymierz co chcesz zrobiæ:" << endl;
		cout << "1. Stan automatu" << endl;
		cout << "2. Dodaj produkt" << endl;
		cout << "3. Usuñ produkt" << endl;
		cout << "4. Edytuj produkt" << endl;
		cout << "5.Wyjscie" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			ListaProduktow[0]->PodajStan();
			break;
		}
		case 2:
		{
			DodajProdukt();
			break;
		}
		case 3:
		{
			delete ListaProduktow[0];
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			return;
		}
		default:
			cout << "Dokona³es nieprawidlowego wyboru" << endl;
			break;
		}
	}

}
void CAutomat::DodajProdukt()
{
	cout << "Jaki produkt?" << endl;
	cout << "1. Baton" << endl;
	unsigned wybor = 0;
	cin >> wybor;
	
	switch (wybor)
	{
	case 1:
	{
		ListaProduktow.push_back(new CBaton);
		break;
	}
	default:
		break;
	}
	
	ListaProduktow[0]->UstalCene();
	ListaProduktow[0]->UstalNazwe();
	ListaProduktow[0]->DodajSpecyficzneDane();
}

CAutomat::CAutomat()
{
}
CAutomat::~CAutomat()
{
}
