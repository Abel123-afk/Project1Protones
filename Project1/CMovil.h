#pragma once
#include<iostream>
using namespace System::Drawing;
class CMovil
{
protected:
	int x, y, dx, dy, ancho, alto, tipo;
public:
	CMovil()
	{
		ancho = 50;
		alto = 50;
		do {
			dx = (rand() % 3 - 1) * 5;
			dy = (rand() % 3 - 1) * 5;
		} while (dx == 0 && dy == 0);
		x = rand() % 950;
		y = rand() % 950;
	}
	~CMovil()
	{

	}
	void mover()
	{
		x += dx;
		y += dy;
	}
	virtual void dibujar(Graphics^g)
	{

	}
	virtual bool movinvalido()
	{
		return false;
	}
	bool colision(Rectangle rec)
	{
		return rec.IntersectsWith(this->getrec());
	}
	Rectangle getrec()
	{
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle getfutrec()
	{
		return Rectangle(x+dx, y+dy, ancho, alto);
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getTipo()
	{
		return tipo;
	}
};

