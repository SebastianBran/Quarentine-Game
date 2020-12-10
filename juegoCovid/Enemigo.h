#pragma once

#include "Personaje.h"
#include "Policia.h"
#include "Ambulancia.h"
#include "Mapa1.h"
#include "DisparoEnemigo.h"

#include <vector>
#include <utility>

using namespace std;

enum DireccionesEne { arribaE, abajoE, derechaE, izquierdaE };

class Enemigo : public Personaje {
private:
	DireccionesEne direccionE;
	bool chocoBala, chocoPoli_Ambu;
	vector<DisparoEnemigo*> disparos;
public:
	Enemigo(Bitmap^ BMenemigo1, int aux, Mapa* mapa, pair<int,int> origen) : Personaje() {
		setX(mapa->getDx() + origen.first);
		setY(mapa->getDy() + origen.second);
		setDx(0);
		setDy(0);
		setAncho(BMenemigo1->Width / 12);
		setLargo(BMenemigo1->Height / 8);
		setIndiceX(3);
		setIndiceY(2*aux);
		setRecorrido(23);
		setAutomatico(true);
		disparos = vector<DisparoEnemigo*>();
		chocoBala = false;
		chocoPoli_Ambu = false;
		direccionE = DireccionesEne(rand() % 4);
	}

	void setChocoBala(bool chocoBala) { this->chocoBala = chocoBala; }
	bool getChocoBala() { return chocoBala; }
	bool getChocoPoli_Ambu() { return chocoPoli_Ambu; }

	vector<DisparoEnemigo*> getDisparos() { return disparos; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ BMenemigo1) {
		Rectangle porcionVisible = Rectangle(getAncho() * getIndiceX(), getLargo() * getIndiceY(), getAncho(), getLargo());
		buffer->Graphics->DrawImage(BMenemigo1, getX(), getY(), porcionVisible, GraphicsUnit::Pixel);
	}

	void choquePolicia(vector<Policia*> policias, int& indicePolicias) {
		for (int i = 0; i < indicePolicias; i++) {
			if (getX() + getAncho() > policias[i]->getX() && getX() < policias[i]->getX() + policias[i]->getAncho()
				&& getY() < policias[i]->getY() + policias[i]->getLargo() && getY() + getLargo() > policias[i]->getY() && chocoBala) {
				chocoPoli_Ambu = true;
			}
		}
	}

	void choqueAmbulancias(vector<Ambulancia*> ambulancias, int& indiceAmbulancias) {
		for (int i = 0; i < indiceAmbulancias; i++) {
			if (getX() + getAncho() > ambulancias[i]->getX() && getX() < ambulancias[i]->getX() + ambulancias[i]->getAncho()
				&& getY() < ambulancias[i]->getY() + ambulancias[i]->getLargo() && getY() + getLargo() > ambulancias[i]->getY() && chocoBala) {
				chocoPoli_Ambu = true;
			}
		}
	}

	int contD = 0;
	void mover(BufferedGraphics^ buffer, Bitmap^ BMenemigo1, Mapa* mapa, vector<Policia*> policias, int& indicePolicias, 
		vector<Ambulancia*> ambulancias, Bitmap^ BMdisparoE, int& indiceAmbulancias, int nivel, bool  dificil) {
		switch (direccionE)
		{
		case abajoE:
			setDx(0);
			setDy(getRecorrido());

			if (getIndiceX() >= 0 && getIndiceX() < 2) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(1);
			}
			break;
		case derechaE:
			setDx(getRecorrido());
			setDy(0);

			if (getIndiceX() >= 3 && getIndiceX() < 5) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(4);
			}
			break;
		case izquierdaE:
			setDx(-1 * getRecorrido());
			setDy(0);

			if (getIndiceX() >= 6 && getIndiceX() < 8) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(7);
			}
			break;
		case arribaE:
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
				switch (direccionE)
				{
				case arribaE: direccionE = DireccionesEne::abajoE;
					break;
				case abajoE: direccionE = DireccionesEne::arribaE;
					break;
				case derechaE: direccionE = DireccionesEne::izquierdaE;
					break;
				case izquierdaE: direccionE = DireccionesEne::derechaE;
					break;
				default:
					break;
				}
			}
		}
		else {
			switch (rand() % 4)
			{
			case 0: direccionE = DireccionesEne::abajoE;
				break;
			case 1: direccionE = DireccionesEne::arribaE;
				break;
			case 2: direccionE = DireccionesEne::izquierdaE;
				break;
			case 3: direccionE = DireccionesEne::derechaE;
				break;
			}
		}

		if (dificil) {
			contD++;
			if (contD == 20) {
				agregarDisparo();
				contD = 0;
			}
		}

		dibujar(buffer, BMenemigo1);
		if (nivel == 1) {
			choquePolicia(policias, indicePolicias);
		}
		else if (nivel == 2) {
			choqueAmbulancias(ambulancias, indiceAmbulancias);
		}
	}

	void agregarDisparo() {
		disparos.push_back(new DisparoEnemigo(getX(), getY(), direccionE));
	}

	void moverDisparos(BufferedGraphics^ buffer, Bitmap^ BMdisparoE, Mapa* mapa) {
		for (int i = 0; i < disparos.size(); i++) {
			disparos[i]->mover(buffer, BMdisparoE, mapa);
			if (disparos[i]->getChoco()) {
				disparos.erase(disparos.begin() + i);
				i--;
			}
		}
	}
};