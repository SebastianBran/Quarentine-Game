#pragma once

#include "Personaje.h"
#include "Enemigo.h"
#include "Policia.h"
#include "Ambulancia.h"
#include "CruzRoja.h"
#include "SimboloCruzRoja.h"
#include "Mapa.h"
#include "DisparoJugador.h"

#include <vector>
#include "DisparoEnemigo.h"

enum Direcciones { ninguna, arriba, abajo, derecha, izquierda };

class Jugador : public Personaje {
private:
	Direcciones direccion;
	Direcciones ultima;
	vector<DisparoJugador*> disparos;
	int indiceMensaje;
	bool mostrarMensaje;
	int vidas, puntaje;
	int nivel;
public:
	Jugador(Bitmap^ BMjugador, int vidas) : Personaje() {
		setX(720);
		setY(355);
		setDx(0);
		setDy(0);
		setAncho(BMjugador->Width / 12);
		setLargo(BMjugador->Height);
		setIndiceX(0);
		direccion = Direcciones::ninguna;
		ultima = Direcciones::abajo;
		setRecorrido(20);
		setAutomatico(false);
		disparos = vector<DisparoJugador*>();
		this->vidas = vidas;
		indiceMensaje = -1;
		mostrarMensaje = false;
		puntaje = 0;
	}

	void setDirecciones(Direcciones nuevaD) { direccion = nuevaD; }

	void setVidas(int vidas) { this->vidas = vidas; }
	void setPuntaje(int puntaje) { this->puntaje = puntaje; }
	void setNivel(int nivel) { this->nivel = nivel; }
	int getVidas() { return vidas; }
	int getPuntaje() { return puntaje; }

	vector<DisparoJugador*> getDisparos() { return disparos; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ BMjugador, Bitmap^ BMmensaje) {
		Rectangle porcionVisible = Rectangle(getAncho() * getIndiceX(), 0, getAncho(), getLargo());
		buffer->Graphics->DrawImage(BMjugador, getX(), getY(), porcionVisible, GraphicsUnit::Pixel);
		dibujarMensaje(buffer, BMmensaje);
	}	

	int contMensaje = 0;
	void dibujarMensaje(BufferedGraphics^ buffer, Bitmap^ BMmensaje) {
		if (mostrarMensaje) {
			Rectangle porcionVisible = Rectangle(61 * indiceMensaje, 0, 61, 42);
			Rectangle zoom = Rectangle(getX() - 75, getY() - 65, 61 * 1.5, 42 * 1.5);
			buffer->Graphics->DrawImage(BMmensaje, zoom, porcionVisible, GraphicsUnit::Pixel);
			contMensaje++;
			if (contMensaje == 30) {
				mostrarMensaje = false;
				contMensaje = 0;
			}
		}
	}

	bool choqueDisparoEnemigo(Enemigo* enemigo) {
		for (int i = 0; i < enemigo->getDisparos().size(); i++) {
			if (getX() + getAncho() > enemigo->getDisparos()[i]->getX() && getX() < enemigo->getDisparos()[i]->getX() + enemigo->getDisparos()[i]->getAncho()
				&& getY() < enemigo->getDisparos()[i]->getY() + enemigo->getDisparos()[i]->getLargo() && getY() + getLargo() > enemigo->getDisparos()[i]->getY()) {
				return true;
			}
		}

		return false;
	}

	void choqueEnemigos(vector<Enemigo*> enemigos, Mapa* mapa, vector<Policia*> policias, vector<Ambulancia*> ambulancias, vector<CruzRoja*> cruzRojas, vector<SimboloCruz*> simboloCruzRoja) {
		for (int i = 0; i < enemigos.size(); i++) {
			if ((getX() + getAncho() > enemigos[i]->getX() && getX() < enemigos[i]->getX() + enemigos[i]->getAncho()
				&& getY() < enemigos[i]->getY() + enemigos[i]->getLargo() && getY() + getLargo() > enemigos[i]->getY())
				|| choqueDisparoEnemigo(enemigos[i])) {
				
				int nx, ny;
				
				if (nivel == 1) {
					nx = -620 - mapa->getDx();
					ny = -480 - mapa->getDy();
					mapa->setDx(-620);
					mapa->setDy(-480);
				}
				else {
					nx = -120 - mapa->getDx();
					ny = -240 - mapa->getDy();
					mapa->setDx(-120);
					mapa->setDy(-240);
				}

				for (int j = 0; j < enemigos.size(); j++) {
					enemigos[j]->setX(enemigos[j]->getX() + nx);
					enemigos[j]->setY(enemigos[j]->getY() + ny);
					for (int j = 0; j < enemigos[i]->getDisparos().size(); j++) {
						enemigos[i]->getDisparos()[j]->setX(enemigos[i]->getDisparos()[j]->getX() + nx);
						enemigos[i]->getDisparos()[j]->setY(enemigos[i]->getDisparos()[j]->getY() + ny);
					}
				}

				for (int j = 0; j < policias.size(); j++) {
					policias[j]->setX(policias[j]->getX() + nx);
					policias[j]->setY(policias[j]->getY() + ny);
				}

				for (int j = 0; j < ambulancias.size(); j++) {
					ambulancias[j]->setX(ambulancias[j]->getX() + nx);
					ambulancias[j]->setY(ambulancias[j]->getY() + ny);
				}

				for (int j = 0; j < cruzRojas.size(); j++) {
					cruzRojas[j]->setX(cruzRojas[j]->getX() + nx);
					cruzRojas[j]->setY(cruzRojas[j]->getY() + ny);
				}

				for (int j = 0; j < simboloCruzRoja.size(); j++) {
					simboloCruzRoja[j]->setX(simboloCruzRoja[j]->getX() + nx);
					simboloCruzRoja[j]->setY(simboloCruzRoja[j]->getY() + ny);
				}

				setX(720);
				setY(355);
				direccion = Direcciones::ninguna;
				ultima = Direcciones::abajo;
				vidas--;
			}
		}
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ BMjugador, Mapa* mapa, vector<Enemigo*> enemigos,
		vector<Policia*> policias, vector<Ambulancia*> ambulancias, vector<CruzRoja*> cruzRojas,
		vector<SimboloCruz*> simboloCruzRoja) {
		
		switch (direccion)
		{
		case ninguna:
			setDx(0);
			setDy(0);
			switch (ultima)
			{
			case abajo:
				setIndiceX(0); 
				break;
			case derecha:
				setIndiceX(3);
				break;
			case izquierda:
				setIndiceX(6); 
				break;
			case arriba:
				setIndiceX(9);
				break;
			}
			break;
		case abajo:
			setDx(0);
			setDy(getRecorrido());

			ultima = abajo;
			if (getIndiceX() >= 0 && getIndiceX() < 2) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(1);
			}
			break;
		case derecha:
			setDx(getRecorrido());
			setDy(0);

			ultima = derecha;
			if (getIndiceX() >= 3 && getIndiceX() < 5) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(4);
			}
			break;
		case izquierda:
			setDx(-1 * getRecorrido());
			setDy(0);

			ultima = izquierda;
			if (getIndiceX() >= 6 && getIndiceX() < 8) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(7);
			}
			break;
		case arriba:
			setDx(0);
			setDy(-1 * getRecorrido());

			ultima = arriba;
			if (getIndiceX() >= 9 && getIndiceX() < 11) {
				setIndiceX(getIndiceX() + 1);
			}
			else {
				setIndiceX(10);
			}
			break;
		}

		if (!mapa->choque(getX(), getDx(), getY(), getDy(), getAncho(), getLargo(), getAutomatico())) {
			if (mapa->getX() + -1 * getDx() <= 0 &&  mapa->getX() + -1 * getDx() >= -80 * 15 + 5 && 
				mapa->getY() + -1 * getDy() >= 80 * 10 && mapa->getY() + -1 * getDy() <= 80 * 28
				&& getX() >= 240 && getY() >= 240 && getX() <= 1200 && getY() <= 440) {

				for (int i = 0; i < enemigos.size(); i++) {
					enemigos[i]->setX(enemigos[i]->getX() + -1 * getDx());
					enemigos[i]->setY(enemigos[i]->getY() + -1 * getDy());
					for (int j = 0; j < enemigos[i]->getDisparos().size(); j++) {
						enemigos[i]->getDisparos()[j]->setX(enemigos[i]->getDisparos()[j]->getX() + -1 * getDx());
						enemigos[i]->getDisparos()[j]->setY(enemigos[i]->getDisparos()[j]->getY() + -1 * getDy());
					}
				}
				for (int i = 0; i < policias.size(); i++) {
					policias[i]->setX(policias[i]->getX() + -1 * getDx());
					policias[i]->setY(policias[i]->getY() + -1 * getDy());
				}
				for (int i = 0; i < ambulancias.size(); i++) {
					ambulancias[i]->setX(ambulancias[i]->getX() + -1 * getDx());
					ambulancias[i]->setY(ambulancias[i]->getY() + -1 * getDy());
				}
				for (int i = 0; i < cruzRojas.size(); i++) {
					cruzRojas[i]->setX(cruzRojas[i]->getX() + -1 * getDx());
					cruzRojas[i]->setY(cruzRojas[i]->getY() + -1 * getDy());
					for (int j = 0; j < cruzRojas[i]->getDisparos().size(); j++) {
						cruzRojas[i]->getDisparos()[j]->setX(cruzRojas[i]->getDisparos()[j]->getX() + -1 * getDx());
						cruzRojas[i]->getDisparos()[j]->setY(cruzRojas[i]->getDisparos()[j]->getY() + -1 * getDy());
					}
				}
				for (int i = 0; i < simboloCruzRoja.size(); i++) {
					simboloCruzRoja[i]->setX(simboloCruzRoja[i]->getX() + -1 * getDx());
					simboloCruzRoja[i]->setY(simboloCruzRoja[i]->getY() + -1 * getDy());
				}
				for (int i = 0; i < disparos.size(); i++) {
					disparos[i]->setX(disparos[i]->getX() + -1 * getDx());
					disparos[i]->setY(disparos[i]->getY() + -1 * getDy());
					disparos[i]->setLimiteX(disparos[i]->getLimiteX() + -1 * getDx());
					disparos[i]->setLimiteY(disparos[i]->getLimiteY() + -1 * getDy());
				}

				mapa->setDx(mapa->getDx() + -1 * getDx());
				mapa->setDy(mapa->getDy() + -1 * getDy());
			}
			else if (getX() + getDx() >= 0 && getY() + getDy() >= 0 && getX() + getDx() + 20 < buffer->Graphics->VisibleClipBounds.Width
				&& getY() + getDy() + 50 < buffer->Graphics->VisibleClipBounds.Height) {

				setX(getX() + getDx());
				setY(getY() + getDy());
			}
		}

		choqueEnemigos(enemigos, mapa, policias, ambulancias, cruzRojas, simboloCruzRoja);
	}

	void agregarDisparo() {
		disparos.push_back(new DisparoJugador(getX(), getY(), ultima));
	}

	void choqueEnemigosDisparos(vector<Enemigo*> enemigos) {
		for (int i = 0; i < disparos.size(); i++) {
			for (int j = 0; j < enemigos.size(); j++) {
				if (disparos[i]->getX() + disparos[i]->getAncho() > enemigos[j]->getX() && disparos[i]->getX() < enemigos[j]->getX() + enemigos[j]->getAncho()
					&& disparos[i]->getY() < enemigos[j]->getY() + enemigos[j]->getLargo() && disparos[i]->getY() + disparos[i]->getLargo() > enemigos[j]->getY()) {
					disparos[i]->setChoco(true);
					if (enemigos[j]->getChocoBala() == false) enemigos[j]->setIndiceY(enemigos[j]->getIndiceY() + 1);
					mostrarMensaje = true;
					indiceMensaje++;
					if (indiceMensaje == 5) indiceMensaje = 0;
					enemigos[j]->setChocoBala(true);
					puntaje += 10;
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