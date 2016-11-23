#pragma once
#include "Objeto.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "Caminho.h"

#define VELOCIDADE 50.f

class Creep : public Objeto{
	private:
		int m_proximoPonto, m_id;
		bool m_vivo;
		float m_vida;
		Caminho* m_rota;
		ofVec2f m_arrodear, m_direcao;

	public:
		void Iniciar(Caminho* rota, int id);
		void Atualizar(float angle, ofVec2f player);
		void Draw(ofVec2f mundo);
		bool GetVivo();
		void SetVivo(bool vivo);
		void LevarDano(float dano);
		bool SeguirJogador(ofVec2f player);
		int GetId();
		~Creep() {};
};