#include "stdafx.h"
#include "Baton.h"


CBaton::CBaton()
{
	Smak = "Nie okreslono smaku";
}
CBaton::~CBaton()
{

}

int CBaton::PobierzCene()
{
	return m_iCena;
}
string CBaton::DaneOProdukcie()
{
	return "Baton: " + m_sNazwa + ", "
          + "Cena: " + to_string( m_iCena ) + ", " +"Smak: " + Smak +"\n";
}

void CBaton::UstalSpecyficzneDane(void* Dane /*= nullptr*/)
{
	if (Dane != nullptr)
	{
		Smak = *((string*)Dane); // typ wskaünika void konwertujemy na wskaünik na stringa, a nastepnie
								// wy≥uskujemy wartoúÊ stringa przez *
	}
	else
	{
		cout << "Podaj smak batona: ";
		string smak;
		cin >> smak;
		if (!cin)
		{
			throw this;
		}
		Smak = smak;
	}
}