#pragma once
#include "Jugador.h"
#include "Enemigo.h"
#include "Policia.h"
#include "Ambulancia.h"
#include "CruzRoja.h"
#include "SimboloCruzRoja.h"
#include "Mapa.h"
#include "Mapa2.h"

#include <vector>

class Nivel2
{
private:
	int cantEnemigos = rand() % 5 + 10;
	int indiceEnemigos = 0;
	int cantPolicias = 0;
	int indicePolicias = 0;
	int cantAmbulancias = 3;
	int indiceAmbulancias = 0;
	int cantCruzRoja = 2;
	int indiceCruzRoja = 0;
	int cantSimbolosCruzRoja = 2;
	int indiceSimboloCruzRoja = 0;
	int enemigosCapturados = 0;
	///
	vector<pair<int, int>> origenesEnemigosN2 = { {710,10},{340,2140},{1980,10},{2300,2140} };
	vector<pair<int, int>> origenesAmbulanciasN2 = { {10,370},{2610,370},{10,1330},{2610,1330} };
	vector<pair<int, int>> origenesSimbolosN2 = { {370,370},{370,1330},{1490,850},{1490,1810},{1920,1330},{2290,380},{2290,1810} };
	///
	vector<Enemigo*> enemigos;
	vector<Policia*> policias;
	vector<Ambulancia*> ambulancias;
	vector<CruzRoja*> cruzRojas;
	vector<SimboloCruz*> simboloCruzRoja;
	///
	Mapa* mapa2;
public:
	Nivel2(Bitmap^ BMjugador, Bitmap^ BMenemigo1, Bitmap^ BMpolicia, Bitmap^ BMpistas, Bitmap^ BMedificio, Bitmap^ BMcasitas, Bitmap^ BMservicios,
		Bitmap^ BMmuni, Bitmap^ BMcesped, Bitmap^ BMarbol, Bitmap^ BMmadera) {

		mapa2 = new Mapa2(BMpistas, BMedificio, BMcasitas, BMservicios, BMmuni, BMcesped, BMarbol, BMmadera);
	}

	bool  getGano() {
		return enemigosCapturados > (cantEnemigos / 2);
	}

	int aux = 0;
	void agregarEnemigos(Bitmap^ BMenemigo1, Mapa* mapa2) {
		if (indiceEnemigos < cantEnemigos) {
			int temp = rand() % 4;
			enemigos.push_back(new Enemigo(BMenemigo1, aux, mapa2, origenesEnemigosN2[temp]));
			aux++;
			if (aux == 4) aux = 0;
			indiceEnemigos++;
		}
	}

	void agregarAmbulancias(Bitmap^ BMambulancia, Mapa* mapa2) {
		if (indiceAmbulancias < cantAmbulancias) {
			int temp = rand() % 4;
			ambulancias.push_back(new Ambulancia(mapa2, origenesAmbulanciasN2[temp]));
			indiceAmbulancias++;
		}
	}

	void agregarCruzRoja(Bitmap^ BMcruzRoja, Mapa* mapa2, Jugador* jugador) {
		if (indiceCruzRoja < cantCruzRoja) {
			for (int i = 0; i < simboloCruzRoja.size(); i++) {
				if (jugador->getX() + jugador->getAncho() > simboloCruzRoja[i]->getX() && jugador->getX() < simboloCruzRoja[i]->getX() + simboloCruzRoja[i]->getAncho()
					&& jugador->getY() < simboloCruzRoja[i]->getY() + simboloCruzRoja[i]->getLargo() && jugador->getY() + jugador->getLargo() > simboloCruzRoja[i]->getY()) {

					int temp = rand() % 4;
					pair<int, int> origen = { simboloCruzRoja[i]->getX(),simboloCruzRoja[i]->getY() };
					cruzRojas.push_back(new CruzRoja(BMcruzRoja, mapa2, origen));
					indiceCruzRoja++;
					simboloCruzRoja.erase(simboloCruzRoja.begin() + i);
					i--;
				}
			}
		}
	}

	void agregarSimboloCruzRoja(Bitmap^ BMsimboloCruzRoja, Mapa* mapa2) {
		if (indiceSimboloCruzRoja < cantSimbolosCruzRoja) {
			int temp = rand() % 7;
			simboloCruzRoja.push_back(new SimboloCruz(BMsimboloCruzRoja, mapa2, origenesSimbolosN2[temp]));
			indiceSimboloCruzRoja++;
		}
	}

	int contE = 90, contA = 0, contS = 0;
	void Jugar(BufferedGraphics^ buffer, Jugador* jugador, Bitmap^ BMjugador, Bitmap^ BMdisparoJ, Bitmap^ BMmensajes, Bitmap^ BMenemigo1, Bitmap^ BMdisparoE,
		Bitmap^ BMpolicia, Bitmap^ BMambulancia, Bitmap^ BMcruzRoja, Bitmap^ BMsimboloCruzRoja, Bitmap^ BMpistas, Bitmap^ BMedificio, Bitmap^ BMcasitas, Bitmap^ BMservicios, Bitmap^ BMmuni, Bitmap^ BMcesped,
		Bitmap^ BMarbol, Bitmap^ BMmadera, bool dificil) {

		jugador->mover(buffer, BMjugador, mapa2, enemigos, policias, ambulancias, cruzRojas, simboloCruzRoja);
		mapa2->dibujarMapa(buffer, BMpistas, BMedificio, BMcasitas, BMservicios, BMmuni, BMcesped, BMarbol, BMmadera);
		//Simbolos Cruz Roja
		contS++;
		if (contS == 700) {
			agregarSimboloCruzRoja(BMsimboloCruzRoja, mapa2);
			contS = 0;
		}
		for (int i = 0; i < simboloCruzRoja.size(); i++) {
			simboloCruzRoja[i]->dibujar(buffer, BMsimboloCruzRoja);
		}
		////Enemigos
		contE++;
		if (contE == 100) {
			agregarEnemigos(BMenemigo1, mapa2);
			contE = 0;
		}
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->mover(buffer, BMenemigo1, mapa2, policias, indicePolicias, ambulancias, BMdisparoE, indiceAmbulancias, 2, dificil);
			enemigos[i]->moverDisparos(buffer, BMdisparoE, mapa2);
			if (enemigos[i]->getChocoPoli_Ambu()) {
				enemigos.erase(enemigos.begin() + i);
				enemigosCapturados++;
				i--;
			}
		}
		////Ambulancias
		contA++;
		if (contA == 100) {
			agregarAmbulancias(BMambulancia, mapa2);
			contA = 0;
		}
		for (int i = 0; i < ambulancias.size(); i++) {
			ambulancias[i]->mover(buffer, BMambulancia, mapa2);
		}
		//CruzRojas
		agregarCruzRoja(BMcruzRoja, mapa2, jugador);
		for (int i = 0; i < cruzRojas.size(); i++) {
			cruzRojas[i]->mover(buffer, BMcruzRoja, mapa2);
			cruzRojas[i]->moverDisparos(buffer, BMdisparoJ, mapa2, enemigos);
		}
		////
		jugador->moverDisparos(buffer, BMdisparoJ, mapa2, enemigos);
		jugador->dibujar(buffer, BMjugador, BMmensajes);
	}
};