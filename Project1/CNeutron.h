#pragma once
#include "CMovil.h"
class CNeutron :public CMovil
{
private:

public:
	CNeutron() : CMovil()
	{
		tipo = 2;
	}
	~CNeutron()
	{

	}
	void dibujar(Graphics^ g)
	{
		g->FillEllipse(Brushes::Blue, getrec());
		g->FillEllipse(Brushes::Red, Rectangle(x + 3, y + 3, ancho - 6, alto - 6));
		g->DrawString("N", gcnew Font("Arial", 12), Brushes::DarkBlue, Rectangle(x + 8, y + 8, ancho - 16, alto - 16));
	}
	bool movinvalido()
	{
		return true;
	}



};

