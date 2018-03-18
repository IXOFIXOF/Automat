#include "stdafx.h"
#include "Produkt.h"


CProdukt::CProdukt()
{
	m_iCena = -1;
	m_sNazwa = "Nie podano nazwy";
}
CProdukt::~CProdukt()
{
}
void CProdukt::UstalCene()
{
	int iCena = 0;
	cout << "Podaj cene: ";
	cin >> iCena;
	m_iCena = iCena;
}
void CProdukt::UstalNazwe()
{
	string sNazwa;
	cout << "Podaj nazwe: ";
	cin.ignore();
	getline(cin, sNazwa);
	m_sNazwa = sNazwa;
}