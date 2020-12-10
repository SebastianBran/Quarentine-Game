#pragma once

#include "Personaje.h"
#include "Mapa1.h"
#include <vector>
#include <utility>

using namespace std;

enum DireccionesPoli { arribaP, abajoP, derechaP, izquierdaP };

class Policia : public Personaje {
private:
	DireccionesPoli direccionP;
public:
	Policia(Bitmap^ BMpolicia, Mapa* mapa, pair<int,int> origen) : Personaje() {
		setX(mapa->getDx() + origen.first);
		setY(mapa->getDy() + origen.second);
		setDx(0);
		setDy(0);
		setAncho(BMpolicia->Width / 12);
		setLargo(BMpolicia->Height);
		setIndiceX(3);
		setRecorrido(15);
		setAutomatico(true);
		direccionP = DireccionesPoli(rand() % 4);
	}

	void dibujar(BufferedGraphics^ buffer, Bitmap^ BMpolicia) {
		Rectangle porcionVisible = Rectangle(getAncho() * getIndiceX(), 0, getAncho(), getLargo());
		buffer->Graphics->DrawImage(BMpolicia, getX(), getY(), porcionVisible, GraphicsUnit::Pixel);
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ BMpolicia, Mapa* mapa) {
		switch (direccionP)
		{
		case abajoP:
			setDx(0);
			setDy(getRecorrido());

			if (getIndiceX() >= 0 && getIndiceX() < 2) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(1);
			}
			break;
		case derechaP:
			setDx(getRecorrido());
			setDy(0);

			if (getIndiceX() >= 3 && getIndiceX() < 5) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(4);
			}
			break;
		case izquierdaP:
			setDx(-1 * getRecorrido());
			setDy(0);

			if (getIndiceX() >= 6 && getIndiceX() < 8) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(7);
			}
			break;
		case arribaP:
			setDx(0);
			setDy(-1 * getRecorrido());

			if (getIndiceX() >= 9 && getIndiceX() < 11) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(10);
			}
			break;
		}

		if (!mapa->choque(getX(), getDx(), getY(), getDy(), getAncho(), getLargo(), getAutomatico())) {
			if (getX() + getDx() >= mapa->getX() && getX() + getDx() + getAncho() <= mapa->getX() + 80 * 34 &&
				getY() + getDy() + 35 <= mapa->getY() && getY() + getDy() + getLargo() - 35 >= mapa->getY() - 80 * 28) {

				setX(getX() + getDx());
				setY(getY() + getDy());
			}
			else {
				switch (direccionP)
				{
				case arribaP: direccionP = DireccionesPoli::abajoP;
					break;
				case abajoP: direccionP = DireccionesPoli::arribaP;
					break;
				case derechaP: direccionP = DireccionesPoli::izquierdaP;
					break;
				case izquierdaP: direccionP = DireccionesPoli::derechaP;
					break;
				default:
					break;
				}
			}
		}
		else {
			switch (rand() % 4)
			{
			case 0: direccionP = DireccionesPoli::abajoP;
				break;
			case 1: direccionP = DireccionesPoli::arribaP;
				break;
			case 2: direccionP = DireccionesPoli::izquierdaP;
				break;
			case 3: direccionP = DireccionesPoli::derechaP;
				break;
			}
		}

		dibujar(buffer, BMpolicia);
	}
};