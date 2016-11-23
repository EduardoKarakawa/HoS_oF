#include "Objeto.h"

void Objeto::SetPosicao(ofVec2f posicao) {
	m_posicao = posicao;
}

ofVec2f Objeto::GetPosicao() {
	return m_posicao;
}