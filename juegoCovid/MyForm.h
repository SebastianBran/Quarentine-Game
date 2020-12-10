#pragma once

#include "Nivel1.h"
#include "Nivel2.h"

#include <ctime>

using namespace System::Drawing;
using namespace System::Media;

namespace juegoCovid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Jugador* jugador;
		Nivel1* nivel1;
		Nivel2* nivel2;
		bool pausa;
		int vidas = 10;
		int Tminutos = 0, Tsegundos = 0, Tmax = 10;
		bool dificil = false;
		//
		int etapa = 1;
		int etapaMenu = 1;
		//
		bool  iluminaContinuar = false;

	private: System::Windows::Forms::Label^ lblTeclas;
	private: System::Windows::Forms::Label^ lblTeclaControl;
	private: System::Windows::Forms::Label^ lblTeclaP;
	private: System::Windows::Forms::TextBox^ tbVidas;
	private: System::Windows::Forms::ComboBox^ cbDificultad;
	private: System::Windows::Forms::TextBox^ tbTiempo;
	private: System::Windows::Forms::Label^ lblIntro1;
	private: System::Windows::Forms::Label^ lblRegla1;
	private: System::Windows::Forms::Label^ lblIntro2;
	private: System::Windows::Forms::Label^ lblRegla2;
	private: System::Windows::Forms::Label^ lblRegla3;
	private: System::Windows::Forms::Label^ lblRegla6;
	private: System::Windows::Forms::Label^ lblRegla4;
	private: System::Windows::Forms::Label^ lblRegla5;
	private: System::Windows::Forms::Label^ lblCreditos;
	private: System::Windows::Forms::Label^ lblRegla7;
	private: System::Windows::Forms::Label^ lblSinVidas;
	private: System::Windows::Forms::Label^ lblSinTiempo;
	private: System::Windows::Forms::Label^ lblPuntajeTotal;
	private: System::Windows::Forms::Timer^ Tiempo;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			TbInfoJugador->Location = Point(555, 3);
			TbInfoJugador->Size = Drawing::Size(430, 33);
			TbPerdiste->Location = Point(540, 320);
			TbPerdiste->Size = Drawing::Size(445, 143);
			lblSinTiempo->Location = Point(585,420);
			lblSinVidas->Location = Point(585, 420);
			lblPuntajeTotal->Location = Point(625, 550);
			//
			lblTeclas->Location = Point(720, 245);
			lblTeclaControl->Location = Point(720, 375);
			lblTeclaP->Location = Point(720, 495);
			//
			lblIntro1->Location = Point(320, 220);
			lblIntro2->Location = Point(320, 390);
			//
			lblRegla1->Location = Point(290, 210);
			lblRegla2->Location = Point(290, 320);
			lblRegla3->Location = Point(290, 480);
			lblRegla4->Location = Point(290, 210);
			lblRegla5->Location = Point(290, 320);
			lblRegla6->Location = Point(290, 540);
			lblRegla7->Location = Point(290, 430);
			//
			lblCreditos->Location = Point(510, 350);
			//
			tbVidas->Location = Point(400, 450);
			tbTiempo->Location = Point(710, 450);
			cbDificultad->Location = Point(1000, 450);
			//
			srand(time(NULL));
			pausa = false;
			//
			BMjugador = gcnew Bitmap("sprites/jugador.png");
			BMdisparoJ = gcnew Bitmap("sprites/disparoJugador.png");
			BMmensajes = gcnew Bitmap("sprites/mensajes.png");
			///
			BMenemigo1 = gcnew Bitmap("sprites/enemigos-verde.png");
			BMenemigo2 = gcnew Bitmap("sprites/enemigos-rojo.png");
			BMdisparoE = gcnew Bitmap("sprites/disparoEnemigo.png");
			BMpolicia = gcnew Bitmap("sprites/policia.png");
			BMambulancia = gcnew Bitmap("sprites/ambulancia.png");
			BMcruzRoja = gcnew Bitmap("sprites/cruzRoja.png");
			///
			BMpistas = gcnew Bitmap("sprites/pistas.png");
			BMedificio = gcnew Bitmap("sprites/edificios.png");
			BMcasitas = gcnew Bitmap("sprites/casitas.png");
			BMservicios = gcnew Bitmap("sprites/servicios.png");
			BMmuni = gcnew Bitmap("sprites/municipalidad.png");
			BMmuni2 = gcnew Bitmap("sprites/municipalidad2.png");
			BMcesped = gcnew Bitmap("sprites/cesped.png");
			BMarbol = gcnew Bitmap("sprites/arbolito.png");
			BMmadera = gcnew Bitmap("sprites/madera.png");
			///
			BMbotonJugar = gcnew Bitmap("sprites/botonJugar.png");
			BMbotonJugarIluminado = gcnew Bitmap("sprites/botonJugarIluminado.png");
			BMbotonContinuar = gcnew Bitmap("sprites/botonContinuar.png");
			BMbotonContinuarIluminado = gcnew Bitmap("sprites/botonContinuarIluminado.png");
			BMpausa = gcnew Bitmap("sprites/pausa.png");
			BMlogo = gcnew Bitmap("sprites/LogoJuego.png");
			BMconfiguracion = gcnew Bitmap("sprites/Configuracion.png");
			BMinstrucciones = gcnew Bitmap("sprites/Instrucciones.png");
			BMreglas = gcnew Bitmap("sprites/Reglas.png");
			BMflechas = gcnew Bitmap("sprites/Flechas.png");
			BMteclaControl = gcnew Bitmap("sprites/TeclaControl.png");
			BMletraP = gcnew Bitmap("sprites/LetraP.png");
			BMfondo = gcnew Bitmap("sprites/Fondo.jpg");
			BMcantVidas = gcnew  Bitmap("sprites/cantVidas.png");
			BMtiempoMin = gcnew  Bitmap("sprites/tiempoMin.png"); 
			BMdificultad = gcnew Bitmap("sprites/dificultad.png");
			BMintroduccion = gcnew Bitmap("sprites/introduccion.png");
			BMnivel1 = gcnew Bitmap("sprites/nivel1.png");
			BMnivel2 = gcnew Bitmap("sprites/nivel2.png");
			BMganaste = gcnew Bitmap("sprites/Ganaste.png");
			BMfraseGanaste = gcnew Bitmap("sprites/fraseGanaste.png");
			BMcreditos = gcnew Bitmap("sprites/creditos.png");
			BMlogoUpc = gcnew Bitmap("sprites/logoUpc.png");
			BMbotonSalir = gcnew  Bitmap("sprites/botonSalir.png");
			BMbotonSalirIluminado = gcnew Bitmap("sprites/botonSalirIluminado.png");
			BMperdiste = gcnew Bitmap("sprites/perdiste.png");
			BMbotonInicio = gcnew Bitmap("sprites/irInicio.png");
			BMbotonInicioIluminado = gcnew Bitmap("sprites/irInicioIluminado.png");
			BMsimboloCruzRoja = gcnew Bitmap("sprites/simboloCruz.png");
			BMlaVictoria = gcnew Bitmap("sprites/laVictoria.png");
			BMvillaElSalvador = gcnew Bitmap("sprites/villaElSalvador.png");
			///
			musicaIntro = gcnew SoundPlayer();
			musicaIntro->SoundLocation = "sprites/musicaIntro.wav";
			musicaIntro->LoadAsync();
			musicaIntro->PlayLooping();
			musicaJuego = gcnew SoundPlayer();
			musicaJuego->SoundLocation = "sprites/musicaJuego.wav";
			musicaJuego->LoadAsync();
			gameover = gcnew SoundPlayer();
			gameover->SoundLocation = "sprites/gameover.wav";
			gameover->LoadAsync();
			///
			jugador = new Jugador(BMjugador, vidas);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::TextBox^ TbInfoJugador;
	private: System::Windows::Forms::TextBox^ TbPerdiste;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Bitmap^ BMjugador;
		Bitmap^ BMdisparoJ;
		Bitmap^ BMmensajes;
		///
		Bitmap^ BMenemigo1;
		Bitmap^ BMenemigo2;
		Bitmap^ BMdisparoE;
		Bitmap^ BMpolicia;
		Bitmap^ BMambulancia;
		Bitmap^ BMcruzRoja;
		///
		Bitmap^ BMpistas;
		Bitmap^ BMedificio;
		Bitmap^ BMcasitas;
		Bitmap^ BMservicios;
		Bitmap^ BMmuni;
		Bitmap^ BMmuni2;
		Bitmap^ BMcesped;
		Bitmap^ BMarbol;
		Bitmap^ BMmadera;
		///
		Bitmap^ BMbotonJugar;
		Bitmap^ BMbotonJugarIluminado;
		Bitmap^ BMbotonContinuar;
		Bitmap^ BMbotonContinuarIluminado;
		Bitmap^ BMpausa;
		Bitmap^ BMlogo;
		Bitmap^ BMconfiguracion;
		Bitmap^ BMinstrucciones;
		Bitmap^ BMreglas;
		Bitmap^ BMflechas;
		Bitmap^ BMteclaControl;
		Bitmap^ BMletraP;
		Bitmap^ BMfondo;
		Bitmap^ BMcantVidas;
		Bitmap^ BMtiempoMin;
		Bitmap^ BMdificultad;
		Bitmap^ BMintroduccion;
		Bitmap^ BMnivel1;
		Bitmap^ BMnivel2;
		Bitmap^ BMganaste;
		Bitmap^ BMfraseGanaste;
		Bitmap^ BMcreditos;
		Bitmap^ BMlogoUpc;
		Bitmap^ BMbotonSalir;
		Bitmap^ BMbotonSalirIluminado;
		Bitmap^ BMperdiste;
		Bitmap^ BMbotonInicio;
		Bitmap^ BMbotonInicioIluminado;
		Bitmap^ BMsimboloCruzRoja;
		Bitmap^ BMlaVictoria;
		Bitmap^ BMvillaElSalvador;
		//
		SoundPlayer^ musicaIntro;
		SoundPlayer^ musicaJuego;
		SoundPlayer^ gameover;
		//

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->TbInfoJugador = (gcnew System::Windows::Forms::TextBox());
			this->TbPerdiste = (gcnew System::Windows::Forms::TextBox());
			this->Tiempo = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblTeclas = (gcnew System::Windows::Forms::Label());
			this->lblTeclaControl = (gcnew System::Windows::Forms::Label());
			this->lblTeclaP = (gcnew System::Windows::Forms::Label());
			this->tbVidas = (gcnew System::Windows::Forms::TextBox());
			this->cbDificultad = (gcnew System::Windows::Forms::ComboBox());
			this->tbTiempo = (gcnew System::Windows::Forms::TextBox());
			this->lblIntro1 = (gcnew System::Windows::Forms::Label());
			this->lblRegla1 = (gcnew System::Windows::Forms::Label());
			this->lblIntro2 = (gcnew System::Windows::Forms::Label());
			this->lblRegla2 = (gcnew System::Windows::Forms::Label());
			this->lblRegla3 = (gcnew System::Windows::Forms::Label());
			this->lblRegla6 = (gcnew System::Windows::Forms::Label());
			this->lblRegla4 = (gcnew System::Windows::Forms::Label());
			this->lblRegla5 = (gcnew System::Windows::Forms::Label());
			this->lblCreditos = (gcnew System::Windows::Forms::Label());
			this->lblRegla7 = (gcnew System::Windows::Forms::Label());
			this->lblSinVidas = (gcnew System::Windows::Forms::Label());
			this->lblSinTiempo = (gcnew System::Windows::Forms::Label());
			this->lblPuntajeTotal = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// TbInfoJugador
			// 
			this->TbInfoJugador->BackColor = System::Drawing::Color::Silver;
			this->TbInfoJugador->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->TbInfoJugador->Enabled = false;
			this->TbInfoJugador->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB Demi", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbInfoJugador->ForeColor = System::Drawing::Color::Black;
			this->TbInfoJugador->Location = System::Drawing::Point(12, 12);
			this->TbInfoJugador->Name = L"TbInfoJugador";
			this->TbInfoJugador->Size = System::Drawing::Size(207, 26);
			this->TbInfoJugador->TabIndex = 0;
			this->TbInfoJugador->Visible = false;
			// 
			// TbPerdiste
			// 
			this->TbPerdiste->BackColor = System::Drawing::Color::Black;
			this->TbPerdiste->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->TbPerdiste->Enabled = false;
			this->TbPerdiste->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB Demi", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TbPerdiste->ForeColor = System::Drawing::Color::Red;
			this->TbPerdiste->Location = System::Drawing::Point(12, 44);
			this->TbPerdiste->Name = L"TbPerdiste";
			this->TbPerdiste->Size = System::Drawing::Size(207, 136);
			this->TbPerdiste->TabIndex = 1;
			this->TbPerdiste->Visible = false;
			// 
			// Tiempo
			// 
			this->Tiempo->Enabled = true;
			this->Tiempo->Interval = 1000;
			this->Tiempo->Tick += gcnew System::EventHandler(this, &MyForm::tiempo_Tick);
			// 
			// lblTeclas
			// 
			this->lblTeclas->AutoSize = true;
			this->lblTeclas->BackColor = System::Drawing::Color::Black;
			this->lblTeclas->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblTeclas->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTeclas->ForeColor = System::Drawing::SystemColors::Control;
			this->lblTeclas->Location = System::Drawing::Point(12, 195);
			this->lblTeclas->Name = L"lblTeclas";
			this->lblTeclas->Size = System::Drawing::Size(536, 120);
			this->lblTeclas->TabIndex = 2;
			this->lblTeclas->Text = L"Teclas direccionales para\r\ntrasladarse   por  el   mapa";
			this->lblTeclas->Visible = false;
			// 
			// lblTeclaControl
			// 
			this->lblTeclaControl->AutoSize = true;
			this->lblTeclaControl->BackColor = System::Drawing::Color::Black;
			this->lblTeclaControl->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblTeclaControl->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTeclaControl->ForeColor = System::Drawing::SystemColors::Control;
			this->lblTeclaControl->Location = System::Drawing::Point(11, 258);
			this->lblTeclaControl->Name = L"lblTeclaControl";
			this->lblTeclaControl->Size = System::Drawing::Size(389, 120);
			this->lblTeclaControl->TabIndex = 3;
			this->lblTeclaControl->Text = L"Tecla control para \r\nlanzar   mensajes";
			this->lblTeclaControl->Visible = false;
			// 
			// lblTeclaP
			// 
			this->lblTeclaP->AutoSize = true;
			this->lblTeclaP->BackColor = System::Drawing::Color::Black;
			this->lblTeclaP->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblTeclaP->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTeclaP->ForeColor = System::Drawing::SystemColors::Control;
			this->lblTeclaP->Location = System::Drawing::Point(11, 327);
			this->lblTeclaP->Name = L"lblTeclaP";
			this->lblTeclaP->Size = System::Drawing::Size(330, 120);
			this->lblTeclaP->TabIndex = 4;
			this->lblTeclaP->Text = L"Tecla    P    para \r\npausar el juego";
			this->lblTeclaP->Visible = false;
			// 
			// tbVidas
			// 
			this->tbVidas->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbVidas->Location = System::Drawing::Point(225, 12);
			this->tbVidas->Name = L"tbVidas";
			this->tbVidas->Size = System::Drawing::Size(100, 65);
			this->tbVidas->TabIndex = 5;
			this->tbVidas->Visible = false;
			// 
			// cbDificultad
			// 
			this->cbDificultad->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbDificultad->FormattingEnabled = true;
			this->cbDificultad->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Fácil", L"Difícil" });
			this->cbDificultad->Location = System::Drawing::Point(225, 113);
			this->cbDificultad->Name = L"cbDificultad";
			this->cbDificultad->Size = System::Drawing::Size(165, 67);
			this->cbDificultad->TabIndex = 7;
			this->cbDificultad->TabStop = false;
			this->cbDificultad->Visible = false;
			// 
			// tbTiempo
			// 
			this->tbTiempo->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbTiempo->Location = System::Drawing::Point(331, 12);
			this->tbTiempo->Name = L"tbTiempo";
			this->tbTiempo->Size = System::Drawing::Size(100, 65);
			this->tbTiempo->TabIndex = 8;
			this->tbTiempo->Visible = false;
			// 
			// lblIntro1
			// 
			this->lblIntro1->AutoSize = true;
			this->lblIntro1->BackColor = System::Drawing::Color::Black;
			this->lblIntro1->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblIntro1->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIntro1->ForeColor = System::Drawing::SystemColors::Control;
			this->lblIntro1->Location = System::Drawing::Point(437, 12);
			this->lblIntro1->Name = L"lblIntro1";
			this->lblIntro1->Size = System::Drawing::Size(1086, 180);
			this->lblIntro1->TabIndex = 9;
			this->lblIntro1->Text = L"En       Quarantine         Game        eres         un       ciudadano\r\nresponsa"
				L"ble  que  quiere  concientizar  a  las personas\r\nsobre      la      pandemia    "
				L"  del      COVID-19.\r\n";
			this->lblIntro1->Visible = false;
			// 
			// lblRegla1
			// 
			this->lblRegla1->AutoSize = true;
			this->lblRegla1->BackColor = System::Drawing::Color::Black;
			this->lblRegla1->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblRegla1->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRegla1->ForeColor = System::Drawing::SystemColors::Control;
			this->lblRegla1->Location = System::Drawing::Point(361, 378);
			this->lblRegla1->Name = L"lblRegla1";
			this->lblRegla1->Size = System::Drawing::Size(1212, 120);
			this->lblRegla1->TabIndex = 10;
			this->lblRegla1->Text = L"Existen     dos     tipos    de     ciudadanos    irresponsables,    los\r\nsaludab"
				L"les    y    los    asintomáticos.\r\n";
			this->lblRegla1->Visible = false;
			// 
			// lblIntro2
			// 
			this->lblIntro2->AutoSize = true;
			this->lblIntro2->BackColor = System::Drawing::Color::Black;
			this->lblIntro2->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblIntro2->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIntro2->ForeColor = System::Drawing::SystemColors::Control;
			this->lblIntro2->Location = System::Drawing::Point(554, 78);
			this->lblIntro2->Name = L"lblIntro2";
			this->lblIntro2->Size = System::Drawing::Size(1078, 300);
			this->lblIntro2->TabIndex = 11;
			this->lblIntro2->Text = resources->GetString(L"lblIntro2.Text");
			this->lblIntro2->Visible = false;
			// 
			// lblRegla2
			// 
			this->lblRegla2->AutoSize = true;
			this->lblRegla2->BackColor = System::Drawing::Color::Black;
			this->lblRegla2->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblRegla2->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRegla2->ForeColor = System::Drawing::SystemColors::Control;
			this->lblRegla2->Location = System::Drawing::Point(11, 447);
			this->lblRegla2->Name = L"lblRegla2";
			this->lblRegla2->Size = System::Drawing::Size(1209, 180);
			this->lblRegla2->TabIndex = 12;
			this->lblRegla2->Text = resources->GetString(L"lblRegla2.Text");
			this->lblRegla2->Visible = false;
			// 
			// lblRegla3
			// 
			this->lblRegla3->AutoSize = true;
			this->lblRegla3->BackColor = System::Drawing::Color::Black;
			this->lblRegla3->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblRegla3->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRegla3->ForeColor = System::Drawing::SystemColors::Control;
			this->lblRegla3->Location = System::Drawing::Point(11, 513);
			this->lblRegla3->Name = L"lblRegla3";
			this->lblRegla3->Size = System::Drawing::Size(1207, 180);
			this->lblRegla3->TabIndex = 13;
			this->lblRegla3->Text = L"Avanzas      al      siguiente      nivel      cuando     hayas    enviado\r\nmensa"
				L"jes  a  la  mitad  de  los  adversarios y  que estos hayan\r\nsido  capturados  en"
				L"  el  nivel  respectivo.";
			this->lblRegla3->Visible = false;
			// 
			// lblRegla6
			// 
			this->lblRegla6->AutoSize = true;
			this->lblRegla6->BackColor = System::Drawing::Color::Black;
			this->lblRegla6->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblRegla6->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRegla6->ForeColor = System::Drawing::SystemColors::Control;
			this->lblRegla6->Location = System::Drawing::Point(12, 783);
			this->lblRegla6->Name = L"lblRegla6";
			this->lblRegla6->Size = System::Drawing::Size(1210, 120);
			this->lblRegla6->TabIndex = 14;
			this->lblRegla6->Text = L"El   juego  termina   cuando   se  acaba  el   tiempo,  cuando  se \r\nsuperen todo"
				L"s los  niveles o cuando pierdas todas tus vidas.";
			this->lblRegla6->Visible = false;
			// 
			// lblRegla4
			// 
			this->lblRegla4->AutoSize = true;
			this->lblRegla4->BackColor = System::Drawing::Color::Black;
			this->lblRegla4->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblRegla4->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRegla4->ForeColor = System::Drawing::SystemColors::Control;
			this->lblRegla4->Location = System::Drawing::Point(11, 583);
			this->lblRegla4->Name = L"lblRegla4";
			this->lblRegla4->Size = System::Drawing::Size(1210, 120);
			this->lblRegla4->TabIndex = 15;
			this->lblRegla4->Text = L"Pierdes   una  vida   si  colisionas  con   un  adversario  ya   sea\r\nen   la   d"
				L"ificultad   fácil   o   difícil. ";
			this->lblRegla4->Visible = false;
			// 
			// lblRegla5
			// 
			this->lblRegla5->AutoSize = true;
			this->lblRegla5->BackColor = System::Drawing::Color::Black;
			this->lblRegla5->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblRegla5->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRegla5->ForeColor = System::Drawing::SystemColors::Control;
			this->lblRegla5->Location = System::Drawing::Point(11, 648);
			this->lblRegla5->Name = L"lblRegla5";
			this->lblRegla5->Size = System::Drawing::Size(1212, 120);
			this->lblRegla5->TabIndex = 16;
			this->lblRegla5->Text = L"Si   está  en  el  grado   de  dificultad   dificil,  pierdes  una  vida\r\nsi coli"
				L"sionas con un objeto lanzado por un adversario.";
			this->lblRegla5->Visible = false;
			// 
			// lblCreditos
			// 
			this->lblCreditos->AutoSize = true;
			this->lblCreditos->BackColor = System::Drawing::Color::Black;
			this->lblCreditos->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblCreditos->Font = (gcnew System::Drawing::Font(L"Impact", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCreditos->ForeColor = System::Drawing::SystemColors::Control;
			this->lblCreditos->Location = System::Drawing::Point(4, 551);
			this->lblCreditos->Name = L"lblCreditos";
			this->lblCreditos->Size = System::Drawing::Size(619, 410);
			this->lblCreditos->TabIndex = 17;
			this->lblCreditos->Text = resources->GetString(L"lblCreditos.Text");
			this->lblCreditos->Visible = false;
			// 
			// lblRegla7
			// 
			this->lblRegla7->AutoSize = true;
			this->lblRegla7->BackColor = System::Drawing::Color::Black;
			this->lblRegla7->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblRegla7->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRegla7->ForeColor = System::Drawing::SystemColors::Control;
			this->lblRegla7->Location = System::Drawing::Point(2, 850);
			this->lblRegla7->Name = L"lblRegla7";
			this->lblRegla7->Size = System::Drawing::Size(1210, 120);
			this->lblRegla7->TabIndex = 18;
			this->lblRegla7->Text = L"Obtienes  10  puntos  cada  vez  uno  de  tus mensaje  impacta \r\na  un  enemigo.";
			this->lblRegla7->Visible = false;
			// 
			// lblSinVidas
			// 
			this->lblSinVidas->AutoSize = true;
			this->lblSinVidas->BackColor = System::Drawing::Color::Black;
			this->lblSinVidas->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblSinVidas->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSinVidas->ForeColor = System::Drawing::SystemColors::Control;
			this->lblSinVidas->Location = System::Drawing::Point(2, 986);
			this->lblSinVidas->Name = L"lblSinVidas";
			this->lblSinVidas->Size = System::Drawing::Size(457, 60);
			this->lblSinVidas->TabIndex = 19;
			this->lblSinVidas->Text = L"Te quedaste sin vidas.";
			this->lblSinVidas->Visible = false;
			// 
			// lblSinTiempo
			// 
			this->lblSinTiempo->AutoSize = true;
			this->lblSinTiempo->BackColor = System::Drawing::Color::Black;
			this->lblSinTiempo->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblSinTiempo->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSinTiempo->ForeColor = System::Drawing::SystemColors::Control;
			this->lblSinTiempo->Location = System::Drawing::Point(465, 986);
			this->lblSinTiempo->Name = L"lblSinTiempo";
			this->lblSinTiempo->Size = System::Drawing::Size(456, 60);
			this->lblSinTiempo->TabIndex = 20;
			this->lblSinTiempo->Text = L"Se te acabó el tiempo.";
			this->lblSinTiempo->Visible = false;
			// 
			// lblPuntajeTotal
			// 
			this->lblPuntajeTotal->AutoSize = true;
			this->lblPuntajeTotal->BackColor = System::Drawing::Color::Black;
			this->lblPuntajeTotal->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblPuntajeTotal->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntajeTotal->ForeColor = System::Drawing::SystemColors::Control;
			this->lblPuntajeTotal->Location = System::Drawing::Point(938, 986);
			this->lblPuntajeTotal->Name = L"lblPuntajeTotal";
			this->lblPuntajeTotal->Size = System::Drawing::Size(286, 60);
			this->lblPuntajeTotal->TabIndex = 21;
			this->lblPuntajeTotal->Text = L"Puntaje total:";
			this->lblPuntajeTotal->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1232, 1055);
			this->Controls->Add(this->lblPuntajeTotal);
			this->Controls->Add(this->lblSinTiempo);
			this->Controls->Add(this->lblSinVidas);
			this->Controls->Add(this->lblRegla7);
			this->Controls->Add(this->lblCreditos);
			this->Controls->Add(this->lblRegla5);
			this->Controls->Add(this->lblRegla4);
			this->Controls->Add(this->lblRegla6);
			this->Controls->Add(this->lblRegla3);
			this->Controls->Add(this->lblRegla2);
			this->Controls->Add(this->lblIntro2);
			this->Controls->Add(this->lblRegla1);
			this->Controls->Add(this->lblIntro1);
			this->Controls->Add(this->tbTiempo);
			this->Controls->Add(this->cbDificultad);
			this->Controls->Add(this->tbVidas);
			this->Controls->Add(this->lblTeclaP);
			this->Controls->Add(this->lblTeclaControl);
			this->Controls->Add(this->lblTeclas);
			this->Controls->Add(this->TbPerdiste);
			this->Controls->Add(this->TbInfoJugador);
			this->HelpButton = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::PresionaTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::TeclaArriba);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Click_Mouse);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Mouse_Encima);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void MenuInicio(BufferedGraphics^ buffer) {
			Rectangle Fondo = Rectangle(0, 0, BMfondo->Width, BMfondo->Height);
			Rectangle zoom = Rectangle(0, 0, BMfondo->Width * 1.9, BMfondo->Height * 2.0);
			buffer->Graphics->DrawImage(BMfondo, zoom, Fondo, GraphicsUnit::Pixel);
			//
			if (etapaMenu == 1) {  //Logo
				Rectangle Logo = Rectangle(0, 0, BMlogo->Width, BMlogo->Height);
				buffer->Graphics->DrawImage(BMlogo, 170, 120, Logo, GraphicsUnit::Pixel);
			}
			else if (etapaMenu == 2) { //Introduccion
				lblIntro1->Visible = true;
				lblIntro2->Visible = true;
				Rectangle Introduccion = Rectangle(0, 0, BMintroduccion->Width, BMintroduccion->Height);
				buffer->Graphics->DrawImage(BMintroduccion, 320, 30, Introduccion, GraphicsUnit::Pixel);
			}
			else if (etapaMenu == 3) { //Instrucciones
				lblIntro1->Visible = false;
				lblIntro2->Visible = false;
				Rectangle Instrucciones = Rectangle(0, 0, BMinstrucciones->Width, BMinstrucciones->Height);
				Rectangle Flechas = Rectangle(0, 0, BMflechas->Width, BMflechas->Height);
				Rectangle zoomFlechas = Rectangle(450, 240, BMflechas->Width * 1.3, BMflechas->Height * 1.3);
				Rectangle TeclaControl = Rectangle(0, 0, BMteclaControl->Width, BMteclaControl->Height);
				Rectangle zoomControl = Rectangle(505, 400, BMteclaControl->Width * 1.3, BMteclaControl->Height * 1.3);
				Rectangle LetraP = Rectangle(0, 0, BMletraP->Width, BMletraP->Height);
				Rectangle zoomLetraP = Rectangle(505, 520, BMletraP->Width * 1.3, BMletraP->Height * 1.3);
				buffer->Graphics->DrawImage(BMinstrucciones, 300, 70, Instrucciones, GraphicsUnit::Pixel);
				buffer->Graphics->DrawImage(BMflechas, zoomFlechas, Flechas, GraphicsUnit::Pixel);
				buffer->Graphics->DrawImage(BMteclaControl, zoomControl, TeclaControl, GraphicsUnit::Pixel);
				buffer->Graphics->DrawImage(BMletraP, zoomLetraP, LetraP, GraphicsUnit::Pixel);
		
				lblTeclas->Visible = true;
				lblTeclaControl->Visible = true;
				lblTeclaP->Visible = true;
			}
			else if (etapaMenu == 4 || etapaMenu == 5) { //Reglas
				lblTeclas->Visible = false;
				lblTeclaControl->Visible = false;
				lblTeclaP->Visible = false;
				//
				if (etapaMenu == 4) {
					lblRegla1->Visible = true;
					lblRegla2->Visible = true;
					lblRegla3->Visible = true;
				}
				else {
					lblRegla1->Visible = false;
					lblRegla2->Visible = false;
					lblRegla3->Visible = false;
					lblRegla4->Visible = true;
					lblRegla5->Visible = true;
					lblRegla6->Visible = true;
					lblRegla7->Visible = true;
				}
				//
				Rectangle Reglas = Rectangle(0, 0, BMreglas->Width, BMreglas->Height);
				buffer->Graphics->DrawImage(BMreglas, 550, 70, Reglas, GraphicsUnit::Pixel);
			}
			else if (etapaMenu == 6){ //Configuracion
				lblRegla4->Visible = false;
				lblRegla5->Visible = false;
				lblRegla6->Visible = false;
				lblRegla7->Visible = false;

				Rectangle Configuracion = Rectangle(0, 0, BMconfiguracion->Width, BMconfiguracion->Height);
				Rectangle CantVidas = Rectangle(0, 0, BMcantVidas->Width, BMcantVidas->Height);
				Rectangle TiempoMin = Rectangle(0, 0, BMtiempoMin->Width, BMtiempoMin->Height);
				Rectangle Dificultad = Rectangle(0, 0, BMdificultad->Width, BMdificultad->Height);
				buffer->Graphics->DrawImage(BMconfiguracion, 290, 30, Configuracion, GraphicsUnit::Pixel);
				buffer->Graphics->DrawImage(BMcantVidas, 340, 300, CantVidas, GraphicsUnit::Pixel);
				buffer->Graphics->DrawImage(BMtiempoMin, 620, 300, TiempoMin, GraphicsUnit::Pixel);
				buffer->Graphics->DrawImage(BMdificultad, 920, 300, Dificultad, GraphicsUnit::Pixel);
				tbVidas->Visible = true;
				cbDificultad->Visible = true;
				tbTiempo->Visible = true;
			}
			else if (etapaMenu == 7) {
				tbVidas->Visible = false;
				cbDificultad->Visible = false;
				tbTiempo->Visible = false;
				tbVidas->Enabled = false;
				cbDificultad->Enabled = false;
				tbTiempo->Enabled = false;

				Rectangle Nivel1 = Rectangle(0, 0, BMnivel1->Width, BMnivel1->Height);
				buffer->Graphics->DrawImage(BMnivel1, 320, 130, Nivel1, GraphicsUnit::Pixel);
				Rectangle laVictoria = Rectangle(0, 0, BMlaVictoria->Width, BMlaVictoria->Height);
				buffer->Graphics->DrawImage(BMlaVictoria, 390, 430, laVictoria, GraphicsUnit::Pixel);
			}
			//
			if (etapaMenu >= 1 && etapaMenu <= 6) {
				if (iluminaContinuar) {
					Rectangle BotonContinuarIluminado = Rectangle(0, 0, BMbotonContinuarIluminado->Width, BMbotonContinuarIluminado->Height);
					buffer->Graphics->DrawImage(BMbotonContinuarIluminado, 673, 648, BotonContinuarIluminado, GraphicsUnit::Pixel);
				}
				else {
					Rectangle BotonContinuar = Rectangle(0, 0, BMbotonContinuar->Width, BMbotonContinuar->Height);
					buffer->Graphics->DrawImage(BMbotonContinuar, 675, 650, BotonContinuar, GraphicsUnit::Pixel);
				}
			}
			else {
				if (iluminaContinuar) {
					Rectangle BotonJugarIluminado = Rectangle(0, 0, BMbotonJugarIluminado->Width, BMbotonJugarIluminado->Height);
					buffer->Graphics->DrawImage(BMbotonJugarIluminado, 673, 598, BotonJugarIluminado, GraphicsUnit::Pixel);
				}
				else {
					Rectangle BotonJugar = Rectangle(0, 0, BMbotonJugar->Width, BMbotonJugar->Height);
					buffer->Graphics->DrawImage(BMbotonJugar, 675, 600, BotonJugar, GraphicsUnit::Pixel);
				}
			}
		}
		void IntroNivel2(BufferedGraphics^ buffer) {
			Rectangle Fondo = Rectangle(0, 0, BMfondo->Width, BMfondo->Height);
			Rectangle zoom = Rectangle(0, 0, BMfondo->Width * 1.9, BMfondo->Height * 2.0);
			Rectangle BotonJugar = Rectangle(0, 0, 190, 93);
			Rectangle Nivel2 = Rectangle(0, 0, BMnivel2->Width, BMnivel2->Height);
			Rectangle VillaElSalvador = Rectangle(0, 0, BMvillaElSalvador->Width, BMvillaElSalvador->Height);
			buffer->Graphics->DrawImage(BMfondo, zoom, Fondo, GraphicsUnit::Pixel);
			buffer->Graphics->DrawImage(BMnivel2, 300, 80, Nivel2, GraphicsUnit::Pixel);
			buffer->Graphics->DrawImage(BMvillaElSalvador, 485, 360, VillaElSalvador, GraphicsUnit::Pixel);

			if (iluminaContinuar) {
				Rectangle BotonJugarIluminado = Rectangle(0, 0, BMbotonJugarIluminado->Width, BMbotonJugarIluminado->Height);
				buffer->Graphics->DrawImage(BMbotonJugarIluminado, 673, 638, BotonJugarIluminado, GraphicsUnit::Pixel);
			}
			else {
				Rectangle BotonJugar = Rectangle(0, 0, BMbotonJugar->Width, BMbotonJugar->Height);
				buffer->Graphics->DrawImage(BMbotonJugar, 675, 640, BotonJugar, GraphicsUnit::Pixel);
			}
		}
		bool reproducir = true;
		bool iluminarSalir = false, iluminarInicio = false;
		void Perdiste(BufferedGraphics^ buffer) {
			if (reproducir) {
				gameover->Play();
				reproducir = !reproducir;
			}

			TbInfoJugador->Visible = false;

			if (jugador->getVidas() == 0) {
				lblSinVidas->Visible = true;
			}
			else {
				lblSinTiempo->Visible = true;
			}
				
			Rectangle Fondo = Rectangle(0, 0, BMfondo->Width, BMfondo->Height);
			Rectangle zoom = Rectangle(0, 0, BMfondo->Width * 1.9, BMfondo->Height * 2.0);
			buffer->Graphics->DrawImage(BMfondo, zoom, Fondo, GraphicsUnit::Pixel);
			
			Rectangle perdiste = Rectangle(0, 0, BMperdiste->Width, BMperdiste->Height);
			buffer->Graphics->DrawImage(BMperdiste, 420, 230, perdiste, GraphicsUnit::Pixel);

			if (iluminarSalir) {
				Rectangle BotonSalirIluminado = Rectangle(0, 0, BMbotonSalirIluminado->Width, BMbotonSalirIluminado->Height);
				buffer->Graphics->DrawImage(BMbotonSalirIluminado, 823, 548, BotonSalirIluminado, GraphicsUnit::Pixel);
			}
			else {
				Rectangle BotonSalir = Rectangle(0, 0, BMbotonSalir->Width, BMbotonSalir->Height);
				buffer->Graphics->DrawImage(BMbotonSalir, 825, 550, BotonSalir, GraphicsUnit::Pixel);
			}

			if (iluminarInicio) {
				Rectangle BotonInicioIluminado = Rectangle(0, 0, BMbotonInicioIluminado->Width, BMbotonInicioIluminado->Height);
				buffer->Graphics->DrawImage(BMbotonInicioIluminado, 523, 548, BotonInicioIluminado, GraphicsUnit::Pixel);
			}
			else {
				Rectangle BotonInicio = Rectangle(0, 0, BMbotonInicio->Width, BMbotonInicio->Height);
				buffer->Graphics->DrawImage(BMbotonInicio, 525, 550, BotonInicio, GraphicsUnit::Pixel);
			}
			//TbPerdiste->Text = "Perdiste :(";
			//TbPerdiste->Visible = true;
		}
		void Ganaste(BufferedGraphics^ buffer) {
			TbInfoJugador->Visible = false;
			lblPuntajeTotal->Visible = true;
			lblPuntajeTotal->Text = "Puntaje Total: " + jugador->getPuntaje();
			Rectangle Fondo = Rectangle(0, 0, BMfondo->Width, BMfondo->Height);
			Rectangle zoom = Rectangle(0, 0, BMfondo->Width * 1.9, BMfondo->Height * 2.0);
			Rectangle Ganaste = Rectangle(0, 0, BMganaste->Width, BMganaste->Height);
			Rectangle fraseGanaste = Rectangle(0, 0, BMfraseGanaste->Width, BMfraseGanaste->Height);

			buffer->Graphics->DrawImage(BMfondo, zoom, Fondo, GraphicsUnit::Pixel);
			buffer->Graphics->DrawImage(BMganaste, 360, 50, Ganaste, GraphicsUnit::Pixel);
			buffer->Graphics->DrawImage(BMfraseGanaste, 175, 290, fraseGanaste, GraphicsUnit::Pixel);

			if (iluminaContinuar) {
				Rectangle BotonContinuarIluminado = Rectangle(0, 0, BMbotonContinuarIluminado->Width, BMbotonContinuarIluminado->Height);
				buffer->Graphics->DrawImage(BMbotonContinuarIluminado, 673, 648, BotonContinuarIluminado, GraphicsUnit::Pixel);
			}
			else {
				Rectangle BotonContinuar = Rectangle(0, 0, BMbotonContinuar->Width, BMbotonContinuar->Height);
				buffer->Graphics->DrawImage(BMbotonContinuar, 675, 650, BotonContinuar, GraphicsUnit::Pixel);
			}
		}
		void BannerPausa(BufferedGraphics^ buffer) {
			Rectangle zoom = Rectangle(300, 150, BMpausa->Width * 1.5, BMpausa->Height * 1.5);
			Rectangle Pausa = Rectangle(0, 0, BMpausa->Width, BMpausa->Height);
			buffer->Graphics->DrawImage(BMpausa, zoom, Pausa, GraphicsUnit::Pixel);
			timer1->Stop();
		}
		void Creditos(BufferedGraphics^ buffer) {
			lblCreditos->Visible = true;
			lblPuntajeTotal->Visible = false;

			Rectangle Fondo = Rectangle(0, 0, BMfondo->Width, BMfondo->Height);
			Rectangle zoom = Rectangle(0, 0, BMfondo->Width * 1.9, BMfondo->Height * 2.0);
			Rectangle creditos = Rectangle(0, 0, BMcreditos->Width, BMcreditos->Height);
			Rectangle zoomCreditos = Rectangle(595, 10, BMcreditos->Width * 0.6, BMcreditos->Height * 0.6);
			Rectangle logoUpc = Rectangle(0, 0, BMlogoUpc->Width, BMlogoUpc->Height);

			buffer->Graphics->DrawImage(BMfondo, zoom, Fondo, GraphicsUnit::Pixel);
			buffer->Graphics->DrawImage(BMcreditos, zoomCreditos, creditos, GraphicsUnit::Pixel);
			buffer->Graphics->DrawImage(BMlogoUpc, 650, 130, logoUpc, GraphicsUnit::Pixel);

			if (iluminarSalir) {
				Rectangle BotonSalirIluminado = Rectangle(0, 0, BMbotonSalirIluminado->Width, BMbotonSalirIluminado->Height);
				buffer->Graphics->DrawImage(BMbotonSalirIluminado, 823, 708, BotonSalirIluminado, GraphicsUnit::Pixel);
			}
			else {
				Rectangle BotonSalir = Rectangle(0, 0, BMbotonSalir->Width, BMbotonSalir->Height);
				buffer->Graphics->DrawImage(BMbotonSalir, 825, 710, BotonSalir, GraphicsUnit::Pixel);
			}

			if (iluminarInicio) {
				Rectangle BotonInicioIluminado = Rectangle(0, 0, BMbotonInicioIluminado->Width, BMbotonInicioIluminado->Height);
				buffer->Graphics->DrawImage(BMbotonInicioIluminado, 523, 708, BotonInicioIluminado, GraphicsUnit::Pixel);
			}
			else {
				Rectangle BotonInicio = Rectangle(0, 0, BMbotonInicio->Width, BMbotonInicio->Height);
				buffer->Graphics->DrawImage(BMbotonInicio, 525, 710, BotonInicio, GraphicsUnit::Pixel);
			}
		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ canvas = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(canvas, this->ClientRectangle);

		if (etapa == 1) {
			Tiempo->Stop();
			MenuInicio(buffer);
			jugador->setNivel(1);
		}
		else if (etapa == 2 && jugador->getVidas()!=0 && Tminutos != Tmax) { //nivel1
			Tiempo->Start();

			nivel1->Jugar(buffer, jugador, BMjugador, BMdisparoJ, BMmensajes, BMenemigo1, BMdisparoE, BMpolicia, BMambulancia, BMcruzRoja,
				BMsimboloCruzRoja, BMpistas, BMedificio, BMcasitas, BMservicios, BMmuni, BMcesped, BMarbol, BMmadera, dificil);

			if (nivel1->getSiguienteNivel()) { etapa = 3; }
		}
		else if (etapa == 3) {
			Tiempo->Stop();
			TbInfoJugador->Visible = false;
			IntroNivel2(buffer);
			jugador->setNivel(2);
			jugador->setX(720);
			jugador->setY(355);
		}
		else if (etapa == 4 && !nivel2->getGano() && jugador->getVidas() != 0 && Tminutos != Tmax) { //nivel2
			Tiempo->Start();

			nivel2->Jugar(buffer, jugador, BMjugador, BMdisparoJ, BMmensajes, BMenemigo2, BMdisparoE, BMpolicia, BMambulancia, BMcruzRoja,
				BMsimboloCruzRoja, BMpistas, BMedificio, BMcasitas, BMservicios, BMmuni2, BMcesped, BMarbol, BMmadera, dificil);
		}
		else if (etapa == 5) {
			Creditos(buffer);
		}

		if (etapa == 2 || etapa == 4) {
			if (!nivel2->getGano() && jugador->getVidas() != 0 && Tminutos != Tmax) {
				TbInfoJugador->Visible = true;
				TbInfoJugador->Text = "Vidas restantes: " + jugador->getVidas() + "   -  Puntaje: " + jugador->getPuntaje() + "   -  Tiempo: " + Tminutos + ":" + Tsegundos;
			}
			if (jugador->getVidas() == 0 || Tminutos == Tmax) { Perdiste(buffer); }
			if (nivel2->getGano()) { Ganaste(buffer); }
			if (pausa) { BannerPausa(buffer); }
		}

		buffer->Render(canvas);
		delete buffer;
		delete espacio;
		delete canvas;
	}
	private: System::Void PresionaTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (etapa == 2 || etapa == 4) {
			if (e->KeyCode == Keys::Up) {
				jugador->setDirecciones(Direcciones::arriba);
			}
			if (e->KeyCode == Keys::Down) {
				jugador->setDirecciones(Direcciones::abajo);
			}
			if (e->KeyCode == Keys::Left) {
				jugador->setDirecciones(Direcciones::izquierda);
			}
			if (e->KeyCode == Keys::Right) {
				jugador->setDirecciones(Direcciones::derecha);
			}
			if (e->KeyCode == Keys::ControlKey) {
				jugador->agregarDisparo();
			}
			if (e->KeyCode == Keys::P && !nivel2->getGano() && jugador->getVidas() != 0 && Tminutos != Tmax) {
				pausa = !pausa;
				if (!pausa) { timer1->Start(); }
			}
		}
	}
	private: System::Void TeclaArriba(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if(e->KeyCode == Keys::Up || e->KeyCode == Keys::Down || e->KeyCode == Keys::Left || e->KeyCode == Keys::Right) jugador->setDirecciones(Direcciones::ninguna);
	}
	private: System::Void Click_Mouse(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (etapa == 1) {
			if ((e->X >= 675 && e->X <= 675 + BMbotonContinuar->Width && e->Y >= 650 && e->Y <= 650 + BMbotonContinuar->Height && etapa != 7)
				|| (e->X >= 675 && e->X <= 675 + BMbotonContinuar->Width && e->Y >= 600 && e->Y <= 600 + BMbotonContinuar->Height && etapaMenu == 7)) {
				if (etapaMenu == 6) {
					if (tbVidas->Text != "" && tbTiempo->Text != "" && cbDificultad->Text != "") {
						if (Convert::ToInt32(tbTiempo->Text) > 0 && Convert::ToInt32(tbVidas->Text) > 0 && (cbDificultad->Text == "Difícil" || cbDificultad->Text == "Fácil")) {
							jugador->setVidas(Convert::ToInt32(tbVidas->Text));
							Tsegundos = Tminutos = 0;
							Tmax = Convert::ToInt32(tbTiempo->Text);
							if (cbDificultad->Text == "Difícil") { dificil = true; }
							jugador->setX(720);
							jugador->setY(355);
							etapaMenu++;
						}
						else {
							MessageBox::Show("Valores incorrectos.");
						}
					}
					else {
						MessageBox::Show("Complete todos los campos para continuar.");
					}
				}
				else {
					etapaMenu++;
				}
				if (etapaMenu == 8) {
					musicaJuego->PlayLooping();
					nivel1 = new Nivel1(BMjugador, BMenemigo1, BMpolicia, BMpistas, BMedificio,
						BMcasitas, BMservicios, BMmuni, BMcesped, BMarbol, BMmadera);
					nivel2 = new Nivel2(BMjugador, BMenemigo2, BMpolicia, BMpistas, BMedificio,
						BMcasitas, BMservicios, BMmuni2, BMcesped, BMarbol, BMmadera);
					etapa = 2;
				}
			}
		}
		else if (etapa == 3) {
			if (e->X >= 675 && e->X <= 675 + BMbotonContinuar->Width && e->Y >= 640 && e->Y <= 640 + BMbotonContinuar->Height){
				etapa = 4;
			}
		}
		else if ((etapa == 2 || etapa == 4) && (jugador->getVidas() == 0 || Tminutos == Tmax)) {
			if (e->X >= 825 && e->X <= 825 + BMbotonContinuar->Width && e->Y >= 550 && e->Y <= 550 + BMbotonContinuar->Height) {
				etapa = 5;
				lblSinTiempo->Visible = false;
				lblSinVidas->Visible = false;
			}

			if (e->X >= 525 && e->X <= 525 + BMbotonContinuar->Width && e->Y >= 550 && e->Y <= 550 + BMbotonContinuar->Height) {
				etapa = 1;
				etapaMenu = 1;
				reproducir = true;
				jugador->setPuntaje(0);
				musicaIntro->PlayLooping();
				tbVidas->Enabled = true;
				tbVidas->Clear();
				tbTiempo->Enabled = true;
				tbTiempo->Clear();
				cbDificultad->Enabled = true;
				cbDificultad->Text = "";
				lblSinTiempo->Visible = false;
				lblSinVidas->Visible = false;
				dificil = false;
			}
		}
		else if (etapa == 4 && nivel2->getGano()) {
			if (e->X >= 675 && e->X <= 675 + BMbotonContinuar->Width && e->Y >= 650 && e->Y <= 650 + BMbotonContinuar->Height) {
				etapa = 5;
			}
		}
		else if (etapa == 5) {
			if (e->X >= 825 && e->X <= 825 + BMbotonContinuar->Width && e->Y >= 710 && e->Y <= 710 + BMbotonContinuar->Height) {
				Form::Close();
			}

			if (e->X >= 525 && e->X <= 525 + BMbotonContinuar->Width && e->Y >= 710 && e->Y <= 710 + BMbotonContinuar->Height) {
				etapa = 1;
				etapaMenu = 1;
				reproducir = true;
				jugador->setPuntaje(0);
				musicaIntro->PlayLooping();
				lblCreditos->Visible = false;
				tbVidas->Enabled = true;
				tbVidas->Clear();
				tbTiempo->Enabled = true;
				tbTiempo->Clear();
				cbDificultad->Enabled = true;
				cbDificultad->Text = "";
				dificil = false;
			}
		}
	}
	private: System::Void tiempo_Tick(System::Object^ sender, System::EventArgs^ e) {
		Tsegundos++;
		if (Tsegundos == 60) {
			Tminutos++;
			Tsegundos = 0;
		}
	}
	private: System::Void Mouse_Encima(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (etapa == 1 || etapa == 3) {
			if ((e->X >= 675 && e->X <= 675 + BMbotonContinuar->Width && e->Y >= 650 && e->Y <= 650 + BMbotonContinuar->Height && etapaMenu != 7)
				|| (e->X >= 675 && e->X <= 675 + BMbotonContinuar->Width && e->Y >= 600 && e->Y <= 600 + BMbotonContinuar->Height && etapaMenu == 7 && etapa!=3)
				|| (e->X >= 675 && e->X <= 675 + BMbotonContinuar->Width && e->Y >= 640 && e->Y <= 640 + BMbotonContinuar->Height && etapa == 3)) {
				iluminaContinuar = true;
			}
			else {
				iluminaContinuar = false;
			}
		}
		else if ((etapa == 2 || etapa == 4) && (jugador->getVidas() == 0 || Tminutos == Tmax)) {
			if (e->X >= 825 && e->X <= 825 + BMbotonContinuar->Width && e->Y >= 550 && e->Y <= 550 + BMbotonContinuar->Height) {
				iluminarSalir = true;
			}
			else {
				iluminarSalir = false;
			}

			if (e->X >= 525 && e->X <= 525 + BMbotonContinuar->Width && e->Y >= 550 && e->Y <= 550 + BMbotonContinuar->Height) {
				iluminarInicio = true;
			}
			else {
				iluminarInicio = false;
			}
		}
		else if (etapa == 4 && nivel2->getGano()) {
			if (e->X >= 675 && e->X <= 675 + BMbotonContinuar->Width && e->Y >= 650 && e->Y <= 650 + BMbotonContinuar->Height) {
				iluminaContinuar = true;
			}
			else {
				iluminaContinuar = false;
			}
		}
		else if (etapa == 5) {
			if (e->X >= 825 && e->X <= 825 + BMbotonContinuar->Width && e->Y >= 710 && e->Y <= 710 + BMbotonContinuar->Height) {
				iluminarSalir = true;
			}
			else {
				iluminarSalir = false;
			}

			if (e->X >= 525 && e->X <= 525 + BMbotonContinuar->Width && e->Y >= 710 && e->Y <= 710 + BMbotonContinuar->Height) {
				iluminarInicio = true;
			}
			else {
				iluminarInicio = false;
			}
		}
	}	
};
}