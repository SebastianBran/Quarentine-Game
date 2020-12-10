#pragma once

class Disparo {
protected:
	int x, y, dx, dy, limiteX, limiteY, ancho, largo, indice, recorrido;
	bool automatico, choco;
public:
	Disparo() {}

	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }	
	int getLimiteX() { return limiteX; }
	int getLimiteY() { return limiteY; }
	int geIndice() { return indice; }
	int getAncho() { return ancho; }
	int getLargo() { return largo; }
	int getRecorrido() { return recorrido; }
	bool getAutomatico() { return automatico; }
	bool getChoco() { return choco; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDX(int dx) { this->dx = dx; }
	void setDY(int dy) { this->dy = dy; }
	void setLimiteX(int limiteX) { this->limiteX = limiteX; }
	void setLimiteY(int limiteY) { this->limiteY = limiteY; }
	void setIndice(int indice) { this->indice = indice; }
	void setAncho(int ancho) { this->ancho = ancho; }
	void setLargo(int largo) { this->largo = largo; }
	void setRecorrido(int recorrido) { this->recorrido = recorrido; }
	void setAutatico(bool automatico) { this->automatico = automatico; }
	void setChoco(bool choco) { this->choco = choco; }

	virtual void dibujar() { return; }
	virtual void mover() { return; }
};