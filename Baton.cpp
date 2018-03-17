#include "stdafx.h"
#include "Baton.h"


CBaton::CBaton()
{
	ilosc += 1;
}
int CBaton::ilosc = 0;
void CBaton::UstalCene()
{
	int iCena = 0;
	cout << "Podaj cene\n";
	cin >> iCena;
	m_iCena = iCena;
}
void CBaton::UstalNazwe()
{
	string sNazwa;
	cout << "Podaj nazwe\n";
	cin >> sNazwa;
	m_Nazwa = sNazwa;
}
void CBaton::PodajStan()
{
	cout << " Liczba batonow w automacie: " << ilosc << endl;
}
CBaton::~CBaton()
{
	ilosc -= 1;
}
void CBaton::DodajSpecyficzneDane()
{

}