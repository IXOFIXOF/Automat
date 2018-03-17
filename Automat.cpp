#include "stdafx.h"
#include "Automat.h"


CAutomat::CAutomat()
{
}

void CAutomat::Init()
{
	unsigned wybor;
	cout << "Wymierz co chcesz zrobiæ:" << endl;
	cout << "1. Stan automatu" << endl;
	cout << "2. Dodaj produkt" << endl;
	cout << "3. Edytuj produkt" << endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
	{

		break;
	}
	case 2:
	{
		break;
	}
	case 3:
	{
		break;
	}
	default:
		cout << "Dokona³es nieprawidlowego wyboru" << endl;
		break;
	}

}
CAutomat::~CAutomat()
{
}
