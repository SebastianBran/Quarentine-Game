#pragma once
#include "Jugador.h"
#include "Enemigo.h"
#include "Policia.h"
#include "Ambulancia.h"
#include "CruzRoja.h"
#include "SimboloCruzRoja.h"
#include "Mapa.h"
#include "Mapa1.h"

#include <vector>	

class Nivel1
{
private: 
	int cantEnemigos = rand() % 5 + 10;
	int indiceEnemigos = 0;
	int cantPolicias = 3;
	int indicePolicias = 0;
	int cantAmbulancias = 0;
	int indiceAmbulancias = 0;
	int cantCruzRoja = 2;
	int indiceCruzRoja = 0;
	int cantSimbolosCruzRoja = 2;
	int indiceSimboloCruzRoja = 0;
	int enemigosCapturados = 0;
	///
	vector<pair<int, int>> origenesEnemigosN1 = { {410,10},{410,2140},{2330,10},{2330,2140} };
	vector<pair<int, int>> origenesPoliciasN1 = { {10,380},{2660,380},{10,1380},{2660,1380} };
	vector<pair<int, int>> origenesSimbolosN1 = { {380,380},{380, 1330},{850,850},{850,1810},{1810,1330},{2290,380},{2290,1810} };
	///
	vector<Enemigo*> enemigos;
	vector<Policia*> policias;
	vector<Ambulancia*> ambulancias;
	vector<CruzRoja*> cruzRojas;
	vector<SimboloCruz*> simboloCruzRoja;
	///
	Mapa* mapa1;
public:
	Nivel1(Bitmap^ BMjugador, Bitmap^ BMenemigo1, Bitmap ^ BMpolicia, Bitmap^ BMpistas, Bitmap^ BMedificio, Bitmap^ BMcasitas, Bitmap^ BMservicios,
		Bitmap^ BMmuni, Bitmap^ BMcesped, Bitmap^ BMarbol, Bitmap^ BMmadera) {
		
		mapa1 = new Mapa1(BMpistas, BMedificio, BMcasitas, BMservicios, BMmuni, BMcesped, BMarbol, BMmadera);
	}

	bool getSiguienteNivel() {
		return enemigosCapturados > (cantEnemigos / 2);
	}

	int aux = 0;
	void agregarEnemigos(Bitmap^ BMenemigo1, Mapa* mapa1) {
		if (indiceEnemigos < cantEnemigos) {
			int temp = rand() % 4;
			enemigos.push_back(new Enemigo(BMenemigo1, aux, mapa1, origenesEnemigosN1[temp]));
			aux++;
			if (aux == 4) aux = 0;
			indiceEnemigos++;
		}
	}

	void agregarPolicias(Bitmap^ BMpolicia, Mapa* mapa1) {
		if (indicePolicias < cantPolicias) {
			int temp = rand() % 4;
			policias.push_back(new Policia(BMpolicia, mapa1, origenesPoliciasN1[temp]));
			indicePolicias++;
		}
	}

	void agregarCruzRoja(Bitmap^ BMcruzRoja, Mapa* mapa1, Jugador* jugador) {
		if (indiceCruzRoja < cantCruzRoja) {
			for (int i = 0; i < simboloCruzRoja.size(); i++) {
				if (jugador->getX() + jugador->getAncho() > simboloCruzRoja[i]->getX() && jugador->getX() < simboloCruzRoja[i]->getX() + simboloCruzRoja[i]->getAncho()
					&& jugador->getY() < simboloCruzRoja[i]->getY() + simboloCruzRoja[i]->getLargo() && jugador->getY() + jugador->getLargo() > simboloCruzRoja[i]->getY()) {
					
					int temp = rand() % 4;
					pair<int, int> origen = {simboloCruzRoja[i]->getX(),simboloCruzRoja[i]->getY()};
					cruzRojas.push_back(new CruzRoja(BMcruzRoja, mapa1, origen));
					indiceCruzRoja++;
					simboloCruzRoja.erase(simboloCruzRoja.begin() + i);
					i--;
				}
			}
		}
	}

	void agregarSimboloCruzRoja(Bitmap^ BMsimboloCruzRoja, Mapa* mapa1) {
		if (indiceSimboloCruzRoja < cantSimbolosCruzRoja) {
			int temp = rand() % 7;
			simboloCruzRoja.push_back(new SimboloCruz(BMsimboloCruzRoja, mapa1, origenesSimbolosN1[temp]));
			indiceSimboloCruzRoja++;
		}
	}

	int contE = 90, contP = 0, contS = 0;
	void Jugar(BufferedGraphics^ buffer, Jugador* jugador, Bitmap^ BMjugador, Bitmap^ BMdisparoJ, Bitmap^ BMmensajes, Bitmap^ BMenemigo1, Bitmap^ BMdisparoE, 
		Bitmap^ BMpolicia, Bitmap^ BMambulancia, Bitmap^ BMcruzRoja, Bitmap^ BMsimboloCruzRoja, Bitmap^ BMpistas, Bitmap^ BMedificio, Bitmap^ BMcasitas,
		Bitmap^ BMservicios, Bitmap^ BMmuni, Bitmap^ BMcesped, Bitmap^ BMarbol, Bitmap^ BMmadera, bool dificil) {

		jugador->mover(buffer, BMjugador,  mapa1, enemigos, policias, ambulancias, cruzRojas, simboloCruzRoja);
		mapa1->dibujarMapa(buffer, BMpistas, BMedificio, BMcasitas, BMservicios, BMmuni, BMcesped, BMarbol, BMmadera);
		//Simbolos Cruz Roja
		contS++;
		if (contS == 700) {
			agregarSimboloCruzRoja(BMsimboloCruzRoja, mapa1);
			contS = 0;
		}
		for (int i = 0; i < simboloCruzRoja.size(); i++) {
			simboloCruzRoja[i]->dibujar(buffer, BMsimboloCruzRoja);
		}
		//Enemigos
		contE++;
		if (contE == 100) {
			agregarEnemigos(BMenemigo1, mapa1);
			contE = 0;
		}
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->mover(buffer, BMenemigo1, mapa1, policias, indicePolicias, ambulancias, BMdisparoE, indiceAmbulancias, 1, dificil);
			enemigos[i]->moverDisparos(buffer, BMdisparoE, mapa1);
			if (enemigos[i]->getChocoPoli_Ambu()) {
				enemigos.erase(enemigos.begin() + i);
				enemigosCapturados++;
				i--;
			}
		}
		//Policias
		contP++;
		if (contP == 100) {
			agregarPolicias(BMpolicia, mapa1);
			contP = 0;
		}
		for (int i = 0; i < policias.size(); i++) {
			policias[i]->mover(buffer, BMpolicia, mapa1);
		}
		//CruzRojas
		agregarCruzRoja(BMcruzRoja, mapa1, jugador);
		for (int i = 0; i < cruzRojas.size(); i++) {
			cruzRojas[i]->mover(buffer, BMcruzRoja, mapa1);
			cruzRojas[i]->moverDisparos(buffer, BMdisparoJ, mapa1, enemigos);
		}
		//Ambulancias
		for (int i = 0; i < cantAmbulancias; i++) {
			ambulancias[i]->mover(buffer, BMambulancia, mapa1);
		}
		jugador->moverDisparos(buffer, BMdisparoJ, mapa1, enemigos);
		jugador->dibujar(buffer, BMjugador, BMmensajes);
	}
};