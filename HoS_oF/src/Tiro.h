#pragma once
#include "Objeto.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#define VELOCIDADE_PROJETIL 200.f

class Tiro : public Objeto{
	private:
		ofVec2f m_posicaoProjetil, m_posicaoAlvo;
		ofVec2f* m_playerPosicao, *m_mundo;
		int m_projetil, m_idCreep;
		float m_tempoDisparar;
		bool m_atirou, m_atingiu;

	public:
		void Iniciar(ofVec2f* playerPosicao, ofVec2f* mundo);
		void Atualizar();
		void Draw(ofVec2f mundo);
		void AtirarEm(ofVec2f alvo, int idCreep);
		void SetAtirou(bool set);
		void SetAtingiu(bool set);
		bool GetAtirou();
		bool GetAtingiu();
		int GetIDCreep();
};