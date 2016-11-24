#pragma once

#include "Creep.h"

#define DISTANCIA 50.f
#define TEMPO_ATIVAR 1.f
#define TEMPO_RESFRIAMENTO 5.f


class Condemn {
	private:
		float m_resfriamento, m_tempoAtivar;
		bool m_ativar;

	public:
		Creep* AplicarDano(ofVec2f player, Creep *listaCreeps, int totalCreeps);
		void Iniciar();
		bool GetAtivado();
		void SetAtivar(bool set);
};