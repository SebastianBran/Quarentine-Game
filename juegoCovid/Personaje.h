#pragma once

#include <iostream>

using namespace System::Drawing;

class Personaje
{
private:
	int x, y, dx, dy, ancho, largo, indiceX, indiceY, recorrido;
	bool automatico;
public:
	Personaje() {}

	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	int getAncho() { return ancho; }
	int getLargo() { return largo; }
	int getIndiceX() { return indiceX; }
	int getIndiceY() { return indiceY; }
	int getRecorrido() { return recorrido; }
	bool getAutomatico() { return automatico; }

	void setX(int x) { this->x=x; }
	void setY(int y) { this->y=y; }
	void setDx(int dx) { this->dx=dx; }
	void setDy(int dy) { this->dy=dy; }
	void setAncho(int ancho) { this->ancho=ancho; }
	void setLargo(int largo) { this->largo=largo; }
	void setIndiceX(int indiceX) { this->indiceX=indiceX; }
	void setIndiceY(int indiceY) { this->indiceY = indiceY; }
	void setRecorrido(int recorrido) { this->recorrido=recorrido; }
	void setAutomatico(bool automatico) { this->automatico = automatico; }

	virtual void dibujar() { return; }
	virtual void mover() { return; }
};
