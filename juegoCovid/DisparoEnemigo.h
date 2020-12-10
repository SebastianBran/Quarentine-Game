#pragma once

#include "Disparo.h"
#include "Jugador.h"

enum DireccionesDisparoE { arribaDE, abajoDE, izquierdaDE, derechaDE };

class DisparoEnemigo : public Disparo {
private:
	DireccionesDisparoE direccionDE;
public:
	DisparoEnemigo(int xJ, int yJ, int direccion) : Disparo() {
		ancho = 32;
		largo = 32;
		choco = false;
		automatico = false;
		recorrido = 50;
		switch (direccion)
		{
		case 0:
			x = xJ + 5;
			y = yJ;
			direccionDE = arribaDE;
			limiteY = y - 250;
			break;
		case 1:
			x = xJ + 5;
			y = yJ + 40;
			direccionDE = abajoDE;
			limiteY = y + 250;
			break;
		case 2:
			x = xJ;
			y = yJ + 16;
			direccionDE = derechaDE;
			limiteX = x + 250;
			break;
		case 3:
			x = xJ;
			y = yJ + 16;
			direccionDE = izquierdaDE;
			limiteX = x - 250;
			break;
		}
	}

	void dibujar(BufferedGraphics^ buffer, Bitmap^ BMdisparoE) {
		Rectangle porcionVisible = Rectangle(0, 0, BMdisparoE->Width, BMdisparoE->Height);
		buffer->Graphics->DrawImage(BMdisparoE, x, y, porcionVisible, GraphicsUnit::Pixel);
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ BMdisparoE, Mapa* mapa) {
		switch (direccionDE)
		{
		case abajoDE:
			dx = 0;
			dy = recorrido;
			break;
		case derechaDE:
			dx = recorrido;
			dy = 0;
			break;
		case izquierdaDE:
			dx = -1 * recorrido;
			dy = 0;
			break;
		case arribaDE:
			dx = 0;
			dy = -1 * recorrido;
			break;
		}

		if (!mapa->choque(x, dx, y, dy, ancho, largo, automatico)) {
			if (x + dx >= mapa->getX() && x + dx + ancho <= mapa->getX() + 80 * 34 &&
				y + dy + 35 <= mapa->getY() && y + dy + largo - 35 >= mapa->getY() - 80 * 28) {
				switch (direccionDE)
				{
				case abajoDE:
					if (y + dy < limiteY) { y += dy; }
					else choco = true;

					break;
				case derechaDE:
					if (x + dx < limiteX) { x += dx; }
					else choco = true;

					break;
				case izquierdaDE:
					if (x + dx > limiteX) { x += dx; }
					else choco = true;

					break;
				case arribaDE:
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

		dibujar(buffer, BMdisparoE);
	}
};