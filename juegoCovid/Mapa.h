#pragma once

class Mapa {
protected:
	int x, y, dx, dy, anchoMapa, largoMapa;

	int anchoP, largoP; //pistas		
	int anchoEdi, largoEdi; //edificio
	int anchoCasi, largoCasi; //casitas
	int anchoSer, largoSer; //servicios
	int anchoMuni, largoMuni; //municipalidad
	int anchoCesped, largoCesped; //cesped
	int anchoArbol, largoArbol; //arbol
	int anchoMadera, largoMadera; //madera
public:
	Mapa() { }
	
	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDx(int dx) { this->dx = dx; }
	void setDy(int dy) { this->dy = dy; }

	virtual void dibujarMapa(BufferedGraphics^ buffer, Bitmap^ BMpistas, Bitmap^ BMedificio, Bitmap^ BMcasitas, Bitmap^ BMservicios,
		Bitmap^ BMmuni, Bitmap^ BMcesped, Bitmap^ BMarbol, Bitmap^ BMmadera) { return; }
	virtual bool choque(int xs, int dxs, int ys, int dys, int anchoJug, int largoJug, bool automatico) { return 0; }
};