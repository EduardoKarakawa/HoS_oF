#include "Condemn.h"

void Condemn::Iniciar() {
	m_tempoAtivar = TEMPO_ATIVAR;
	m_resfriamento = 0;
	m_ativar = false;
}

bool Condemn::GetAtivado(){
	return m_ativar;
}

void Condemn::SetAtivar(bool set){
	m_ativar = set;
	if (m_ativar)
		m_tempoAtivar = TEMPO_ATIVAR;
}


Creep * Condemn::AplicarDano(ofVec2f player, Creep *listCreeps, int totalCreeps){
	if ((m_tempoAtivar <= 0) && (m_resfriamento <= 0) && m_ativar) {
		for (int i = 0; i < totalCreeps; i++) {
			if (player.distance(listCreeps[i].GetPosicao()) <= 300.f) {

				listCreeps[i].SetPosicao(listCreeps[i].GetPosicao() + ofVec2f(player - listCreeps[i].GetPosicao()).normalized() * DISTANCIA);
			}
			m_resfriamento = TEMPO_RESFRIAMENTO;
			m_tempoAtivar = TEMPO_ATIVAR;
			m_ativar = false;

		}
	}
	else {
		m_tempoAtivar -= ofGetLastFrameTime();
		m_resfriamento -= ofGetLastFrameTime();
		
	}


	return listCreeps;
}


