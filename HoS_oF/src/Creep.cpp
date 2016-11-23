#include "Creep.h"

/*---------------------------------------------------------------------------------------------
	Aponta para um caminho 
---------------------------------------------------------------------------------------------*/
void Creep::Iniciar(Caminho* rota, int id) {
	m_id = id;
	m_proximoPonto = 1;
	m_rota = rota;
	m_posicao = rota->PegarPosicaoDe(0); //
	m_direcao = rota->PegarPosicaoDe(1);
	m_vida = 100.f;
	m_vivo = true;

}




/*---------------------------------------------------------------------------------------------
	Realiza a movimentacao do creep com base na distancia dos points da rota
---------------------------------------------------------------------------------------------*/
void Creep::Atualizar(float angle, ofVec2f player) {
	m_vivo = m_vida > 0 ? true : false;

	if(m_vivo){
		if (!SeguirJogador(player)) {

			m_direcao = m_rota->PegarPosicaoDe(m_proximoPonto);
			if (m_posicao.distance(m_direcao) <= 50.f) {
				if (m_proximoPonto < 4)
					m_proximoPonto++;
				else {
					angle = angle * PI / 180.f;
					m_arrodear.set(cosf(angle), sinf(angle));
					m_posicao += ofVec2f(m_arrodear).normalized() * VELOCIDADE * ofGetLastFrameTime();
				}
			}
			else {
				m_posicao += (m_direcao - m_posicao).normalized() * VELOCIDADE * ofGetLastFrameTime();
			}
		
		}

	}

}




/*---------------------------------------------------------------------------------------------
	Desenha o creep 
---------------------------------------------------------------------------------------------*/
void Creep::Draw(ofVec2f mundo) {

	ofSetColor(0, 255, 0);
	ofDrawCircle(m_posicao + mundo, 15);
	ofSetColor(255, 255, 255);
}



/*---------------------------------------------------------------------------------------------
	Retorna se o creep esta vivo ou morto
---------------------------------------------------------------------------------------------*/
bool Creep::GetVivo(){
	return m_vivo;
}



/*---------------------------------------------------------------------------------------------
	Define se o creep esta vivo ou morto
---------------------------------------------------------------------------------------------*/
void Creep::SetVivo(bool vivo){
	m_vivo = vivo;
}



/*---------------------------------------------------------------------------------------------
	Aplica dano no creep
---------------------------------------------------------------------------------------------*/
void Creep::LevarDano(float dano){
	m_vida -= dano;
}

bool Creep::SeguirJogador(ofVec2f player){
	ofVec2f tmp = m_direcao - m_posicao;
	ofVec2f tmp2 = player - m_posicao;
	float angle1 = atan2f(tmp.y, tmp.x) * 180 / PI;
	float angle2 = atan2f(tmp2.y, tmp2.x) * 180 / PI;
	bool seguir = false;
	
	seguir = ((abs(angle1) - abs(angle2)) <= 30) && (m_posicao.distance(player) <= 500.f);

	if (seguir) {
		m_direcao = player;
		m_posicao += ofVec2f(tmp2).normalized() * VELOCIDADE * ofGetLastFrameTime();
	}

	return seguir;
}

int Creep::GetId(){
	return m_id;
}


