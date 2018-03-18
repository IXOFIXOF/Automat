#include "stdafx.h"
#include "Automat.h"
#include "Baton.h"

void CAutomat::Init()
{
	bool bKontynuuj = true;
	
		unsigned wybor = 0;
		cout << "Wymierz co chcesz zrobiæ:" << endl;
		cout << "1. Stan automatu" << endl;
		cout << "2. Dodaj produkt" << endl;
		cout << "3. Usun produkt" << endl;
		cout << "4. Edytuj produkt" << endl;
		cout << "5.Wyjscie" << endl;
	while (bKontynuuj)
	{
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			StanAutomatu();
			break;
		}
		case 2:
		{
			DodajProdukt();
			break;
		}
		case 3:
		{
			UsunProdukt();
			break;
		}
		case 4:
		{
			EdytujDane();
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
		return;
		break;
	}
	it = ListaProduktow.end() - 1;
	(*it)->UstalCene();
	(*it)->UstalNazwe();
	(*it)->UstalSpecyficzneDane();
}
void CAutomat::StanAutomatu()
{
	int licznik = 1;
	it = ListaProduktow.begin();
	while (it != ListaProduktow.end())
	{
		cout << licznik << ": "; (*it)->DaneOProdukcie();
		it++;
		licznik++;
	}
	if (licznik == 1)
	{
		cout << "Brak produktow w automacie\n";
	}
}
void CAutomat::UsunProdukt()
{
	StanAutomatu();
	cout << "Podaj nr. produktu: ";
	int iUsun = 0;
	cin >> iUsun;
	delete ListaProduktow[iUsun- 1];
	ListaProduktow.erase(ListaProduktow.begin() + iUsun - 1);
}
void CAutomat::EdytujDane()
{
	StanAutomatu();
	cout << "Podaj nr. produktu: ";
	int iEdytuj = 0;
	cin >> iEdytuj;
	ListaProduktow[iEdytuj - 1]->UstalCene();
	ListaProduktow[iEdytuj - 1]->UstalNazwe();
	ListaProduktow[iEdytuj - 1]->UstalSpecyficzneDane();
}
CAutomat::CAutomat()
{
}
CAutomat::~CAutomat()
{
}
