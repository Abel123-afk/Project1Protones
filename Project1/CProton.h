#pragma once
#include "CMovil.h"
class CProton:public CMovil
{
private:

public:
	CProton(): CMovil()
	{
		tipo = 1;
	}
	~CProton()
	{

	}
	void dibujar(Graphics^ g)
	{
		g->FillEllipse(Brushes::Yellow, getrec());
		g->FillEllipse(Brushes::Green, Rectangle(x+3,y+3,ancho-6,alto-6));
		g->DrawString("P", gcnew Font("Arial", 12), Brushes::Red, Rectangle(x + 8, y +8, ancho - 16, alto - 16));
	}
	bool movinvalido()
	{
		return true;
	}



};
