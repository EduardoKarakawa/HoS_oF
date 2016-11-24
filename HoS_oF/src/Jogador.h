#pragma once
#include "Objeto.h"
#include "Creep.h"
#include "Condemn.h"
#include "Tiro.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"

#define VELOCIDADE 900.f

class Jogador : public Objeto {
	private:
		Tiro m_listaTiros;
		int m_tirou, m_IDCreep;
		ofVec2f m_proxPosicao, m_posicaoAlvo;
		float m_danoPadrao;


	public:
		Condemn m_condemnAtaque;
		void Iniciar(ofVec2f posicao, ofVec2f* mundo);
		void SetProxPosicao(ofVec2f proxPosicao);
		void Atualizar(ofVec2f mundo, ofVec2f posicaoCreep);
		void Draw(ofVec2f mundo);
		float GetDanoPadrao();
		void SetAtaqueEsseCreep(int idCreep);
		void Atacar();
		int GetCreepID();
		bool GetTiroAtingiu();
		void SetTiroAtingiu(bool set);
};