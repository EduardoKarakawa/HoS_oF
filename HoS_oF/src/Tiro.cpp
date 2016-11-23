#include "Tiro.h"

/*---------------------------------------------------------------------------------------------
	Inicia os parametros padroes do tiro
---------------------------------------------------------------------------------------------*/
void Tiro::Iniciar(ofVec2f * playerPosicao, ofVec2f* mundo){
	m_mundo = mundo;
	m_playerPosicao = playerPosicao;
	m_posicao = *m_playerPosicao;
	m_atirou = false;
	m_atingiu = false;

}



/*---------------------------------------------------------------------------------------------
	Atualiza a posicao do tiro, verifica se ele atingio o alvo e aplica o dano
---------------------------------------------------------------------------------------------*/
void Tiro::Atualizar(){

	ofVec2f tmp_alvo = m_posicaoAlvo;
	if (m_atirou) {

		if (m_posicao.distance(tmp_alvo) >= 10.f) {

			/* Atualiza a posicao do tiro */
			m_posicao += (tmp_alvo - m_posicao).normalized() * VELOCIDADE_PROJETIL * ofGetLastFrameTime();


		}
		else if (m_posicao.distance(tmp_alvo) < 11.f) {
		
			/* Reseta o tiro e aplica dano no alvo*/
			m_atirou = false;
			m_atingiu = true;
			m_posicao = *m_playerPosicao;

		}
	}
	else {
		m_posicao = *m_playerPosicao;
	}
	
}



/*---------------------------------------------------------------------------------------------
	Desenha o tiro
---------------------------------------------------------------------------------------------*/
void Tiro::Draw(ofVec2f mundo){
	if (m_atirou) {

	ofSetColor(255, 192, 45);
	ofDrawCircle(m_posicao + mundo, 3.f);
	ofSetColor(255, 255, 255);

	}

}


/*---------------------------------------------------------------------------------------------
	Indica para qual creep o tiro deve ir, mas somente se tiver passado um tempo
---------------------------------------------------------------------------------------------*/
void Tiro::AtirarEm(ofVec2f alvo, int idCreep){
	m_idCreep = idCreep;
	m_posicaoAlvo = alvo;
	m_atirou = true;
}

void Tiro::SetAtirou(bool set){
	m_atirou = set;
}

void Tiro::SetAtingiu(bool set){
	m_atingiu = set;
}


/*---------------------------------------------------------------------------------------------
	Retorna o valor da variavel m_atirou
---------------------------------------------------------------------------------------------*/
bool Tiro::GetAtirou(){
	return m_atirou;
}



/*---------------------------------------------------------------------------------------------
	Retorna se o tiro atingiu ou nao o creep
---------------------------------------------------------------------------------------------*/
bool Tiro::GetAtingiu(){
	return m_atingiu;
}

int Tiro::GetIDCreep(){
	return m_idCreep;
}




