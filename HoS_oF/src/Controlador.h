#pragma once
#include "Creep.h"
#include "Jogador.h"
#include "ofPath.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

class Controlador {
	private:
		Jogador* m_player;
		int m_totalCreep;
		float m_tempoRespaw, m_contTempoRespaw;
		ofVec2f* m_mundo;
		Creep *m_listaCreeps;
		Caminho m_rota;
		bool m_desenharRota;

	public:
		void Iniciar(ofVec2f* mundo, Jogador* player);
		void Atualizar();
		void Draw();
		void DrawRota();
		Creep* OrganizarListaCreep();
		void SetDesenharRota(bool mudar);
		bool GetDesenharRota();
		int MouseClicouEm();
		void AumentarVelocidadeRespaw();
		void DiminuirVelocidadeRespaw();
		ofVec2f GetPosicaoCreep(int id);

};