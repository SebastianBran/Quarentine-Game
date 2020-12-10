#pragma once

#include "Personaje.h"
#include "Mapa1.h"
#include "DisparoJugador.h"
#include <vector>
#include <utility>

using namespace std;

enum DireccionesCruz { arribaC, abajoC, derechaC, izquierdaC };

class CruzRoja : public Personaje {
private:
	DireccionesCruz direccionC;
	vector<DisparoJugador*> disparos;
public:
	CruzRoja(Bitmap^ BMcruzRoja, Mapa* mapa, pair<int, int> origen) : Personaje() {
		setX(origen.first);
		setY(origen.second);
		setDx(0);
		setDy(0);
		setAncho(BMcruzRoja->Width / 12);
		setLargo(BMcruzRoja->Height);
		setIndiceX(3);
		setRecorrido(15);
		setAutomatico(true);
		direccionC = DireccionesCruz(rand() % 4);
		disparos = vector<DisparoJugador*>();
	}

	vector<DisparoJugador*> getDisparos() { return disparos; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ BMcruzRoja) {
		Rectangle porcionVisible = Rectangle(getAncho() * getIndiceX(), 0, getAncho(), getLargo());
		buffer->Graphics->DrawImage(BMcruzRoja, getX(), getY(), porcionVisible, GraphicsUnit::Pixel);
	}

	int contD = 0;
	void mover(BufferedGraphics^ buffer, Bitmap^ BMcruzRoja, Mapa* mapa) {
		switch (direccionC)
		{
		case abajoC:
			setDx(0);
			setDy(getRecorrido());

			if (getIndiceX() >= 0 && getIndiceX() < 2) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(1);
			}
			break;
		case derechaC:
			setDx(getRecorrido());
			setDy(0);

			if (getIndiceX() >= 3 && getIndiceX() < 5) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(4);
			}
			break;
		case izquierdaC:
			setDx(-1 * getRecorrido());
			setDy(0);

			if (getIndiceX() >= 6 && getIndiceX() < 8) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(7);
			}
			break;
		case arribaC:
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
				switch (direccionC)
				{
				case arribaC: direccionC = DireccionesCruz::abajoC;
					break;
				case abajoC: direccionC = DireccionesCruz::arribaC;
					break;
				case derechaC: direccionC = DireccionesCruz::izquierdaC;
					break;
				case izquierdaC: direccionC = DireccionesCruz::derechaC;
					break;
				default:
					break;
				}
			}
		}
		else {
			switch (rand() % 4)
			{
			case 0: direccionC = DireccionesCruz::abajoC;
				break;
			case 1: direccionC = DireccionesCruz::arribaC;
				break;
			case 2: direccionC = DireccionesCruz::izquierdaC;
				break;
			case 3: direccionC = DireccionesCruz::derechaC;
				break;
			}
		}

		contD++;
		if (contD == 20) {
			agregarDisparo();
			contD = 0;
		}

		dibujar(buffer, BMcruzRoja);
	}

	void agregarDisparo() {
		disparos.push_back(new DisparoJugador(getX(), getY(), direccionC + 1));
	}

	void choqueEnemigosDisparos(vector<Enemigo*> enemigos) {
		for (int i = 0; i < disparos.size(); i++) {
			for (int j = 0; j < enemigos.size(); j++) {
				if (disparos[i]->getX() + disparos[i]->getAncho() > enemigos[j]->getX() && disparos[i]->getX() < enemigos[j]->getX() + enemigos[j]->getAncho()
					&& disparos[i]->getY() < enemigos[j]->getY() + enemigos[j]->getLargo() && disparos[i]->getY() + disparos[i]->getLargo() > enemigos[j]->getY()) {
					disparos[i]->setChoco(true);
					if (enemigos[j]->getChocoBala() == false) enemigos[j]->setIndiceY(enemigos[j]->getIndiceY() + 1);
					enemigos[j]->setChocoBala(true);
					return;
				}
			}
		}
	}

	void moverDisparos(BufferedGraphics^ buffer, Bitmap^ BMdisparoJ, Mapa* mapa, vector<Enemigo*> enemigos) {
		for (int i = 0; i < disparos.size(); i++) {
			disparos[i]->mover(buffer, BMdisparoJ, mapa);
			choqueEnemigosDisparos(enemigos);
			if (disparos[i]->getChoco()) {
				disparos.erase(disparos.begin() + i);
				i--;
			}
		}
	}
};