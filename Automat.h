#pragma once
#include "stdafx.h"
#include <vector>
#include "Produkt.h"
#include "Baton.h"
#include "Woda.h"
#include "Napoj.h"
#include "Przekaska.h"
#include "Zestawienie.h"
class CAutomat
{

public:
	CAutomat();
	void Init();
	~CAutomat();
private:
	vector< CProdukt* > ListaProduktow;
	vector< CProdukt*> ::iterator it;
	void DodajProdukt();
	void StanAutomatu();
	void UsunProdukt();
	void EdytujDane();
	CZestawienie oZestawienie;
};

