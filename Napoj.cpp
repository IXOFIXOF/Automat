#include "stdafx.h"
#include "Napoj.h"


CNapoj::CNapoj()
{
	pojemnosc = -1;
}
CNapoj::~CNapoj()
{
}
int CNapoj::PobierzCene()
{
	return m_iCena;
}
string CNapoj::DaneOProdukcie()
{
	return "Napoj: " + m_sNazwa + ", "
		+ "Cena: " + to_string(m_iCena) + ", " + "Pojemnosc: " + to_string(pojemnosc) + "\n";
}

void CNapoj::UstalSpecyficzneDane(void* Dane /*= nullptr*/)
{
	if (Dane != nullptr)
	{
		pojemnosc = (int)Dane; // typ wskaünika void konwertujemy na wskaünik na stringa, a nastepnie					 // wy≥uskujemy wartoúÊ stringa przez *
	}
	else
	{
		cout << "Podaj pojemnosc napoju: ";
		int poj;
		cin >> poj;
		if (!cin)
		{
			throw this;
		}
		pojemnosc = poj;
	}
}