#pragma once

#include "Personaje.h"
#include "Mapa1.h"

using namespace std;

enum DireccionesAmbu { arribaA, abajoA, derechaA, izquierdaA };

class Ambulancia : public Personaje {
private:
	DireccionesAmbu direccionA;
	int CoorY, CoorX;
public:
	Ambulancia(Mapa* mapa, pair<int,int> origen) : Personaje() {
		setX(mapa->getDx() + origen.first);
		setY(mapa->getDy() + origen.second);
		setDx(0);
		setDy(0);
		setAncho(60);
		setLargo(100);
		setIndiceX(0);
		CoorY = 0;
		CoorX = 0;
		setRecorrido(15);
		setAutomatico(true);
		direccionA = DireccionesAmbu(rand() % 4);
	}

	void dibujar(BufferedGraphics^ buffer, Bitmap^ BMambulancia) {
		Rectangle porcionVisible = Rectangle(CoorX, CoorY, getAncho(), getLargo());
		buffer->Graphics->DrawImage(BMambulancia, getX(), getY(), porcionVisible, GraphicsUnit::Pixel);
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ BMambulancia, Mapa* mapa) {
		switch (direccionA)
		{
		case abajoA:
			setDx(0);
			setDy(getRecorrido());

			setAncho(60);
			setLargo(100);
			CoorY = 0;
			CoorX = 120;
			break;
		case derechaA:
			setDx(getRecorrido());
			setDy(0);

			setAncho(100);
			setLargo(60);
			CoorY = 20;
			CoorX = 200;
			break;
		case izquierdaA:
			setDx(-1 * getRecorrido());
			setDy(0);

			setAncho(100);
			setLargo(60);
			CoorY = 20;
			CoorX = 300;
			break;
		case arribaA:
			setDx(0);
			setDy(-1 * getRecorrido());

			setAncho(60);
			setLargo(100);
			CoorY = 0;
			CoorX = 20;
			break;
		}

		if (!mapa->choque(getX(), getDx(), getY(), getDy(), getAncho(), getLargo(), getAutomatico())) {
			if (getX() + getDx() >= mapa->getX() && getX() + getDx() + getAncho() <= mapa->getX() + 80 * 34 &&
				getY() + getDy() + 35 <= mapa->getY() && getY() + getDy() + getLargo() - 35 >= mapa->getY() - 80 * 28) {

				setX(getX() + getDx());
				setY(getY() + getDy());
			}
			else {
				switch (direccionA)
				{
				case arribaA: direccionA = DireccionesAmbu::abajoA;
					break;
				case abajoA: direccionA = DireccionesAmbu::arribaA;
					break;
				case derechaA: direccionA = DireccionesAmbu::izquierdaA;
					break;
				case izquierdaA: direccionA = DireccionesAmbu::derechaA;
					break;
				default:
					break;
				}
			}
		}
		else {

			switch (rand() % 4)
			{
			case 0: direccionA = DireccionesAmbu::abajoA;
				break;
			case 1: direccionA = DireccionesAmbu::arribaA;
				break;
			case 2: direccionA = DireccionesAmbu::izquierdaA;
				break;
			case 3: direccionA = DireccionesAmbu::derechaA;
				break;
			}
		}

		dibujar(buffer, BMambulancia);
	}
};
