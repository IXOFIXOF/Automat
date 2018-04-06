#include "stdafx.h"
#include "Woda.h"


CWoda::CWoda()
{
	Gazowana = "Jeszcze nie wiadomo";
}
CWoda::~CWoda()
{
}
void CWoda::UstalSpecyficzneDane(void* Dane /* = nullptr */)
{
	if (Dane != nullptr)
	{
		Gazowana = *((string*)Dane); // typ wska�nika void konwertujemy na wska�nik na stringa, a nastepnie
								 // wy�uskujemy warto�� stringa przez *
	}
	else
	{
		cout << "Czy woda jest gazowana: ";
		string gaz;
		cin >> gaz;
		if (!cin)
		{
			throw this;
		}
		Gazowana = gaz;
	}
}
string CWoda::DaneOProdukcie()
{
	return "Woda: " + m_sNazwa + ", "
		+ "Cena: " + to_string(m_iCena) + ", " + "Gazowana: " + Gazowana + "\n";
}
int CWoda::PobierzCene()
{
	return m_iCena;
}
