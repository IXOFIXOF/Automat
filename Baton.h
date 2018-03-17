#pragma once
#include "Produkt.h"


class CBaton : public CProdukt
{
public:
	CBaton();
	~CBaton();
	void UstalCene(int iCena);
	void UstalNazwe(string sNazwa);
};

