#include "Jogador.h"


/*---------------------------------------------------------------------------------------------
	Inicia o jogador
---------------------------------------------------------------------------------------------*/
void Jogador::Iniciar(ofVec2f posicao, ofVec2f* mundo){
	m_condemnAtaque.Iniciar();
	m_posicao = posicao;
	m_proxPosicao = posicao;
	m_danoPadrao = 15.f;
	m_IDCreep = NULL;

	m_listaTiros.Iniciar(&m_posicao, mundo);


	m_tirou = 0;
}





/*---------------------------------------------------------------------------------------------
	Atualiza o jogador
---------------------------------------------------------------------------------------------*/
void Jogador::Atualizar(ofVec2f mundo, ofVec2f posicaoCreep) {
	m_posicaoAlvo = posicaoCreep;
	/* Atualiza a posicao do jogador */
	if (m_posicaoAlvo == ofVec2f(0,0)) {

		if (m_posicao.distance(m_proxPosicao) > 25.f) {
			ofVec2f tmp = m_proxPosicao - m_posicao;
			tmp.normalize();
			m_posicao += tmp * VELOCIDADE * ofGetLastFrameTime();
		}
		m_listaTiros.SetPosicao(m_posicao);
		m_listaTiros.SetAtirou(false);

	}
	else {
		if (m_posicao.distance(m_posicaoAlvo) > 250.f) {
			ofVec2f tmp = m_posicaoAlvo - m_posicao;
			tmp.normalize();
			m_posicao += tmp * VELOCIDADE * ofGetLastFrameTime();
			m_proxPosicao = m_posicao;
		}
		
		

	}

	Atacar();

}




/*---------------------------------------------------------------------------------------------
	Indica para onde o jogador deve se mover
---------------------------------------------------------------------------------------------*/
void Jogador::SetProxPosicao(ofVec2f proxPosicao) {
	m_proxPosicao = proxPosicao;
}




/*---------------------------------------------------------------------------------------------
	Desenha  o jogador
---------------------------------------------------------------------------------------------*/
void Jogador::Draw(ofVec2f mundo) {

	if (m_listaTiros.GetAtirou())
		m_listaTiros.Draw(mundo);
	ofDrawCircle(m_posicao + mundo, 25);
}





/*---------------------------------------------------------------------------------------------
	Retorna o valor de dano padrao do jogador
---------------------------------------------------------------------------------------------*/
float Jogador::GetDanoPadrao(){
	return m_danoPadrao;
}




/*---------------------------------------------------------------------------------------------
	Indica qual creep o jogador deve atacar
---------------------------------------------------------------------------------------------*/
void Jogador::SetAtaqueEsseCreep(int idCreep){
	m_IDCreep = idCreep;

}




/*---------------------------------------------------------------------------------------------
	O jogador atira no creep, cada tiro eh disparado conforme o tempo de disparo
---------------------------------------------------------------------------------------------*/
void Jogador::Atacar(){


		if (m_posicao.distance(m_posicaoAlvo) <= 280.f) {
		
			m_listaTiros.AtirarEm(m_posicaoAlvo, m_IDCreep);
			m_listaTiros.Atualizar();
		}


}


/*---------------------------------------------------------------------------------------------
	Retorna o ID do creep que esta sendo atacado
---------------------------------------------------------------------------------------------*/
int Jogador::GetCreepID(){
	return m_IDCreep;
}


/*---------------------------------------------------------------------------------------------
	Retorna se o tiro atingiu o creep
---------------------------------------------------------------------------------------------*/
bool Jogador::GetTiroAtingiu(){
	return m_listaTiros.GetAtingiu();
}

/*---------------------------------------------------------------------------------------------
	Define um valor para a variavel que indica se um tiro atingiu um creep ou nao
---------------------------------------------------------------------------------------------*/
void Jogador::SetTiroAtingiu(bool set){
	m_listaTiros.SetAtingiu(set);
}


