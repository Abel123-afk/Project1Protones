#pragma once
#include "CMovil.h"
class CUnionB :public CMovil
{
private:

public:
	CUnionB(int x, int y) : CMovil()
	{
		tipo = 10;
		this->x = x;
		this->y = y;
		ancho = 100;
		alto = 100;
	}
	~CUnionB()
	{

	}
	void dibujar(Graphics^ g)
	{
		//Proton
		g->FillEllipse(Brushes::Yellow, x, y, 50, 50);
		g->FillEllipse(Brushes::Green, Rectangle(x + 3, y + 3, 50 - 6, 50 - 6));
		g->DrawString("P", gcnew Font("Arial", 12), Brushes::Red, Rectangle(x + 8, y + 8, 50 - 16, 50 - 16));
		//Neutron
		g->FillEllipse(Brushes::Blue, x + 50, y, 50, 50);
		g->FillEllipse(Brushes::Red, Rectangle(x + 50 + 3, y + 3, 50 - 6, 50 - 6));
		g->DrawString("N", gcnew Font("Arial", 12), Brushes::DarkBlue, Rectangle(x + 50 + 8, y + 8, 50 - 16, 50 - 16));
		//Neutron
		g->FillEllipse(Brushes::Blue, x + 25, y + 50, 50, 50);
		g->FillEllipse(Brushes::Red, Rectangle(x + 25 + 3, y + 50 + 3, 50 - 6, 50 - 6));
		g->DrawString("N", gcnew Font("Arial", 12), Brushes::DarkBlue, Rectangle(x + 25 + 8, y + 50 + 8, 50 - 16, 50 - 16));
	}
	bool movinvalido()
	{
		dx *= -1;
		dy *= -1;
		return false;
	}



};
