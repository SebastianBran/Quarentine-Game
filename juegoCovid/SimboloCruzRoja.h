#pragma once

#include "Mapa.h"
#include <utility>

using namespace std;
using namespace System::Drawing;

class SimboloCruz {
private:
	int x, y, ancho, largo;
public:
	SimboloCruz(Bitmap^ BMsimboloCruz, Mapa* mapa, pair<int, int> origen) {
		x = mapa->getDx() + origen.first;
		y = mapa->getDy() + origen.second;
		ancho = BMsimboloCruz->Width;
		largo = BMsimboloCruz->Height;
	}

	int getX() { return x; }
	int getY() { return y; }
	double getAncho() { return ancho * 0.05; }
	double getLargo() { return largo * 0.05; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setAncho(int ancho) { this->ancho = ancho; }
	void setLargo(int largo) { this->largo = largo; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ BMsimboloCruz) {
		Rectangle porcionVisible = Rectangle(0, 0, ancho, largo);
		Rectangle zoom = Rectangle(x, y, ancho * 0.05, largo * 0.05);
		buffer->Graphics->DrawImage(BMsimboloCruz, zoom, porcionVisible, GraphicsUnit::Pixel);
	}
};