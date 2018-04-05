#include "stdafx.h"
#include "Automat.h"

void CAutomat::Init()
{
	bool bKontynuuj = true;

	unsigned wybor = 0;
	cout << "Wymierz co chcesz zrobiæ:" << endl;
	cout << "1. Stan automatu" << endl;
	cout << "2. Dodaj produkt" << endl;
	cout << "3. Usun uprodukt" << endl;
	cout << "4. Edytuj produkt" << endl;
	cout << "5. Wyjscie" << endl;
	cout << "6. Zapisz stan automatu " << endl;
	cout << "7. Stan automatu z danego dnia " << endl;
	while (bKontynuuj)
	{
		try
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
				oZestawienie.ZapiszStan();
				break;
			}
			case 3:
			{
				UsunProdukt();
				oZestawienie.ZapiszStan();
				break;
			}
			case 4:
			{
				EdytujDane();
				oZestawienie.ZapiszStan();
				break;
			}
			case 5:
			{
				return;
			}
			case 6:
			{
				oZestawienie.ZapiszStan(false);
				break;
			}
			case 7:
			{
				oZestawienie.PobierzStan(oZestawienie.RaportDoOdczytu());
				StanAutomatu();
				oZestawienie.PobierzStan();// Poniewa¿ musimy przywróciæ stan automatu z ostatnio zapisanego pliku;
				break;
			}
			default:
				cout << "Dokona³es nieprawidlowego wyboru" << endl;
				break;
			}
		}
		catch (CProdukt* e)
		{
			it = find(ListaProduktow.begin(), ListaProduktow.end(), e);
			ListaProduktow.erase(it);
			delete e;
			cout << "Blednie wprowadzone dane, sprobuj ponownie.\n";
			cin.clear();
			cin.ignore();
		}
		catch(exception* e)
		{
			delete e;
			cout << "Blednie wprowadzone dane, sprobuj ponownie.\n";
			cin.clear();
			cin.ignore();
		}
	}

}
void CAutomat::DodajProdukt()
{
	cout << "Jaki produkt?" << endl;
	cout << "1. Baton" << endl;
	unsigned wybor = 0;
	cin >> wybor;
	if (!cin)
	{
		throw new exception;
	}
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
		cout << licznik << ": " << (*it)->DaneOProdukcie();
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
	if (!cin)
	{
		throw new exception;
	}
	delete ListaProduktow[iUsun- 1];
	ListaProduktow.erase(ListaProduktow.begin() + iUsun - 1);
}
void CAutomat::EdytujDane()
{
	StanAutomatu();
	cout << "Podaj nr. produktu: ";
	int iEdytuj = 0;
	cin >> iEdytuj;
	if (!cin)
	{
		throw new exception;
	}
	ListaProduktow[iEdytuj - 1]->UstalCene();
	ListaProduktow[iEdytuj - 1]->UstalNazwe();
	ListaProduktow[iEdytuj - 1]->UstalSpecyficzneDane();
}
CAutomat::CAutomat()
{
	oZestawienie.Init(&ListaProduktow);
	oZestawienie.PobierzStan();
}
CAutomat::~CAutomat()
{
	oZestawienie.ZapiszStan();
}
