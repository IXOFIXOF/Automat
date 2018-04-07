#include "stdafx.h"
#include "Przekaska.h"


CPrzekaska::CPrzekaska()
{
}


CPrzekaska::~CPrzekaska()
{
}
int CPrzekaska::PobierzCene()
{
	return m_iCena;
}
string CPrzekaska::DaneOProdukcie()
{
	return "Przekaska: " + m_sNazwa + ", "
		+ "Cena: " + to_string(m_iCena) +"\n";
}

void CPrzekaska::UstalSpecyficzneDane(void* Dane /*= nullptr*/)
{

}