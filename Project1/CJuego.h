#pragma once
#include"CNeutron.h"
#include"CProton.h"
#include"CUnionA.h"
#include"CUnionB.h"
#include<vector>
using namespace std;
class CJuego
{
private:
	vector<CMovil*>vec;
public:
	CJuego()
	{
		for (int i = 0; i < 50; i++)
		{
			vec.push_back(new CNeutron());
			vec.push_back(new CProton());
		}
	}
	~CJuego()
	{}
	void jugar(Graphics^g)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i]->getfutrec().X<0 || vec[i]->getfutrec().Y<0 
				|| vec[i]->getfutrec().X+ vec[i]->getfutrec().Width>g->VisibleClipBounds.Width 
				|| vec[i]->getfutrec().Y+ vec[i]->getfutrec().Height>g->VisibleClipBounds.Height)
			{
				if (vec.at(i)->movinvalido())
				{
					vec.erase(vec.begin() + i);
					i--;
				}
			}
			else
			{
				vec[i]->mover();
				vec[i]->dibujar(g);
			}
		}
		for (int i=0; i<vec.size(); i++)
		{
			bool terminar = false;
			for (int j = i+1; j < vec.size(); j++)
			{

				for (int k=j+1; k < vec.size(); k++)
				{
					if (vec.at(i)->colision(vec.at(j)->getrec()) &&
						vec.at(i)->colision(vec.at(k)->getrec()))
					{
						if (vec.at(i)->getTipo() + vec.at(j)->getTipo() + vec.at(k)->getTipo() == 4)
						{
							vec.push_back(new CUnionA(vec.at(i)->getrec().X, vec.at(i)->getrec().Y));
							vec.erase(vec.begin() + k);
							vec.erase(vec.begin() + j);
							vec.erase(vec.begin() + i);
							i--;
							terminar = true;
							break;
						}
						else
						{
							if (vec.at(i)->getTipo() + vec.at(j)->getTipo() + vec.at(k)->getTipo() == 5)
							{
								vec.push_back(new CUnionB(vec.at(i)->getrec().X, vec.at(i)->getrec().Y));
								vec.erase(vec.begin() + k);
								vec.erase(vec.begin() + j);
								vec.erase(vec.begin() + i);
								i--;
								terminar = true;
								break;
							}
						}

					}
				}
				if (terminar)
					break;
			}
		}
		
	}


};