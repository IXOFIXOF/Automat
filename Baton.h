#pragma once
#include "Produkt.h"


class CBaton : public CProdukt
{
public:
	static int ilosc;
	CBaton();
	~CBaton();
	void UstalCene();
	void UstalNazwe();
	void DodajSpecyficzneDane();
	void PodajStan();
};

