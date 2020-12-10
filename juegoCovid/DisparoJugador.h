#pragma once

#include "Disparo.h"
#include "Jugador.h"

enum DireccionesDisparoJ { arribaDJ, abajoDJ, izquierdaDJ, derechaDJ };

class DisparoJugador : public Disparo {
private:
	DireccionesDisparoJ direccionDJ;
public:
	DisparoJugador(int xJ, int yJ, int direccion) : Disparo() {
		ancho = 32;
		largo = 32;
		choco = false;
		automatico = false;
		recorrido = 50;
		switch (direccion)
		{
		case 1:
			x = xJ + 5;
			y = yJ;
			direccionDJ = arribaDJ;
			limiteY = y - 400;
			break;
		case 2:
			x = xJ + 5;
			y = yJ + 40;
			direccionDJ = abajoDJ;
			limiteY = y + 400;
			break;
		case 3:
			x = xJ;
			y = yJ + 16;
			direccionDJ = derechaDJ;
			limiteX = x + 400;
			break;
		case 4:
			x = xJ;
			y = yJ + 16;
			direccionDJ = izquierdaDJ;
			limiteX = x - 400;
			break;
		}
	}
	
	void dibujar(BufferedGraphics^ buffer, Bitmap^ BMdisparoJ) {
		Rectangle porcionVisible = Rectangle(ancho * indice, 0, ancho, largo);
		buffer->Graphics->DrawImage(BMdisparoJ, x, y, porcionVisible, GraphicsUnit::Pixel);
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ BMdisparoJ, Mapa* mapa) {
		switch (direccionDJ)
		{
		case abajoDJ:
			dx = 0;
			dy = recorrido;
			indice = 1;

			break;
		case derechaDJ:
			dx = recorrido;
			dy = 0;
			indice = 2;

			break;
		case izquierdaDJ:
			dx = -1 * recorrido;
			dy = 0;
			indice = 3;
			break;
		case arribaDJ:
			dx = 0;
			dy = -1 * recorrido;
			indice = 0;
			break;
		}

		if (!mapa->choque(x, dx, y, dy, ancho, largo, automatico)) {
			if (x + dx >= mapa->getX() && x + dx + ancho <= mapa->getX() + 80 * 34 &&
				y + dy + 35 <= mapa->getY() && y + dy + largo - 35 >= mapa->getY() - 80 * 28) {
				switch (direccionDJ)
				{
				case abajoDJ:
					if (y + dy < limiteY) { y += dy; }
					else choco = true;

					break;
				case derechaDJ:
					if (x + dx < limiteX) { x += dx; }
					else choco = true;

					break;
				case izquierdaDJ:
					if (x + dx > limiteX) { x += dx; }
					else choco = true;

					break;
				case arribaDJ:
					if (y + dy > limiteY) { y += dy; }
					else choco = true;

					break;
				}
			}
			else {
				choco = true;
			}
		}
		else {
			choco = true;
		}

		dibujar(buffer, BMdisparoJ);
	}
};