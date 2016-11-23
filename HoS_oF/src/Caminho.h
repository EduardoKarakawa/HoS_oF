#pragma once
#include "ofVec2f.h"
#include "ofAppRunner.h"

class Caminho {
private:
	ofVec2f m_listaPontos[5];
	int m_posNovoPonto;

public:
	void Inicializar(ofVec2f mundo);
	void NovoCaminho(ofVec2f novaPosicao, ofVec2f mundo);
	void SetCaminho(ofVec2f novaRota[5]);
	float GetDistancia(int indice, ofVec2f ponto);
	ofVec2f PegarPosicaoDe(int indice);

};