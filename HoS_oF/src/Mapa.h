#pragma once
#include "ofVec2f.h"
#include "ofImage.h"
#include "ofAppRunner.h"
#include <string>
#include "Objeto.h"

#define BORDA_CAMERA 120.f
#define VELOCIDADE_CAM 8.f

class Mapa : public Objeto{
private:
	bool m_seguirJogador, m_atingiuBorda;
	ofImage m_sprite;

public:
	void Iniciar(ofVec2f posicao, string localImagem);
	void ControladorCam(ofVec2f jogador);
	void FixarCamJogador(ofVec2f jogador);
	void CamLivre();
	void Draw(ofVec2f mundo);
	void ToggleCam();
	ofVec2f* GetEnderecoPosicao();
};