#include "Mapa.h"

void Mapa::Iniciar(ofVec2f posicao, string localImagem) {
	m_posicao = posicao;
	m_sprite.load(localImagem);
	m_atingiuBorda = true;
}




//------------------------------------------------------------------------------------------
//----------------------- CONTROLADOR DE CAMERA -------------------------------------------
void Mapa::ControladorCam(ofVec2f jogador) {
	m_seguirJogador ? FixarCamJogador(jogador) : CamLivre();
}


void Mapa::ToggleCam() {
	m_seguirJogador = !m_seguirJogador;
}

ofVec2f * Mapa::GetEnderecoPosicao()
{
	return &m_posicao;
}





//------------------------------------------------------------------------------------------
//------------------------- FIXA A CAMERA NO JOGADOR ---------------------------------------
void Mapa::FixarCamJogador(ofVec2f jogador) {
	ofVec2f tmp = jogador - ofVec2f(ofGetWidth() / 2.f, ofGetHeight() / 2.f);
	m_posicao = -tmp;
}





//------------------------------------------------------------------------------------------
//------------------ MOVE A CAMERA QUANDO MOUSE ENCOSTAR NAS BORDAS DA TELA ----------------
void Mapa::CamLivre() {

	ofVec2f tmp_mouse(ofGetMouseX(), ofGetMouseY()); //Pegando a posicao do mouse
	float temp = 0;
	if (tmp_mouse.x < BORDA_CAMERA) {		//Verificando se o mouse esta perto da borda da tela
		temp = m_posicao.x + (BORDA_CAMERA - tmp_mouse.x) * VELOCIDADE_CAM * ofGetLastFrameTime();

		temp < 0 ? m_posicao.x = temp : 0;	//Verifica se o sprite vai estar dentro da tela

	}
	else if (tmp_mouse.x > ofGetWidth() - BORDA_CAMERA) {
		temp = m_posicao.x + (ofGetWidth() - BORDA_CAMERA - tmp_mouse.x) * VELOCIDADE_CAM * ofGetLastFrameTime();

		float tmp2 = (m_sprite.getWidth() + m_posicao.x - ofGetWidth()); //Pega a posicao do mundo + o sprite e tira width da tela
		tmp2 > 0 ? m_posicao.x = temp : 0; //Verifica se o sprite vai estar dentro da tela

	}

	if (tmp_mouse.y < BORDA_CAMERA) {
		temp = m_posicao.y + (BORDA_CAMERA - tmp_mouse.y) * VELOCIDADE_CAM * ofGetLastFrameTime();

		temp < 0 ? m_posicao.y = temp : 0;	//Verifica se o sprite vai estar dentro da tela
	}

	else if (tmp_mouse.y > ofGetHeight() - BORDA_CAMERA) {
		temp = m_posicao.y + (ofGetHeight() - BORDA_CAMERA - tmp_mouse.y) * VELOCIDADE_CAM * ofGetLastFrameTime();

		float tmp2 = (m_sprite.getHeight() + m_posicao.y - ofGetHeight()); //Pega a posicao do mundo + o sprite e tira width da tela
		tmp2 > 0 ? m_posicao.y = temp  : 0; //Verifica se o sprite vai estar dentro da tela

	}

}






//------------------------------------------------------------------------------------------
//-------------------- DESENHAR NA TELA ----------------------------------------------------
void Mapa::Draw(ofVec2f mundo) {
	m_sprite.draw(m_posicao);
}