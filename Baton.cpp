#include "stdafx.h"
#include "Baton.h"


CBaton::CBaton()
{
	
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
          + "Cena: " + to_string( m_iCena ) + "\n";
}

void CBaton::UstalSpecyficzneDane(void* Dane /*= nullptr*/)
{

}