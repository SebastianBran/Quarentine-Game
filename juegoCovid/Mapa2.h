#pragma once

#include "Mapa.h"
#include "Personaje.h"

using namespace System::Drawing;

const int filasM2 = 28;
const int columnasM2 = 34;

class Mapa2 : public Mapa {
private:

public:
	Mapa2(Bitmap^ BMpistas, Bitmap^ BMedificio, Bitmap^ BMcasitas, Bitmap^ BMservicios,
		Bitmap^ BMmuni2, Bitmap^ BMcesped, Bitmap^ BMarbol, Bitmap^ BMmadera) : Mapa() {
		//mapa
		dx = -120;
		dy = -240;
		anchoMapa = 80;
		largoMapa = 80;
		//pistas
		anchoP = BMpistas->Width / 4;
		largoP = BMpistas->Height / 3;
		//edificio
		anchoEdi = BMedificio->Width / 4;
		largoEdi = BMedificio->Height;
		//casitas
		anchoCasi = BMedificio->Width / 4;
		largoCasi = BMedificio->Height;
		//servicios
		anchoSer = BMservicios->Width / 4;
		largoSer = BMservicios->Height;
		//municipalidad
		anchoMuni = BMmuni2->Width;
		largoMuni = BMmuni2->Height;
		//cesped
		anchoCesped = BMcesped->Width;
		largoCesped = BMcesped->Height;
		//arbol
		anchoArbol = BMarbol->Width;
		largoArbol = BMarbol->Height;
		//madera
		anchoMadera = BMmadera->Width;
		largoMadera = BMmadera->Height;
	}

	//1, 2, 3, 4, 5, 12, 13, 14, 15, 16, 17, 18, 19: pistas
	//6: edificios
	//7: casitas
	//8: servicios
	//9: munipalidad
	//10: cesped y arbol
	//11: madera

	int mapa2[filasM2][columnasM2] = {
		{6, 0, 0, 0, 7, 0, 0, 0, 1, 0, 6, 0, 0, 0, 10, 10, 2, 0, 9, 0, 0, 0, 0, 0, 1, 0, 7, 0, 0, 0, 7, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 10, 10, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{3, 4, 3, 4, 14, 14, 3, 4, 17, 0, 4, 3, 4, 3, 4, 3, 5, 0, 3, 4, 3, 4, 3, 4, 17, 0, 4, 3, 14, 14, 4, 3, 4, 3},
		{0, 0, 0, 0, 15, 0, 0, 0, 16, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 0, 0, 15, 0, 0, 0, 0, 0},
		{8, 0, 0, 0, 2, 0, 10, 10, 10, 10, 11, 11, 10, 10, 10, 10, 1, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 2, 0, 6, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 10, 10, 10, 10, 11, 11, 10, 10, 10, 10, 2, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 10, 10, 10, 10, 11, 11, 10, 10, 10, 10, 1, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 10, 10, 10, 10, 11, 11, 10, 10, 10, 10, 2, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 1, 0, 0, 0, 0, 0},
		{4, 3, 4, 3, 5, 0, 3, 4, 3, 4, 3, 4, 3, 4, 14, 14, 17, 0, 14, 14, 3, 4, 3, 4, 3, 4, 3, 4, 5, 0, 3, 4, 3, 4},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 16, 16, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{6, 0, 0, 0, 1, 0, 8, 0, 0, 0, 7, 0, 0, 0, 1, 0, 10, 10, 1, 0, 7, 0, 0, 0, 8, 0, 0, 0, 1, 0, 7, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 10, 10, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 10, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 10, 10, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
		{3, 4, 3, 4, 5, 0, 4, 3, 4, 3, 4, 3, 4, 3, 17, 0, 14, 14, 17, 0, 4, 3, 14, 14, 3, 4, 3, 4, 5, 0, 4, 3, 4, 3},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 16, 15, 0, 16, 16, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{6, 0, 0, 0, 2, 0, 10, 10, 8, 0, 0, 0, 7, 0, 0, 0, 1, 0, 7, 0, 0, 0, 2, 0, 10, 10, 10, 10, 2, 0, 6, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 10, 10, 10, 10, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 10, 10, 10, 10, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 7, 0, 0, 0, 1, 0, 10, 10, 10, 10, 1, 0, 7, 0, 0, 0},
		{4, 3, 4, 3, 5, 0, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 19, 18, 0, 0, 0, 0, 12, 13, 3, 4, 3, 4, 19, 18, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0},
		{7, 0, 0, 0, 1, 0, 7, 0, 0, 0, 6, 0, 0, 0, 10, 10, 2, 0, 6, 0, 0, 0, 2, 0, 7, 0, 0, 0, 1, 0, 6, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0}
	};

	void dibujarMapa(BufferedGraphics^ buffer, Bitmap^ BMpistas, Bitmap^ BMedificio, Bitmap^ BMcasitas, Bitmap^ BMservicios,
		Bitmap^ BMmuni2, Bitmap^ BMcesped, Bitmap^ BMarbol, Bitmap^ BMmadera) {
		x = dx;
		y = dy;
		int indiceEdificios = 0;
		int indiceCasitas = 0;
		int indiceServicios = 0;
		for (int i = 0; i < filasM2; i++) {
			for (int j = 0; j < columnasM2; j++) {
				if (mapa2[i][j] == 1) {
					Rectangle porcionVisible = Rectangle(anchoP * 2, 0, anchoP * 2, largoP);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 2) {
					Rectangle porcionVisible = Rectangle(0, 0, anchoP * 2, largoP);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 3) {
					Rectangle porcionVisible = Rectangle(0, largoP, anchoP, largoP * 2);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 4) {
					Rectangle porcionVisible = Rectangle(anchoP, largoP, anchoP, largoP * 2);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 5) {
					Rectangle porcionVisible = Rectangle(anchoP * 2, largoP, anchoP * 2, largoP * 2);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 5) {
					Rectangle porcionVisible = Rectangle(anchoP * 2, largoP, anchoP * 2, largoP * 2);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 6) {
					Rectangle porcionVisible = Rectangle(anchoEdi * indiceEdificios, 0, anchoEdi, largoEdi);
					buffer->Graphics->DrawImage(BMedificio, x, y, porcionVisible, GraphicsUnit::Pixel);
					indiceEdificios++;
					if (indiceEdificios == 4) indiceEdificios = 0;
				}
				else if (mapa2[i][j] == 7) {
					Rectangle porcionVisible = Rectangle(anchoCasi * indiceCasitas, 0, anchoCasi, largoCasi);
					buffer->Graphics->DrawImage(BMcasitas, x, y, porcionVisible, GraphicsUnit::Pixel);
					indiceCasitas++;
					if (indiceCasitas == 4) indiceCasitas = 0;
				}
				else if (mapa2[i][j] == 8) {
					Rectangle porcionVisible = Rectangle(anchoSer * indiceServicios, 0, anchoSer, largoSer);
					buffer->Graphics->DrawImage(BMservicios, x, y, porcionVisible, GraphicsUnit::Pixel);
					indiceServicios++;
					if (indiceServicios == 4) indiceServicios = 0;
				}
				else if (mapa2[i][j] == 9) {
					Rectangle porcionVisible = Rectangle(0, 0, anchoMuni, largoMuni);
					buffer->Graphics->DrawImage(BMmuni2, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 10) {
					Rectangle porcionVisible = Rectangle(0, 0, anchoCesped, largoCesped);
					buffer->Graphics->DrawImage(BMcesped, x, y, porcionVisible, GraphicsUnit::Pixel);
					Rectangle porcionVisible2 = Rectangle(0, 0, anchoArbol, largoArbol);
					buffer->Graphics->DrawImage(BMarbol, x, y, porcionVisible2, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 11) {
					Rectangle porcionVisible = Rectangle(0, 0, anchoMadera, largoMadera);
					buffer->Graphics->DrawImage(BMmadera, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 12) {
					Rectangle porcionVisible = Rectangle(anchoP * 2, 0, anchoP, largoP);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 13) {
					Rectangle porcionVisible = Rectangle(anchoP * 3, largoP, anchoP, largoP * 2);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 14) {
					Rectangle porcionVisible = Rectangle(anchoP, largoP, anchoP, largoP);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 15) {
					Rectangle porcionVisible = Rectangle(anchoP * 2, largoP * 2, anchoP * 2, largoP);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 16) {
					Rectangle porcionVisible = Rectangle(anchoP, largoP * 2, anchoP, largoP);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 17) {
					Rectangle porcionVisible = Rectangle(anchoP * 2, largoP, anchoP * 2, largoP);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 18) {
					Rectangle porcionVisible = Rectangle(anchoP * 3, 0, anchoP, largoP);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				else if (mapa2[i][j] == 19) {
					Rectangle porcionVisible = Rectangle(anchoP * 2, largoP, anchoP, largoP * 2);
					buffer->Graphics->DrawImage(BMpistas, x, y, porcionVisible, GraphicsUnit::Pixel);
				}
				x += anchoMapa;
			}
			y += largoMapa;
			x = dx;
		}
	}

	int cont = 0;

	bool choque(int xs, int dxs, int ys, int dys, int anchoJug, int largoJug, bool automatico) {
		x = dx;
		y = dy;

		for (int i = 0; i < filasM2; i++) {
			for (int j = 0; j < columnasM2; j++) {
				if (mapa2[i][j] == 6) {
					if (xs + dxs + anchoJug + 10 > x && xs + dxs < x + anchoEdi + 10 && ys + dys < y + largoEdi + 10 && ys + dys + largoJug + 10 > y) {
						return true;
					}
				}
				else if (mapa2[i][j] == 7) {
					if (xs + dxs + anchoJug + 10 > x && xs + dxs < x + anchoCasi + 10 && ys + dys < y + largoCasi + 10 && ys + dys + largoJug + 10 > y) {
						return true;
					}
				}
				else if (mapa2[i][j] == 8) {
					if (xs + dxs + anchoJug + 10 > x && xs + dxs < x + anchoSer + 10 && ys + dys < y + largoSer + 10 && ys + dys + largoJug + 10 > y) {
						return true;
					}
				}
				else if (mapa2[i][j] == 9) {
					if (xs + dxs + anchoJug + 10 > x && xs + dxs < x + anchoMuni + 10 && ys + dys < y + largoMuni + 10 && ys + dys + largoJug + 10 > y) {
						return true;
					}
				}
				else if (mapa2[i][j] == 10) {
					if (xs + dxs + anchoJug + 10 > x && xs + dxs < x + anchoCesped + 10 && ys + dys < y + largoCesped + 10 && ys + dys + largoJug + 10 > y) {
						return true;
					}
				}
				else if (mapa2[i][j] == 11 && automatico) {
					if (xs + dxs + anchoJug + 10 > x && xs + dxs < x + anchoMadera + 10 && ys + dys < y + largoMadera + 10 && ys + dys + largoJug + 10 > y) {
						return true;
					}
				}
				else if ((mapa2[i][j] == 5 || mapa2[i][j] == 17 || mapa2[i][j] == 19) && automatico && cont == 0) {
					if ((xs >= x && xs + anchoJug <= x + 160 && ys + largoJug <= y + 114 && ys + largoJug >= y + 94 && dys < 0) ||
						(xs >= x && xs + anchoJug <= x + 160 && ys <= y + 76 && ys >= y + 56 && dys > 0) ||
						(xs >= x + 38 && xs <= x + 58 && ys + largoJug <= y + 160 && ys >= y && dxs > 0) ||
						(xs + anchoJug >= x + 112 && xs + anchoJug <= x + 132 && ys + largoJug <= y + 160 && ys >= y && dxs < 0)) {

						cont++;
						return true;
					}
				}
				else if (mapa2[i][j] == 15 && automatico && cont == 0) {
					if ((xs >= x && xs + anchoJug <= x + 160 && ys + largoJug <= y + 34 && ys + largoJug <= y + 14 && dys < 0) ||
						(xs >= x && xs + anchoJug <= x + 160 && ys <= y - 4 && ys >= y - 24 && dys > 0) ||
						(xs >= x + 38 && xs <= x + 58 && ys + largoJug <= y + 80 && ys >= y - 80 && dxs > 0) ||
						(xs + anchoJug >= x + 112 && xs + anchoJug <= x + 132 && ys + largoJug <= y + 80 && ys >= y - 80 && dxs < 0)) {

						cont++;
						return true;
					}
				}

				x += anchoMapa;
			}

			y += largoMapa;
			x = dx;
		}

		if (cont >= 1) {
			cont++;
			if (cont == 20) {
				cont = 0;
			}
		}

		return false;
	}
};